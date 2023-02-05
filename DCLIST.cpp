/*-- DCLIST.cpp------------------------------------------------------------

   This file implements DCLIST member functions.

-------------------------------------------------------------------------*/

#include "DCLIST.h"
#include <assert.h>

// DoublyNode class constructor
DCLIST::DoublyNode::DoublyNode(ElementType n)
{
	data = n;
	predecessor = NULL;
	successor = NULL;
}

// DCLIST class constructor
DCLIST::DCLIST()
	: mySize(0), myFirst(NULL) // assigning 0 to mySize and NULL to myFirst
{
}

// DCLIST copy constructor
DCLIST::DCLIST(DCLIST &origList)
	: myFirst(NULL), mySize(0) // assigning 0 to mySize and NULL to myFirst
{
	Nodeptr temp = origList.myFirst;
	/*looping till the end of the origList and inserting the origList data in the list
	 at the end one by one.*/
	for (int i = 0; i < origList.mySize; i++)
	{
		insertAtEnd(temp->data);
		temp = temp->successor;
	}
}
// DCLIST private function searchNode that returns the item if it is present in the list
DCLIST::Nodeptr DCLIST::searchNode(ElementType data) const
{
	if (!isEmpty())
	{
		Nodeptr temp = myFirst;
		do
		{
			if (temp->data == data) // if data is found
			{
				return temp; // return the pointer to the node where the data was found
			}
			temp = temp->successor;
		} while (temp != myFirst); // loop all over the list unless data is found
		return NULL;			   // data was not found
	}
	// else
	return NULL; // the list was empty
}

//--- Definition of equal operator
const DCLIST &DCLIST::operator=(const DCLIST &rightHandSide)
{
	if (this != &rightHandSide) // check that not self-assignment
	{

		if (!rightHandSide.isEmpty()) // check that its not empty
		{

			this->~DCLIST(); // invoking the destructor

			mySize = 0;
			myFirst = NULL;

			Nodeptr temp = rightHandSide.myFirst;
			// copying the rightHandSide data into the list
			for (int i = 0; i < rightHandSide.mySize; i++)
			{
				insertAtEnd(temp->data);
				temp = temp->successor;
			}
			return *this;
		}
		// else
		this->~DCLIST(); // rightHandSide was empty
		mySize = 0;
		myFirst = NULL;
		return *this;
	}
	return *this; // it was self assignment
}

// DCLIST class destructor
DCLIST::~DCLIST()
{
	if (isEmpty()) // check if the list is empty
	{
		return; // nothing to destruct
	}
	// else
	Nodeptr temp;
	for (int i = 0; i < mySize; i++)
	{
		temp = myFirst;				  // setting temp to myFirst
		myFirst = myFirst->successor; // moving my first to the right once
		delete temp;				  // deleting temp
	}
}

//--- Definition of isEmpty()
bool DCLIST::isEmpty() const
{
	return mySize == 0;
}

//--- Definition of search()
bool DCLIST::search(ElementType data) const
{
	assert(!isEmpty());			  // make sure the list is not empty
	if (searchNode(data) != NULL) // if data was found
	{
		return true;
	}
	// else
	return false; // data is not found
}

//--- Definition of insertAtPosition()
bool DCLIST::insertAtPosition(ElementType data, int position)
{
	Nodeptr newNode = new DoublyNode(data); // create a new node with n = data
	Nodeptr temp = myFirst;
	if (position >= 0 && position <= mySize) // check if the position is legal
	{
		if (isEmpty()) // list is empty
		{
			myFirst = newNode;
			myFirst->predecessor = myFirst;
			myFirst->successor = myFirst;
		}
		else if (position == 0) // list is not empty and we insert at beginning
		{
			newNode->predecessor = myFirst->predecessor;
			newNode->successor = myFirst;
			myFirst->predecessor->successor = newNode;
			myFirst->predecessor = newNode;
			myFirst = newNode;
		}

		else // list not empty and we're inserting in middle or end
		{
			for (int i = 1; i < position; i++)
			{
				temp = temp->successor;
			}
			newNode->successor = temp->successor;
			newNode->predecessor = temp;
			(temp->successor)->predecessor = newNode;
			temp->successor = newNode;
		}
		mySize++; // increment mySize
		return true;
	}
	// else
	cerr << "Position is not valid" << endl;
	return false;
}

//--- Definition of insertAtEnd()
bool DCLIST::insertAtEnd(ElementType data)
{
	// invoke inserAtPosition with mySize as the postion to insert at end
	return insertAtPosition(data, mySize);
}

//--- Definition of insertAtBegining()
bool DCLIST::insertAtBegining(ElementType data)
{
	// invoke inserAtPosition with 0 as the postion to insert at begining
	return insertAtPosition(data, 0);
}

