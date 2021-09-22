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
LinkedList::Iterator::Iterator(Node* p) :
	ptr(p){}


//Iterator Operators
string& LinkedList::Iterator::operator*() {
	return ptr->data;
}

LinkedList::Iterator& LinkedList::Iterator::operator++() {

}

LinkedList::Iterator LinkedList::Iterator::operator++(int) {

}

LinkedList::Iterator& LinkedList::Iterator::operator--() {

}

LinkedList::Iterator LinkedList::Iterator::operator--(int) {

}

bool LinkedList::Iterator::operator==(const Iterator& other) {

}

bool LinkedList::Iterator::operator!=(const Iterator& other) {

}

//LinkedList Constructor
LinkedList::LinkedList() : head(new Node(std::string())), tail(new Node(std::string())), len(0)
{
	head->next = tail;
	tail->prev = head;
}

//LinkedList Copy Constructor
LinkedList::LinkedList(const LinkedList& other)
{

}

//LinkedList Destructor
LinkedList::~LinkedList() {

}

//LinkedList Methods
LinkedList::Iterator LinkedList::begin() const {

}

LinkedList::Iterator LinkedList::end() const {

}

void LinkedList::insert(const Iterator& iter, const string& item) {

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