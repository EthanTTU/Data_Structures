#pragma once


class List{
private:
	//int size = 0;
	struct node{
		int datum; // Integer data
		node* next; // Pointer of type node pointer
	}; 
	node* head; // Pointers of type node for going through our linked list
	node* current;
	node* temp;
public:
	List(); // Prototype just to create the list to be acted upon
	void setNode(int); // Class function to set a node
	void remNode(int); // Class function to remove a node
	void printList(); // Class function to print the linked list
	//void insert(int, int); //Unused function I toyed with before not making it in time for submission, not needed
};
	