#pragma once
#include "BinaryTree.h"

template < class btElementType >
class BST : public BinaryTree < book > {			
public:
	BST();
	virtual BinaryTree <btElementType>* insertNode(btElementType & d, BinaryTree *parent_pt);
	virtual BinaryTree < btElementType > * retrieve(btElementType & d);
	BinaryTree < btElementType > * deleteNode(BinaryTree * root, int key);
	BinaryTree < btElementType > * minValueNode(BinaryTree* node);
};

template < class btElementType >
BinaryTree <btElementType>*
BST < btElementType >
::insertNode(btElementType & d, BinaryTree *parent_pt )
{
	BinaryTree * tmp;
	if (nullTree) {
		nullTree = false;
		leftTree = new BST;
		rightTree = new BST;
		treeData = d;
		parent = parent_pt;
		color = RED;
		tmp = this;
		tmp->parent = this->parent;

	}

	else if (d.getBorrowCount() < treeData.getBorrowCount())
		tmp = leftTree->insertNode(d, this);
	else
		tmp = rightTree->insertNode(d, this);
	return tmp;
}

template < class btElementType >
BinaryTree < btElementType > *
BST < btElementType >
::retrieve(btElementType & d)
{
	if (nullTree || d.getIsbn() == treeData.getIsbn())
		return this;
	else if (d.getBorrowCount() < treeData.getBorrowCount())
		return ((BST <btElementType> *) leftTree)->retrieve(d);
	else
		return ((BST <btElementType> *) rightTree)->retrieve(d);
}

template < class btElementType >
BST < btElementType >
::BST() : BinaryTree < btElementType >()
{
	nullTree = true;
	leftTree = 0;
	rightTree = 0;
	parent = 0;
}

template < class btElementType >
BinaryTree < btElementType > *
BST < btElementType >
::
deleteNode(BinaryTree* root, int key)
{

    if (root == NULL) return root;
    if (key < root->getData().getBorrowCount())
        root->leftTree = deleteNode(root->leftTree, key);
 
    else if (key > root->getData().getBorrowCount())
        root->rightTree = deleteNode(root->rightTree, key);
 
    else
    {
        if (root->leftTree->nullTree == true)
        {
            BinaryTree <book> *temp = root->rightTree;
            free(root);
            return temp;
        }
        else if (root->rightTree->nullTree == true)
        {
			BinaryTree <book> * temp = root->leftTree;
            free(root);
            return temp;
        }

		//지우는 노드가 root가 아닌경우
		if (root->parent != root) {
			BinaryTree <book> * temp = minValueNode(root->rightTree);
			temp->parent->leftTree = temp->rightTree;
			temp->rightTree = root->rightTree;
			root = temp;

		}
		else {
			BinaryTree <book> *temp = minValueNode(root->rightTree);
			book temp2 = temp->getData();
			root->rightTree=deleteNode(temp, temp->getData().getBorrowCount());
			root->treeData = temp2;
		
		}
    }
    return root;
}

template < class btElementType >
BinaryTree < btElementType > *
BST < btElementType >
:: minValueNode(BinaryTree * node)
{
    BinaryTree * current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->leftTree->nullTree != true)
        current = current->leftTree;
 
    return current;
}
