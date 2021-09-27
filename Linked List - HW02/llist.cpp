//  Name: Matthew Jensen
//  Assignment number: 3/2 (for both 318 and 571)
//  Assignment: Linked List Implementation
//  File name: llist.cpp
//  Date last modified: September 21, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment. 


#include "llist.h"


LinkedList::Node::Node(const string& item) :
	data(item), next(nullptr), prev(nullptr) {}


//Iterator Constructor
LinkedList::Iterator::Iterator(LinkedList::Node* p) :
	ptr(p) {}


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
	//handle edge case where someone decrements prior to beginning
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
LinkedList::LinkedList() : head(new LinkedList::Node(std::string())), tail(new LinkedList::Node(std::string())), len(0)
{
	head->next = tail;
	tail->prev = head;
	len = 0;
}

//LinkedList Copy Constructor
LinkedList::LinkedList(const LinkedList& other) : head(new LinkedList::Node(std::string())), tail(new LinkedList::Node(std::string())), len(0)
{
	head->next = tail;
	tail->prev = head;

	LinkedList::Iterator copier = other.begin();
	LinkedList::Iterator iter = this->begin();

	while (copier.ptr) {
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
	LinkedList::Node* item_node = new LinkedList::Node(item);

	iter.ptr->prev->next = item_node;
	item_node->prev = iter.ptr->prev;
	item_node->next = iter.ptr;
	iter.ptr->prev = item_node;

	len++;
}

void LinkedList::remove(Iterator& iter) {

	// I think this would be better handled by simple preventing an iterator from incrementing to or past the beginning or end.
	if (this->begin() == this->end() || iter.ptr == (--begin()).ptr || iter.ptr == this->end().ptr) { //nothing should be removed from an empty list || The iterator should not be the head node || The iterator should not be the end node
		return;
	}

	iter.ptr->prev->next = iter.ptr->next;
	iter.ptr->next->prev = iter.ptr->prev;

	Iterator tmp = iter;
	iter.ptr = iter.ptr->prev;
	delete(tmp.ptr);

	len--;
}



LinkedList::Iterator LinkedList::find(const string& seek) const {
	//why can't I do this: test1.remove(test1.find("test"));
	LinkedList::Iterator iter = begin();
	while (iter.ptr->data != seek) {
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
	//Why can't I do this: return(!(this == &other));
	LinkedList::Iterator this_iter = this->begin();
	LinkedList::Iterator other_iter = other.begin();
	while (this_iter.ptr->next) {
		if (this_iter.ptr->data != other_iter.ptr->data) {
			return true;
		}
		this_iter++;
		other_iter++;
	}
	return false;
}