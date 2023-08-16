// Write a program to implement stack using array.

#include <iostream>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of the stack"<<endl;
    cin>>size;
    int stack[size];
    int top = -1;
    int choice;
    do
    {
        cout<<"Enter 1 to push an element"<<endl;
        cout<<"Enter 2 to pop an element"<<endl;
        cout<<"Enter 3 to display the stack"<<endl;
        cout<<"Enter 4 to exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            if(top==size-1){
                cout<<"Stack overflow"<<endl;
            }
            else{
                int element;
                cout<<"Enter the element to be pushed"<<endl;
                cin>>element;
                top++;
                stack[top] = element;
            }
            break;
        case 2:
            if(top==-1){
                cout<<"Stack underflow"<<endl;
            }
            else{
                cout<<"The popped element is "<<stack[top]<<endl;
                top--;
            }
            break;
        case 3:
            if(top==-1){
                cout<<"Stack underflow"<<endl;
            }
            else{
                cout<<"The stack is"<<endl;
                for(int i=top;i>=0;i--){
                    cout<<stack[i]<<" ";
                }
                cout<<endl;
            }
            break;
        case 4:
            cout<<"Exiting"<<endl;
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    } while (choice!=4);
    
    return 0;
}