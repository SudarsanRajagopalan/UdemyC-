//Max Sum Sub Array (Brute Force)
//Time Complexity O(N^3)
#include <iostream>
using namespace std;

int sumOfSubArray(int arr[], int n)
{
    int maxSum = arr[0];
    int interSum = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            for(int k=i; k<=j ; k++)
            {
               interSum += arr[k];
            }
            cout << interSum<<endl;
            if(interSum > maxSum)
                maxSum = interSum;
            interSum = 0;
        }
    }
    return maxSum;
}

int main() {
	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(arr)/sizeof(int);
	int maxSum = sumOfSubArray(arr, n);
	cout << "MaxSum of SubArray:" << maxSum;
    return 0;
}
