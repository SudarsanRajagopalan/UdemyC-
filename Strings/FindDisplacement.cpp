/*
Practice Problem:
Find Displacement:  Given a long route containing N, S, E, W directions find the shortest path to reach the location.

Sample Input:
SNNNEWE

Sample Output:
ENN
(or)
NNE
*/

#include <iostream>

using namespace std;

int main()
{
    char route[1000];
    cin.getline(route, 1000);
    int x = 0, y = 0;
    
    for(int i=0; route[i]!='\0'; i++)
    {
        switch(route[i])
        {
            case 'E': x++;
                      break;
            case 'W': x--;
                      break;
            case 'N': y++;
                      break;
            case 'S': y--;
                      break;
        }
    }
    
    cout << "Final X:"<<x<<endl;
    cout << "Final Y:"<<y<<endl;
    
    if(x>=0 and y>=0)
    {
        while(x--)
            cout<<"E";
        while(y--)
            cout<<"N";
    }
    else if(x<0 and y>=0)
    {
        while(x++)
            cout<<"W";
        while(y--)
            cout<<"N";
    }
    else if(x<0 and y<0)
    {
        while(x++)
            cout<<"W";
        while(y++)
            cout<<"S";
    }
    else
    {
        while(x--)
            cout<<"E";
        while(y++)
            cout<<"S";
    }
        
    

    return 0;
}
