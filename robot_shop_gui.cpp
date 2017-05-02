#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_ask.H>
#include <FL/Fl_Text_Display.H>


using namespace std;


void show_part_dialog_CB(Fl_Widget* w, void* p);
void hide_part_dialog_CB(Fl_Widget* w, void* p);
void show_head_dialog_CB(Fl_Widget* w, void* p);
void hide_head_dialog_CB(Fl_Widget* w, void* p);
void create_head_CB(Fl_Widget* w, void* p);
void show_arm_dialog_CB(Fl_Widget* w, void* p);
void hide_arm_dialog_CB(Fl_Widget* w, void* p);
void create_arm_CB(Fl_Widget* w, void* p);
void show_torso_dialog_CB(Fl_Widget* w, void* p);
void hide_torso_dialog_CB(Fl_Widget* w, void* p);
void create_torso_CB(Fl_Widget* w, void* p);
void show_locomotor_dialog_CB(Fl_Widget* w, void* p);
void hide_locomotor_dialog_CB(Fl_Widget* w, void* p);
void create_locomotor_CB(Fl_Widget* w, void* p);
void show_battery_dialog_CB(Fl_Widget* w, void* p);
void hide_battery_dialog_CB(Fl_Widget* w, void* p);
void create_battery_CB(Fl_Widget* w, void* p);
void list_parts_CB(Fl_Widget* w, void* p);
void show_model_dialog_CB(Fl_Widget* w, void* p);
void hide_model_dialog_CB(Fl_Widget* w, void* p);
void create_model_CB(Fl_Widget* w, void* p);
void create_sales_associate_CB(Fl_Widget* w, void* p);
void show_sales_associate_dialog_CB(Fl_Widget* w, void* p);
void hide_sales_associate_dialog_CB(Fl_Widget* w, void* p);
void create_customer_CB(Fl_Widget* w, void* p);
void show_customer_dialog_CB(Fl_Widget* w, void* p);
void hide_customer_dialog_CB(Fl_Widget* w, void* p);
void create_order_dialog_CB(Fl_Widget* w, void* p);
void list_models_dialog_CB(Fl_Widget* w, void* p);
void show_order_dialog_CB(Fl_Widget* w, void* p);
void hide_order_dialog_CB(Fl_Widget* w, void* p);


// /////////////////////////////////
//		     C U S T O M E R
// /////////////////////////////////

class Customer {
	public:
	  Customer(string _name, int _customer_number, string _phone_number, string _email_address)
	  		   : name(_name), customer_number(_customer_number), phone_number(_phone_number), email_address(_email_address) {}	 
	  string to_string();
	  int get_customer_number();
	  void save_customer(ostream& ofs);
	private:
	  string name;
	  int customer_number;
	  string phone_number;
	  string email_address;
};

string Customer::to_string() {
	string return_string = "\nBeloved Customer >>\n\nName :" + name + "\nCustomer number: " + std::to_string(customer_number) + "\nPhone number: " + phone_number + "\nEmail address : " + email_address + "\n\n";
	return return_string;
}

int Customer::get_customer_number() {
    return customer_number;
}

void Customer::save_customer(ostream& ofs) {
    ofs << name << "," << customer_number << "," << phone_number << "," << email_address << endl;
}

// /////////////////////////////////
//	 S A L E S  A S S O C I A T E
// /////////////////////////////////

class Sales_associate {
	public:
		Sales_associate(string _name, int _employee_number) : name(_name), employee_number(_employee_number) {}
		string to_string();
		int get_employee_number();
		void save_sales_associate(ostream& ofs);
	private:
		string name;
		int employee_number;
};

string Sales_associate::to_string() {
	string return_string = "\nSales Associate >>\n\nName: " + name + "\n" + "Employee number: " + std::to_string(employee_number) + "\n\n";
	return return_string;
}

int Sales_associate::get_employee_number() {
    return employee_number;
}

void Sales_associate::save_sales_associate(ostream& ofs) {
    ofs << name << "," << employee_number << endl;
}

// /////////////////////////////////
//			      R O B O T
// /////////////////////////////////

class Robot_part {
protected:
    string name;
    int model_number;
    double cost;
    string description;
    string image_filename;
public:
    Robot_part(string _name, int _model_number, double _cost, string _description, string _image_filename);
    string get_name();
    int get_model_number();
    double get_cost();
    string get_description();
    string get_image_filename();
    void save_part(ostream& ofs);
};

class Head : public Robot_part{
private:
    double power;
public:
    Head(string _name, int _model_number, double _cost, string _description, string _image_filename, double _power);
    string to_string();
    double get_power();
    void save_head(ostream& ofs);
};

class Torso : public Robot_part{
private:
    int battery_compartments;
    int max_arms;
public:
    Torso(string _name, int _model_number, double _cost, string _description, string _image_filename, int _battery_compartments, int _max_arms);
    string to_string();
    int get_battery_compartments();
    int get_max_arms();    
    void save_torso(ostream& ofs);
};

class Arm : public Robot_part{
private:
    double max_power;
public:
    Arm(string _name, int _model_number, double _cost, string _description, string _image_filename, double _max_power);
    string to_string();
    double get_max_power();
    void save_arm(ostream& ofs);
};

class Locomotor : public Robot_part{
private:
    double max_power;
public:
    Locomotor(string _name, int _model_number, double _cost, string _description, string _image_filename, double _max_power);
    string to_string();
    double get_max_power();
    void save_locomotor(ostream& ofs);
};

class Battery : public Robot_part{
private:
    double power_availible;
    double max_energy;
public:
    Battery(string _name, int _model_number, double _cost, string _description, string _image_filename, double _power_availible, double _max_energy);
    string to_string();
    double get_power_availible();
    double get_max_energy();
    void save_battery(ostream& ofs);
};

class Robot_model{
private:
    string name;
    int model_number;
    Head head;
    Torso torso;
    Arm arm;
    Locomotor locomotor;
    Battery battery;
public:
    Robot_model(string _name, int _model_number, Head _head, Torso _torso, Arm _arm, Locomotor _locomotor, Battery _battery);
    string to_string();
    double cost();
    int get_model_number();
    void save_robot_model(ostream& ofs);
};

Robot_part::Robot_part(string _name, int _model_number, double _cost, string _description, string _image_filename)
                         : name(_name), model_number(_model_number), cost(_cost), description(_description), image_filename(_image_filename) {}



string Robot_part::get_name() {
    return name;
}

int Robot_part::get_model_number() {
    return model_number;
}

double Robot_part::get_cost() {
    return cost;
}

string Robot_part::get_description() {
    return description;
}

string Robot_part::get_image_filename() {
    return image_filename;
}

void Robot_part::save_part(ostream& ofs) {
    ofs << name << "," << model_number << "," << cost << "," << description << "," << image_filename << ",";
}




Head::Head(string _name, int _model_number, double _cost, string _description, string _image_filename, double _power) :
           Robot_part(_name, _model_number, _cost, _description, _image_filename), power(_power) {}


string Head::to_string() {
    string head = "Name: " + name + "\n" + "Model number: " + std::to_string(model_number) + "\n" + "Cost: " + std::to_string(cost) + "\n" +
                "Description: " + description + "\n" + "Image filename: " + image_filename + "\n" + "Power: " + std::to_string(power) + "\n\n";

    return head;
}

double Head::get_power() {
    return power;
}

void Head::save_head(ostream& ofs) {
    save_part(ofs);
    ofs << power << endl;
}




