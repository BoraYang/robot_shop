#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>

using namespace std;

class Customer {
	public:
	  Customer(string _name, int _customer_number, string _phone_number, string _email_address)
	  		   : name(_name), customer_number(_customer_number), phone_number(_phone_number), email_address(_email_address) {}	 
	  string to_string();
	private:
	  string name;
	  int customer_number;
	  string phone_number;
	  string email_address;
};

#endif