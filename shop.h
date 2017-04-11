#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <string>
#include "customer.h"
#include "sales_associate.h"
#include "robot.h"
#include "order.h"

using namespace std;

class Shop {
	public:
	void add_robot_model(Robot_model robot_model);
	void add_head(Head head);
	void add_torso(Torso torso);
	void add_arm(Arm arm);
	void add_locomotor(Locomotor locomotor);
	void add_battery(Battery battery);
	void add_customer(Customer customer);
	void add_sales_associate(Sales_associate sales_associate);


	Head get_head(int head_index);
	Torso get_torso(int torso_index);
	Arm get_arm(int arm_index);
	Locomotor get_locomotor(int locomotor_index);
	Battery get_battery(int battery_index);


	string robot_model_to_string(int model_index);
	string head_to_string(int head_index);
	string torso_to_string(int torso_index);
	string arm_to_string(int arm_index);
	string locomotor_to_string(int locomotor_index);
	string battery_to_string(int battery_index);
	string customer_to_string(int customer_index);
	string sales_associate_to_string(int sales_associate_index);


	int number_of_robot_models();
	int number_of_heads();
	int number_of_torsos();
	int number_of_arms();
	int number_of_locomotors();
	int number_of_batteries();


	void get_part(int index);
	void create_order(int order_number, string date, int customer_number, int employee_number, int model_number, int quantity, int status);

	private:
	vector<Robot_model> robot_models;
	vector<Head> heads;
	vector<Torso> torsos;
	vector<Arm> arms;
	vector<Locomotor> locomotors;
	vector<Battery> batteries;
	vector<Customer> customers;
	vector<Sales_associate> sales_associates;
	vector<Order> orders;
};

#endif