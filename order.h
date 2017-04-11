#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <fstream>
#include "customer.h"
#include "sales_associate.h"
#include "robot.h"

using namespace std;

class Order {
	public:
		Order(int _order_number, string _date, Customer _customer, Sales_associate _sales_associate, Robot_model _robot_model, int _quantity, int _status) :
	  		  order_number(_order_number), date(_date), customer(_customer), sales_associate(_sales_associate), robot_model(_robot_model), quantity(_quantity), status(_status) {}
		
		double robot_cost();
	  	double extended_price();
	  	int get_order_number();
	  	string get_date();
	  	Customer get_customer();
	  	Sales_associate get_sales_associate();
	  	Robot_model get_robot_model();
	  	int get_quantity();
	  	int get_status();

	private:
	  	int order_number;
	  	string date;
	  	Customer customer;
	  	Sales_associate sales_associate;
	  	Robot_model robot_model;
	  	int quantity;
	  	int status;
};

#endif