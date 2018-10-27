
//ORIGINAL CREATOR:  tom bailey   1050  31 jan 2011
//Creator/Modifier:	Justin Blakeman - Oct 26, 2018
//Class:	COSC 2030 - Data Structures
//Name:		"Project01" - "Blood Sugar Project"
// Definitions of the Node class methods

#include "pch.h"
#include "Node.h"


Node::Node(float entry)
	: entry_(entry), next_(NULL)
{
	//cout << "Node( " << entry_ << ", " << next_ <<
		//" ) created at " << this << endl;
}

Node::Node(float entry, Node * next)
	: entry_(entry), next_(next)
{
	//cout << "Node( " << entry_ << ", " << next_ <<
		//" ) created at " << this << endl;
}

Node::~Node()
{
	//cout << "Node( " << entry_ << ", " << next_ <<
	//	" ) at " << this << " destroyed" << endl;
}