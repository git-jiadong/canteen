#include "my_class.h"

card::card(float b):balance(b)
{
}

bool card::pay(float n)
{
	if(balance < n)
		return false;
	else
		balance -= n;
	return true;
}

void card::recharge_balance(float n)
{
	balance += n;
}

std::ostream &operator << (std::ostream &os, card &cd)
{
	std::cout << cd.balance;
}

person::person(float b):card(b)
{
}

student::student()
	:name("student"), id(0), person(0.0)
{
}

student::student(const char *n, int i, float b)
	:name(n), id(i), person(b)
{
}

student::student(const string &n, int i, float b)
	:name(n), id(i), person(b)
{
}

bool student::order(float p)
{
	return pay(p);
}

bool student::login(const string &str)
{
	if(name == str)
		return true;
	else
		return false;
}

std::ostream &operator << (std::ostream &os, student &stu)
{
	std::cout << "name: " << stu.name 
		<< "\tidnumber: " << stu.id
		<< "\tbalance: " << *(card *)&stu;

	return os;
}

graduate::graduate(const char *n, int i, float b, float w)
	:student(n, i, b), wage(w)
{
}

graduate::graduate(const string &n, int i, float b, float w)
	:student(n, i, b), wage(w)
{
}

std::ostream &operator << (std::ostream &os, graduate &gra)
{
	std::cout <<  *(student *)&gra
		<< "\twage: " << gra.wage;

	return os;
}

staff::staff(const char *n, float b)
	:name(n), person(b)
{
}

staff::staff(const string &n, float b)
	:name(n), person(b)
{
}

bool staff::order(float p)
{
	return pay(p * 0.9);
}

std::ostream &operator << (std::ostream &os, staff &sta)
{
	std::cout << "name: " << sta.name
		<< "\tbalance: " << *(card *)&sta;

	return os;
}

void canteen::get_menu(void)
{
	std::ifstream fin;
	fin.open("menu.txt", std::ifstream::in);
	char ch[256];
	fin.getline(ch, 256);
	food fd;

	while(fin.good())
	{
		fd.name = strtok(ch, "	");
		fd.price = atof(strtok(NULL, "	"));
		menu.push_back(fd);
		fin.getline(ch, 256);
	}

	fin.close();
}

std::ostream &operator << (std::ostream &os, food &fd)
{
	std::cout << fd.name << "\t\t" << fd.price;

	return os;
}

void canteen::menu_show(void)
{
	std::cout << "\tcategory\t" << "price" << std::endl;
	std::cout << "=====================================" << std::endl;

	for(int i=0; i<menu.size(); i++)
	{
		std::cout << "[" << i+1 << "]\t" << menu[i] << std::endl; 
	}
}

float canteen::get_price(int i)
{
	if(i-1 >= menu.size())
		return -1;
	return menu[i - 1].price; 
}
