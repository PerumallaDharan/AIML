// Stack using file system

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Error opening files." << endl;
        return 1;
    }

    int stackSize;
    inputFile >> stackSize;
    int stack[stackSize];
    int top = -1;
    string operation;
    while (inputFile >> operation)
    {
        if (operation == "Push")
        {
            if (top == stackSize - 1)
            {
                outputFile << "Stack Overflow" << endl;
            }
            else
            {
                int data;
                inputFile >> data;
                top++;
                stack[top] = data;
            }
        }
        else if (operation == "Pop")
        {
            if (top == -1)
            {
                outputFile << "Stack Underflow" << endl;
            }
            else
            {
                cout << "Popped element is " << stack[top] << endl;
                top--;
            }
        }
        else if (operation == "Display")
        {
            if (top == -1)
            {
                outputFile << "Stack is empty" << endl;
            }
            else
            {
                for (int i = top; i >= 0; i--)
                {
                    outputFile << stack[i] << " ";
                }
                outputFile << endl;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
