/*-- DCList.h --------------------------------------------------------------

  This header file defines the data type DCLIST for processing lists.
  Basic operations are:
	 Constructor
	 Copy Constructor
	 Assignment operator
	 Destructor
	 isEmpty: Check if list is empty
	 searchNode: returns the item if it is present in the list
	 search: returns true if the item is present in the list
	 insertAtPosition: Inserts an item at a specified position
	 insertAtEnd: Inserst an item at the end of the list
	 insertAtBegining: Inserts an item at the begining of the list
	 deleteAtPosition: Deletes an item at a specified position
	 deleteAValue: Deletes the item that has the value data
	 deleteBeforeAnElement: Deletes an item before the data was found
	 findAndDelete: Searches for an item and deletes all its occurences
	 removeFirst: Cuts the first node from the list and returns its data
	 removeLast: Cuts the last node from the list and returns its data
	 deleteDuplicates: Keeps only the first occurrence of an element in
		 the list and removes all the others.
	 display:  Output the list
	 << :      Output operator
-------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#ifndef DLIST
#define DLIST

typedef int ElementType;

class DCLIST
{
public:
	/******** Function Members ********/
	/***** Class constructor *****/
	DCLIST();
	/*----------------------------------------------------------------------
	  Construct a DCLIST object.

	  Precondition:  None
	  Postcondition: An empty DCLIST object has been constructed; mySize is 0;
		myFirst is NULL.
	-----------------------------------------------------------------------*/

	/***** Copy constructor *****/
	DCLIST(DCLIST &origList);
	/*----------------------------------------------------------------------
	  Construct a copy of a DCLIST object.

	  Precondition:  A copy of origList is needed; origList is a const
		  reference parameter.
	  Postcondition: A copy of origList has been constructed.
   -----------------------------------------------------------------------*/

	/***** Assignment operator *****/
	const DCLIST &operator=(const DCLIST &rightHandSide);
	/*----------------------------------------------------------------------
	  Assign a copy of a DCLIST object to the current object.

	  Precondition: none
	  Postcondition: A copy of rightHandSide has been assigned to this
		  object. A const reference to this DCLIST is returned.
   -----------------------------------------------------------------------*/

	/***** Class destructor *****/
	~DCLIST();
	/*----------------------------------------------------------------------
	  Destroys a DCLIST object.

	  Precondition:  The life of a DCLIST object is over.
	  Postcondition: The memory allocated by the constructor for the DCLIST
		  object has been returned to the heap.
   -----------------------------------------------------------------------*/

	/***** empty operation *****/
	bool isEmpty() const;
	/*----------------------------------------------------------------------
	  Check if a list is empty.

	  Precondition:  None
	  Postcondition: true is returned if the list is empty, false if not.
	-----------------------------------------------------------------------*/

	/***** search operation *****/
	bool search(ElementType data) const;
	/*----------------------------------------------------------------------
	  Check if an item is in the list.

	  Precondition:  The list is not empty.
	  Postcondition: true is returned if data is found, false if not. if the
		  list is empty, the execution is interrupted.
	-----------------------------------------------------------------------*/

	/**** insertAtPosition ****/
	bool insertAtPosition(ElementType data, int position);
	/*----------------------------------------------------------------------
	  Insert a value into the list at a given position.

	  Precondition:  data is the value to be inserted; the position satisfies
		  0 <= pos <= mySize.
	  Postcondition: true is returned if the data has been inserted into the
		  list at the position determined by posistion successfully (provided
		  that the position is a legal position), false if not. Error message
		  is diplayed if the position is illegal, and false is returned.
	-----------------------------------------------------------------------*/

	/**** insertAtEnd ****/
	bool insertAtEnd(ElementType data);
	/*----------------------------------------------------------------------
	  Insert a value at the end of the list.

	  Precondition:  data is the value to be inserted; insertAtPosition is to
		  be invoked.
	  Postcondition: true is returned if data has been inserted at the end
		  of the list successfully, false if not.
	-----------------------------------------------------------------------*/

	/**** insertAtBegining ****/
	bool insertAtBegining(ElementType data);
	/*----------------------------------------------------------------------
	  Insert a value at the begining of the list.

	  Precondition:  data is the value to be inserted. insertAtPosition is to
		  be invoked.
	  Postcondition: true is returned if data has been inserted at the
		  begining of the list successfully, false if not.
	-----------------------------------------------------------------------*/

	/**** deleteAtPosition ****/
	bool deleteAtPosition(int position);
	/*----------------------------------------------------------------------
	  Remove a value from the list at a given position.

	  Precondition:  The list is not empty and the position satisfies
		  0 <= pos < mySize.
	  Postcondition: true is returned if the element at the position
		  determined by pos has been removed (provided pos is a legal
		  position), false if not. if the list is empty, the execution is
		  interrupted.
	----------------------------------------------------------------------*/

	/**** deleteBeforeAnElement ****/
	bool deleteBeforeAnElement(ElementType data);
	/*----------------------------------------------------------------------
	  searches for data in the list. If data is found, then it should delete
	  the element before the element where data was found.

	  Precondition:  The list is not empty and data is found in the list.
	  Postcondition: true is returned if the element before the element where
		  data was found is deleted. if the list is empty, the
		  execution is interrupted; If data is not found or no other node is in
		  the list, false is returned and an error message is displayed.
	----------------------------------------------------------------------*/

	/**** findAndDelete ****/
	int findAndDelete(ElementType data);
	/*----------------------------------------------------------------------
	  Searches for an item and deletes all its occurences from the list.

	  Precondition:  The list is not empty; the item must be present in the
		  list.
	  Postcondition: returns the number of deleted elements. if the list is
		  empty, the execution is interrupted; if the item is not present,
		  -1 is returned.
	----------------------------------------------------------------------*/

	/**** removeFirst ****/
	ElementType removeFirst();
	/*----------------------------------------------------------------------
	  Cuts the first node from the list and returns its data.

	  Precondition:  The list is not empty.
	  Postcondition: Cuts the first node from the list and returns its data.
		  if the list is empty, the execution is interrupted.
	----------------------------------------------------------------------*/

	/**** removeLast ****/
	ElementType removeLast();
	/*----------------------------------------------------------------------
	  Cuts the last node from the list and returns its data.

	  Precondition:  The list is not empty.
	  Postcondition: Cuts the last node from the list and returns its data.
		  if the list is empty, the execution is interrupted.
	----------------------------------------------------------------------*/

	/**** deleteDuplicates ****/
	int deleteDuplicates();
	/*----------------------------------------------------------------------
	  Keeps only the first occurrence of an element in the list and removes
	  all the others.

	  Precondition:  The list is not empty.
	  Postcondition: returns the number of deleted elements. if the list is
		  empty, the execution is interrupted;
	----------------------------------------------------------------------*/

	/***** output *****/
	void display(ostream &out) const;
	/*----------------------------------------------------------------------
	  Display a list.

	  Precondition:  The ostream out is open.
	  Postcondition: The list represented by this List object has been
		  inserted into out.
	-----------------------------------------------------------------------*/

