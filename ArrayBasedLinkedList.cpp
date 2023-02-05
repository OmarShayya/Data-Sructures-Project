/*-- ArrayBasedLinkedList.cpp------------------------------------------------------------
 
   This file implements ArrayBasedLinkedList member functions.

-------------------------------------------------------------------------*/
#include "ArrayBasedLinkedList.h"

// ArrayBasedLinkedList class constructor
ArrayBasedLinkedList::ArrayBasedLinkedList()
    : mySize(0), myFirst(-1)
{
}

int ArrayBasedLinkedList::newNode()
{
    for (int i = 0; i < CAPACITY; i++)
    {
        if (myArray[i].next == Free) // checks if the element is free 
            return i;
    }
    return -1;
}

bool ArrayBasedLinkedList::isEmpty() const
{
    return mySize == 0;
}

bool ArrayBasedLinkedList::isFull() const
{
    return mySize == CAPACITY;
}

int ArrayBasedLinkedList::search(const ElementType &data)
{
    if (isEmpty())
    {
        cerr << "Empty list" << endl;
        exit(1);
    }
    int temp = myFirst;
    for (int i = 0; i < mySize; i++)
    {
        if (myArray[temp].data == data)
        {
            return i; // return index where data was found
        }
        temp = myArray[temp].next;
    }
    return -1; // data was not found
}

bool ArrayBasedLinkedList::insertAtPosition(const ElementType &data, int pos)
{
    if (isFull())
    {
        cerr << "List is Full" << endl;
        exit(1);
    }

    if (pos < 0 || pos > mySize)
    {
        cerr << "invalid position" << endl;
        return false;
    }

    if (isEmpty()) // list is empty
    {
        myFirst++; // myfirst is 0 now
        myArray[myFirst].data = data;
        myArray[myFirst].next = NULL_VALUE; // points to a null-value
        mySize++;
        return true;
    }

    if (pos == 0)
    {
        int x = newNode(); // get a free position to input
        myArray[x].data = data; 
        myArray[x].next = myFirst;
        myFirst = x;
        mySize++;
        return true;
    }

    int curr = myFirst;
    for (int i = 1; i < pos; i++)
    {
        curr = myArray[curr].next; // move curr to pos -1
    }
    int x = newNode();
    myArray[x].data = data;
    myArray[x].next = myArray[curr].next;
    myArray[curr].next = x;
    mySize++;
    return true;
}

bool ArrayBasedLinkedList::insertAtBegining(const ElementType &data)
{
    return insertAtPosition(data, 0);
}

bool ArrayBasedLinkedList::insertAtEnd(const ElementType &data)
{
    return insertAtPosition(data, mySize);
}

bool ArrayBasedLinkedList::deleteAtPosition(int pos)
{
    if (isEmpty())
    {
        cerr << "Empty List" << endl;
        exit(1);
    }

    if (pos < 0 || pos >= mySize)
    {
        cerr << "position is invalid" << endl;
        return false;
    }

    if (pos == 0)
    {
        int temp = myFirst;
        myFirst = myArray[myFirst].next;
        myArray[temp].next = Free;
        mySize--;
        return true;
    }

    // else
    int curr = myFirst;
    for (int i = 1; i < pos; i++)
    {
        curr = myArray[curr].next;
    }
    int temp = curr;
    curr = myArray[curr].next;
    myArray[temp].next = Free;
    myArray[temp].next = myArray[curr].next;
    mySize--;
    return true;
}

bool ArrayBasedLinkedList::deleteAtBegining()
{
    return deleteAtPosition(0);
}

bool ArrayBasedLinkedList::deleteAtEnd()
{
    return deleteAtPosition(mySize - 1);
}

bool ArrayBasedLinkedList::deleteAValue(ElementType data)
{
    if (isEmpty())
    {
        cerr << "List is Empty" << endl;
        exit(1);
    }
    int x = search(data);
    if (x != -1)
    {
        return deleteAtPosition(x);
    }
    cerr << "Element is not found" << endl;
    return false;
}

void ArrayBasedLinkedList::display(ostream &out) const
{
    if (isEmpty())
        out << "List is Empty" << endl;
    else
    {
        out << "The list is:" << endl;
        int ptr = myFirst;
        for (int i = 0; i < mySize; i++)
        {
            out << myArray[ptr].data << " ";
            ptr = myArray[ptr].next;
        }
        cout << endl;
    }
}

ostream &operator<<(ostream &out, const ArrayBasedLinkedList &r)
{
    r.display(out);
    return out;
}