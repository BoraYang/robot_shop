#include "shop.h"


void Shop::add_robot_model(Robot_model robot_model) {
	robot_models.push_back(robot_model);
}

void Shop::add_head(Head head) {
	heads.push_back(head);
}

void Shop::add_torso(Torso torso) {
	torsos.push_back(torso);
}

void Shop::add_arm(Arm arm) {
	arms.push_back(arm);
}

void Shop::add_locomotor(Locomotor locomotor) {
	locomotors.push_back(locomotor);
}

void Shop::add_battery(Battery battery) {
	batteries.push_back(battery);
}

void Shop::add_customer(Customer customer) {
	customers.push_back(customer);
}

void Shop::add_sales_associate(Sales_associate sales_associate) {
	sales_associates.push_back(sales_associate);
}




Head Shop::get_head(int head_index) {
	return heads[head_index];
}

Torso Shop::get_torso(int torso_index) {
	return torsos[torso_index];
}

Arm Shop::get_arm(int arm_index) {
	return arms[arm_index];
}

Locomotor Shop::get_locomotor(int locomotor_index) {
	return locomotors[locomotor_index];
}

Battery Shop::get_battery(int battery_index) {
	return batteries[battery_index];
}



string Shop::robot_model_to_string(int model_index) {
	return robot_models[model_index].to_string();
}

string Shop::head_to_string(int head_index) {
	return heads[head_index].to_string();
}

string Shop::torso_to_string(int torso_index) {
	return torsos[torso_index].to_string();
}

string Shop::arm_to_string(int arm_index) {
	return arms[arm_index].to_string();
}

string Shop::locomotor_to_string(int locomotor_index) {
	return locomotors[locomotor_index].to_string();
}

string Shop::battery_to_string(int battery_index) {
	return batteries[battery_index].to_string();
}

string Shop::customer_to_string(int customer_index) {
	return customers[customer_index].to_string();
}

string Shop::sales_associate_to_string(int sales_associate_index) {
	return sales_associates[sales_associate_index].to_string();
}



int Shop::number_of_robot_models() {
	return robot_models.size();
}

int Shop::number_of_heads() {
	return heads.size();
}

int Shop::number_of_torsos() {
	return torsos.size();
}

int Shop::number_of_arms() {
	return arms.size();
}

int Shop::number_of_locomotors() {
	return locomotors.size();
}

int Shop::number_of_batteries() {
	return batteries.size();
}



void Shop::create_order(int order_number, string date, int customer_number, int employee_number, int model_number, int quantity, int status) {
	Order order(order_number, date, customers[customer_number], sales_associates[employee_number], robot_models[model_number], quantity, status);
	orders.push_back(order);
}



void Shop::get_part(int index) {
	string name;
	static int model_number, head, torso, arm, locomotor, battery;
	if (index == 1) {
		cout << "Part number of the head: ";
		cin >> head;
	}
	else if (index == 2) {
		cout << "Part number of the torso: ";
		cin >> torso;
	}
	else if (index == 3) {
		cout << "Part number of the arm: ";
		cin >> arm;
	}
	else if (index == 4) {
		cout << "Part number of the locomotor: ";
		cin >> locomotor;
	}
	else if (index == 5) {
		cout << "Part number of the battery: ";
		cin >> battery;

		cout << "Robot name: ";
		cin >> name;

		cout << "Model number: ";
		cin >> model_number;

		Robot_model model(name, model_number, get_head(head), get_torso(torso),
			              get_arm(arm), get_locomotor(locomotor), get_battery(battery));

		add_robot_model(model);
	}
}
