#include "BinaryTree.h"
#include "book.h"
#include "BST.h"
#include "RBT.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

typedef BST < book > bookBST;
typedef bookBST * bookBSTPtr;
bookBSTPtr v(new bookBST);

typedef RBT < book > bookRBT;
typedef bookRBT * bookRBTPtr;
bookRBTPtr l(new bookRBT);


void makeData1();
void makeData2();
void printBSTInsert(int nX, int nY, BinaryTree<book> * nAge, int height);
void printBSTdelete(int nX, int nY, BinaryTree<book> * nAge, int height);
void printBSTdelete2(int nX, int nY, BinaryTree<book> * nAge, int height);
void printBSTdelete3(int nX, int nY, BinaryTree<book> * nAge, int height);

void printRBTInsert(int nX, int nY, BinaryTree<book> * nAge, int height);
void printRBTdelete(int nX, int nY, BinaryTree<book> * nAge, int height);
void printRBTdelete2(int nX, int nY, BinaryTree<book> * nAge, int height);
void printRBTdelete3(int nX, int nY, BinaryTree<book> * nAge, int height);
void printRBTdelete4(int nX, int nY, BinaryTree<book> * nAge, int height);

int nRows = 1024, nCols = 1280;
Mat dst = Mat(nRows, nCols, CV_8UC3, (Scalar(255, 255, 255)));      //BST

Mat dst2 = Mat(nRows, nCols, CV_8UC3, (Scalar(255, 255, 255)));      //RBT
Mat dst3 = Mat(nRows, nCols, CV_8UC3, (Scalar(255, 255, 255)));
Mat dst4 = Mat(nRows, nCols, CV_8UC3, (Scalar(255, 255, 255)));
Mat dst5 = Mat(nRows, nCols, CV_8UC3, (Scalar(255, 255, 255)));
Mat dst6 = Mat(nRows, nCols, CV_8UC3, (Scalar(255, 255, 255)));
Mat dst7 = Mat(nRows, nCols, CV_8UC3, (Scalar(255, 255, 255)));

Mat dst8 = Mat(nRows, nCols, CV_8UC3, (Scalar(255, 255, 255)));      //BST
Mat dst9 = Mat(nRows, nCols, CV_8UC3, (Scalar(255, 255, 255)));

int moveValue = 90;
int leftMove = -moveValue - 30, leftDown = moveValue, rightMove = moveValue + 30, rightDown = moveValue;
int nRadius = 40;

Scalar blackColor = Scalar(0, 0, 0);   //black: BGR
Scalar redColor = Scalar(0, 0, 255);   //red: BGR
Scalar textColor = Scalar(100, 100, 0);   //red: BGR

int nThickness = 3;
int height;

