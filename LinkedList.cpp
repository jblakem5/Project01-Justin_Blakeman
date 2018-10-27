//Creator:	Justin Blakeman - Oct 26, 2018
//Class:	COSC 2030 - Data Structures
//Name:		"Project01" - "Blood Sugar Project"

//This Code Implements the Functions form the LinkedList.h class

#include "pch.h"
#include "LinkedList.h"
#include <list>
#include <string>

#include <utility>


//A LList Constructor
List::List()
	: first_(NULL), last_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}

//A LList Deconstructor
List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}

//Not Implemented in this program. Although could be useful for other purposes.
bool List::operator==(const List &rhs) {
	return true;
}

//Checks to see if a LList is empty
bool List::empty() const
{
	return first_ == NULL;
}

//Very VERY similar to getCount below, however see if you can spot the difference, getCount handles empty lists alot better.
int List::getSize(const List) {
	int count = 0;
	if (!empty()) {
		Node * ptr = first_;
		while (ptr != NULL)
		{
			count++;
			ptr = ptr->next_;
		}
	}
	return count;
}


void List::insertAsLast(float x)
{
	Node * ptr = first_;
	while (ptr->next_ != NULL) {
		ptr = ptr->next_;
	}

	ptr->next_ = new Node(x);
}

void List::insertAsFirst(float x)
{
	first_ = new Node(x, first_);
}

//Should we ever choose to, we can remove an entry --- ***This is not implemented in the final solution of this program***
float List::removeFirst()
{
	float item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}

//A function that simply iterates through a linked list of a day and prints out the values stored at each node
void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;		//Move pointer to next node
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;	//Print the value being pointed at
			ptr = ptr->next_;			//Move pointer to next value
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each float in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}

//Overload the << operator to accept outputing Lists
ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}


//Calculates the sum of any given day, since days are linked lists, it iterates through them
float List::sum(List day) {
	float sum = 0.0;
	if (!empty()) {
		Node * ptr = first_;
		while (ptr != NULL)
		{
			sum = sum + ptr->entry_;
			ptr = ptr->next_;
		}
	}
	return sum;
}

//Finds the Max in a given day, since days are linked lists, it iterates through them
float List::max(List day) {
	if (!empty()) {
		Node * ptr = first_;
		float max = ptr->entry_;
		while (ptr != NULL)
		{
			if (ptr->entry_ > max) {
				max = ptr->entry_;
			}
			ptr = ptr->next_;
		}
		return max;		//returns the max float found in a non empty List
	}
	else {
		return 0.0; //returns an "impossible value" that can be easily recognized if returned (occurs when list is empty)
	}
}

//Finds the Min in a given day, since days are linked lists, it iterates through them
float List::min(List day) {
	if (!empty()) {
		Node * ptr = first_;
		float min = ptr->entry_;
		while (ptr != NULL)
		{
			if (ptr->entry_ < min) {
				min = ptr->entry_;
			}
			ptr = ptr->next_;
		}
		return min;		//returns the max float found in a non empty List
	}
	else {
		return 0.0; //returns an "impossible value" that can be easily recognized if returned (occurs when list is empty) WHY DOESNT -FLOAT WORK HERE BUT 0.0 DOES?????
	}
}

//This keeps a count of how many values/entries are in a linked list, or in a day.
int List::count(List day) {
	int count = 0;
	if (!empty()) {
		Node * ptr = first_;
		count++;
		while (ptr != NULL) {
			ptr = ptr->next_;
			count++;
		}
	}
	return count;
}