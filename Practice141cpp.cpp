/*

142. Dequeue: You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and deleted from both the ends.
You don't need to double the capacity.
You need to implement the following functions -

1. constructor
You need to create the appropriate constructor. Size for the queue passed is 10.
2. insertFront -
This function takes an element as input and insert the element at the front of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
3. insertRear -
This function takes an element as input and insert the element at the end of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
4. deleteFront -
This function removes an element from the front of queue. Print -1 if queue is empty.
5. deleteRear -
This function removes an element from the end of queue. Print -1 if queue is empty.
6. getFront -
Returns the element which is at front of the queue. Return -1 if queue is empty.
7. getRear -
Returns the element which is at end of the queue. Return -1 if queue is empty.

*/

/**********

 Following is the main function we are using internally.
 Refer this for completing the Dequeue class.


 int main()
 {
 Deque dq(10);
 int choice,input;
 while(true) {
 cin >> choice;
 switch (choice) {
 case 1:
 cin >> input;
 dq.insertfront(input);
 break;
 case 2:
 cin >> input;
 dq.insertrear(input);
 break;
 case 3:
 dq.deletefront();
 break;
 case 4:
 dq.deleterear();
 break;
 case 5:
 cout << dq.getFront() << "\n";
 break;
 case 6:
 cout << dq.getRear() << "\n";
 break;
 default:
 return 0;
 }
 }

 return 0;
 }

 ************/

#include <iostream>
using namespace std;

class Deque
{
private:
    int *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

public:
    Deque(int x)
    {
        data = new int[10];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = x;
    }
    void insertFront(int element)
    {
        if (size == capacity)
        {
            cout << -1 << endl;
            return;
        }
        if (size == 0)
        {
            firstIndex = 0;
            nextIndex = 1;
        }
        else
        {
            firstIndex = (((firstIndex - 1) % capacity + capacity) % capacity);
        }
        data[firstIndex] = element;
        size++;
    }

    void insertRear(int element)
    {
        if (size == capacity)
        {
            cout << -1 << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
    }

    void deleteFront()
    {
        if (size == 0)
        {
            cout << -1 << endl;
            return;
        }
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
    }

    void deleteRear()
    {
        if (size == 0)
        {
            cout << -1 << endl;
            return;
        }
        nextIndex = ((nextIndex - 1) % capacity + capacity) % capacity;
        size--;
        if (size == 0)
        {
            nextIndex = 0;
            firstIndex = -1;
        }
    }

    int getFront()
    {
        if (size == 0)
        {
            return -1;
        }
        return data[firstIndex];
    }

    int getRear()
    {
        if (size == 0)
        {
            return -1;
        }
        return data[(((nextIndex - 1) % capacity + capacity) % capacity)];
    }
};
