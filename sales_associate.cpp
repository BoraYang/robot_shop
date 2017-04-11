#include "sales_associate.h"

string Sales_associate::to_string() {
	string return_string = "\nSales Associate >>\n\nName: " + name + "\n" + "Employee number: " + std::to_string(employee_number) + "\n\n";
	return return_string;
}