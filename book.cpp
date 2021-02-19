#include "book.h"
/*@characteristic:default 생성자*/
/*@preconditions:객체 생성 선언*/
/*@postconditions:default값으로 초기화*/
/*@return:none*/
book::book() :name(""), author(""), company(""), category(""), isbn(""), borrowerName("")
{
	num = 0;
	borrowCount = 0;
}
/*@characteristic:생성자 오버로딩*/
/*@preconditions:객체 생성 선언*/
/*@postconditions:parameter값으로 초기화*/
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
/*@preconditions:name에 저장할 값을 parameter값으로 보내준다.*/
/*@postconditions:parameter값으로 변수값을 저장한다.*/
/*@return:none*/
void book::setName(string s)
{
	name = s;
}
/*@preconditions:author에 저장할 값을 parameter값으로 보내준다.*/
/*@postconditions:parameter값으로 변수값을 저장한다.*/
/*@return:none*/
void book::setAuthor(string s)
{
	author = s;

}
/*@preconditions:company에 저장할 값을 parameter값으로 보내준다.*/
/*@postconditions:parameter값으로 변수값을 저장한다.*/
/*@return:none*/
void book::setCompany(string s)
{
	company = s;

}
/*@preconditions:category에 저장할 값을 parameter값으로 보내준다.*/
/*@postconditions:parameter값으로 변수값을 저장한다.*/
/*@return:none*/
void book::setCategory(string s)
{
	category = s;

}
/*@preconditions:num에 저장할 값을 parameter값으로 보내준다.*/
/*@postconditions:parameter값으로 변수값을 저장한다.*/
/*@return:none*/
void book::setNum(int n)
{
	num = n;

}
/*@preconditions:isbn에 저장할 값을 parameter값으로 보내준다.*/
/*@postconditions:parameter값으로 변수값을 저장한다.*/
/*@return:none*/
void book::setIsbn(string s)
{
	isbn = s;

}
/*@preconditions:borrowerName에 저장할 값을 parameter값으로 보내준다.*/
/*@postconditions:parameter값으로 변수값을 저장한다.*/
/*@return:none*/
void book::setBorrowerName(string s)
{
	borrowerName = s;

}
/*@preconditions:borrowDate에 저장할 값을 parameter값으로 보내준다.*/
/*@postconditions:parameter값으로 변수값을 저장한다.*/
/*@return:none*/
void book::setBorrowDate(date d)
{
	borrowDate = d;

}
/*@preconditions:returnDate에 저장할 값을 parameter값으로 보내준다.*/
/*@postconditions:parameter값으로 변수값을 저장한다.*/
/*@return:none*/
void book::setReturnDate(date d)
{
	returnDate = d;

}
/*@preconditions:borrowCount에 저장할 값을 parameter값으로 보내준다.*/
/*@postconditions:parameter값으로 변수값을 저장한다.*/
/*@return:none*/
void book::setBorrowCount(int n)
{
	borrowCount = n;

}
/*@preconditions:book class의 name이라는 변수에 값이 저장되어 있다.*/
/*@postconditions:none*/
/*@return:name에 저장되어 있는 값*/
string book::getName()
{
	return name;

}
/*@preconditions:book class의 author라는 변수에 값이 저장되어 있다.*/
/*@postconditions:none*/
/*@return:author에 저장되어 있는 값*/
string book::getAuthor()
{
	return author;

}
/*@preconditions:book class의 company라는 변수에 값이 저장되어 있다.*/
/*@postconditions:none*/
/*@return:company에 저장되어 있는 값*/
string book::getCompany()
{
	return company;

}
/*@preconditions:book class의 category이라는 변수에 값이 저장되어 있다.*/
/*@postconditions:none*/
/*@return:category에 저장되어 있는 값*/
string book::getCategory()
{
	return category;

}
/*@preconditions:book class의 num이라는 변수에 값이 저장되어 있다.*/
/*@postconditions:none*/
/*@return:num에 저장되어 있는 값*/
int book::getNum()
{
	return num;

}
/*@preconditions:book class의 isbn이라는 변수에 값이 저장되어 있다.*/
/*@postconditions:none*/
/*@return:isbn에 저장되어 있는 값*/
string book::getIsbn()
{
	return isbn;

}
/*@preconditions:book class의 borrowerName이라는 변수에 값이 저장되어 있다.*/
/*@postconditions:none*/
/*@return:borrowerName에 저장되어 있는 값*/
string book::getBorrowerName()
{
	return borrowerName;

}
/*@preconditions:book class의 borrowDate이라는 변수에 값이 저장되어 있다.*/
/*@postconditions:none*/
/*@return:borrowDate에 저장되어 있는 값*/
date book::getBorrowDate()
{
	return borrowDate;

}
/*@preconditions:book class의 returnDate이라는 변수에 값이 저장되어 있다.*/
/*@postconditions:none*/
/*@return:returnDate에 저장되어 있는 값*/
date book::getReturnDate()
{
	return returnDate;

}
/*@preconditions:book class의 borrowCount이라는 변수에 값이 저장되어 있다.*/
/*@postconditions:none*/
/*@return:borrowCount에 저장되어 있는 값*/
int book::getBorrowCount()
{
	return borrowCount;

}

string book::getWordName()
{
	return wordName;
}

/*@preconditions:borrowCount 변수에 값이 저장 되어 있어서 비교가 가능하다.*/
/*@postconditions:borrowCount의 크기를 비교한다.*/
/*@return:큰지 작은지 bool값으로 나타내어 return*/
bool book::operator>(const book &bBook)
{
	return (this->borrowCount>bBook.borrowCount);
}