int main()
{

	makeData1();   //BST insert

	Point ptCenter = Point(nCols / 2, 30);
	Point ptCenter2 = Point((nCols / 2) - 300, 80);
	Point ptCenter3 = Point((nCols / 2) + 300, 80);

	circle(dst, ptCenter, nRadius, blackColor, nThickness);

	string ab = to_string(v->getData().getBorrowCount());
	string word = v->getData().getWordName();

	putText(dst, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst, word, ptCenter - Point(+10, -10), FONT_HERSHEY_PLAIN, 1, textColor);

	arrowedLine(dst, ptCenter - Point(+nRadius), ptCenter2 - Point(-nRadius), blackColor, nThickness);
	arrowedLine(dst, ptCenter - Point(-nRadius), ptCenter3 - Point(+nRadius), blackColor, nThickness);


	if (v->left()->isEmpty() != true)
		printBSTInsert((nCols / 2) - 300, 80, v->left(), 8);
	if (v->right()->isEmpty() != true)
		printBSTInsert((nCols / 2) + 300, 80, v->right(), 8);

	namedWindow("bst insert");
	imshow("bst insert", dst);

	//waitKey(0);

	//BST delete
	//자식 0개
	v->deleteNode(v, 177);
	circle(dst2, ptCenter, nRadius, blackColor, nThickness);

	putText(dst2, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst2, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);

	arrowedLine(dst2, ptCenter - Point(+nRadius), ptCenter2 - Point(-nRadius), blackColor, nThickness);
	arrowedLine(dst2, ptCenter - Point(-nRadius), ptCenter3 - Point(+nRadius), blackColor, nThickness);
	namedWindow("bst delete");
	imshow("bst delete", dst2);

	if (v->left()->isEmpty() != true)
		printBSTdelete((nCols / 2) - 300, 80, v->left(), 10);
	if (v->right()->isEmpty() != true)
		printBSTdelete((nCols / 2) + 300, 80, v->right(), 10);

	//waitKey(0);

	//자식 1개
	v->deleteNode(v, 174);
	circle(dst8, ptCenter, nRadius, blackColor, nThickness);

	putText(dst8, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst8, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);

	arrowedLine(dst8, ptCenter - Point(+nRadius), ptCenter2 - Point(-nRadius), blackColor, nThickness);
	arrowedLine(dst8, ptCenter - Point(-nRadius), ptCenter3 - Point(+nRadius), blackColor, nThickness);
	namedWindow("bst delete2");
	imshow("bst delete2", dst8);

	if (v->left()->isEmpty() != true)
		printBSTdelete2((nCols / 2) - 300, 80, v->left(), 10);
	if (v->right()->isEmpty() != true)
		printBSTdelete2((nCols / 2) + 300, 80, v->right(), 10);

	//waitKey(0);


	//자식 2개
	v->deleteNode(v, 151);
	circle(dst9, ptCenter, nRadius, blackColor, nThickness);

	putText(dst9, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst9, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);

	arrowedLine(dst9, ptCenter - Point(+nRadius), ptCenter2 - Point(-nRadius), blackColor, nThickness);
	arrowedLine(dst9, ptCenter - Point(-nRadius), ptCenter3 - Point(+nRadius), blackColor, nThickness);
	namedWindow("bst delete3");
	imshow("bst delete3", dst9);

	if (v->left()->isEmpty() != true)
		printBSTdelete3((nCols / 2) - 300, 80, v->left(), 10);
	if (v->right()->isEmpty() != true)
		printBSTdelete3((nCols / 2) + 300, 80, v->right(), 10);

	//waitKey(0);


	makeData2();   //RBT insert


	string color = "BLACK";

	circle(dst3, ptCenter, nRadius, blackColor, nThickness);
	//putText(dst3, "Count: ", ptCenter - Point(+50), FONT_HERSHEY_PLAIN, 2, blackColor);
	putText(dst3, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	//putText(dst3, "Title: ", ptCenter - Point(+150,-35), FONT_HERSHEY_PLAIN, 2, blackColor);
	putText(dst3, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);
	//putText(dst3, "Color: ", ptCenter - Point(+150,-70), FONT_HERSHEY_PLAIN, 2, blackColor);
	putText(dst3, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);

	arrowedLine(dst3, ptCenter - Point(+nRadius), ptCenter2 - Point(-nRadius), blackColor, nThickness);
	arrowedLine(dst3, ptCenter - Point(-nRadius), ptCenter3 - Point(+nRadius), blackColor, nThickness);
	namedWindow("rbt insert");
	imshow("rbt insert", dst3);

	if (l->left()->isEmpty() != true)
		printRBTInsert((nCols / 2) - 300, 80, l->left(), 10);
	if (l->right()->isEmpty() != true)
		printRBTInsert((nCols / 2) + 300, 80, l->right(), 10);

	//waitKey(0);

	//RBT delete
	//sibling : 검정, sibling child : 빨강 (직선 경우)
	l->deleteRBT(l, 139);
	circle(dst4, ptCenter, nRadius, blackColor, nThickness);

	color = "BLACK";

	putText(dst4, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst4, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);
	putText(dst4, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
	arrowedLine(dst4, ptCenter - Point(+nRadius), ptCenter2 - Point(-nRadius), blackColor, nThickness);
	arrowedLine(dst4, ptCenter - Point(-nRadius), ptCenter3 - Point(+nRadius), blackColor, nThickness);
	namedWindow("rbt delete");
	imshow("rbt delete", dst4);

	if (l->left()->isEmpty() != true)
		printRBTdelete((nCols / 2) - 300, 80, l->left(), 10);
	if (l->right()->isEmpty() != true)
		printRBTdelete((nCols / 2) + 300, 80, l->right(), 10);

	//waitKey(0);

	//sibling : 검정, sibling child : 검정
	l->deleteRBT(l, 111);
	
	circle(dst5, ptCenter, nRadius, blackColor, nThickness);

	color = "BLACK";

	putText(dst5, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst5, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);
	putText(dst5, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
	arrowedLine(dst5, ptCenter - Point(+nRadius), ptCenter2 - Point(-nRadius), blackColor, nThickness);
	arrowedLine(dst5, ptCenter - Point(-nRadius), ptCenter3 - Point(+nRadius), blackColor, nThickness);
	namedWindow("rbt delete2");
	imshow("rbt delete2", dst5);

	if (l->left()->isEmpty() != true)
		printRBTdelete2((nCols / 2) - 300, 80, l->left(), 10);
	if (l->right()->isEmpty() != true)
		printRBTdelete2((nCols / 2) + 300, 80, l->right(), 10);

	//waitKey(0);

	//sibling : 빨강
	l->deleteRBT(l, 162);
	circle(dst6, ptCenter, nRadius, blackColor, nThickness);

	color = "BLACK";

	putText(dst6, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst6, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);
	putText(dst6, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
	arrowedLine(dst6, ptCenter - Point(+nRadius), ptCenter2 - Point(-nRadius), blackColor, nThickness);
	arrowedLine(dst6, ptCenter - Point(-nRadius), ptCenter3 - Point(+nRadius), blackColor, nThickness);
	namedWindow("rbt delete3");
	imshow("rbt delete3", dst6);

	if (l->left()->isEmpty() != true)
		printRBTdelete3((nCols / 2) - 300, 80, l->left(), 10);
	if (l->right()->isEmpty() != true)
		printRBTdelete3((nCols / 2) + 300, 80, l->right(), 10);

	//waitKey(0);

	//sibling : 검정, sibling child : 빨강 (굽은 경우)
	l->deleteRBT(l, 192);
	
	circle(dst7, ptCenter, nRadius, blackColor, nThickness);

	color = "BLACK";

	putText(dst7, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst7, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);
	putText(dst7, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
	arrowedLine(dst7, ptCenter - Point(+nRadius), ptCenter2 - Point(-nRadius), blackColor, nThickness);
	arrowedLine(dst7, ptCenter - Point(-nRadius), ptCenter3 - Point(+nRadius), blackColor, nThickness);
	namedWindow("rbt delete4");
	imshow("rbt delete4", dst7);

	if (l->left()->isEmpty() != true)
		printRBTdelete4((nCols / 2) - 300, 80, l->left(), 10);
	if (l->right()->isEmpty() != true)
		printRBTdelete4((nCols / 2) + 300, 80, l->right(), 10);

	waitKey(0);

	return 0;
}


//BST insert 출력하는 문
void printBSTInsert(int nX, int nY, BinaryTree<book> * nAge, int height) {
	Point ptCenter = Point(nX, nY);
	Point ptCenter2 = Point(nX - height * 15 + nRadius, nY + leftDown);
	Point ptCenter3 = Point(nX + height * 15 - nRadius, nY + rightDown);
	circle(dst, ptCenter, nRadius, blackColor, nThickness);
	string ab2 = to_string(nAge->getData().getBorrowCount());
	string word2 = nAge->getData().getWordName();

	putText(dst, ab2, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);

	putText(dst, word2, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);

	ptCenter = Point(nX - nRadius, nY);
	arrowedLine(dst, ptCenter, ptCenter2, blackColor, nThickness);
	ptCenter = Point(nX + nRadius, nY);
	arrowedLine(dst, ptCenter, ptCenter3, blackColor, nThickness);
	namedWindow("bst insert");
	imshow("bst insert", dst);
	if (nAge->left()->isEmpty() != true)
		printBSTInsert(nX - height * 15, nY + leftDown, nAge->left(), height - 1);
	if (nAge->right()->isEmpty() != true)
		printBSTInsert(nX + height * 15, nY + rightDown, nAge->right(), height - 1);
}

//BST delete 출력하는 문
void printBSTdelete(int nX, int nY, BinaryTree<book> * nAge, int height) {
	Point ptCenter = Point(nX, nY);
	Point ptCenter2 = Point(nX - height * 15 + nRadius, nY + leftDown);
	Point ptCenter3 = Point(nX + height * 15 - nRadius, nY + rightDown);
	circle(dst2, ptCenter, nRadius, blackColor, nThickness);
	string ab2 = to_string(nAge->getData().getBorrowCount());
	string word2 = nAge->getData().getWordName();

	putText(dst2, ab2, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst2, word2, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);
	ptCenter = Point(nX - nRadius, nY);
	arrowedLine(dst2, ptCenter, ptCenter2, blackColor, nThickness);
	ptCenter = Point(nX + nRadius, nY);
	arrowedLine(dst2, ptCenter, ptCenter3, blackColor, nThickness);
	namedWindow("bst delete");
	imshow("bst delete", dst2);
	if (nAge->left()->isEmpty() != true)
		printBSTdelete(nX - height * 15, nY + leftDown, nAge->left(), height - 2);
	if (nAge->right()->isEmpty() != true)
		printBSTdelete(nX + height * 15, nY + rightDown, nAge->right(), height - 2);
}

//BST delete 출력하는 문
void printBSTdelete2(int nX, int nY, BinaryTree<book> * nAge, int height) {
	Point ptCenter = Point(nX, nY);
	Point ptCenter2 = Point(nX - height * 15 + nRadius, nY + leftDown);
	Point ptCenter3 = Point(nX + height * 15 - nRadius, nY + rightDown);
	circle(dst8, ptCenter, nRadius, blackColor, nThickness);
	string ab2 = to_string(nAge->getData().getBorrowCount());
	string word2 = nAge->getData().getWordName();

	putText(dst8, ab2, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst8, word2, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);
	ptCenter = Point(nX - nRadius, nY);
	arrowedLine(dst8, ptCenter, ptCenter2, blackColor, nThickness);
	ptCenter = Point(nX + nRadius, nY);
	arrowedLine(dst8, ptCenter, ptCenter3, blackColor, nThickness);
	namedWindow("bst delete2");
	imshow("bst delete2", dst8);
	if (nAge->left()->isEmpty() != true)
		printBSTdelete2(nX - height * 15, nY + leftDown, nAge->left(), height - 2);
	if (nAge->right()->isEmpty() != true)
		printBSTdelete2(nX + height * 15, nY + rightDown, nAge->right(), height - 2);
}

//BST delete 출력하는 문
void printBSTdelete3(int nX, int nY, BinaryTree<book> * nAge, int height) {
	Point ptCenter = Point(nX, nY);
	Point ptCenter2 = Point(nX - height * 15 + nRadius, nY + leftDown);
	Point ptCenter3 = Point(nX + height * 15 - nRadius, nY + rightDown);
	circle(dst9, ptCenter, nRadius, blackColor, nThickness);
	string ab2 = to_string(nAge->getData().getBorrowCount());
	string word2 = nAge->getData().getWordName();

	putText(dst9, ab2, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst9, word2, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);
	ptCenter = Point(nX - nRadius, nY);
	arrowedLine(dst9, ptCenter, ptCenter2, blackColor, nThickness);
	ptCenter = Point(nX + nRadius, nY);
	arrowedLine(dst9, ptCenter, ptCenter3, blackColor, nThickness);
	namedWindow("bst delete3");
	imshow("bst delete3", dst9);
	if (nAge->left()->isEmpty() != true)
		printBSTdelete3(nX - height * 15, nY + leftDown, nAge->left(), height - 2);
	if (nAge->right()->isEmpty() != true)
		printBSTdelete3(nX + height * 15, nY + rightDown, nAge->right(), height - 2);
}

//RBT insert 출력하는 문
void printRBTInsert(int nX, int nY, BinaryTree<book> * nAge, int height) {
	Point ptCenter = Point(nX, nY);
	Point ptCenter2 = Point(nX - height * 15 + nRadius, nY + leftDown);
	Point ptCenter3 = Point(nX + height * 15 - nRadius, nY + rightDown);
	string color;
	if (nAge->color == BLACK)
		circle(dst3, ptCenter, nRadius, blackColor, nThickness);
	else
		circle(dst3, ptCenter, nRadius, redColor, nThickness);
	string ab = to_string(nAge->getData().getBorrowCount());
	string word = nAge->getData().getWordName();

	putText(dst3, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst3, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);


	if (nAge->color == BLACK)
	{
		color = "BLACK";
		putText(dst3, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
		ptCenter = Point(nX - nRadius, nY);
		arrowedLine(dst3, ptCenter, ptCenter2, blackColor, nThickness);
		ptCenter = Point(nX + nRadius, nY);
		arrowedLine(dst3, ptCenter, ptCenter3, blackColor, nThickness);
	}
	else
	{
		color = "RED";
		putText(dst3, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
		ptCenter = Point(nX - nRadius, nY);
		arrowedLine(dst3, ptCenter, ptCenter2, redColor, nThickness);
		ptCenter = Point(nX + nRadius, nY);
		arrowedLine(dst3, ptCenter, ptCenter3, redColor, nThickness);
	}
	namedWindow("rbt insert");
	imshow("rbt insert", dst3);

	if (nAge->leftTree->isEmpty() == false)
		printRBTInsert(nX - height * 15, nY + leftDown, nAge->left(), height - 2);
	if (nAge->rightTree->isEmpty() == false)
		printRBTInsert(nX + height * 15, nY + rightDown, nAge->right(), height - 2);
}


//RBT delete 출력하는 문
void printRBTdelete(int nX, int nY, BinaryTree<book> * nAge, int height) {
	Point ptCenter = Point(nX, nY);
	Point ptCenter2 = Point(nX - height * 15 + nRadius, nY + leftDown);
	Point ptCenter3 = Point(nX + height * 15 - nRadius, nY + rightDown);
	string color;
	if (nAge->color == BLACK)
		circle(dst4, ptCenter, nRadius, blackColor, nThickness);
	else
		circle(dst4, ptCenter, nRadius, redColor, nThickness);
	string ab = to_string(nAge->getData().getBorrowCount());
	string word = nAge->getData().getWordName();

	putText(dst4, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst4, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);

	if (nAge->color == BLACK)
	{
		color = "BLACK";
		putText(dst4, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
		ptCenter = Point(nX - nRadius, nY);
		arrowedLine(dst4, ptCenter, ptCenter2, blackColor, nThickness);
		ptCenter = Point(nX + nRadius, nY);
		arrowedLine(dst4, ptCenter, ptCenter3, blackColor, nThickness);
	}
	else
	{
		color = "RED";
		putText(dst4, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
		ptCenter = Point(nX - nRadius, nY);
		arrowedLine(dst4, ptCenter, ptCenter2, redColor, nThickness);
		ptCenter = Point(nX + nRadius, nY);
		arrowedLine(dst4, ptCenter, ptCenter3, redColor, nThickness);
	}
	namedWindow("rbt delete");
	imshow("rbt delete", dst4);
	if (nAge->leftTree->isEmpty() == false)
		printRBTdelete(nX - height * 15, nY + leftDown, nAge->left(), height - 2);
	if (nAge->rightTree->isEmpty() == false)
		printRBTdelete(nX + height * 15, nY + rightDown, nAge->right(), height - 2);
}

//RBT delete 출력하는 문
void printRBTdelete2(int nX, int nY, BinaryTree<book> * nAge, int height) {
	Point ptCenter = Point(nX, nY);
	Point ptCenter2 = Point(nX - height * 15 + nRadius, nY + leftDown);
	Point ptCenter3 = Point(nX + height * 15 - nRadius, nY + rightDown);
	string color;
	if (nAge->color == BLACK)
		circle(dst5, ptCenter, nRadius, blackColor, nThickness);
	else
		circle(dst5, ptCenter, nRadius, redColor, nThickness);
	string ab = to_string(nAge->getData().getBorrowCount());
	string word = nAge->getData().getWordName();

	putText(dst5, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst5, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);

	if (nAge->color == BLACK)
	{
		color = "BLACK";
		putText(dst5, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
		ptCenter = Point(nX - nRadius, nY);
		arrowedLine(dst5, ptCenter, ptCenter2, blackColor, nThickness);
		ptCenter = Point(nX + nRadius, nY);
		arrowedLine(dst5, ptCenter, ptCenter3, blackColor, nThickness);
	}
	else
	{
		color = "RED";
		putText(dst5, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
		ptCenter = Point(nX - nRadius, nY);
		arrowedLine(dst5, ptCenter, ptCenter2, redColor, nThickness);
		ptCenter = Point(nX + nRadius, nY);
		arrowedLine(dst5, ptCenter, ptCenter3, redColor, nThickness);
	}
	namedWindow("rbt delete2");
	imshow("rbt delete2", dst5);
	if (nAge->leftTree->isEmpty() == false)
		printRBTdelete2(nX - height * 15, nY + leftDown, nAge->left(), height - 2);
	if (nAge->rightTree->isEmpty() == false)
		printRBTdelete2(nX + height * 15, nY + rightDown, nAge->right(), height - 2);
}

//RBT delete 출력하는 문
void printRBTdelete3(int nX, int nY, BinaryTree<book> * nAge, int height) {
	Point ptCenter = Point(nX, nY);
	Point ptCenter2 = Point(nX - height * 15 + nRadius, nY + leftDown);
	Point ptCenter3 = Point(nX + height * 15 - nRadius, nY + rightDown);
	string color;
	if (nAge->color == BLACK)
		circle(dst6, ptCenter, nRadius, blackColor, nThickness);
	else
		circle(dst6, ptCenter, nRadius, redColor, nThickness);
	string ab = to_string(nAge->getData().getBorrowCount());
	string word = nAge->getData().getWordName();

	putText(dst6, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst6, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);

	if (nAge->color == BLACK)
	{
		color = "BLACK";
		putText(dst6, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
		ptCenter = Point(nX - nRadius, nY);
		arrowedLine(dst6, ptCenter, ptCenter2, blackColor, nThickness);
		ptCenter = Point(nX + nRadius, nY);
		arrowedLine(dst6, ptCenter, ptCenter3, blackColor, nThickness);
	}
	else
	{
		color = "RED";
		putText(dst6, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
		ptCenter = Point(nX - nRadius, nY);
		arrowedLine(dst6, ptCenter, ptCenter2, redColor, nThickness);
		ptCenter = Point(nX + nRadius, nY);
		arrowedLine(dst6, ptCenter, ptCenter3, redColor, nThickness);
	}
	namedWindow("rbt delete3");
	imshow("rbt delete3", dst6);
	if (nAge->leftTree->isEmpty() == false)
		printRBTdelete3(nX - height * 15, nY + leftDown, nAge->left(), height - 2);
	if (nAge->rightTree->isEmpty() == false)
		printRBTdelete3(nX + height * 15, nY + rightDown, nAge->right(), height - 2);
}

//RBT delete 출력하는 문
void printRBTdelete4(int nX, int nY, BinaryTree<book> * nAge, int height) {
	Point ptCenter = Point(nX, nY);
	Point ptCenter2 = Point(nX - height * 15 + nRadius, nY + leftDown);
	Point ptCenter3 = Point(nX + height * 15 - nRadius, nY + rightDown);
	string color;
	if (nAge->color == BLACK)
		circle(dst7, ptCenter, nRadius, blackColor, nThickness);
	else
		circle(dst7, ptCenter, nRadius, redColor, nThickness);
	string ab = to_string(nAge->getData().getBorrowCount());
	string word = nAge->getData().getWordName();

	putText(dst7, ab, ptCenter - Point(+10), FONT_HERSHEY_PLAIN, 1, blackColor);
	putText(dst7, word, ptCenter - Point(+10, -15), FONT_HERSHEY_PLAIN, 1, textColor);

	if (nAge->color == BLACK)
	{
		color = "BLACK";
		putText(dst7, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
		ptCenter = Point(nX - nRadius, nY);
		arrowedLine(dst7, ptCenter, ptCenter2, blackColor, nThickness);
		ptCenter = Point(nX + nRadius, nY);
		arrowedLine(dst7, ptCenter, ptCenter3, blackColor, nThickness);
	}
	else
	{
		color = "RED";
		putText(dst7, color, ptCenter - Point(+10, -30), FONT_HERSHEY_PLAIN, 1, blackColor);
		ptCenter = Point(nX - nRadius, nY);
		arrowedLine(dst7, ptCenter, ptCenter2, redColor, nThickness);
		ptCenter = Point(nX + nRadius, nY);
		arrowedLine(dst7, ptCenter, ptCenter3, redColor, nThickness);
	}
	namedWindow("rbt delete4");
	imshow("rbt delete4", dst7);
	if (nAge->leftTree->isEmpty() == false)
		printRBTdelete4(nX - height * 15, nY + leftDown, nAge->left(), height - 2);
	if (nAge->rightTree->isEmpty() == false)
		printRBTdelete4(nX + height * 15, nY + rightDown, nAge->right(), height - 2);
}

void makeData1()
{
	v->parent = 0;
	book a("모든 순간이 너였다", "하태완", "위즈덤하우스", "시/에세이", 0, "9791162202913", 151, "You");
	v->insertNode(a, v);
	book b("용서해 테오", "질 티보", "어린이작가정신", "동화", 1, "9788972889410", 162, "Teo");
	v->insertNode(b, v);
	book c("최신 온도센서 기술동향", "정용택", "홍릉과학출판사", "기술/공학", 2, "9791156003434", 123, "Sensor");
	v->insertNode(c, v);
	book d("죽여 마땅한 사람들", "피터 스완슨", "푸른숲", "소설", 3, "9791156756552", 192, "People");
	v->insertNode(d, v);
	book e("비하인드 허 아이즈", "사라 핀보로", "북폴리오", "소설", 4, "9788937857591", 184, "Eyes");
	v->insertNode(e, v);
	book f("아낌없이 뺏는 사랑", "피터 스완슨", "푸른숲", "소설", 5, "9791156756934", 139, "Love");
	v->insertNode(f, v);
	book g("켈빈이 들려주는 온도 이야기", "김충섭", "자음과모음", "과학", 6, "9788954420822", 174, "Story");
	v->insertNode(g, v);
	book h("오직 두 사람", "김영하", "문학동네", "소설", 7, "9788954645614", 177, "Person");
	v->insertNode(h, v);
	book i("냉장고를 부탁해", "JTBC 냉장고를 부탁해 제작팀", "중앙북스", "요리", 8, "9788927806837", 111, "ask");
	v->insertNode(i, v);
	book j("온가족이 즐거운 주말요리", "구본길", "리스컴", "요리", 9, "9788991193352", 100, "Family");
	v->insertNode(j, v);
	book k("늙지 않는 비밀", "엘리자베스 블랙번", "알에이치코리아", "건강", 10, "9788925563275", 130, "Secret");
	v->insertNode(k, v);
	//book u("나쁜국어 독해기술", "진형석", "쏠티북스", "중/고등참고서", 11, "9788997408139", 190, "Korean");
	//v->insertNode(u, v);
	//book m("불행 피하기 기술", "롤프 도벨리", "인플루엔셜", "자기계발", 12, "9791186560617", 122, "Unhappiness");
	//v->insert(m);
	//book n("크레이빙 마인드", "저드슨 브루어", "어크로스", "인문", 13, "9791160560404", 134, "Mind");
	//v->insert(n);
	//book o("용서", "달라이 라마", "오래된미래", "시/에세이", 14, "9788995501467", 199, "Forgiveness");
	//v->insert(o);
	//book p("며느라기", "수신지", "귤프레스", "만화", 15, "9791196287801", 100, "Daughter");
	//v->insert(p);
	//book q("나와 청소년문학 20년", "박상률", "학교도서관저널", "시/에세이", 16, "9788969150233", 162, "20 years");
	//v->insert(q);
	//book r("언어의 온도", "이기주", "말글터", "시/에세이", 17, "9791195522125", 136, "Language");
	//v->insert(r);
	//book s("인투 더 워터", "폴라 호킨스", "북폴리오", "소설", 18, "9791162332528", 148, "Water");
	//v->insert(s);
	//book t("푸드 앤 더 시티", "제니퍼 코크럴킹", "삼천리", "정치/사회", 19, "9788994898261", 191, "Food");
	//v->insert(t);
}

void makeData2()
{
	l->parent = l;
	book a("모든 순간이 너였다", "하태완", "위즈덤하우스", "시/에세이", 0, "9791162202913", 151, "You");
	l->insert(a, l);
	book b("용서해 테오", "질 티보", "어린이작가정신", "동화", 1, "9788972889410", 162, "Teo");
	l->insert(b, l);
	book c("최신 온도센서 기술동향", "정용택", "홍릉과학출판사", "기술/공학", 2, "9791156003434", 123, "Sensor");
	l->insert(c, l);
	book d("죽여 마땅한 사람들", "피터 스완슨", "푸른숲", "소설", 3, "9791156756552", 192, "People");
	l->insert(d, l);
	book e("비하인드 허 아이즈", "사라 핀보로", "북폴리오", "소설", 4, "9788937857591", 184, "Eyes");
	l->insert(e, l);

	//uncle : black (굽은 경우)
	book f("아낌없이 뺏는 사랑", "피터 스완슨", "푸른숲", "소설", 5, "9791156756934", 139, "Love");
	l->insert(f, l);

	//parent : red, uncle : red
	book g("켈빈이 들려주는 온도 이야기", "김충섭", "자음과모음", "과학", 6, "9788954420822", 174, "Story");
	l->insert(g, l);

	//uncle : black (직선 경우)
	book h("오직 두 사람", "김영하", "문학동네", "소설", 7, "9788954645614", 177, "Person");
	l->insert(h, l);
	book i("냉장고를 부탁해", "JTBC 냉장고를 부탁해 제작팀", "중앙북스", "요리", 8, "9788927806837", 111, "ask");
	l->insert(i, l);
	book j("온가족이 즐거운 주말요리", "구본길", "리스컴", "요리", 9, "9788991193352", 100, "Family");
	l->insert(j, l);
	book k("늙지 않는 비밀", "엘리자베스 블랙번", "알에이치코리아", "건강", 10, "9788925563275", 130, "Secret");
	l->insert(k, l);
	//book u("나쁜국어 독해기술", "진형석", "쏠티북스", "중/고등참고서", 11, "9788997408139", 190, "Korean");
	//l->insert(u, l);
	//book m("불행 피하기 기술", "롤프 도벨리", "인플루엔셜", "자기계발", 12, "9791186560617", 179, "Un");
	//l->insert(m, l);
	//book n("크레이빙 마인드", "저드슨 브루어", "어크로스", "인문", 13, "9791160560404", 118, "Mind");
	//l->insert(n, l);
	//book o("용서", "달라이 라마", "오래된미래", "시/에세이", 14, "9788995501467", 180, "Forgive");
	//l->insert(o, l);
	//   book p("며느라기", "수신지", "귤프레스", "만화", 15, "9791196287801", 100, "Daughter");
	//   l->insert(p);
	//   book q("나와 청소년문학 20년", "박상률", "학교도서관저널", "시/에세이", 16, "9788969150233", 162, "20 years");
	//   l->insert(q);
	//   book r("언어의 온도", "이기주", "말글터", "시/에세이", 17, "9791195522125", 136, "Language");
	//   l->insert(r);
	//   book s("인투 더 워터", "폴라 호킨스", "북폴리오", "소설", 18, "9791162332528", 148, "Water");
	//   l->insert(s);
	//   book t("푸드 앤 더 시티", "제니퍼 코크럴킹", "삼천리", "정치/사회", 19, "9788994898261", 191, "Food");
	//   l->insert(t);
}