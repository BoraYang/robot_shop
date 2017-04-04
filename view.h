#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <string>
#include "shop.h"

using namespace std;

class View {
	public :
		View (Shop& shop) : shop(shop) {}
		string get_menu();
		void get_parts_list();
		void get_catalog_list();
	private:
		Shop& shop;
};

#endif