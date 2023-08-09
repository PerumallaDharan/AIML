// Write a program using function Sum(row-id, no-of-elements) to make the question-1 more modular.

#include<iostream>
using namespace std;

int sum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

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
        cout<<sum(arr[i],m)<<" ";
    }
    cout<<endl;
    cout<<"The sum of each column is: ";
    for(int i=0;i<m;i++){
        int temp[n];
        for(int j=0;j<n;j++){
            temp[j]=arr[j][i];
        }
        cout<<sum(temp,n)<<" ";
    }
    cout<<endl;
    return 0;
}