#include <iostream>

using namespace std;
void read_arr(int arr[],int n);
int smallest_num(int arr[], int n);
int main()
{
    int arr[10],smallest;
    read_arr(arr,(sizeof(arr)/4));
    cout<<"\nThe smallest num in arr is = "<<smallest_num(arr,(sizeof(arr)/4));
}
void read_arr(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"arr ["<<i<<"] = ";
        cin>>arr[i];
    }
}

int smallest_num(int arr[],int n)
{
    int smallest = arr[0];
    for (int i=0;i<n-1;i++)
    {
        if(arr[i]<smallest||arr[i+1]<smallest)
            smallest=(arr[i]<arr[i+1])?arr[i]:arr[i+1];
    }
    return smallest ;
}
