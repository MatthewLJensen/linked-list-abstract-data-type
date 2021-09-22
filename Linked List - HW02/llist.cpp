//  Name: Matthew Jensen
//  Assignment number: 3/2 (for both 318 and 571)
//  Assignment: Linked List Implementation
//  File name: llist.cpp
//  Date last modified: September 21, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment. 

#include "llist.h"


LinkedList::Node::Node(const string& item) :
	data(item), prev(nullptr), next(nullptr){}


//Iterator Constructor
LinkedList::Iterator::Iterator(LinkedList::Node* p) :
	ptr(p){}


//Iterator Operators
string& LinkedList::Iterator::operator*() {
	return ptr->data;
}

//Preincrement
LinkedList::Iterator& LinkedList::Iterator::operator++() {
	this->ptr = this->ptr->next;
	return *this;
}

//Postincrement
LinkedList::Iterator LinkedList::Iterator::operator++(int) {
	LinkedList::Iterator tmp(*this);
	++(*this);
	return tmp;
}

//Predecrement
LinkedList::Iterator& LinkedList::Iterator::operator--() {
	this->ptr = this->ptr->prev;
	return *this;
}

//Postdecrement
LinkedList::Iterator LinkedList::Iterator::operator--(int) {
	LinkedList::Iterator tmp(*this);
	--(*this);
	return tmp;
}

bool LinkedList::Iterator::operator==(const Iterator& other) {
	return (this->ptr == other.ptr);
}

bool LinkedList::Iterator::operator!=(const Iterator& other) {
	return !(this == &other);
}

//LinkedList Constructor
LinkedList::LinkedList() : head(new LinkedList::Node(std::string())), tail(new LinkedList::Node(std::string())), len(0)
{
	head->next = tail;
	tail->prev = head;
}

//LinkedList Copy Constructor
LinkedList::LinkedList(const LinkedList& other) : head(new LinkedList::Node(std::string())), tail(new LinkedList::Node(std::string())), len(0)
{

}

//LinkedList Destructor
LinkedList::~LinkedList() {

}

//LinkedList Methods
LinkedList::Iterator LinkedList::begin() const {
	return LinkedList::Iterator(this->head->next);
}

LinkedList::Iterator LinkedList::end() const {
	return LinkedList::Iterator(this->tail);
}

void LinkedList::insert(const Iterator& iter, const string& item) {
	LinkedList::Node* item_node = new LinkedList::Node(item);
	
	iter.ptr->prev->next = item_node;
	item_node->prev = iter.ptr->prev;
	item_node->next = iter.ptr;
	iter.ptr->prev = item_node;
	
	len++;
}

void LinkedList::remove(Iterator& iter) {

}

LinkedList::Iterator LinkedList::find(const string& seek) const {

}

int LinkedList::length() const {

}

void LinkedList::clear() {

}

bool LinkedList::operator==(const LinkedList& other) const {

}

bool LinkedList::operator!=(const LinkedList& other) const {

}