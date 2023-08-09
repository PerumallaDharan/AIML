// Write a program to find the number of ZEROs in a particular column of a 2-D matrix.

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

    int col;
    cout<<"Enter the column number"<<endl;
    cin>>col;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i][col]==0){
            count++;
        }
    }
    cout<<"The number of zeroes in column "<<col<<" is "<<count<<endl;
    return 0;
}