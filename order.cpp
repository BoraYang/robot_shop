#include "order.h"


double Order::robot_cost() {
	return quantity * robot_model.cost();
}

double Order::extended_price() {
	return 1.3 * quantity * robot_model.cost();
}

int Order::get_order_number() {
    return order_number;
}

string Order::get_date() {
    return date;
}

Customer Order::get_customer() {
    return customer;
}

Sales_associate Order::get_sales_associate() {
    return sales_associate;
}

Robot_model Order::get_robot_model() {
    return robot_model;
}

int Order::get_quantity() {
    return quantity;
}

int Order::get_status() {
    return status;
}