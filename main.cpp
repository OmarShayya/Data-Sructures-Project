/*-------------------------------------------------------------------------
   This program is for testing the class ArrayBasedLinkedList
-------------------------------------------------------------------------*/
#include "ArrayBasedLinkedList.cpp"

int main(){
    ArrayBasedLinkedList list1;
   
    cout << list1 <<endl;
    list1.insertAtPosition(2,0);
    cout << list1;
    list1.insertAtPosition(8,1);
    cout << list1;
    list1.insertAtPosition(7,2);
    cout << list1;
    list1.deleteAtPosition(2);
    cout << list1;
    list1.insertAtBegining(1);
    list1.insertAtEnd(20);
    cout << list1;
    list1.deleteAtBegining();
    list1.deleteAtEnd();
    cout << list1;
    list1.deleteAValue(8);
    cout << list1;
    
}