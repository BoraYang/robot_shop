#include "customer.h"

string Customer::to_string() {
	string return_string = "\nBeloved Customer >>\n\nName :" + name + "\nCustomer number: " + std::to_string(customer_number) + "\nPhone number: " + phone_number + "\nEmail address : " + email_address + "\n\n";
	return return_string;
} 