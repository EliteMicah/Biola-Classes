#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;


template <class T>
struct ListNode {
	T data; //the data
	ListNode<T>* next; //the pointer to (address of) the next node
};

template <class T>
class LinkedList {
public:

	LinkedList() {
		head = nullptr; //head points to null
		lsize = 0;
	}

	void insert_at(int k, T x);
	void remove_at(int k);
	bool isSorted() const;
	void print() const;

	//destructor
	~LinkedList();

private:
	ListNode<T>* head; //pointer to the first element
	int lsize; //the number of elements in the list
};

template <class T>
void LinkedList<T>::print() const {
	cout << "{";
	ListNode<T>* walker = head; //create a pointer that will "walk" to the end of the list

		while (walker != nullptr) { //walker is not the last element
			cout << walker->data << ", "; //print the data field of the current	node
				walker = walker->next; //move to the next node
		}

	cout << "}";
}
//destructor
template <class T>
LinkedList<T>::~LinkedList() {
	ListNode<T>* walker = head;
	while (walker != nullptr) {
		ListNode<T>* temp = walker;
		walker = walker->next;
		delete temp;
	}
}

template <class T>
void LinkedList<T>::insert_at(int k, T x) {

	int count = 0;

	//create a new node
	ListNode<T>* newnode = new ListNode<T>;  //allocate memory
	ListNode<T>* temp = new ListNode<T>;
	ListNode<T>* walker = head;

	newnode->data = x; //set the data field of the new node to x

	if (k == 0) {

		newnode->next = head; //the next field is the address of the first element
		head = newnode; //newnode is the head of the list
		return;
	}

	while (walker != nullptr) { //until reaches the end
		if (count + 1 == k) { //index k found
			temp = walker->next;
			walker->next = newnode;
			newnode->next = temp;
			return;
		}
		walker = walker->next;
		count++;
	}
}

template <class T>
void LinkedList<T>::remove_at(int k) {

	int count = 0;

	ListNode<T>* walker = head;

	if (walker == nullptr) { // List is empty
		cout << "List is empty" << endl;
		return;
	}

	if (k == 0) { //remove the first element
		head = head->next; //head point to the second node
		delete walker; //deallocate the memory for the first node
		return;
	}

	//position the walker to the node before the node to be removed
	while (walker->next != nullptr) { //until reaches the end
		if (count + 1 == k) { // k found
			ListNode<T>* temp = walker->next; //pointer to the node to be deleted
			walker->next = temp->next; //the next pointer of walker bypasses temp;
			delete temp; //deallocate the memory of temp
			return;
		}
		count++; // Increase count to move on
		walker = walker->next;  //move to the next node
	}
	cout << "Walker = null" << endl;
	return;
}

template <class T>
bool LinkedList<T>::isSorted() const {

	//create a new node
	ListNode<T>* walker = head;

	if (walker == nullptr) { // List is empty
		cout << "List is empty" << endl;
		return false;
	}

	//a pointer that is going to visit all nodes. start at the head
	while (walker->next != nullptr) { //until reaches the end
		if (walker->data >= walker->next->data) // If "current" is greater than "next"
			return false;
		walker = walker->next;  //move to the next node
	}

	return true;
}

#endif
