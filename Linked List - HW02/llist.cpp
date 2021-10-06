//  Name: Matthew Jensen, Hayden Rigsby
//  Assignment number: 3
//  Assignment: Linked List Implementation
//  File name: llist.cpp
//  Date last modified: September 29, 2021
//  Honor statement: We have neither given nor received any unauthorized help on this assignment. 


#include "llist.h"


LinkedList::Node::Node(const string& item) :
	data(item), next(nullptr), prev(nullptr) {}


//Iterator Constructor
LinkedList::Iterator::Iterator(LinkedList::Node* p) : ptr(p) {}


//Iterator Operators
string& LinkedList::Iterator::operator*() {
	return ptr->data;
}

//Preincrement
LinkedList::Iterator& LinkedList::Iterator::operator++() {
	//handle edge case where someone increments past end
	this->ptr = this->ptr->next;
	return *this;
}

//Postincrement
LinkedList::Iterator LinkedList::Iterator::operator++(int) {
	//handle edge case where someone increments past end
	LinkedList::Iterator tmp(*this);
	++(*this);
	return tmp;
}

//Predecrement
LinkedList::Iterator& LinkedList::Iterator::operator--() {
	
	if (this->ptr )

	this->ptr = this->ptr->prev;
	return *this;
}

//Postdecrement
LinkedList::Iterator LinkedList::Iterator::operator--(int) {
	//handle edge case where someone decrements prior to beginning
	LinkedList::Iterator tmp(*this);
	--(*this);
	return tmp;
}

bool LinkedList::Iterator::operator==(const Iterator& other) {
	return (this->ptr == other.ptr);
}

bool LinkedList::Iterator::operator!=(const Iterator& other) {
	return (this->ptr != other.ptr);
}

//LinkedList Constructor
LinkedList::LinkedList() : head(new LinkedList::Node(std::string("*HEAD*"))), tail(new LinkedList::Node(std::string("*TAIL*"))), len(0)
{
	head->next = tail;
	tail->prev = head;
	len = 0;
}

//LinkedList Copy Constructor
LinkedList::LinkedList(const LinkedList& other) : head(new LinkedList::Node(std::string("*HEAD*"))), tail(new LinkedList::Node(std::string("*TAIL*"))), len(0)
{
	head->next = tail;
	tail->prev = head;

	LinkedList::Iterator copier = other.begin();
	LinkedList::Iterator iter = this->begin();

	while (copier.ptr->next) {
		this->insert(iter, copier.ptr->data);
		copier++;

	}

	len = other.len;
}

//LinkedList Destructor
LinkedList::~LinkedList() {
	LinkedList::Iterator iter = this->begin();
	while (iter.ptr->next) { //this stops when it gets to the tail node
		LinkedList::Iterator tmp_iter = iter.ptr->next;
		delete(iter.ptr);
		iter = tmp_iter;
	}

	delete(this->head);
	delete(this->tail);
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
	if (*this == other) {
		return *this;
	}

	this->clear();
	this->head->next = this->tail;
	this->tail->prev = this->head;

	LinkedList::Iterator copier = other.begin();
	LinkedList::Iterator iter = this->begin();

	while (copier.ptr) {
		this->insert(iter, copier.ptr->data);
		copier++;
	}

	len = other.len;

	return *this;

}

//LinkedList Methods
LinkedList::Iterator LinkedList::begin() const {
	return LinkedList::Iterator(this->head->next);
}

LinkedList::Iterator LinkedList::end() const {
	return LinkedList::Iterator(this->tail);
}

void LinkedList::insert(const Iterator& iter, const string& item) {

	if (iter.ptr == (--begin()).ptr || iter.ptr == (++end()).ptr) { //nothing should be added prior to the beginning | nothing should be inserted after the end sentinal node
		return;
	}


	LinkedList::Node* item_node = new LinkedList::Node(item);

	iter.ptr->prev->next = item_node;
	item_node->prev = iter.ptr->prev;
	item_node->next = iter.ptr;
	iter.ptr->prev = item_node;

	this->len++;
}

void LinkedList::remove(Iterator& iter) {

	if (this->begin() == this->end() || iter.ptr == (--begin()).ptr || iter.ptr == this->end().ptr) { //nothing should be removed from an empty list | The iterator should not be the head node | The iterator should not be the end node
		return;
	}

	iter.ptr->prev->next = iter.ptr->next;
	iter.ptr->next->prev = iter.ptr->prev;

	Iterator tmp = iter;
	iter.ptr = iter.ptr->next;
	delete(tmp.ptr);

	len--;
}



LinkedList::Iterator LinkedList::find(const string& seek) const {
	LinkedList::Iterator iter = begin();
	while (iter.ptr->data != seek && iter.ptr->next) {
		iter++;
	}
	return iter;
}


int LinkedList::length() const {
	return len;
}

void LinkedList::clear() {

	LinkedList::Iterator iter = this->begin();
	while (iter.ptr->next) { //this stops when it gets to the tail node
		LinkedList::Iterator tmp_iter = iter.ptr->next;
		delete(iter.ptr);
		iter = tmp_iter;
	}

	head->next = tail;
	tail->prev = head;
	len = 0;

}

bool LinkedList::operator==(const LinkedList& other) const {
	if (this->length() != other.length()) {
		return false;
	}

	LinkedList::Iterator this_iter = this->begin();
	LinkedList::Iterator other_iter = other.begin();
	while (this_iter.ptr->next) {
		if (this_iter.ptr->data != other_iter.ptr->data) {
			return false;
		}
		this_iter++;
		other_iter++;
	}
	return true;
}

bool LinkedList::operator!=(const LinkedList& other) const {
	return !(*this == other);
}