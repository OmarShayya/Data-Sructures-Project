/*-- ArrayBasedLinkedList.h --------------------------------------------------------------

  This header file defines the data type ArrayBasedLinkedList for processing lists.
  Basic operations are:
	 Constructor
	 isEmpty: Check if list is empty
     isFull: Check if the list is full
	 search: returns the index of the element if it is present in the list
	 insertAtPosition: Inserts an item at a specified position
	 insertAtEnd: Inserst an item at the end of the list
	 insertAtBegining: Inserts an item at the begining of the list
	 deleteAtPosition: Deletes an item at a specified position
     deleteAtBegining: Deletes the item at the begining
     deleteAtEnd: Deletes the item at the End
	 deleteAValue: Deletes the item that has the value data
	 display:  Output the list
	 << :      Output operator
-------------------------------------------------------------------------*/
#ifndef ARRAYBASEDLINKEDLIST
#define ARRAYBASEDLINKEDLIST

#include <iostream>
using namespace std;

typedef int ElementType;

const int CAPACITY = 20;
const int NULL_VALUE = -1; // a non-existent location
int Free = -5; // points to a free node
class ArrayBasedLinkedList
{
private:
/******* NodeType class *******/
    class NodeType
    {
    public:
    /******** Data Members ********/
        ElementType data;
        int next;
        /***** Class constructor *****/
        NodeType()
        {
           next = Free; // set all nodes to free at first
        }
        /*----------------------------------------------------------------------
		Construct a NodeType object.

		Precondition:  None
		Postcondition: Instantiates a new node with next equal to Free
		-----------------------------------------------------------------------*/

    }; //--- end of NodeType class

    /******** Data Members ********/
    int myFirst; // represents the array index fo the first node 
    int mySize; // represents the number of available elements in the DCList.
    NodeType myArray[CAPACITY]; // create a static array with size = capacity.

    /**** newNode ****/
    int newNode();
    /*----------------------------------------------------------------------
	  returns the index of the first free node in the array.

	  Precondition:  None
	  Postcondition: Returns the index of the first free space in the array.
	-----------------------------------------------------------------------*/

public:
    /******** Function Members ********/
	/***** Class constructor *****/
    ArrayBasedLinkedList();
    /*----------------------------------------------------------------------
	  Construct an ArrayBasedLinkedList object.

	  Precondition:  None
	  Postcondition: An empty ArrayBasedLinkedList object has been constructed;
        mySize is 0; myFirst is -1.
	-----------------------------------------------------------------------*/

    /***** empty operation *****/
    bool isEmpty() const;
	/*----------------------------------------------------------------------
	  Check if a list is empty.

	  Precondition:  None
	  Postcondition: true is returned if the list is empty, false if not.
	-----------------------------------------------------------------------*/

    /***** isFull operation *****/
    bool isFull() const;
	/*----------------------------------------------------------------------
	  Check if a list is full.

	  Precondition:  None
	  Postcondition: true is returned if the list is full, false if not.
	-----------------------------------------------------------------------*/

    /***** search operation *****/
    int search(const ElementType &data);
    /*----------------------------------------------------------------------
	  Check if an item is in the list.

	  Precondition:  The list is not empty.
	  Postcondition: The index of the element is returned if data is found,
      -1 if not. if the list is empty, the execution is interrupted.
	-----------------------------------------------------------------------*/

    /**** insertAtPosition ****/
    bool insertAtPosition(const ElementType &data, int pos);
    /*----------------------------------------------------------------------
	  Insert a value into the list at a given position.

	  Precondition:  data is the value to be inserted; the position satisfies
		  0 <= pos <= mySize.
	  Postcondition: true is returned if the data has been inserted into the
		  list at the position determined by posistion successfully (provided
		  that the position is a legal position), false if not. Error message
		  is diplayed if the position is illegal, and false is returned.
	-----------------------------------------------------------------------*/

    /**** insertAtBegining ****/
    bool insertAtBegining(const ElementType &data);
	/*----------------------------------------------------------------------
	  Insert a value at the begining of the list.

	  Precondition:  data is the value to be inserted. insertAtPosition is to
		  be invoked.
	  Postcondition: true is returned if data has been inserted at the
		  begining of the list successfully, false if not.
	-----------------------------------------------------------------------*/

    /**** insertAtEnd ****/
    bool insertAtEnd(const ElementType &data);
    /*----------------------------------------------------------------------
	  Insert a value at the end of the list.

	  Precondition:  data is the value to be inserted; insertAtPosition is to
		  be invoked.
	  Postcondition: true is returned if data has been inserted at the end
		  of the list successfully, false if not.
	-----------------------------------------------------------------------*/

    /**** deleteAtPosition ****/
    bool deleteAtPosition(int pos);
    /*----------------------------------------------------------------------
	  Remove a value from the list at a given position.

	  Precondition:  The list is not empty and the position satisfies
		  0 <= pos < mySize.
	  Postcondition: true is returned if the element at the position
		  determined by pos has been removed (provided pos is a legal
		  position), false if not. if the list is empty, the execution is
		  interrupted.
	----------------------------------------------------------------------*/

    /**** deleteAtBeining ****/
    bool deleteAtBegining();
    /*----------------------------------------------------------------------
	  Deletes the item at the begining.

	  Precondition:  The list is not empty.
	  Postcondition: Deletes the item at the begining. If the list is 
        empty, the execution is interrupted.
	----------------------------------------------------------------------*/

    /**** deleteAtEnd ****/
    bool deleteAtEnd();
    /*----------------------------------------------------------------------
	  Deletes the item at the End.

	  Precondition:  The list is not empty.
	  Postcondition: Deletes the item at the End. If the list is 
        empty, the execution is interrupted.
	----------------------------------------------------------------------*/

    /***** deleteAValue *****/
    bool deleteAValue(ElementType  data);
    /*----------------------------------------------------------------------
	   Deletes the item that has the value data.

	  Precondition:  The list is not empty; data is the value to be deleted.
	  Postcondition: returns true if the item was deleted from the list,
		  false if not. If data is not in the list, it returns false and
		  display an error message.
	-----------------------------------------------------------------------*/

    /***** output *****/
    void display(ostream &out) const;
    /*----------------------------------------------------------------------
	  Display a list.

	  Precondition:  The ostream out is open.
	  Postcondition: The list represented by this List object has been
		  inserted into out.
	-----------------------------------------------------------------------*/
};

//------ Prototype of output operator
ostream &operator<<(ostream &out, const ArrayBasedLinkedList &r);

#endif