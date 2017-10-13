#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include "my_class.h"

struct food
{
	std::string name;
	float price;
};

void student_init(std::vector<student *> &stu);
//void graduate_init(std::vector<graduate *> &gra);
//void staff_init(std::vector<staff *> &sta);
void menu_init(std::vector<struct food> &menu);
void menu_show(std::vector<struct food> &menu);

std::ostream &operator << (std::ostream &os, food &fd)
{
	std::cout << fd.name << "\t\t" << fd.price;

	return os;
}

int main()
{
	using std::cout;
	using std::endl;
	std::vector<struct food> menu;
	std::vector<student *> stu;
	//std::vector<graduate *> gra;
	//std::vector<staff *> sta;
	student_init(stu);
	//graduate * gra =  (gratudate *)stu[100];
	//staff * sta =  (staff *)stu[100];
	//graduate_init(gra);
	//staff_init(sta);
	menu_init(menu);
	menu_show(menu);


	string name;
	while(1)
	{
		cout << "Please enter your's name: ";
		std::cin >> name;

		for(int i=0; i<120; i++)
		{
			if(stu[i]->is_me(name))
			{
				cout << *stu[i] << endl;
				break;
			}
		}
		
	}

/*
	for(int i=0; i<100; i++)
		cout << *stu[i] << endl;
	for(int i=0; i<10; i++)
		cout << *gra[i] << endl;
	for(int i=0; i<10; i++)
		cout << *sta[i] << endl;
*/


	return 0;
}

void student_init(std::vector<student *> &stu)
{
	srand(time(NULL));
	std::stringstream ss;
	student *p;
	string str;
	for(int i=0; i<100; i++)
	{
		ss << i;
		str = "student" + ss.str();
		p = new student(str, 10000+i, rand() % 150 + 50);
		stu.push_back(p);	
		str.clear();
		ss.str("");
		ss.clear();
	
	}

	for(int i=0; i<10; i++)
	{
		ss << i;
		str = "graduate" + ss.str();
		p = new graduate(str, 20000+i, rand()%150 + 50, rand()%5000 + 500);
		stu.push_back(p);
		str.clear();
		ss.str("");
		ss.clear();
	}

	for(int i=0; i<10; i++)
	{
		ss << i;
		str = "staff" + ss.str();
		p = new staff(str, 20000+i, rand()%150 + 50);
		stu.push_back(p);
		str.clear();
		ss.str("");
		ss.clear();
	}

}

/*
void graduate_init(std::vector<graduate *> &gra)
{
	srand(time(NULL));
	std::stringstream ss;
	graduate *p;
	string str;

	for(int i=0; i<10; i++)
	{
		ss << i;
		str = "graduate" + ss.str();
		p = new graduate(str, 20000+i, rand()%150 + 50, rand()%5000 + 500);
		gra.push_back(p);
		str.clear();
		ss.str("");
		ss.clear();
	}
}

void staff_init(std::vector<staff *> &sta)
{
	srand(time(NULL));
	std::stringstream ss;
	staff *p;
	string str;

	for(int i=0; i<10; i++)
	{
		ss << i;
		str = "staff" + ss.str();
		p = new staff(str, 20000+i, rand()%150 + 50);
		sta.push_back(p);
		str.clear();
		ss.str("");
		ss.clear();
	}
}
*/

void menu_init(std::vector<struct food> &menu)
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

void menu_show(std::vector<struct food> &menu)
{
	std::cout << "\tcategory\t" << "price" << std::endl;
	std::cout << "=====================================" << std::endl;
	
	for(int i=0; i<menu.size(); i++)
	{
		std::cout << "[" << i+1 << "]\t"<< menu[i] << std::endl;
	}
	
}
