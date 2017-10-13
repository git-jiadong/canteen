#include <iostream>
#include <ctime>
#include <sstream>
#include "my_class.h"

void data_init(person * &p)
{
	srand(time(NULL));
	std::stringstream ss;
	string str;

	for(int i=0; i<100; i++)
	{
		ss << i;
		str = "student" + ss.str();
		p[i] = new student(str, 10000+i, rand()%150 + 50);
		str.clear();
		ss.str("");
		ss.clear();
	}
}

int main()
{
	using std::cout;
	using std::endl;
	
	canteen cant;
	cant.get_menu();
	cant.menu_show();

	person *per[120];
	data_init(per);

	for(int i=0; i<100; i++)
	{
		cout << *(student *)per[i] << endl;
	}

	cout << cant.get_price(1) << endl;
	cout << cant.get_price(14) << endl;
	cout << cant.get_price(15) << endl;
	cout << cant.get_price(16) << endl;

	return 0;
}
