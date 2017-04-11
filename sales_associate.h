#ifndef SALES_ASSOCIATE_H
#define SALES_ASSOCIATE_H
#include <iostream>
#include <string>

using namespace std;

class Sales_associate {
	public :
		Sales_associate(string _name, int _employee_number) : name(_name), employee_number(_employee_number) {}
		string to_string();
	private :
		string name;
		int employee_number;
};

#endif