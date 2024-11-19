#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::mutex mtx; // Mutex for critical section
std::condition_variable cv; // Condition variable for synchronization
std::queue<int> buffer; // Shared buffer
const int BUFFER_SIZE = 5; // Maximum buffer size

bool done = false; // Flag to indicate producer is finished

// Producer function
void producer() {
    for (int i = 0; i < 10; ++i) { // Producing 10 items
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < BUFFER_SIZE; }); // Wait if buffer is full
        buffer.push(i); // Add item to the buffer
        std::cout << "Produced: " << i << std::endl;
        lock.unlock();
        cv.notify_all(); // Notify consumer
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate production delay
    }
    // Signal consumers to stop
    std::unique_lock<std::mutex> lock(mtx);
    done = true;
    lock.unlock();
    cv.notify_all();
}

// Consumer function
void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty() || done; }); // Wait if buffer is empty
        if (!buffer.empty()) {
            int item = buffer.front();
            buffer.pop(); // Remove item from the buffer
            std::cout << "Consumed: " << item << std::endl;
        } else if (done) {
            break; // Exit if producer is finished and buffer is empty
        }
        lock.unlock();
        cv.notify_all(); // Notify producer
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate consumption delay
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}