#pragma once
#include <iostream>
using namespace std;
#include <string>

/*characteristic:대출 날짜 변수와 반납 날짜 변수에 사용할 구조체로 년,월,일을 나타낼 수 있다.*/
struct date		
{
	int year;		
	int month;
	int day;
};

/*characteristic:책에 대한 정보를 나타내는 구조체로 
변수로는 책 이름, 저자, 출판사, 카테고리, 일련번호, isbn, 대출자 이름, 대출일, 반납일, 대출 횟수가 있고
각 변수에 대한 getter,setter함수와 생성자가 있다.*/
class book{
private:
	string name;
	string author;
	string company;
	string category;
	int num;
	string isbn;
	int borrowCount;
	string borrowerName;
	date borrowDate;
	date returnDate;
	string wordName;
	
public:
	book();
	book(string name, string author, string company, string category, int num, string isbn);
	book(string name, string author, string company, string category, int num, string isbn, int borrowCount, string wordName);
	void setName(string s);
	void setAuthor(string s);
	void setCompany(string s);
	void setCategory(string s);
	void setNum(int n);
	void setIsbn(string s);
	void setBorrowerName(string s);
	void setBorrowDate(date s);
	void setReturnDate(date s);
	void setBorrowCount(int n);
	bool operator>(const book &bBook);

	string getName();
	string getAuthor();
	string getCompany();
	string getCategory();
	int getNum();
	string getIsbn();
	string getBorrowerName();
	date getBorrowDate();
	date getReturnDate();
	int getBorrowCount();
	string getWordName();

};

