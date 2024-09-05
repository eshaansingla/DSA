#include<bits/stdc++.h>
using namespace std;
/*Koko loves to eat bananas. There are" n piles" of bananas, the "ith pile" has "piles[i]" bananas. The guards have gone and will come back in "h" hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours*/
long long banana(vector<int>& piles, int h){
        long long totalhrs=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            totalhrs += ceil((double)piles[i]/(double)h);
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    int total=0;
    int n=piles.size();
    int low=1;
    int high=*max_element(piles.begin(), piles.end());
    int mid;
    long long hours;
    while(high>=low){
        mid=low + (high-low)/2;
        hours=banana(piles,mid);
        if(h>=hours){
             high=mid-1;
             }
        else {
            low=mid+1;
            }
    }
    return low;
    }
int main(){
    vector<int>v={3,4,5,6,7};
cout<<minEatingSpeed(v,8)<<endl;
}