#include "controller.h"

void Controller::cli() {
	int cmd = -1;
	while (cmd != 0) {
		cout << view.get_menu() << "\n";
		cout << "Command: ";
		cin >> cmd;
		cin.ignore();
		execute_cmd(cmd);
	}
}



void Controller::execute_cmd(int cmd) {
	if (cmd == 1) { // Customer
		int sub_cmd = 0;
		cout << "\n\n(1) Browse a catalog of robot models\n";
		cin >> sub_cmd;
		cin.ignore();
		if (sub_cmd == 1) {
			if (shop.number_of_robot_models() != 0) {
				view.get_catalog_list();
			}
			else {
				cout << "\n\nNothing!\n";
			}
		}
		else {
				cout << "*** Invalid command ***\n\n";
		}
	}
	else if (cmd == 2) { // Product Manager
		int sub_cmd = 0;
		cout << "\n\n(1) Create a robot part\n";
		cout << "(2) Create a robot model\n";
		cout << "(3) Save Parts\n";
		cout << "(4) Load Parts\n";
		cin >> sub_cmd;
		cin.ignore();

		if (sub_cmd == 1) {
			int input, model_number, max_arms, battery_compartments;
			double power, max_power, power_available, max_energy, cost;
			string name, description, image_filename;
			
			cout << "\n(1) Head\n";
			cout << "(2) Torso\n";
			cout << "(3) Arm\n";
			cout << "(4) Locomotor\n";
			cout << "(5) Battery\n\n";

			cout << "Choose a robot part you want to create: ";
			cin >> input;
			cin.ignore();

			if (input == 1) {
				cout << "Name: ";
				getline(cin, name);

				cout << "Model Number: ";
				cin >> model_number;
				cin.ignore();

				cout << "Cost: ";
				cin >> cost;
				cin.ignore();

				cout << "Description: ";
				getline(cin, description);

				cout << "Image filename: ";
				getline(cin, image_filename);

				cout << "Power: ";
				cin >> power;
				cin.ignore();

				shop.add_head(Head(name, model_number, cost, description, image_filename, power));
			}
			else if (input == 2) {
				cout << "Name: ";
				getline(cin, name);

				cout << "Model Number: ";
				cin >> model_number;
				cin.ignore();

				cout << "Cost: ";
				cin >> cost;
				cin.ignore();

				cout << "Description: ";
				getline(cin, description);

				cout << "Image filename: ";
				getline(cin, image_filename);

				cout << "Battery compartments: ";
				cin >> battery_compartments;
				cin.ignore();

				cout << "Max arms: ";
				cin >> max_arms;
				cin.ignore();

				shop.add_torso(Torso(name, model_number, cost, description, image_filename, battery_compartments, max_arms));
			}
			else if (input == 3) {
				cout << "Name: ";
				getline(cin, name);

				cout << "Model Number: ";
				cin >> model_number;
				cin.ignore();

				cout << "Cost: ";
				cin >> cost;
				cin.ignore();

				cout << "Description: ";
				getline(cin, description);

				cout << "Image filename: ";
				getline(cin, image_filename);

				cout << "Max power: ";
				cin >> max_power;
				cin.ignore();

				shop.add_arm(Arm(name, model_number, cost, description, image_filename, max_power));
			}
			else if (input == 4) {
				cout << "Name: ";
				getline(cin, name);

				cout << "Model Number: ";
				cin >> model_number;
				cin.ignore();

				cout << "Cost: ";
				cin >> cost;
				cin.ignore();

				cout << "Description: ";
				getline(cin, description);

				cout << "Image filename: ";
				getline(cin, image_filename);

				cout << "Max power: ";
				cin >> max_power;
				cin.ignore();

				shop.add_locomotor(Locomotor(name, model_number, cost, description, image_filename, max_power));
			}
			else if (input == 5) {
				cout << "Name: ";
				getline(cin, name);

				cout << "Model Number: ";
				cin >> model_number;
				cin.ignore();

				cout << "Cost: ";
				cin >> cost;
				cin.ignore();

				cout << "Description: ";
				getline(cin, description);

				cout << "Image filename: ";
				getline(cin, image_filename);

				cout << "Power available: ";
				cin >> power_available;
				cin.ignore();

				cout << "Max energy: ";
				cin >> max_energy;
				cin.ignore();

				shop.add_battery(Battery(name, model_number, cost, description, image_filename, power_available, max_energy));
			}
			else {
				cerr << "*** Invalid input ***\n\n";
			}
		}
		else if (sub_cmd == 2) {
			if (shop.number_of_heads() != 0 && shop.number_of_torsos() != 0 && shop.number_of_arms() != 0 && shop.number_of_locomotors() != 0 && shop.number_of_batteries() != 0) {
				view.get_parts_list();
			}
			else {
				cout << "\n\nInsufficient number of parts.\n\n";
			}
		}
	else if (cmd == 3) { // Sales Associate
		int sub_cmd = 0;
		cout << "\n\n(1) Add new customer\n";
		cout << "(2) Order a robot\n";
		cin >> sub_cmd;
		cin.ignore();
		
		if (sub_cmd == 1) {
			int customer_number;
			string name, phone_number, email_address;

			cout << "Name: ";
			cin.ignore();
			getline(cin, name);

			cout << "Customer number: ";
			cin >> customer_number;
			cin.ignore();

			cout << "Phone number: ";
			cin.ignore();
			getline(cin, phone_number);

			cout << "Email address: ";
			cin.ignore();
			getline(cin, email_address);

			Customer customer(name, customer_number, phone_number, email_address);

			shop.add_customer(customer);
		}
		else if (sub_cmd == 2) {
			int order_number, quantity, status, customer_number, employee_number, model_number;
	  		string date;

			if (shop.number_of_robot_models() != 0) {
				
				view.get_catalog_list();

				cout << "Order number: ";
				cin >> order_number;
				cin.ignore();

				cout << "Date: ";
				getline(cin, date);

				cout << "Customer number: ";
				cin >> customer_number;
				cin.ignore();

				cout << "Employee number: ";
				cin >> employee_number;
				cin.ignore();

				cout << "Model number: ";
				cin >> model_number;
				cin.ignore();

				cout << "Quantity: ";
				cin >> quantity;
				cin.ignore();

				cout << "Status: ";
				cin >> status;
				cin.ignore();

				shop.create_order(order_number, date, customer_number, employee_number, model_number, quantity, status);
			}
			else {
				cout << "\n\nInsufficient number of robot models.\n\n";
			}
		//else {
		//	cout << "*** Invalid command ***\n\n";
		//}
	}
	else if (cmd == 4) { // Pointed-haired Boss
		int sub_cmd = 0;
		cout << "\n\n(1) Add new sales associate\n";
		cin >> sub_cmd;
		cin.ignore();
		
		if (sub_cmd == 1) {
			int employee_number;
			string name;

			cout << "Name: ";
			cin.ignore();
			getline(cin, name);

			cout << "Customer number: ";
			cin >> employee_number;
			cin.ignore();

			Sales_associate sales_associate(name, employee_number);

			shop.add_sales_associate(sales_associate);
		}
		else
		{
			cout << "*** Invalid command ***\n\n";
		}
	}
	else if (cmd == 0) { // Exit

	}
	else {
		cerr << "*** Invalid command ***\n\n";
	}
	}
}
}



