Torso::Torso(string _name, int _model_number, double _cost, string _description, string _image_filename, int _battery_compartments, int _max_arms) :
             Robot_part(_name, _model_number, _cost, _description, _image_filename), battery_compartments(_battery_compartments), max_arms(_max_arms) {}



string Torso::to_string() {
    string torso = "Name: " + name + "\n" + "Model number: " + std::to_string(model_number) + "\n" + "Cost: " + std::to_string(cost) + "\n" +
                 "Description: " + description + "\n" + "Image filename: " + image_filename + "\n" + "Battery compartments: " +
                 std::to_string(battery_compartments) + "\n" + "Max arms: " + std::to_string(max_arms) + "\n\n";

    return torso;
}

int Torso::get_battery_compartments() {
    return battery_compartments;
}

int Torso::get_max_arms() {
    return max_arms;
}

void Torso::save_torso(ostream& ofs)
{
    save_part(ofs);
    ofs << battery_compartments << "," << max_arms << endl;
}



Arm::Arm(string _name, int _model_number, double _cost, string _description, string _image_filename, double _max_power)
           : Robot_part(_name, _model_number, _cost, _description, _image_filename), max_power(_max_power) {}



string Arm::to_string()
{
    string arm = "Name: " + name + "\n" + "Model number: " + std::to_string(model_number) + "\n" + "Cost: " + std::to_string(cost) + "\n" +
               "Description: " + description + "\n" + "Image filename: " + image_filename + "\n" + "Max power: " + std::to_string(max_power) + "\n\n";

    return arm;
}

double Arm::get_max_power() {
    return max_power;
}

void Arm::save_arm(ostream& ofs)
{
    save_part(ofs);
    ofs << max_power << endl;
}




Locomotor::Locomotor(string _name, int _model_number, double _cost, string _description,
                       string _image_filename, double _max_power) : Robot_part(_name, _model_number,
                       _cost, _description, _image_filename), max_power(_max_power) {}




string Locomotor::to_string()
{
    string locomotor = "Name: " + name + "\n" + "Model number: " + std::to_string(model_number) + "\n" + "Cost: " + std::to_string(cost) + "\n" +
                     "Description: " + description + "\n" + "Image filename: " + image_filename + "\n" + "Max power: " + std::to_string(max_power) + "\n\n";

    return locomotor;
}

double Locomotor::get_max_power() {
    return max_power;
}

void Locomotor::save_locomotor(ostream& ofs) {
    save_part(ofs);
    ofs << max_power << endl;
}



Battery::Battery(string _name, int _model_number, double _cost, string _description, string _image_filename, 
                   double _power_availible, double _max_energy) : Robot_part(_name, _model_number,
                   _cost, _description, _image_filename), power_availible(_power_availible), max_energy(_max_energy) {}



string Battery::to_string()
{
  string battery = "Name: " + name + "\n" + "Model number: " + std::to_string(model_number) + "\n" + "Cost: " + std::to_string(cost) + "\n" +
                   "Description: " + description + "\n" + "Image filename: " + image_filename + "\n" +
                   "Power availible: " + std::to_string(power_availible) + "\n" + "Max energy: " + std::to_string(max_energy) + "\n\n";

    return battery;
}

double Battery::get_power_availible() {
    return power_availible;
}

double Battery::get_max_energy() {
    return max_energy;
}

void Battery::save_battery(ostream& ofs) {
    save_part(ofs);
    ofs << power_availible << "," << max_energy << endl;
}



Robot_model::Robot_model(string _name, int _model_number, Head _head, Torso _torso, Arm _arm, Locomotor _locomotor, Battery _battery) : 
                           name(_name), model_number(_model_number), head(_head), torso(_torso), arm(_arm), locomotor(_locomotor), battery(_battery) {}


string Robot_model::to_string() {
  string robot_model = "Name: " + name + "\n" + "Model number: " + std::to_string(model_number) + "\n\n" + head.to_string() + torso.to_string() +
                        arm.to_string() + locomotor.to_string() + battery.to_string() + "\n";

  return robot_model;
}


void Robot_model::save_robot_model(ostream& ofs) {
    ofs << name << "," << model_number << "," << torso.get_model_number() << "," << head.get_model_number() << "," << locomotor.get_model_number() << "," << arm.get_model_number() <<
        "," << battery.get_model_number() << endl;
}

int Robot_model::get_model_number() {
    return model_number;
}

double Robot_model::cost() {
  double cost = 0;
  cost = head.get_cost() + torso.get_cost() + arm.get_cost() + locomotor.get_cost() + battery.get_cost();
  return cost;
}


// /////////////////////////////////
//			      O R D E R
// /////////////////////////////////

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
	  	void save_order(ostream& ofs);

	private:
	  	int order_number;
	  	string date;
	  	Customer customer;
	  	Sales_associate sales_associate;
	  	Robot_model robot_model;
	  	int quantity;
	  	int status;
};

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

void Order::save_order(ostream& ofs) {
    ofs << order_number << "," << date << "," << robot_model.get_model_number() << "," << quantity << "," << customer.get_customer_number() << "," << status << "," << sales_associate.get_employee_number() << endl;
}


// /////////////////////////////////
//			  S H O P 
// /////////////////////////////////

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
	void add_order(Order order);


	Head get_head(int head_index);
	Torso get_torso(int torso_index);
	Arm get_arm(int arm_index);
	Locomotor get_locomotor(int locomotor_index);
	Battery get_battery(int battery_index);
	Robot_model get_robot_model(int robot_model_index);
	Customer get_customer(int customer_index);
	Sales_associate get_sales_associate(int sales_associate_index);
	Order get_order(int order_index);

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
	int number_of_customers();
	int number_of_orders();
	int number_of_sales_associates();


	void get_part(int index);
	//void create_order(int order_number, string date, int customer_number, int employee_number, int model_number, int quantity, int status);

	string shop_to_string();
	void save_shop(ostream& ofs);

  Shop* get_shop();

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

