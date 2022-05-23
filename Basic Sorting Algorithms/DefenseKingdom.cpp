/*
Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. 
The player builds crossbow towers in some cells of the grid. 
The tower defends all the cells in the same row and the same column. No two towers share a row or a column.
The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.
*/

#include<bits/stdc++.h>
using namespace std;
#include<algorithm>
#include<vector>
#define all(v) v.begin(), v.end()
typedef long long ll;
//using ll = long long;

int defkin(int W, int H, vector<pair<int, int>> position)
{
    vector<pair<int, int>> v = position;
    vector<ll> x, y;
    
    ll maxx = INT_MIN, maxy = INT_MIN;
    
    x.push_back(0), y.push_back(0);
    
    for(int i=0; i<v.size(); i++)
        x.push_back(v[i].first), y.push_back(v[i].second);
    
    //x.push_back(W+1), y.push_back(H+1); //(For end co-ordinates we have to add 1) If we use this method
    //Also No need to do maxx and maxy after the below for loop if we use this method
    
    sort(all(x));
    sort(all(y));
    
    for(ll i=1; i<x.size(); i++)  //can use y.size() as well because both will be same
    {
        maxx = max(maxx, x[i] - x[i - 1] - 1);
        maxy = max(maxy, y[i] - y[i - 1] - 1);
    }
    maxx = max(maxx, W - x[x.size() - 1]);
    maxy = max(maxy, H - y[y.size() - 1]);
   
    return (maxx * maxy);
}