//--- Definition of deleteAtPosition()
bool DCLIST::deleteAtPosition(int position)
{
	assert(!isEmpty()); // make sure the list is not empty

	if (position >= 0 && position < mySize) // check if the position is legal
	{
		Nodeptr temp;

		if (position == 0) // delete at begining
		{
			if (mySize == 1) // only one element is in the list
			{
				myFirst = NULL;
				cout << "Empty list" << endl;
			}
			else // more than one element is in the list
			{
				myFirst->successor->predecessor = myFirst->predecessor;
				myFirst->predecessor->successor = myFirst->successor;
				temp = myFirst;
				myFirst = myFirst->successor;
				delete temp;
			}
		}

		else // delete at middle or end
		{
			temp = myFirst->successor;

			for (int i = 1; i < position; i++)
			{
				temp = temp->successor;
			}

			(temp->successor)->predecessor = temp->predecessor;
			(temp->predecessor)->successor = temp->successor;
			delete temp;
		}
		mySize--; // decrement size
		return true;
	}
	// else
	cerr << "position is not valid" << endl;
	return false;
}

//--- Definition of deleteAValue()
bool DCLIST::deleteAValue(ElementType data)
{
	assert(!isEmpty()); // make sure the list is not empty
	Nodeptr temp = searchNode(data);

	if (temp != NULL) // data is found
	{
		if (mySize == 1) // only one element is in the list
		{
			delete temp;
			myFirst = NULL;
		}
		else if (temp == myFirst) // the element is at the begining
		{
			myFirst->successor->predecessor = myFirst->predecessor;
			myFirst->predecessor->successor = myFirst->successor;
			myFirst = myFirst->successor;
			delete temp;
		}
		else // the element is at the middle or end
		{
			(temp->successor)->predecessor = temp->predecessor;
			(temp->predecessor)->successor = temp->successor;
			delete temp;
		}
		mySize--; // decrement size
		return true;
	}
	else // data is not found
	{
		cerr << "data is not found" << endl;
		return false;
	}
}

//--- Definition of deleteBeforeAnElement()
bool DCLIST::deleteBeforeAnElement(ElementType data)
{
	Nodeptr temp = searchNode(data);
	if (temp != NULL) // element is found
	{
		if (mySize > 1) // more than one element in the list
		{
			// invoke deleteAValue with the value of the node before temp as a paremeter
			if (deleteAValue((temp->predecessor)->data))
				return true;
		}
		cerr << "No other node in the list" << endl;
		return false;
	}
	// else
	cerr << "Element is not in the list" << endl;
	return false;
}

//--- Definition of findAndDelete()
int DCLIST::findAndDelete(ElementType data)
{
	int count = 0; // create a counter
	while (search(data))
	{
		deleteAValue(data); // invoke deleteAValue
		count++;			// increment count
	}
	return count;
}

//--- Definition of removeFirst()
ElementType DCLIST::removeFirst()
{
	assert(!isEmpty());				  // make sure the list is not empty
	ElementType temp = myFirst->data; // save the data of myFirst in temp
	deleteAtPosition(0);			  // delete the first node
	return temp;					  // return the saved data
}

ElementType DCLIST::removeLast()
{
	assert(!isEmpty());							   // make sure the list is not empty
	ElementType temp = myFirst->predecessor->data; // save the data of the last element in temp
	deleteAtPosition(mySize - 1);				   // delete the last node
	return temp;								   // return the saved data
}

int DCLIST::deleteDuplicates()
{
	assert(!isEmpty());
	Nodeptr temp1 = myFirst;
	Nodeptr temp2 = myFirst->successor;
	int count = 0;						// create a counter
	int i = 0, j = 0;					// for the postion of the data
	while (temp1->successor != myFirst) // traverse temp1 into the list
	{
		i = j + 1;				 // set position
		while (temp2 != myFirst) // traverse temp2 into the list
		{
			if (temp2->data == temp1->data) // compare temp1 and temp2
			{
				temp2 = temp2->successor; // move temp2 to the next node

				deleteAtPosition(i); // delete the occurenece at position i

				count++; // increment count
			}
			else // temp1 is not equal temp2
			{
				temp2 = temp2->successor; // move temp2 to the next node
				i++;					  // increment i
			}
		}

		temp1 = temp1->successor; // move temp1 to the next node to compare it again
		temp2 = temp1->successor; // set temp2 to temp1->successor again
		j++;					  // increment j
	}

	return count;
}

//--- Definition of display()
void DCLIST::display(ostream &out) const
{
	if (isEmpty()) // list is empty
		out << "Empty List";
	else
	{
		Nodeptr dataPtr = myFirst;
		out << "The List is:" << endl;
		// display data from begining till end-1 with <-> in between
		for (int i = 0; i < mySize - 1; i++)
		{
			out << dataPtr->data << " <-> ";
			dataPtr = dataPtr->successor;
		}
		cout << dataPtr->data << endl; // display the last data
	}
}

//--- Definition of output operator
ostream &operator<<(ostream &out, const DCLIST &rightHandSide)
{
	rightHandSide.display(out); // invoke display()
	return out;
}
