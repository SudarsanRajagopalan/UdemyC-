/*
Given a vector of pairs representing coordinates x and y of different cabs on a X-Y plane. Sort them according to their distance from the origin in the non-decreasing order i.e. the cab with shortest distance from the origin will be at first.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

float sumOfPairs(pair<int, int> s)
{
    return sqrt((s.first*s.first) + (s.second*s.second));
    //Why we are squaring and taking square root is because the coordinates
    //can be negative as well
}
bool compare(pair<int, int> a1, pair<int, int> a2)
{
    return sumOfPairs(a1) < sumOfPairs(a2);
}
vector<pair<int,int>> sortCabs(vector<pair<int,int>> v){
    sort(all(v), compare);
    return v;
}
