// Write a program to implement queue using array.

#include <iostream>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of the queue"<<endl;
    cin>>size;
    int queue[size];
    int front = -1;
    int rear = -1;
    int choice;
    do
    {
        cout<<"Enter 1 to enqueue an element"<<endl;
        cout<<"Enter 2 to dequeue an element"<<endl;
        cout<<"Enter 3 to display the queue"<<endl;
        cout<<"Enter 4 to exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            if(rear==size-1){
                cout<<"Queue overflow"<<endl;
            }
            else{
                int element;
                cout<<"Enter the element to be enqueued"<<endl;
                cin>>element;
                if(front==-1){
                    front++;
                }
                rear++;
                queue[rear] = element;
            }
            break;
        case 2:
            if(front==-1){
                cout<<"Queue underflow"<<endl;
            }
            else{
                cout<<"The dequeued element is "<<queue[front]<<endl;
                front++;
                if(front>rear){
                    front = -1;
                    rear = -1;
                }
            }
            break;
        case 3:
            if(front==-1){
                cout<<"Queue underflow"<<endl;
            }
            else{
                cout<<"The queue is"<<endl;
                for(int i=front;i<=rear;i++){
                    cout<<queue[i]<<" ";
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