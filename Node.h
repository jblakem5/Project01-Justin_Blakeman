#pragma once
// Node.h

// tom bailey   0755  05 oct 2010
//Creator/Modifier:	Justin Blakeman - Oct 26, 2018
//Class:	COSC 2030 - Data Structures
//Name:		"Project01" - "Blood Sugar Project"

// Node uses public access to simplify code in the
// container classes that use Nodes.  Client access is
// controlled by the container classes.

// The constructors and destructor are verbose to facilitate
// tracking of memory leaks.

// The default constructor and assignment operator are
// declared private so they cannot be called.

#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
using std::cout;
using std::endl;


class Node
{
public:

	float entry_;
	Node * next_;

public:
	// Constructors

	// post: this Node contains entry and a NULL pointer
	explicit Node(float entry);

	// post: this Node contains entry and next
	Node(float entry, Node * next);

	// Destructor

	~Node();

private:
	// Inaccessible standard functions
	Node();
	Node(const Node &);
	const Node & operator=(const Node &);
};

#endif