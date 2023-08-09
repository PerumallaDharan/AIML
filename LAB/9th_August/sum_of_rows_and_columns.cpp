// Write a program to read a 2-D matrix and find the sum of each rows and columns.

#include<iostream>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the number of rows and columns"<<endl;
    cin>>n>>m;
    int arr[n][m];
    cout<<"Enter the elements of the matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"The sum of each row is: ";
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=arr[i][j];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
    cout<<"The sum of each column is: ";
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=arr[j][i];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
    return 0;
}
