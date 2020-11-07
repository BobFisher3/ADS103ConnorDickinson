#pragma once
#include <iostream>

using namespace std;

//Class for the Linked List
class list
{
public:
	struct node {
		int data;
		struct node* next;
	} *head;

	//Constructor
	list() :head(NULL) {}

	//Destructor
	~list() {
		node* current, * temp;
		current = head;
		temp = head;
		while (current != NULL) {
			current = current->next;
			delete temp;
			temp = current;
		}
	}

	// Adding to the end of list  
	void insertAtEnd(int n) {
		node* newNode = new node;
		newNode->data = n;
		newNode->next = NULL;

		//If list is empty, add a head node
		if (head == NULL) {
			head = newNode;
			return;
		}

		//Create temp node 'cur' and set to head
		node* cur = head;
		while (cur) {
			//Check to see if there is a node after current
			if (cur->next == NULL) {
				//If there is no node, create one at the end
				cur->next = newNode;
				return;
			}
			//If there is a node, loop through until there isn't one
			cur = cur->next;
		}
	}

	//Add to beginning
	void insertAtBeginning(int n) {
		node* newNode = new node;
		newNode->data = n;
		newNode->next = NULL;

		//If the list is empty, add a new node
		if (head == NULL) {
			head = newNode;
			return;
		}
		//If head exists, move head to next node and insert new node as the head
		else {
			newNode->next = head;
			head = newNode;
		}

	}

	//Delete from beginning
	void deleteFromBeginning() {
		if (head != NULL) {
			node* temp = head->next;
			delete head;
			head = temp;
		}
		if (head == NULL) {
			return;
		}
	}

	void deleteFromEnd() {
		node* temp;
		if (head == NULL)
		{
			cout << " There is no item to delete!" << endl;
			return;
		}
		node* start = head;
		if (start->next != NULL)
		{
			while ((start->next)->next != NULL)
			{
				start = start->next;
			}
			temp = start->next;
			start->next = NULL;
		}
		else
		{
			temp = start;
			head = NULL;
		}
		delete temp;
	}

	//Display List
	void displayList() {
		if (head != NULL) {
			for (node* temp = head; temp != NULL; temp = temp->next) {
				cout << temp->data << " ";
			}
			cout << endl;
		}
	}

};
