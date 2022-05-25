//Expected Time Complexity: O(rows + columns)
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> stairCaseSearch(vector<vector<int>> vect, int key)
{
    int row = 0;
    int col = vect[0].size() - 1;
    
    //Return {-1, -1} if the key to be found is lesser than the first element or greater than the last element
    if(key < vect[0][0] or key > vect[vect.size()-1][col])
        return {-1, -1};
        
    while(row < vect.size() and col >= 0)
    {
        if(vect[row][col] == key)
            return {row, col};
        else if(vect[row][col] > key)
            col--;
        else  //if(vect[row][col] < key)
            row++;
    }
    
    return {-1, -1};
    
}

int main()
{
    //2D Row and Column wise sorted Array 
    vector<vector<int>> vect {{10, 20, 30, 40},
                             {15, 25 ,35, 45},
                             {27, 29, 37, 48},
                             {32, 33, 39, 50}};
    pair<int, int> coords = stairCaseSearch(vect, 37);
    if(coords.first != -1)
        cout << "The key is found at: {" << coords.first <<", " << coords.second <<"}";
    else
        cout << "The key is not found in the 2d array";
    return 0;
}
