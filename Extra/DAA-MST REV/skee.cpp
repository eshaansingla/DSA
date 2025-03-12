#include <bits/stdc++.h>
using namespace std;
vector<int> assignSkis(vector<int> P, vector<int> S)
{
    vector<pair<int, int>> skier;
    vector<pair<int, int>> skies;
    for (int i = 0; i < P.size(); i++)
    {
        skier.push_back({P[i], i});
        skies.push_back({S[i], i});
    }
    sort(skier.begin(), skier.end());
    sort(skies.begin(), skies.end());
    vector<int> sol(P.size());
    for (int i = 0; i < P.size(); i++)
    {
        sol[skier[i].second] = skies[i].second;
    }
    return sol;
}
int main()
{
    vector<int> P = {3, 2, 5, 1}; // Skiers' heights 1 2 3 5
    vector<int> S = {5, 7, 2, 9}; // Skis' heights   2 5 7 9

    vector<int> A = assignSkis(P, S);

    // Output the assignment array
    cout << "Assignment array A: ";
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}