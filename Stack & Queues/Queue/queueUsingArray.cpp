#include <bits/stdc++.h>
using namespace std;

template <typename T>
class queueUsingArray
{
    T *data;
    int nextIndex;
    int firstIndex;
    int capacity;
    int size;

public:
    queueUsingArray()
    {
        data = new int[4];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = 4;
    }

    //number of elements
    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    //insert an element
    void enqueue(T element)
    {
        if (size == capacity)
        {
            T *newData = new T[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Stack is empty !";
            return;
        }
        return data[firstIndex];
    }

    //delete an element
    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Stack is empty !";
            return;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};
