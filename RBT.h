#pragma once
#include "BST.h"
#include <queue>
enum Color { BLACK, RED };

template < class btElementType >
class RBT : public BinaryTree < book > {         //book을 btElementType로 변경할경우 안된다? 2017 컴파일러 오류?
public:
	RBT();
	virtual BinaryTree <btElementType>* insertNode(btElementType & d, BinaryTree *parent_pt);
	virtual void insert(btElementType & d, BinaryTree *parent_pt);
	BinaryTree < btElementType > * deleteNode(BinaryTree* root, int key);
	void deleteRBT(BinaryTree* root, int key);
	BinaryTree <btElementType>* findRoot(BinaryTree *current);
	BinaryTree < btElementType > * minValueNode(BinaryTree* node);
	//virtual BinaryTree < btElementType > * retrieve(const btElementType & d);
	void inorder();
	void inorderHelper(BinaryTree *root);
	void levelOrder();
	void levelOrderHelper(BinaryTree *root);
	void swap(BinaryTree *a, BinaryTree *b);


	BinaryTree * parent;

protected:
	void rotateLeft(BinaryTree *&, BinaryTree *&);
	void rotateRight(BinaryTree *&, BinaryTree *&);
	void fixViolation(BinaryTree *&, BinaryTree *&);

};


template < class btElementType >
RBT < btElementType >
::RBT() : BinaryTree < btElementType >()
{
	nullTree = true;
	leftTree = 0;
	rightTree = 0;
	parent = 0;
	root = this;
}

template < class btElementType >
void
RBT< btElementType>
::swap(BinaryTree *a, BinaryTree *b) {
	bool temp = a->color;
	a->color = b->color;
	b->color = temp;
}

template < class btElementType >
BinaryTree <btElementType>*
RBT < btElementType >
::insertNode(btElementType & d, BinaryTree *parent_pt)
{
	BinaryTree * tmp;
	if (nullTree) {
		nullTree = false;
		leftTree = new RBT;
		rightTree = new RBT;
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
void
RBT < btElementType >
::insert(btElementType & d, BinaryTree *parent_pt)
{
	BinaryTree * tmp;
	tmp = insertNode(d, parent_pt);
	BinaryTree * root = findRoot(tmp);
	fixViolation(root, tmp);
}

template < class btElementType >
void
RBT < btElementType >
::deleteRBT(BinaryTree* root, int key)
{
	BinaryTree * tmp;
	tmp = deleteNode(root, key);
	BinaryTree * tmproot = findRoot(tmp);
	fixViolation(tmproot, tmp);
}


template < class btElementType >
BinaryTree < btElementType > *
RBT < btElementType >
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

		//지우는 노드가 root가 아닌 경우
		if (root->parent != root) {
			BinaryTree <book> * temp = minValueNode(root->leftTree);
			book temp2 = temp->getData();
			root->leftTree = deleteNode(temp, temp->getData().getBorrowCount());
			root->treeData = temp2;
		}
		else {
			BinaryTree <book> *temp = minValueNode(root->leftTree);
			book temp2 = temp->getData();
			deleteNode(temp, temp->getData().getBorrowCount());
			root->treeData = temp2;

		}
	}
	return root;
}



template < class btElementType >
BinaryTree < btElementType > *
RBT < btElementType >
::minValueNode(BinaryTree * node)
{
	BinaryTree * current = node;

	/* loop down to find the leftmost leaf */
	while (current->rightTree->nullTree != true)
		current = current->rightTree;

	return current;
}


template < class btElementType >
BinaryTree <btElementType>*
RBT < btElementType >
::findRoot(BinaryTree *tmp) {
	BinaryTree *current = tmp;
	while (current != current->parent)
		current = current->parent;
	return current;
}



//template < class btElementType >
//BinaryTree < btElementType > *
//RBT < btElementType >
//::retrieve(const btElementType & d)
//{
//   if (nullTree || d == treeData)
//      return this;
//   else if (d < treeData)
//      return ((RBT <btElementType> *) leftTree)->retrieve(d);
//   else
//      return ((RBT <btElementType> *) rightTree)->retrieve(d);
//}

// Function to do inorder and level order traversals
template < class btElementType >
void
RBT< btElementType >
::inorder() { inorderHelper(root); }

