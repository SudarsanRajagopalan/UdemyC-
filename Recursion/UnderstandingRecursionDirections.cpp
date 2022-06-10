//Print 1,2,3,4...,N and N,N-1,N-2,...,1 using recursion
#include <iostream>

using namespace std;

void decreasingOrderPrint(int N)
{
    if(N == 0)
        return;
    cout << N << endl;
    decreasingOrderPrint(N - 1);
}

void increasingOrderPrint(int N)
{
    if (N == 0)
        return;
    increasingOrderPrint(N-1);
    cout << N << endl;
        
}

int main()
{
    int N;
    int start = 1;
    cin >> N;
    decreasingOrderPrint(N);
    increasingOrderPrint(N);
    return 0;
}
