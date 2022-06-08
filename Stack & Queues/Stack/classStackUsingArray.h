#include <bits/stdc++.h>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    //insert element
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    //number of elements
    int size()
    {
        return nextIndex;
    }

    //if stack is empty or not
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    //delete an element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty !!";
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty !!";
            return INT_MIN;
        }
        return data[nextIndex--];
    }
};