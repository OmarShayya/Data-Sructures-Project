/*-------------------------------------------------------------------------
   This program is for testing the class DCLIST. It implements a
   well-designed CLI menu which allows the user to manipulate the DCLIST.
-------------------------------------------------------------------------*/
#include "DCLIST.cpp"

void menu(); // prototype of the function menu()

int main()
{
	ElementType x;	   // for storing data
	DCLIST myTestList; // creating an empty DCLIST
	int choice = 0;
	int value, // value that the user input to add/delete to/from the list.
		pos,   // position that the user input to add/delete a value.
		num;   // number of deleted elements

	cout << "Welcome to Doubly-Circular Linked List Test program."
		 << "\nAn Empty DCList of integers has been created for you." << endl;

	while (choice != 11) // keep displaying the menu until the user exits
	{
		menu();		   // display the menu
		cin >> choice; // input choice from the user

		switch (choice)
		{
		/*input an int value from the user, insert the element at beginning of the
		myTestList and displays the updated list.*/
		case 1: // tests insertAtBegining function
			cout << "Enter an element to insert at the begining of your list:" << endl;
			cin >> value;
			myTestList.insertAtBegining(value);
			cout << myTestList;
			break;

		/*input an int value from the user, insert the element at end of the myTestList
		and displays the updated list.*/
		case 2: // tests insertAtEnd function
			cout << "Enter an element to insert at the end of your list:" << endl;
			cin >> value;
			myTestList.insertAtEnd(value);
			cout << myTestList;
			break;

		/*input an int value from the user, and a position value (any value >= 1) and
		checks if the insertion of the element at the specified position of myTestList is successful and
		displays the updated list.*/
		case 3: // tests insertAtPosition function
			cout << "Enter an element to insert:" << endl;
			cin >> value;
			cout << "Enter the position you want to insert the element at (any value >= 1):" << endl;
			cin >> pos;
			myTestList.insertAtPosition(value, (pos - 1));
			cout << myTestList;
			break;

		/*input a position value from the user and checks if the element was successfully
		removed from myTestList and displays the updated list.*/
		case 4: // tests deleteAtPosition function
			cout << "Enter the position you want to delete the element at:" << endl;
			cin >> pos;
			if (myTestList.deleteAtPosition(pos - 1))
				cout << myTestList;
			break;

		/*input an int value from the user and checks if the element is found in the
		myTestList. If the element is found it will delete the element before the found element and
		display the updated list.*/
		case 5: // tests deleteBeforeAnElement function
			cout << "Enter an element to delete before it:" << endl;
			cin >> value;
			if (myTestList.deleteBeforeAnElement(value))
				cout << myTestList;
			break;

		/*input an int value from the user and displays whether this value exists
		 in the list or not.*/
		case 6: // tests search function
			cout << "Enter an element to search if it's present in the list:" << endl;
			cin >> value;
			if (myTestList.search(value))
				cout << value << " is found in the list" << endl;
			else
				cout << value << " is not in the list" << endl;
			break;

		/*input an int value from the user, delete the element located in myTestList if it
		was found and display the updated list.*/
		case 7: // tests findAndDelete function
			cout << "Enter an element to delete all of its occureneces present in the list:" << endl;
			cin >> value;
			num = myTestList.findAndDelete(value);
			cout << num << " occureneces were deleted" << endl;
			cout << myTestList;
			break;

		/*remove the first element of myTestList and display the value of the element.*/
		case 8: // tests removeFirst function
			x = myTestList.removeFirst();
			cout << x << " was removed" << endl;
			break;

		/*remove the last element of myTestList and display the value of the element*/
		case 9: // tests removeLast function
			x = myTestList.removeLast();
			cout << x << " was removed" << endl;
			break;

		/*erase all the duplicated elements in myTestList leaving only the first
		occurrence of each element and display the number of deleted elements and
		the updated list.*/
		case 10: // tests deleteDuplicates function
			num = myTestList.deleteDuplicates();
			cout << num << " elements were deleted." << endl;
			cout << myTestList;
			break;

		case 11: // displays a thank you massage and exits the program
			cout << "Thank you for using DCLIST tester program" << endl;
			break;

		default: // displays invalid input if a number < 1 or number > 11 is entered
			cout << "Invalid input." << endl;
			break;
		}
	}

	return 0;
}

void menu() // void function menu that displays the menu each time its invoked
{
	cout << "Please choose one of the following options: " << endl;
	cout << "1- Insert at beginning"
		 << "\n2- Insert at end"
		 << "\n3- Insert at position"
		 << "\n4- Delete at position"
		 << "\n5- Delete before an element"
		 << "\n6- Search element"
		 << "\n7- Find and delete"
		 << "\n8- Remove first element"
		 << "\n9- Remove last element"
		 << "\n10- Delete duplicated elements"
		 << "\n11- Exit" << endl;
}
