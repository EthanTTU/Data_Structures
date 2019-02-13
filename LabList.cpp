#include "LabList.h"
#include <iostream>
//all of the next shit is based off of the head
using namespace std;

List::List(){
	head = NULL;
	current = NULL;
	tail = NULL;
}

void List::setNode(int datum){
	node* point = new node; // Create a new node with it's location assigned to node pointer point
	point->next = NULL; // Make the next pointer point to NULL
	point->datum = datum; // Insert the datum at the memory location.
	
	if (head != NULL){
		current = head; // If the head isn't Null, current pointer will point to the front of the list, to create a starting point
		while (current->next != NULL){ // Until we reach the end of the list, iterate the current pointer along the list
			current = current->next;
		}
		current->next = point; // set the end node location equal to the data stored at point
	}
	else
		head = point; // Or set point location as the head, to create the start of the list.
		
	//this->size++;
}

void List::remNode(int index){
	current = head;
	if (index == 0){
		current = head; // Creates a temporary value that also points to head
		temp = current->next; // Creates a temporary value for the pointer to the second node
		head = temp; // Sets the head to point to the new first node.  This can all be broken down into two lines of code, not three
	}
	else{
		for(int i = 0; i < index-1 ; i++)
		current = current->next; // Cycle along the list until we hit the index given
		temp = current->next; // Have a temporary pointer point to the node that is after the node current is pointing to
		current->next = temp->next; // This sets the current node pointer to the pointer to the node after. Essentially this goes around the node at index, removing it from the list
	}
	//this->size--;
}

/*void List::insert(int index, int data){
	if (index == 0){
		
		node* point = head;
		//for (int i = 0; i < size; i++){
		//}
		head->datum = data;
	}
	
}*/

void List::printList(){	
	current = head;
	cout << "{ ";
	while (current != NULL){
		if (current->next != NULL)
			{
			cout << current->datum << ", ";
			current = current->next;
			}
		else 
		{
			cout << current->datum;
			current = current->next;
		}
	}
	cout << " }" << endl;
}