private:
	/******* DoublyNode class *******/
	class DoublyNode
	{
	public:
		/******** Data Members ********/
		ElementType data;
		DoublyNode *predecessor; // pointer to the previous node
		DoublyNode *successor; // pointer to the next node

		/***** Class constructor *****/
		DoublyNode(ElementType n);
		/*----------------------------------------------------------------------
		Construct a Node object.

		Precondition:  None
		Postcondition: Instantiates a new node with n, the parameter, as data
			and the two pointer equal to NULL
		-----------------------------------------------------------------------*/
	}; //--- end of DoublyNode class

	typedef DoublyNode *Nodeptr;

	/******** Data Members ********/
	int mySize; // represents the number of available elements in the DCList.
	Nodeptr myFirst; // pointer to the first node of the list.

	/******** Private Function Members ********/
	/***** searchNode operation *****/
	Nodeptr searchNode(ElementType data) const;
	/*----------------------------------------------------------------------
	  Check if an item is in the list.

	  Precondition:  The list is not empty;
	  Postcondition: returns the a pointer to the item if it is present in
		  the list, NULL otherwise.
	-----------------------------------------------------------------------*/

	/***** deleteAValue *****/
	bool deleteAValue(ElementType data);
	/*----------------------------------------------------------------------
	   Deletes the item that has the value data.

	  Precondition:  The list is not empty; data is the value to be deleted.
	  Postcondition: returns true if the item was deleted from the list,
		  false if not. If data is not in the list, it returns false and
		  display an error message.
	-----------------------------------------------------------------------*/

}; //--- end of DCLIST class

//------ Prototype of output operator
ostream &operator<<(const ostream &out, const DCLIST &rightHandSide);

#endif
