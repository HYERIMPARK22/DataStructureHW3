#pragma once
#include <iostream>
using namespace std;
#include <string>

/*characteristic:���� ��¥ ������ �ݳ� ��¥ ������ ����� ����ü�� ��,��,���� ��Ÿ�� �� �ִ�.*/
struct date		
{
	int year;		
	int month;
	int day;
};

/*characteristic:å�� ���� ������ ��Ÿ���� ����ü�� 
�����δ� å �̸�, ����, ���ǻ�, ī�װ�, �Ϸù�ȣ, isbn, ������ �̸�, ������, �ݳ���, ���� Ƚ���� �ְ�
�� ������ ���� getter,setter�Լ��� �����ڰ� �ִ�.*/
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

