#include "D_List.h"
#include <iostream>
#include <string>
using namespace std;

void Node::List(){
	head = NULL;
	current = NULL;
	tail = NULL;
	prev = NULL;
	next = NULL;
}

void Node::addNode(int datum){
	Node* newnode = new Node; // Create a new node with it's location assigned to node pointer newnode
	newnode->next = NULL; // Make the next pointer point to NULL
	newnode->datum = datum; // Insert the datum at the memory location.
	
	if (head != NULL){
		current = head; // If the head isn't Null, current pointer will point to the front of the list, to create a starting point
		while (current->next != NULL){ // Until we reach the end of the list, which is when the next pointer points to NULL, iterate the current pointer along the list
			current = current->next;
		}
		current->next = newnode; // set the end node location equal to the data stored at point
		tail = newnode; // Set the tail equal to the new node since it adds to the end of the list
		tail->prev = current; // Create the previous pointer equal to the node before our added node, creating the backwards previous pointer. Essential to the doubly linked list
		tail->next = NULL; // Make the final node point to NULL always, helps in finding the end of the list without using a size function.
	}
	else{
		head = newnode; // Or set point location as the head, to create the start of the list.
		tail = newnode; // tail and head is equal to newnode as there is only one node so far.
		head->prev = NULL; // create null on either side of the list
	}
	this->size++;
}

void Node::remNode(int index){ // Function to remove node
	if(index <= 0 || index > size){
		throw "Index out of bounds error.";
	}
	current = head; // Set current pointer to address of the head
	Node* temp;
	if (index == 1){ // test case 1 of 3 (If the index to be removed is the head of the list)
		head = current->next;
		head->prev = NULL;
	}
	else if (index == size){ // test case 2 of 3 (if the index to be removed is the tail of the list)
		tail=tail->prev;
		tail->next = NULL;
	}
	else{// test case 3 of 3 (if the index is anywhere between the head and tail)
		for (int i = 1; i < index-1; i++){
			current = current->next; // Iterate along until the node before the node we want to remove
			temp = current->next; // set a temporary pointer to the node we want to remove
			current->next = temp->next; // set the current pointer, that points to the next node in the list, equal to the location of the node after the one we want to remove
			// Thereby severing it from the list
			temp->next->prev = current; // Set the node after the one we want to remove pointing to the node before the one we want to remove, severing the previous pointer as well
			
		}
	}
	
	this->size--;
}

void Node::print_list(){	
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
	cout << " }\n{ ";
	current = tail;
	while (current != NULL){
		if (current->prev != NULL)
			{
			cout << current->datum << ", ";
			current = current->prev;
			}
		else 
		{
			cout << current->datum;
			current = current->prev;
		}
	}
	cout << " }" << endl;
}

int Node::sizelist(){
	return this->size;
}