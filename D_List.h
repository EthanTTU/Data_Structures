#pragma once

class Node{
	int size = 0, datum;
	Node* head;
	Node* prev;
	Node* next;
	Node* current;
	Node* tail;
public:
	void List();
	void addNode(int);
	void remNode(int);
	//void (int);
	int sizelist();
	void print_list();
};