void Shop::add_order(Order order) {
	orders.push_back(order);
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

Robot_model Shop::get_robot_model(int model_index) {
	return robot_models[model_index];
}

Customer Shop::get_customer(int customer_index) {
	return customers[customer_index];
}

Sales_associate Shop::get_sales_associate(int sales_associate_index) {
	return sales_associates[sales_associate_index];
}

Order Shop::get_order(int order_index) {
	return orders[order_index];
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

string Shop::robot_model_to_string(int robot_model_index) {
	return robot_models[robot_model_index].to_string();
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

int Shop::number_of_customers() {
	return customers.size();
}

int Shop::number_of_orders() {
	return orders.size();
}

int Shop::number_of_sales_associates() {
	return sales_associates.size();
}



string Shop::shop_to_string()
{
	stringstream os;

	for (int i = 0; i < number_of_heads(); i++) {
		os << head_to_string(i);
	}

	for (int i = 0; i < number_of_torsos(); i++) {
		os << torso_to_string(i);
	}

	for (int i = 0; i < number_of_arms(); i++) {
		os << arm_to_string(i);
	}
	
	for (int i = 0; i < number_of_locomotors(); i++) {
		os << locomotor_to_string(i);
	}
	
	for (int i = 0; i < number_of_batteries(); i++) {
		os << battery_to_string(i);
	}

	return os.str();
}




void Shop::save_shop(ostream& ofs) {
	for (int i = 0; i < number_of_heads(); i++) {
		(get_head(i)).save_head(ofs);
		ofs << "-1" << endl;
	}

	for (int i = 0; i < number_of_torsos(); i++) {
		(get_torso(i)).save_torso(ofs);
		ofs << "-1" << endl;
	}

	for (int i = 0; i < number_of_arms(); i++) {
		(get_arm(i)).save_arm(ofs);
		ofs << "-1" << endl;
	}

	for (int i = 0; i < number_of_locomotors(); i++) {
		(get_locomotor(i)).save_locomotor(ofs);
		ofs << "-1" << endl;
	}

	for (int i = 0; i < number_of_batteries(); i++) {
		(get_battery(i)).save_battery(ofs);
		ofs << "-1" << endl;
	}

	for (int i = 0; i < number_of_robot_models(); i++) {
		(get_robot_model(i)).save_robot_model(ofs);
		ofs << "-1" << endl;
	}

	for(int i = 0; i < number_of_customers(); i++){
        (get_customer(i)).save_customer(ofs);
        ofs << "-1" << endl;
    }
    
    for(int i = 0; i < number_of_sales_associates(); i++){
        (get_sales_associate(i)).save_sales_associate(ofs);
        ofs << "-1" << endl;
    }

    for(int i = 0; i < number_of_orders(); i++){
        (get_order(i)).save_order(ofs);
        ofs << "-1" << endl;
    }
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



// /////////////////////////////////
//			  V I E W 
// /////////////////////////////////

class View {
	public :
		View (Shop& shop) : shop(shop) {}
		string get_menu();
		void get_parts_list();
		void get_catalog_list();
	private:
		Shop& shop;
};

string View::get_menu() {
	string menu = R"(

********************************
CSE1325 Robbie Robot Shop System
********************************

	Users
	______
	(1) Customer
	(2) Product Manager
	(3) Sales Associate
	(4) Pointed-haired Boss


	Utility
	_______
	(0) Exit

)";
	return menu;
}



void View::get_parts_list() {
	cout << "\n\n## Head ##\n";
	for (int i = 0; i < shop.number_of_heads(); i++) {
		cout << "Part number: " << i << "\n" << shop.head_to_string(i) << "\n";
	}
	shop.get_part(1);

	cout << "\n\n## Torso ##\n";
	for (int i = 0; i < shop.number_of_torsos(); i++)	{
		cout << "Part number: " << i << "\n" << shop.torso_to_string(i) << "\n";
	}
	shop.get_part(2);

	cout << "\n\n## Arm ##\n";
	for (int i = 0; i < shop.number_of_arms(); i++)	{
		cout << "Part number: " << i << "\n" << shop.arm_to_string(i) << "\n";
	}
	shop.get_part(3);

	cout << "\n\n## Locomotor ##\n";
	for (int i = 0; i < shop.number_of_locomotors(); i++)	{
		cout << "Part number: " << i << "\n" << shop.locomotor_to_string(i) << "\n";
	}
	shop.get_part(4);

	cout << "\n\n## Battery ##\n";
	for (int i = 0; i < shop.number_of_batteries(); i++)	{
		cout << "Part number: " << i << "\n" << shop.battery_to_string(i) << "\n";
	}
	shop.get_part(5);
}


void View::get_catalog_list() {
	for (int i = 0; i < shop.number_of_robot_models(); i++) {
		cout << shop.robot_model_to_string(i) << "\n\n";
	}
}



// /////////////////////////////////
//			      S A V E
// /////////////////////////////////

class Save {
private:
    Shop shop;
public:
    Save();
    void save(string filename);
    void open(string filename);
    void open_head(string s);
    void open_torso(string s);
    void open_arm(string s);
    void open_locomotor(string s);
    void open_battery(string s);
    void open_model(string s);
    void open_customer(string s);
    void open_sales_associate(string s);
    void open_order(string s);
    Shop* get_shop();
};

Save::Save(){}

void Save::save(string filename) {
    ofstream ofs(filename.c_str());
	  shop.save_shop(ofs);    
}

void Save::open(string filename) {
    string s;
    ifstream ifs(filename.c_str());

    while(1){
        if(!getline(ifs, s)) break;
        if(s == "-1") break;
        open_head(s);
    }

    while(1){
        if(!getline(ifs, s)) break;
        if(s == "-1") break;
        open_torso(s);
    }

    while(1){
        if(!getline(ifs, s)) break;
        if(s == "-1") break;
        open_arm(s);
    }

    while(1){
        if(!getline(ifs, s)) break;
        if(s == "-1") break;
        open_locomotor(s);
    }
    while(1){
        if(!getline(ifs, s)) break;
        if(s == "-1") break;
        open_battery(s);
    }

    while(1){
        if(!getline(ifs, s)) break;
        if(s == "-1") break;
        open_model(s);
    }

    while(1){
        if(!getline(ifs, s)) break;
        if(s == "-1") break;
        open_customer(s);
    }
    while(1){
        if(!getline(ifs, s)) break;
        if(s == "-1") break;
        open_sales_associate(s);
    }

    while(1){
        if(!getline(ifs, s)) break;
        if(s == "-1") break;
        open_order(s);
    }

}
void Save::open_head(string s) {
    vector<string> data;
    istringstream iss(s);

    while(iss){
        if(!getline(iss, s, ',')) break;
        data.push_back(s);
    }

    string name = data.at(0);
    int model_number = stoi(data.at(1));
    double cost = stod(data.at(2));
    string description = data.at(3);
    string image_filename = data.at(4);
    double power = stod(data.at(5));
    Head head(name, model_number, cost, description, image_filename, power);
    shop.add_head(head);
    data.clear();
}


void Save::open_torso(string s) {
    vector<string> data;
    istringstream iss(s);

    while(iss){
        if(!getline(iss, s, ',')){
            break;
        }
        data.push_back(s);
    }

    string name = data.at(0);
    int model_number = stoi(data.at(1));
    double cost = stod(data.at(2));
    string description = data.at(3);
    string image_filename = data.at(4);
    int battery_compartments = stoi(data.at(5));
    int max_arms = stoi(data.at(6));
    Torso torso(name, model_number, cost, description, image_filename, battery_compartments, max_arms);
    shop.add_torso(torso);
    data.clear();

}


void Save::open_arm(string s) {
    vector<string> data;
    istringstream iss(s);
    while(iss){
        if(!getline(iss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    string name = data.at(0);
    int model_number = stoi(data.at(1));
    double cost = stod(data.at(2));
    string description = data.at(3);
    string image_filename = data.at(4);
    double max_power = stod(data.at(5));
    Arm arm(name, model_number, cost, description, image_filename, max_power);
    shop.add_arm(arm);
    data.clear();

}


void Save::open_locomotor(string s) {
    vector<string> data;
    istringstream iss(s);

    while(iss){
        if(!getline(iss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    string name = data.at(0);
    int model_number = stoi(data.at(1));
    double cost = stod(data.at(2));
    string description = data.at(3);
    string image_filename = data.at(4);
    double max_power = stod(data.at(5));
    Locomotor locomotor(name, model_number, cost, description, image_filename, max_power);
    shop.add_locomotor(locomotor);
    data.clear();
}

void Save::open_battery(string s) {
    vector<string> data;
    istringstream iss(s);

    while(iss){
        if(!getline(iss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    string name = data.at(0);
    int model_number = stoi(data.at(1));
    double cost = stod(data.at(2));
    string description = data.at(3);
    string image_filename = data.at(4);
    double power_avaible = stod(data.at(5));
    double max_energy = stod(data.at(6));
    Battery battery(name, model_number, cost, description, image_filename, power_avaible, max_energy);
    shop.add_battery(battery);
    data.clear();
}

void Save::open_model(string s) {
    vector<string> data;
    istringstream iss(s);

    while(iss){
        if(!getline(iss, s, ',')){
            break;
        }
        data.push_back(s);
    }
    string name = data.at(0);
    int model_number = stoi(data.at(1));
    double torso_number = stod(data.at(2));
    for(int i = 0; i < shop.number_of_torsos(); i++){
        if(torso_number == shop.get_torso(i).get_model_number()){
            torso_number = i;
            break;
        }
    }
    double head_number = stod(data.at(3));
    for(int i = 0; i < shop.number_of_heads(); i++){
        if(head_number == shop.get_head(i).get_model_number()){
            head_number = i;
            break;
        }
    }
    double locomotor_number = stod(data.at(4));
    for(int i = 0; i < shop.number_of_locomotors(); i++){
        if(locomotor_number == shop.get_locomotor(i).get_model_number()){
            locomotor_number = i;
            break;
        }
    }
    double arm_number = stod(data.at(5));
    for(int i = 0; i < shop.number_of_arms(); i++){
        if(arm_number == shop.get_arm(i).get_model_number()){
            arm_number = i;
            break;
        }
    }
    double battery_number = stod(data.at(6));
    for(int i = 0; i < shop.number_of_batteries(); i++){
        if(battery_number == shop.get_battery(i).get_model_number()){
            battery_number = i;
            break;
        }
    }
    Robot_model robot_model(name, model_number, shop.get_head(head_number), shop.get_torso(torso_number), shop.get_arm(arm_number),
                            shop.get_locomotor(locomotor_number), shop.get_battery(battery_number));
    shop.add_robot_model(robot_model);
    data.clear();
}


void Save::open_customer(string s) {
    vector<string> data;
    istringstream iss(s);

    while(iss){
        if(!getline(iss, s, ',')) break;
        data.push_back(s);
    }

    string name = data.at(0);
    int customer_number = stoi(data.at(1));
    string phone_number = data.at(2);
    string email_address = data.at(3);
    Customer customer(name, customer_number, phone_number, email_address);
    shop.add_customer(customer);
    data.clear();
}


void Save::open_sales_associate(string s) {
    vector<string> data;
    istringstream iss(s);

    while(iss){
        if(!getline(iss, s, ',')) break;
        data.push_back(s);
    }

    string name = data.at(0);
    int employee_number = stoi(data.at(1));
    Sales_associate sales_associate(name, employee_number);
    shop.add_sales_associate(sales_associate);
    data.clear();
}


void Save::open_order(string s) {
    vector<string> data;
    istringstream iss(s);

    while(iss){
        if(!getline(iss, s, ',')) break;
        data.push_back(s);
    }

    int order_number = stoi(data.at(0));

    string date = data.at(1);

    int robot_model_number = stoi(data.at(2));
    for(int i = 0; i < shop.number_of_robot_models(); i++){
        if(robot_model_number == shop.get_robot_model(i).get_model_number()){
            robot_model_number = i;
            break;
        }
    }

    int quantity = stoi(data.at(3));

    int customer_number = stoi(data.at(4));
    for(int i = 0; i < shop.number_of_customers(); i++){
        if(customer_number == shop.get_customer(i).get_customer_number()){
            customer_number = i;
            break;
        }
    }

    int status = stoi(data.at(5));
    int sales_associate_number = stoi(data.at(6));
    for(int i = 0; i < shop.number_of_sales_associates(); i++){
        if(sales_associate_number == shop.get_sales_associate(i).get_employee_number()){
            sales_associate_number = i;
            break;
        }
    }

    Order order(order_number, date, shop.get_customer(customer_number), shop.get_sales_associate(sales_associate_number),
                shop.get_robot_model(robot_model_number), quantity, status);

    shop.add_order(order);
    data.clear();
}

Shop* Save::get_shop() {
  return &shop;
}

Save save;

// /////////////////////////////////
//	   	  C O N T R O L L E R
// /////////////////////////////////

class Controller {
	public:
		Controller (View& view, Shop& shop) : view(view), shop(shop) {}
		void gui();
		void execute_cmd(int cmd);
	private:
		View& view;
		Shop& shop;
};

void Controller::gui() {
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
		else if (sub_cmd == 3) {
			//save
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

				Order order(order_number, date, shop.get_customer(customer_number), shop.get_sales_associate(employee_number), shop.get_robot_model(model_number), quantity, status);
				shop.add_order(order);
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

// /////////////////////////////////
//		      W I D G E T S
// /////////////////////////////////

Fl_Window *win;
Fl_Menu_Bar *menubar;

Controller *controller_p;

// /////////////////////////////////
//		  P A R T   D I A L O G
// /////////////////////////////////

class part_dialog {
	public :
	part_dialog() {
		dialog = new Fl_Window(600,480,"Robot Parts");

		head_part = new Fl_Button(125, 60, 100, 25, "Head");
		head_part->callback((Fl_Callback *)show_head_dialog_CB, 0);

		torso_part = new Fl_Button(125, 100, 100, 25, "Torso");
		torso_part->callback((Fl_Callback *)show_torso_dialog_CB, 0);

		arm_part = new Fl_Button(125, 140, 100, 25, "Arm");
		arm_part->callback((Fl_Callback *)show_arm_dialog_CB, 0);

		locomotor_part = new Fl_Button(125, 180, 100, 25, "Locomotor");
		locomotor_part->callback((Fl_Callback *)show_locomotor_dialog_CB, 0);

		battery_part = new Fl_Button(125, 220, 100, 25, "Battery");
		battery_part->callback((Fl_Callback *)show_battery_dialog_CB, 0);

		cancel = new Fl_Return_Button(220, 350, 100, 25, "Cancel");
		cancel->callback((Fl_Callback *) hide_part_dialog_CB, 0);

		dialog->end();
    dialog->set_non_modal();
		}

		void show() {
			dialog->show();
		}

		void hide() {
			dialog->hide();
		}
	private :
		Fl_Window *dialog;
		Fl_Button *head_part, *torso_part, *arm_part, *locomotor_part, *battery_part;
    Fl_Return_Button *cancel;
};

part_dialog *part_dl;

void show_part_dialog_CB(Fl_Widget* w, void* p) {
	part_dl->show();
}

void hide_part_dialog_CB(Fl_Widget* w, void* p) {
	part_dl->hide();
}

void Exit_CB (Fl_Widget* w, void* p) { 
  win -> hide();
}



// /////////////////////////////////
//       H E A D  D I A L O G
// /////////////////////////////////

class head_dialog {
  public:
    head_dialog() {
    dialog = new Fl_Window(600, 480, "Robot Part - Head");

    part_name = new Fl_Input(150, 20, 280, 25, "Name: ");

    part_model_number = new Fl_Input(150, 60, 280, 25, "Model Number: ");

    part_cost = new Fl_Input(150, 100, 280, 25, "Cost: ");

    part_description = new Fl_Multiline_Input(150, 140, 280, 75, "Description: ");

    part_image_file_name = new Fl_Input(150, 230, 280, 25, "Image File Name: ");

    part_power = new Fl_Input(150, 270, 280, 25, "Power: ");

    create_part = new Fl_Return_Button(150, 310, 100, 25, "Create");
    create_part->callback((Fl_Callback *)create_head_CB, 0);

    cancel = new Fl_Return_Button(300, 310, 100, 25, "Cancel");
    cancel->callback((Fl_Callback *)hide_head_dialog_CB, 0);

    dialog->end();
    dialog->set_non_modal();
    }

    void show() {
      dialog->show();
    }

    void hide() {
      dialog->hide();
    }

    void clear() {
      part_name->value(NULL);
      part_model_number->value(NULL);
      part_cost->value(NULL);
      part_description->value(NULL);
      part_image_file_name->value(NULL);
      part_power->value(NULL);
    }

    string name() {
      return part_name->value();
    }

    int model_number() {
      return atoi(part_model_number->value());
    }

    double cost() {
      return atof(part_cost->value());
    }

    string description() {
      return part_description->value();
    }

    string image_file_name() {
      return part_image_file_name->value();
    }

    double power() {
      return atof(part_power->value());
    }

  private:
    Fl_Window *dialog;
    Fl_Input *part_name, *part_model_number, *part_cost, *part_description, *part_image_file_name, *part_power;
    Fl_Return_Button *create_part, *cancel;
};

head_dialog *head_dl;

void show_head_dialog_CB(Fl_Widget* w, void* p) {
  head_dl->show();
}

void hide_head_dialog_CB(Fl_Widget* w, void* p) {
  head_dl->hide();
}

void create_head_CB(Fl_Widget* w, void* p)
{
  Head head(head_dl->name(), head_dl->model_number(), head_dl->cost(), head_dl->description(), head_dl->image_file_name(), head_dl->power());
  save.get_shop()->add_head(head);
  fl_message("Head part created!");
  head_dl->clear();
  head_dl->hide();
}



// /////////////////////////////////
//      T O R S O  D I A L O G
// /////////////////////////////////

class torso_dialog {
  public:
    torso_dialog() {
    dialog = new Fl_Window(600, 480, "Robot Part - Torso");

    part_name = new Fl_Input(150, 20, 280, 25, "Name: ");

    part_model_number = new Fl_Input(150, 60, 280, 25, "Model Number: ");

    part_cost = new Fl_Input(150, 100, 280, 25, "Cost:");

    part_description = new Fl_Multiline_Input(150, 140, 280, 75, "Description: ");

    part_image_file_name = new Fl_Input(150, 230, 280, 25, "Image File Name: ");

    part_battery = new Fl_Input(150, 270, 280, 25, "Battery Compartments: ");

    part_max_arms = new Fl_Input(150, 310, 280, 25, "Max Arms: ");

    create_part = new Fl_Return_Button(150, 350, 100, 25, "Create");
    create_part->callback((Fl_Callback *)create_torso_CB, 0);

    cancel = new Fl_Return_Button(300, 350, 100, 25, "Cancel");
    cancel->callback((Fl_Callback *)hide_torso_dialog_CB, 0);

    dialog->end();
    dialog->set_non_modal();
    }

    void show() {
      dialog->show();
    }

    void hide() {
      dialog->hide();
    }

    void clear() {
      part_name->value(NULL);
      part_model_number->value(NULL);
      part_cost->value(NULL);
      part_description->value(NULL);
      part_image_file_name->value(NULL);
      part_battery->value(NULL);
      part_max_arms->value(NULL);
    }

    string name() {
      return part_name->value();
    }

    int model_number() {
      return atoi(part_model_number->value());
    }

    int cost() {
      return atoi(part_cost->value());
    }

    string description() {
      return part_description->value();
    }

    string image_file_name() {
      return part_image_file_name->value();
    }

    int battery() {
      return atoi(part_battery->value());
    }

    int max_arms() {
      return atoi(part_max_arms->value());
    }

  private:
    Fl_Window *dialog;
    Fl_Input *part_name, *part_model_number, *part_cost, *part_description, *part_image_file_name, *part_battery, *part_max_arms;
    Fl_Return_Button *create_part, *cancel;
};

torso_dialog *torso_dl;

void show_torso_dialog_CB(Fl_Widget* w, void* p) {
  torso_dl->show();
}

void hide_torso_dialog_CB(Fl_Widget* w, void* p) {
  torso_dl->hide();
}

void create_torso_CB(Fl_Widget* w, void* p) {
  Torso torso(torso_dl->name(), torso_dl->model_number(), torso_dl->cost(), torso_dl->description(), torso_dl->image_file_name(), torso_dl->battery(), torso_dl->max_arms());
  save.get_shop()->add_torso(torso);
  fl_message("Torso part created!");
  torso_dl->hide();
  torso_dl->clear();
}



// /////////////////////////////////
//        A R M  D I A L O G
// /////////////////////////////////

class arm_dialog {
  public:
    arm_dialog() {
    dialog = new Fl_Window(600, 480, "Robot Part - Arm");

    part_name = new Fl_Input(150, 20, 280, 25, "Name: ");

    part_model_number = new Fl_Input(150, 60, 280, 25, "Model Number: ");

    part_cost = new Fl_Input(150, 100, 280, 25, "Cost: ");

    part_description = new Fl_Multiline_Input(150, 140, 280, 75, "Description: ");

    part_image_file_name = new Fl_Input(150, 230, 280, 25, "Image File Name: ");

    part_power = new Fl_Input(150, 270, 280, 25, "Max Arm Power: ");

    create_part = new Fl_Return_Button(150, 310, 100, 25, "Create");
    create_part->callback((Fl_Callback *)create_arm_CB, 0);

    cancel = new Fl_Return_Button(300, 310, 100, 25, "Cancel");
    cancel->callback((Fl_Callback *)hide_arm_dialog_CB, 0);

    dialog->end();
    dialog->set_non_modal();
    }

    void show() {
      dialog->show();
    }

    void hide() {
      dialog->hide();
    }

    void clear() {
      part_name->value(NULL);
      part_model_number->value(NULL);
      part_cost->value(NULL);
      part_description->value(NULL);
      part_image_file_name->value(NULL);
      part_power->value(NULL);
    }

    string name() {
      return part_name->value();
    }

    int model_number() {
      return atoi(part_model_number->value());
    }

    int cost() {
      return atoi(part_cost->value());
    }

    string description() {
      return part_description->value();
    }

    string image_file_name() {
      return part_image_file_name->value();
    }

    double power() {
      return atof(part_power->value());
    }

  private:
    Fl_Window *dialog;
    Fl_Input *part_name, *part_model_number, *part_cost, *part_description, *part_image_file_name, *part_power;
    Fl_Return_Button *create_part, *cancel;
};

arm_dialog *arm_dl;

void show_arm_dialog_CB(Fl_Widget* w, void* p) {
  arm_dl->show();
}

void hide_arm_dialog_CB(Fl_Widget* w, void* p) {
  arm_dl->hide();
}

void create_arm_CB(Fl_Widget* w, void* p) {
  Arm arm(arm_dl->name(), arm_dl->model_number(), arm_dl->cost(), arm_dl->description(), arm_dl->image_file_name(), arm_dl->power());
  save.get_shop()->add_arm(arm);
  fl_message("Arm part created!");
  arm_dl->hide();
  arm_dl->clear();
}



// /////////////////////////////////
//  L O C O M O T O R  D I A L O G
// /////////////////////////////////

class locomotor_dialog {
  public:
    locomotor_dialog() {
    dialog = new Fl_Window(600, 480, "Robot Part - Locomotor");

    part_name = new Fl_Input(150, 20, 280, 25, "Name: ");

    part_model_number = new Fl_Input(150, 60, 280, 25, "Model Number: ");

    part_cost = new Fl_Input(150, 100, 280, 25, "Cost: ");

    part_description = new Fl_Multiline_Input(150, 140, 280, 75, "Description: ");

    part_image_file_name = new Fl_Input(150, 230, 280, 25, "Image File Name: ");

    part_power = new Fl_Input(150, 270, 280, 25, "Max Locomotor Power: ");

    create_part = new Fl_Return_Button(150, 310, 100, 25, "Create");
    create_part->callback((Fl_Callback *)create_locomotor_CB, 0);

    cancel = new Fl_Return_Button(300, 310, 100, 25, "Cancel");
    cancel->callback((Fl_Callback *)hide_locomotor_dialog_CB, 0);

    dialog->end();
    dialog->set_non_modal();
    }

    void show() {
      dialog->show();
    }

    void hide() {
      dialog->hide();
    }

    void clear() {
      part_name->value(NULL);
      part_model_number->value(NULL);
      part_cost->value(NULL);
      part_description->value(NULL);
      part_image_file_name->value(NULL);
      part_power->value(NULL);
    }

    string name() {
      return part_name->value();
    }

    int model_number() {
      return atoi(part_model_number->value());
    }

    int cost() {
      return atoi(part_cost->value());
    }

    string description() {
      return part_description->value();
    }

    string image_file_name() {
      return part_image_file_name->value();
    }

    double power() {
      return atof(part_power->value());
    }

  private:
    Fl_Window *dialog;
    Fl_Input *part_name, *part_model_number, *part_cost, *part_description, *part_image_file_name, *part_power;
    Fl_Return_Button *create_part, *cancel;
};

locomotor_dialog *locomotor_dl;

void show_locomotor_dialog_CB(Fl_Widget* w, void* p) {
  locomotor_dl->show();
}

void hide_locomotor_dialog_CB(Fl_Widget* w, void* p) {
  locomotor_dl->hide();
}

void create_locomotor_CB(Fl_Widget* w, void* p) {
  Locomotor locomotor(locomotor_dl->name(), locomotor_dl->model_number(), locomotor_dl->cost(), locomotor_dl->description(), locomotor_dl->image_file_name(), locomotor_dl->power());
  save.get_shop()->add_locomotor(locomotor);
  fl_message("Locomotor part created!");
  locomotor_dl->hide();
  locomotor_dl->clear();
}



// /////////////////////////////////
//    B A T T E R Y  D I A L O G
// /////////////////////////////////

class battery_dialog
{
  public:
    battery_dialog() {
    dialog = new Fl_Window(600, 360, "Robot Part - Battery");

    part_name = new Fl_Input(150, 10, 280, 25, "Name: ");

    part_model_number = new Fl_Input(150, 40, 280, 25, "Model Number: ");

    part_cost = new Fl_Input(150, 70, 280, 25, "Cost: ");

    part_description = new Fl_Multiline_Input(150, 100, 280, 75, "Description: ");

    part_image_file_name = new Fl_Input(150, 180, 280, 25, "File Name: ");

    part_power = new Fl_Input(150, 220, 280, 25, "Power Available: ");

    part_energy = new Fl_Input(150, 250, 280, 25, "Energy Available: ");

    create_part = new Fl_Return_Button(150, 280, 100, 25, "Create");
    create_part->callback((Fl_Callback *)create_battery_CB, 0);

    cancel = new Fl_Return_Button(380, 280, 95, 25, "Cancel");
    cancel->callback((Fl_Callback *)hide_battery_dialog_CB, 0);

    dialog->end();
    dialog->set_non_modal();
    }

    void show() {
      dialog->show();
    }

    void hide() {
      dialog->hide();
    }

    void clear() {
      part_name->value(NULL);
      part_model_number->value(NULL);
      part_cost->value(NULL);
      part_description->value(NULL);
      part_image_file_name->value(NULL);
      part_power->value(NULL);
      part_energy->value(NULL);
    }

    string name() {
      return part_name->value();
    }

    int model_number() {
      return atoi(part_model_number->value());
    }

    int cost() {
      return atoi(part_cost->value());
    }

    string description() {
      return part_description->value();
    }

    string image_file_name() {
      return part_image_file_name->value();
    }

    double power() {
      return atof(part_power->value());
    }

    double energy() {
      return atof(part_energy->value());
    }

  private:
    Fl_Window *dialog;
    Fl_Input *part_name, *part_model_number, *part_cost, *part_description, *part_image_file_name, *part_power, *part_energy;
    Fl_Return_Button *create_part, *cancel;
};

battery_dialog *battery_dl;

void show_battery_dialog_CB(Fl_Widget* w, void* p) {
  battery_dl->show();
}

void hide_battery_dialog_CB(Fl_Widget* w, void* p) {
  battery_dl->hide();
}

void create_battery_CB(Fl_Widget* w, void* p) {
  Battery battery(battery_dl->name(), battery_dl->model_number(), battery_dl->cost(), battery_dl->description(), battery_dl->image_file_name(), battery_dl->power(), battery_dl->energy());
  save.get_shop()->add_battery(battery);
  fl_message("Battery part created!");
  battery_dl->hide();
  battery_dl->clear();
}

void save_CB(Fl_Widget* w, void* p) {
  save.save("data.txt");
}

void open_CB(Fl_Widget* w, void* p) {
  save.open("data.txt");
}


// /////////////////////////////////
//      M O D E L  D I A L O G
// /////////////////////////////////


class model_dialog {
  public:
    model_dialog() {
    dialog = new Fl_Window(600, 480, "Robot Model");

    part_head_index = new Fl_Input(150, 20, 280, 25, "Head Index: ");

    part_torso_index = new Fl_Input(150, 60, 280, 25, "Torso Index: ");

    part_arm_index = new Fl_Input(150, 100, 280, 25, "Arm Index: ");

    part_locomotor_index = new Fl_Input(150, 140, 280, 25, "Locomotor Index: ");

    part_battery_index = new Fl_Input(150, 180, 280, 25, "Battery Index: ");

    part_name = new Fl_Input(150, 220, 220, 25, "Model Name: ");

    part_model_number = new Fl_Input(150, 260, 280, 25, "Model Number: ");

    list_parts = new Fl_Return_Button(80, 300, 100, 25, "List Parts");
    list_parts->callback((Fl_Callback *)list_parts_CB, 0);

    create_part = new Fl_Return_Button(230, 300, 100, 25, "Create");
    create_part->callback((Fl_Callback *)create_model_CB, 0);

    cancel = new Fl_Return_Button(380, 300, 100, 25, "Cancel");
    cancel->callback((Fl_Callback *)hide_model_dialog_CB, 0);

    dialog->end();
    dialog->set_non_modal();
    }

    void show() {
      dialog->show();
    }

    void hide() {
      dialog->hide();
    }

    void clear() {
      part_name->value(NULL);
      part_head_index->value(NULL);
      part_torso_index->value(NULL);
      part_arm_index->value(NULL);
      part_locomotor_index->value(NULL);
      part_battery_index->value(NULL);
    }

    string name() {
      return part_name->value();
    }

    int model_number() {
      return atoi(part_model_number->value());
    }

    int head() {
      return atoi(part_head_index->value());
    }

    int torso() {
      return atoi(part_torso_index->value());
    }

    int arm() {
      return atoi(part_arm_index->value());
    }

    int locomotor() {
      return atoi(part_locomotor_index->value());
    }

    int battery() {
      return atoi(part_battery_index->value());
    }

  private:
    Fl_Window *dialog;
    Fl_Input *part_head_index, *part_torso_index, *part_arm_index, *part_locomotor_index, *part_battery_index, *part_model_number, *part_name;
    Fl_Return_Button *list_parts, *create_part, *cancel;
};

model_dialog *model_dl;

void show_model_dialog_CB(Fl_Widget* w, void* p) {
  model_dl->show();
}

void hide_model_dialog_CB(Fl_Widget* w, void* p) {
  model_dl->hide();
}

void create_model_CB(Fl_Widget* w, void* p) {
  Robot_model model(model_dl->name(), model_dl->model_number(), (save.get_shop()->get_head(model_dl->head()-1)), (save.get_shop()->get_torso(model_dl->torso()-1)), (save.get_shop()->get_arm(model_dl->arm()-1)), (save.get_shop()->get_locomotor(model_dl->locomotor()-1)), (save.get_shop()->get_battery(model_dl->battery()-1)));
  save.get_shop()->add_robot_model(model);
  fl_message("Robot model created!");
  model_dl->hide();
  model_dl->clear();
}

void list_parts_CB(Fl_Widget* w, void* p)
{
  Fl_Window *win = new Fl_Window(640,480);
  stringstream os;

  int i = 0;

  os << "## Heads ##\n";
  for (i = 0; i < save.get_shop()->number_of_heads(); i++) {
    os << "Part index: " << i + 1 << "\n" << save.get_shop()->head_to_string(i) << '\n\n';
  }

  os << "## Torsos ##\n";
  for ( i= 0; i < save.get_shop()->number_of_torsos(); i++) {
    os << "Part index: " << i + 1 << '\n' << save.get_shop()->torso_to_string(i) << '\n\n';
  }

  os << "## Arms ##\n";
  for (i = 0; i < save.get_shop()->number_of_arms(); i++) {
    os << "Part index: " << i + 1 << '\n' << save.get_shop()->arm_to_string(i) << '\n\n';
  }

  os << "## Locomotors ##\n";
  for (i = 0; i < save.get_shop()->number_of_locomotors(); i++) {
    os << "Part index: " << i + 1 << '\n' << save.get_shop()->locomotor_to_string(i) << '\n\n';
  }

  os << "## Batteries ##\n";
  for (i = 0; i < save.get_shop()->number_of_batteries(); i++) {
    os << "Part index: " << i + 1 << '\n' << save.get_shop()->battery_to_string(i) << '\n\n';
  }

  Fl_Text_Buffer *buff = new Fl_Text_Buffer();
  Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640-40, 480-40, "Robot Parts");
  disp->buffer(buff);
  win->resizable(*disp);
  win->show();
  buff->text((os.str()).c_str());
}

class list_models_dialog {
public:
    list_models_dialog() {}

    void show() {
        dialog = new Fl_Window(640, 520);

        robot_model_number = new Fl_Input(400, 480, 210, 25, "Model Number: ");

        for(int i = 0; i < save.get_shop()->number_of_robot_models(); i++) {
            os << save.get_shop()->robot_model_to_string(i) << "\n\n";
        }

        Fl_Text_Buffer *buff = new Fl_Text_Buffer();
        Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640-40, 480-40, "Robot Models");

        disp->buffer(buff);
        dialog->resizable(*disp);
        dialog->show();
        buff->text((os.str()).c_str());
    }

    void hide() {
      dialog->hide();
    }

    void clear() {
      robot_model_number->value(NULL);
    }

    int model_number() {
      return atoi(robot_model_number->value());
    }

private:
    Fl_Window *dialog;
    Fl_Input *robot_model_number;
    Fl_Text_Buffer *buff;
    Fl_Text_Display *disp;
    stringstream os;
};

list_models_dialog *list_models_dl;

void show_list_models_dialog_CB(Fl_Widget* w, void* p) {
    list_models_dl->show();
}

void hide_list_models_dialog_CB(Fl_Widget* w, void* p) {
    list_models_dl->hide();
}


// /////////////////////////////////
//   S A L E S  A S S O C I A T E
// /////////////////////////////////

class sales_associate_dialog {
  public:
    sales_associate_dialog() {
      dialog = new Fl_Window(600, 480, "Sales Associate");

      name_dl = new Fl_Input(150, 20, 280, 25, "Name: ");

      employee_number_dl = new Fl_Input(150, 60, 280, 25, "Employee Number: ");

      create = new Fl_Return_Button(150, 100, 100, 25, "Create");
      create->callback((Fl_Callback *)create_sales_associate_CB, 0);

      cancel = new Fl_Return_Button(300, 100, 100, 25, "Cancel");
      cancel->callback((Fl_Callback *)hide_sales_associate_dialog_CB, 0);

      dialog->end();
      dialog->set_non_modal();
    }

    void show() {
      dialog->show();
    }

    void hide() {
      dialog->hide();
    }

    void clear() {
      name_dl->value(NULL);
      employee_number_dl->value(NULL);
    }

    string name() {
      return name_dl->value();
    }

    int employee_number() {
      return atoi(employee_number_dl->value());
    }

  private:
    Fl_Window *dialog;
    Fl_Input *name_dl, *employee_number_dl;
    Fl_Return_Button *create, *cancel;
};

sales_associate_dialog *sales_associate_dl;


void show_sales_associate_dialog_CB(Fl_Widget* w, void* p) {
  sales_associate_dl->show();
}

void hide_sales_associate_dialog_CB(Fl_Widget* w, void* p) {
  sales_associate_dl->hide();
}

void create_sales_associate_CB(Fl_Widget* w, void* p) {
  Sales_associate sales_associate(sales_associate_dl->name(), sales_associate_dl->employee_number());
  save.get_shop()->add_sales_associate(sales_associate);
  fl_message("Sales associate created!");
  sales_associate_dl->hide();
  sales_associate_dl->clear();
}


// /////////////////////////////////
//         C U S T O M E R
// /////////////////////////////////

class customer_dialog {
    public:
      customer_dialog() {
      dialog = new Fl_Window(600, 480, "Customer");

      name_dl = new Fl_Input(150, 20, 280, 25, "Name: ");

      customer_number_dl = new Fl_Input(150, 60, 280, 25, "Customer Number: ");

      phone_number_dl = new Fl_Input(150, 100, 280, 25, "Phone Number: ");

      email_address_dl = new Fl_Input(150, 140, 280, 25, "Email Address: ");

      create = new Fl_Return_Button(150, 180, 100, 25, "Create");
      create->callback((Fl_Callback *)create_customer_CB, 0);

      cancel = new Fl_Return_Button(300, 180, 100, 25, "Cancel");
      cancel->callback((Fl_Callback *)hide_customer_dialog_CB, 0);

      dialog->end();
      dialog->set_non_modal();
      }

    void show() {
      dialog->show();
    }

    void hide() {
      dialog->hide();
    }

    void clear() {
      name_dl->value(NULL);
      customer_number_dl->value(NULL);
    }

    string name() {
      return name_dl->value();
    }

    int customer_number() {
      return atoi(customer_number_dl->value());
    }

    string phone_number() {
      return phone_number_dl->value();
    }

    string email_address() {
      return email_address_dl->value();
    }

  private:
    Fl_Window *dialog;
    Fl_Input *name_dl, *customer_number_dl, *phone_number_dl, *email_address_dl;
    Fl_Return_Button *create, *cancel;
};

customer_dialog *customer_dl;

void create_customer_CB(Fl_Widget* w, void* p) {
  Customer customer(customer_dl->name(), customer_dl->customer_number(),customer_dl->phone_number(),customer_dl->email_address());
  save.get_shop()->add_customer(customer);
  fl_message("Customer created!");
  customer_dl->hide();
  customer_dl->clear();
}

void show_customer_dialog_CB(Fl_Widget* w, void* p) {
  customer_dl->show();
}

void hide_customer_dialog_CB(Fl_Widget* w, void* p) {
  customer_dl->hide();
}



// /////////////////////////////////
//            O R D E R
// /////////////////////////////////

class order_dialog {
  public:
    order_dialog() {
      dialog = new Fl_Window(600, 480, "Create Order");

      order_number_dl = new Fl_Input(150, 20, 280, 25, "Order Number: ");

      date_dl = new Fl_Input(150, 60, 280, 25, "Date (MMDDYY): ");

      model_index_dl = new Fl_Input(150, 100, 280, 25, "Model Index:");
    
      quantity_dl = new Fl_Input(150, 140, 280, 25,"Quantity: ");

      customer_number_dl = new Fl_Input(150, 180, 280, 25, "Customer number: ");
          
      employee_number_dl = new Fl_Input(150, 220, 280, 25, "Employee number: ");

      list_models_dl = new Fl_Return_Button(250, 260, 150, 25, "List Models");
      list_models_dl->callback((Fl_Callback *)list_models_dialog_CB, 0);

      create = new Fl_Return_Button(150, 300, 100, 25, "Create");
      create->callback((Fl_Callback *)create_order_dialog_CB, 0);

      cancel = new Fl_Return_Button(300, 300, 100, 25, "Cancel");
      cancel->callback((Fl_Callback *)hide_order_dialog_CB, 0);

      dialog->end();
      dialog->set_non_modal();
    }

    void show() {
      dialog->show();
    }

    void hide() {
      dialog->hide();
    }

    void clear() {
      model_index_dl->value(NULL);
      quantity_dl->value(NULL);
      customer_number_dl->value(NULL);
      employee_number_dl->value(NULL);
    }

    int order_number() {
      return atoi(order_number_dl->value());
    }

    string date() {
      return date_dl->value();
    }

    int model_index() {
      return atoi(model_index_dl->value());
    }

    int quantity() {
      return atoi(quantity_dl->value());
    }

    int customer_number() {
      return atoi(customer_number_dl->value());
    }

    int employee_number() {
      return atoi(employee_number_dl->value());
    }
    
  private:
  Fl_Window *dialog;
  Fl_Input *order_number_dl, *date_dl, *model_index_dl, *quantity_dl, *customer_number_dl, *employee_number_dl;
  Fl_Return_Button *list_models_dl, *create, *cancel;
};

order_dialog *order_dl;

void create_order_dialog_CB(Fl_Widget* w, void* p) {
  Order get_order(order_dl->order_number(), order_dl->date(), (save.get_shop()->get_customer(order_dl->customer_number() - 1)), (save.get_shop()->get_sales_associate(order_dl->employee_number() - 1)), (save.get_shop()->get_robot_model(order_dl->model_index()-1)), order_dl->quantity(), 1);
  save.get_shop()->add_order(get_order);
  fl_message("Order created!");
  order_dl->hide();
  order_dl->clear();
}


void list_models_dialog_CB(Fl_Widget* w, void* p) {
    Fl_Window *win = new Fl_Window(600, 480);
    stringstream os;

    for(int i = 0; i< save.get_shop()->number_of_robot_models(); i++) {
        os << save.get_shop()->robot_model_to_string(i) << "\n\n";
    }

    Fl_Text_Buffer *buff = new Fl_Text_Buffer();
    Fl_Text_Display *disp = new Fl_Text_Display(20,20,600-40,480-30, "List of Robot Models");

    disp->buffer(buff);
    win->resizable(*disp);
    win->show();
    buff->text((os.str()).c_str());    
}


void show_order_dialog_CB(Fl_Widget* w, void* p) {
  order_dl->show();
}

void hide_order_dialog_CB(Fl_Widget* w, void* p) {
  order_dl->hide();
}




// /////////////////////////////////
//			       M E N U
// /////////////////////////////////

Fl_Menu_Item menuitems[] = {
  { "&File", 0, 0, 0, FL_SUBMENU },
//    { "&New Shop", 0, (Fl_Callback *) Exit_CB },
    { "&Load Shop", 0, (Fl_Callback *) open_CB },
    { "&Save Shop", 0, (Fl_Callback *) save_CB },
  	{ "E&xit", 0, (Fl_Callback *) Exit_CB },
    { 0 },
/*  { "&Edit", 0, 0, 0, FL_SUBMENU },
    { "Cu&t", 0, (Fl_Callback *) Exit_CB },
    { "&Copy", 0, (Fl_Callback *) Exit_CB },
    { "&Paste", 0, (Fl_Callback *) Exit_CB },
    { "Pre&ferences", 0, (Fl_Callback *) Exit_CB },
    { 0 }, */
  { "&Create", 0, 0, 0, FL_SUBMENU },
  	{ "&Order", 0, (Fl_Callback *) show_order_dialog_CB },
    { "&Customer", 0, (Fl_Callback *) show_customer_dialog_CB },
    { "&Sales Associate", 0, (Fl_Callback *) show_sales_associate_dialog_CB },
    { "Robot &Model", 0, (Fl_Callback *) show_model_dialog_CB },
    { "&Robot Component", 0, (Fl_Callback *) show_part_dialog_CB },
    { 0 },
  { "&View", 0, 0, 0, FL_SUBMENU },
//    { "&Orders", 0, (Fl_Callback *) Exit_CB },
//    { "&Customers", 0, (Fl_Callback *) Exit_CB },
//    { "&Sales Associates", 0, (Fl_Callback *) Exit_CB },
    { "Robot &Models", 0, (Fl_Callback *) show_list_models_dialog_CB },
    { "&Robot Parts", 0, (Fl_Callback *) list_parts_CB },
    { 0 },
/*  { "&Tools", 0, 0, 0, FL_SUBMENU },
    { 0 },
  { "&Help", 0, 0, 0, FL_SUBMENU },
    { 0 }, */
  { 0 }
};


// /////////////////////////////////
//			       M A I N
// /////////////////////////////////

int main() {
  const int X = 480;
  const int Y = 300;

  part_dl = new part_dialog{};
  head_dl = new head_dialog{};
  torso_dl = new torso_dialog{};
  arm_dl = new arm_dialog{};
  locomotor_dl = new locomotor_dialog{};
  battery_dl = new battery_dialog{};
  model_dl = new model_dialog{};
  list_models_dl = new list_models_dialog{};
  sales_associate_dl = new sales_associate_dialog{};
  customer_dl = new customer_dialog{};
  order_dl = new order_dialog{};

	fl_register_images();
	win = new Fl_Window(X, Y, "Robbie Robot Shop");
		win -> color (FL_WHITE);
		menubar = new Fl_Menu_Bar(0, 0, win->w(), 30);
		menubar -> menu(menuitems);
	win->end();
	win->show();
	Shop shop;
	View view(shop);
	Controller controller(view, shop);
	controller_p = &controller;
	return Fl::run();
}