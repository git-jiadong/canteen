#ifndef __MY_CLASS_H
#define __MY_CLASS_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>

using std::string;

class card
{
private:
	float balance;
public:
	card(float b);
	bool pay(float n);
	void recharge_balance(float n);
	friend std::ostream &operator << (std::ostream &os, card &cd);
};

class person:public card
{
public:
	person(float b);
	virtual bool login(const string &name) = 0;
	virtual bool order(float p) = 0;
};

class student:public person
{
private:
	const string name;
	const int id;
public:
	student();
	student(const char *n, int i, float b);
	student(const string &n, int i, float b);
	bool order(float p);
	bool login(const string &str);
	friend std::ostream &operator << (std::ostream &os, student &stu);
};

class graduate:public student
{
private:
	float wage;
public:
	graduate(const char *n, int i, float b, float w);
	graduate(const string &n, int i, float b, float w);
	friend std::ostream &operator << (std::ostream &os, graduate &gra);

};

class staff:public person 
{
private:
	const string name;

public:
	staff(const char *n, float b);
	staff(const string &n, float b);
	bool order(float p);
	bool login(float n);
	friend std::ostream &operator << (std::ostream &os, staff &sta);
};

struct food
{
	string name;
	float price;
};

class canteen
{
private:
	std::vector<struct food> menu;
public:
	void menu_show(void);
	float get_price(int i);
	void get_menu(void);
};

#endif
