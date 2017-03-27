#include <string>
#include <iostream>

using namespace std;

class Robot_part {
	protected:
		string name;
		string type;
		int model_number;
		double weight;
		double cost;
		string description;
		string image_filename;

	public:
		string get_name() { return name; }
		friend class Shop;

};


class Head : public Robot_part {
	private:
		double power;
	public:
		double get_power() { return power; }
		void set_power(double _power) { power = _power; }
};

class Arm : public Robot_part {
	private:
		double max_power;
	public:
		double get_max_power() { return max_power; }
		void set_max_power(double _max_power) { max_power = _max_power; }
};

class Torso : public Robot_part {
	private:
		int battery_compartments;
		int max_arms;
	public:
		int get_battery_compartments() { return battery_compartments; }
		void set_battery_compartments(int _battery_compartments) { battery_compartments = _battery_compartments; }

		int get_max_arms() { return max_arms ;}
		void set_max_arms(int _max_arms) { max_arms = _max_arms; }
};

class Locomotor : public Robot_part {
	private:
		double max_power;
	public:
		double get_max_power() { return max_power; }
		void set_max_power(double _max_power) { max_power = _max_power; }
};

class Battery : public Robot_part{
	private:
		double power_available;
		double max_energy;
	public:
		double get_power_available() { return power_available; }
		void set_power_available(double _power_available) { power_available = _power_available; }

		double get_max_energy() { return max_energy; }
		void set_max_energy(double _max_energy) { max_energy = _max_energy; }
};

class Shop {
	private:
		Robot_part robot_parts;
		Head head;
		Arm arm;
		Torso torso;
		Locomotor locomotor;
		Battery battery;
	public:
		void create_new_robot_part();
		friend class Robot_part;
};

void Shop::create_new_robot_part() {
		string name, type, description;
		int model_number, battery_compartments, max_arms;
		double weight, cost, power, a_max_power, l_max_power, power_available, max_energy;
		int cmd = -1;

		cout << "\n** Robbie Robot Shop Management System **";
		cout << "\n---------- Creating A New Part ----------\n\n";

		while (cmd != 0) {
			cout << "Name? ";
			getline (cin, name);
			robot_parts.name = name;

			cout << "Type? ";
			getline (cin, type);
			robot_parts.type = type;

			if (type == "Head" || type == "head") {
				cout << "Power? ";
				cin >> power;
				cin.ignore();
				head.set_power(power);
			}
			else if (type == "Arm" || type == "arm") {
				cout << "Max power? ";
				cin >> a_max_power;
				cin.ignore();
				arm.set_max_power(a_max_power);
			}
			else if (type == "Torso" || type == "torso") {
				cout << "Battery compartments? ";
				cin >> battery_compartments;
				cin.ignore();
				torso.set_battery_compartments(battery_compartments);

				cout << "Max Arms? ";
				cin >> max_arms;
				cin.ignore();
				torso.set_max_arms(max_arms);
			}
			else if (type == "Locomotor" || type == "locomotor") {
				cout << "Max power? ";
				cin >> l_max_power;
				cin.ignore();
				locomotor.set_max_power(l_max_power);
			}
			else if (type == "Battery" || type == "battery") {
				cout << "Power available? ";
				cin >> power_available;
				cin.ignore();
				battery.set_power_available(power_available);

				cout << "Max energy? ";
				cin >> max_energy;
				cin.ignore();
				battery.set_max_energy(max_energy);
			}
			else {
				cout << "Wrong type...\n";
				continue;
			}

			cout << "Model number? ";
			cin >> model_number;
			cin.ignore();
			robot_parts.model_number = model_number;

			cout << "Weight? ";
			cin >> weight;
			cin.ignore();
			robot_parts.weight = weight;

			cout << "Cost? ";
			cin >> cost;
			cin.ignore();
			robot_parts.cost = cost;

			cout << "Description? ";
			getline (cin, description);
			robot_parts.description = description;

			cout << "If you want to quit, type 0. Otherwise, type any number except 0.\n";
			cin >> cmd;
			cin.ignore();
		}	
}


int main(void) {
	Shop shop;
	shop.create_new_robot_part();
	return 0;
}
