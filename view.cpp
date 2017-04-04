#include "view.h"



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
	for (int i = 0; i < shop.number_of_heads(); i++)
	{
		cout << "Part number: " << i << "\n" << shop.head_to_string(i) << "\n";
	}
	shop.get_part(1);

	cout << "\n\n## Torso ##\n";
	for (int i = 0; i < shop.number_of_torsos(); i++)
	{
		cout << "Part number: " << i << "\n" << shop.torso_to_string(i) << "\n";
	}
	shop.get_part(2);

	cout << "\n\n## Arm ##\n";
	for (int i = 0; i < shop.number_of_arms(); i++)
	{
		cout << "Part number: " << i << "\n" << shop.arm_to_string(i) << "\n";
	}
	shop.get_part(3);

	cout << "\n\n## Locomotor ##\n";
	for (int i = 0; i < shop.number_of_locomotors(); i++)
	{
		cout << "Part number: " << i << "\n" << shop.locomotor_to_string(i) << "\n";
	}
	shop.get_part(4);

	cout << "\n\n## Battery ##\n";
	for (int i = 0; i < shop.number_of_batteries(); i++)
	{
		cout << "Part number: " << i << "\n" << shop.battery_to_string(i) << "\n";
	}
	shop.get_part(5);
}



void View::get_catalog_list() {
	for (int i = 0; i < shop.number_of_robot_models(); i++)
	{
		cout << shop.robot_model_to_string(i) << "\n\n";
	}
}