#pragma once
//ORIGINAL CREATOR: tom bailey   0740  5 oct 2010

//Creator:	Justin Blakeman - Oct 26, 2018
//Class:	COSC 2030 - Data Structures
//Name:		"Project01" - "Blood Sugar Project"

//This Code Defines the LinkedList Class


#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>
#include <string>
using std::ostream;

#include "Node.h"

#define ulong unsigned long


class List
{
public:
	//*** Standard functions ***

	float sum(List day);

	float max(List day);

	//List maxList(List day);

	float min(List day);

	int count(List day);


	// Default constructor
	// post: this List is empty.
	List();

	// Copy constructor
	// post: this List now stores a copy of the sequence stored
	//         in other
	List(const List & other);

	// Destructor
	// post: all the Nodes of this List have been destroyed.
	~List();

	// Assignment operator
	// post: this List now stores a copy of the sequence stored
	//         in other
	const List & operator=(const List & other);

	// Test for equality
	bool operator==(const List &rhs);

	//*** Accessors ***

	// post: true has been returned just if this List is
	//         empty.
	bool empty() const;

	int getSize(const List);    //--------> I Made That



	// post: the doubles in this List have been written to
	//         outfile.
	void print(ostream & outfile) const;


	//*** Mutators ***

	// post: x has been added as the first double in this
	//         List.
	void insertAsFirst(float x);

	void insertAsLast(float x);

	// pre:  this List is not empty.
	// post: the first double in this List has been removed
	//         from this List and has been returned.
	float removeFirst();

	int findValueIndex(List day, float value);

	float deltaDayFunction(List weekMaxList, List weekMinList);



private:
	//*** Inaccessible standard functions ****


	//*** Helper functions ***
	// process part of the linked structure

	// post: a pointer to a copy of the linked structure
	//         targeted by ptr has been returned.
	static Node * clone(Node * ptr);


private:
	Node * first_;
	Node * last_;

};


//*** Auxiliary functions ***

// post: the doubles in list have been written to outfile
ostream & operator<<(ostream & outfile, const List & list);

#endif