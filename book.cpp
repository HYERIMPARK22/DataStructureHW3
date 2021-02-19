#include "book.h"
/*@characteristic:default ������*/
/*@preconditions:��ü ���� ����*/
/*@postconditions:default������ �ʱ�ȭ*/
/*@return:none*/
book::book() :name(""), author(""), company(""), category(""), isbn(""), borrowerName("")
{
	num = 0;
	borrowCount = 0;
}
/*@characteristic:������ �����ε�*/
/*@preconditions:��ü ���� ����*/
/*@postconditions:parameter������ �ʱ�ȭ*/
/*@return:none*/

book::book(string name, string author, string company, string category, int num, string isbn) {
	this->name = name;
	this->author = author;
	this->company = company;
	this->category = category;
	this->num = num;
	this->isbn = isbn;

}
book::book(string name, string author, string company, string category, int num, string isbn, int borrowCount, string wordName) {
	this->name = name;
	this->author = author;
	this->company = company;
	this->category = category;
	this->num = num;
	this->isbn = isbn;
	this->borrowCount = borrowCount;
	this->wordName = wordName;

}
/*@preconditions:name�� ������ ���� parameter������ �����ش�.*/
/*@postconditions:parameter������ �������� �����Ѵ�.*/
/*@return:none*/
void book::setName(string s)
{
	name = s;
}
/*@preconditions:author�� ������ ���� parameter������ �����ش�.*/
/*@postconditions:parameter������ �������� �����Ѵ�.*/
/*@return:none*/
void book::setAuthor(string s)
{
	author = s;

}
/*@preconditions:company�� ������ ���� parameter������ �����ش�.*/
/*@postconditions:parameter������ �������� �����Ѵ�.*/
/*@return:none*/
void book::setCompany(string s)
{
	company = s;

}
/*@preconditions:category�� ������ ���� parameter������ �����ش�.*/
/*@postconditions:parameter������ �������� �����Ѵ�.*/
/*@return:none*/
void book::setCategory(string s)
{
	category = s;

}
/*@preconditions:num�� ������ ���� parameter������ �����ش�.*/
/*@postconditions:parameter������ �������� �����Ѵ�.*/
/*@return:none*/
void book::setNum(int n)
{
	num = n;

}
/*@preconditions:isbn�� ������ ���� parameter������ �����ش�.*/
/*@postconditions:parameter������ �������� �����Ѵ�.*/
/*@return:none*/
void book::setIsbn(string s)
{
	isbn = s;

}
/*@preconditions:borrowerName�� ������ ���� parameter������ �����ش�.*/
/*@postconditions:parameter������ �������� �����Ѵ�.*/
/*@return:none*/
void book::setBorrowerName(string s)
{
	borrowerName = s;

}
/*@preconditions:borrowDate�� ������ ���� parameter������ �����ش�.*/
/*@postconditions:parameter������ �������� �����Ѵ�.*/
/*@return:none*/
void book::setBorrowDate(date d)
{
	borrowDate = d;

}
/*@preconditions:returnDate�� ������ ���� parameter������ �����ش�.*/
/*@postconditions:parameter������ �������� �����Ѵ�.*/
/*@return:none*/
void book::setReturnDate(date d)
{
	returnDate = d;

}
/*@preconditions:borrowCount�� ������ ���� parameter������ �����ش�.*/
/*@postconditions:parameter������ �������� �����Ѵ�.*/
/*@return:none*/
void book::setBorrowCount(int n)
{
	borrowCount = n;

}
/*@preconditions:book class�� name�̶�� ������ ���� ����Ǿ� �ִ�.*/
/*@postconditions:none*/
/*@return:name�� ����Ǿ� �ִ� ��*/
string book::getName()
{
	return name;

}
/*@preconditions:book class�� author��� ������ ���� ����Ǿ� �ִ�.*/
/*@postconditions:none*/
/*@return:author�� ����Ǿ� �ִ� ��*/
string book::getAuthor()
{
	return author;

}
/*@preconditions:book class�� company��� ������ ���� ����Ǿ� �ִ�.*/
/*@postconditions:none*/
/*@return:company�� ����Ǿ� �ִ� ��*/
string book::getCompany()
{
	return company;

}
/*@preconditions:book class�� category�̶�� ������ ���� ����Ǿ� �ִ�.*/
/*@postconditions:none*/
/*@return:category�� ����Ǿ� �ִ� ��*/
string book::getCategory()
{
	return category;

}
/*@preconditions:book class�� num�̶�� ������ ���� ����Ǿ� �ִ�.*/
/*@postconditions:none*/
/*@return:num�� ����Ǿ� �ִ� ��*/
int book::getNum()
{
	return num;

}
/*@preconditions:book class�� isbn�̶�� ������ ���� ����Ǿ� �ִ�.*/
/*@postconditions:none*/
/*@return:isbn�� ����Ǿ� �ִ� ��*/
string book::getIsbn()
{
	return isbn;

}
/*@preconditions:book class�� borrowerName�̶�� ������ ���� ����Ǿ� �ִ�.*/
/*@postconditions:none*/
/*@return:borrowerName�� ����Ǿ� �ִ� ��*/
string book::getBorrowerName()
{
	return borrowerName;

}
/*@preconditions:book class�� borrowDate�̶�� ������ ���� ����Ǿ� �ִ�.*/
/*@postconditions:none*/
/*@return:borrowDate�� ����Ǿ� �ִ� ��*/
date book::getBorrowDate()
{
	return borrowDate;

}
/*@preconditions:book class�� returnDate�̶�� ������ ���� ����Ǿ� �ִ�.*/
/*@postconditions:none*/
/*@return:returnDate�� ����Ǿ� �ִ� ��*/
date book::getReturnDate()
{
	return returnDate;

}
/*@preconditions:book class�� borrowCount�̶�� ������ ���� ����Ǿ� �ִ�.*/
/*@postconditions:none*/
/*@return:borrowCount�� ����Ǿ� �ִ� ��*/
int book::getBorrowCount()
{
	return borrowCount;

}

string book::getWordName()
{
	return wordName;
}

/*@preconditions:borrowCount ������ ���� ���� �Ǿ� �־ �񱳰� �����ϴ�.*/
/*@postconditions:borrowCount�� ũ�⸦ ���Ѵ�.*/
/*@return:ū�� ������ bool������ ��Ÿ���� return*/
bool book::operator>(const book &bBook)
{
	return (this->borrowCount>bBook.borrowCount);
}