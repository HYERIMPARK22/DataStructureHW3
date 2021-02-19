#pragma once
#include <assert.h>


template < class btElementType >
class BinaryTree {
public:
	BinaryTree();
	bool isEmpty() const;
	btElementType getData() const; 
	virtual void insert(btElementType & d);
	virtual BinaryTree <btElementType>* insertNode(btElementType & d, BinaryTree *parent_pt);
	BinaryTree * left();
	BinaryTree * right();
	void makeLeft(BinaryTree * T1);
	void makeRight(BinaryTree * T1);
	void Print();

	bool color;
	bool nullTree;
	btElementType treeData;
	BinaryTree * leftTree;
	BinaryTree * rightTree;
	BinaryTree * parent;
	BinaryTree *root;
};


template < class btElementType >
BinaryTree < btElementType > ::BinaryTree()
{
	nullTree = true;
	leftTree = 0;
	rightTree = 0;
	parent = 0;
}

template < class btElementType >
bool
BinaryTree < btElementType > ::isEmpty() const
{
	return nullTree;
}

template < class btElementType >
btElementType
BinaryTree < btElementType > ::getData() const
{
	//assert(!isEmpty());
	return treeData;
}

template < class btElementType >
void
BinaryTree < btElementType >
::insert(btElementType & d)
{
	treeData = d;
	if (nullTree) {
		nullTree = false;
		leftTree = new BinaryTree;
		rightTree = new BinaryTree;
		parent = new BinaryTree;
	}
}


template < class btElementType >
BinaryTree <btElementType>*
BinaryTree < btElementType >
::insertNode(btElementType & d, BinaryTree *parent_pt)
{
	//printf("he");
	return NULL;
}

template < class btElementType >
BinaryTree < btElementType > *
BinaryTree < btElementType > ::left()
{
	return leftTree;
}

template < class btElementType >
BinaryTree < btElementType > *
BinaryTree < btElementType > ::right()
{
	return rightTree;
}


template < class btElementType >
void
BinaryTree < btElementType >
::makeLeft(BinaryTree * T1)
{
	assert(!isEmpty());
	assert(left()->isEmpty());
	delete left();
	leftTree = T1;
}

template < class btElementType >
void
BinaryTree < btElementType >
::makeRight(BinaryTree * T1)
{
	assert(!isEmpty());
	assert(right()->isEmpty());
	delete right();
	rightTree = T1;
}


template < class btElementType >
void
BinaryTree < btElementType >
::Print()
{
	if (!isEmpty())
	{
		cout << treeData << endl;
		left()->Print();
		right()->Print();
	}
}