// A recursive function to do level order traversal
template < class btElementType >
void
RBT< btElementType >
::inorderHelper(BinaryTree *root)
{
	if (root == NULL)
		return;

	inorderHelper(root->leftTree);
	cout << root->treeData.getName() << "  ";
	inorderHelper(root->rightTree);
}


template < class btElementType >
void
RBT< btElementType >
::levelOrder() { levelOrderHelper(root); }

template < class btElementType >
void
RBT< btElementType >
::levelOrderHelper(BinaryTree *root)
{
	if (root == NULL)
		return;

	std::queue<BinaryTree *> q;
	q.push(root);

	while (!q.empty())
	{
		BinaryTree *temp = q.front();
		cout << temp->treeData.getName() << "  ";
		q.pop();

		if (temp->leftTree != NULL)
			q.push(temp->leftTree);

		if (temp->rightTree != NULL)
			q.push(temp->rightTree);
	}
}

template < class btElementType >
void
RBT< btElementType >
::rotateLeft(BinaryTree *&root, BinaryTree *&pt)
{

	BinaryTree *pt_right = pt->rightTree;

	pt->rightTree = pt_right->leftTree;

	if (pt->rightTree != NULL)
		pt->rightTree->parent = pt;

	pt_right->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_right;

	else if (pt == pt->parent->leftTree)
		pt->parent->leftTree = pt_right;

	else
		pt->parent->rightTree = pt_right;

	pt_right->leftTree = pt;
	pt->parent = pt_right;
}

template < class btElementType >
void
RBT< btElementType >
::rotateRight(BinaryTree *&root, BinaryTree *&pt)
{
	BinaryTree *pt_left = pt->leftTree;

	pt->leftTree = pt_left->rightTree;

	if (pt->leftTree != NULL)
		pt->leftTree->parent = pt;

	pt_left->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_left;

	else if (pt == pt->parent->leftTree)
		pt->parent->leftTree = pt_left;

	else
		pt->parent->rightTree = pt_left;

	pt_left->rightTree = pt;
	pt->parent = pt_left;
}

// This function fixes violations caused by BST insertion
template < class btElementType >
void
RBT< btElementType >
::fixViolation(BinaryTree *&root, BinaryTree *&pt)
{
	BinaryTree *parent_pt = NULL;
	BinaryTree *grand_parent_pt = NULL;

	while ((pt != root) && (pt->color != BLACK) &&
		(pt->parent->color == RED))
	{

		parent_pt = pt->parent;
		grand_parent_pt = pt->parent->parent;

		/*  Case : A
		Parent of pt is left child of Grand-parent of pt */
		if (parent_pt == grand_parent_pt->leftTree)
		{

			BinaryTree * uncle_pt = grand_parent_pt->rightTree;

			/* Case : 1
			The uncle of pt is also red
			Only Recoloring required */
			if (uncle_pt != NULL && uncle_pt->color == RED)
			{
				grand_parent_pt->color = RED;
				parent_pt->color = BLACK;
				uncle_pt->color = BLACK;
				pt = grand_parent_pt;
			}

			else
			{
				/* Case : 2
				pt is right child of its parent
				Left-rotation required */
				if (pt == parent_pt->rightTree)
				{
					rotateLeft(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

				/* Case : 3
				pt is left child of its parent
				Right-rotation required */
				rotateRight(root, grand_parent_pt);
				swap(parent_pt, grand_parent_pt);
				pt = parent_pt;
			}
		}

		/* Case : B
		Parent of pt is right child of Grand-parent of pt */
		else
		{
			BinaryTree *uncle_pt = grand_parent_pt->leftTree;

			/*  Case : 1
			The uncle of pt is also red
			Only Recoloring required */
			if ((uncle_pt != NULL) && (uncle_pt->color == RED))
			{
				grand_parent_pt->color = RED;
				parent_pt->color = BLACK;
				uncle_pt->color = BLACK;
				pt = grand_parent_pt;
			}
			else
			{
				/* Case : 2
				pt is left child of its parent
				Right-rotation required */
				if (pt == parent_pt->leftTree)
				{
					rotateRight(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}

				/* Case : 3
				pt is right child of its parent
				Left-rotation required */
				rotateLeft(root, grand_parent_pt);
				swap(parent_pt, grand_parent_pt);
				pt = parent_pt;
			}
		}
	}

	root->color = BLACK;
}
