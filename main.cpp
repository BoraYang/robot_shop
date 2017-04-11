#include <iostream>
#include <string>
#include "view.h"
#include "controller.h"
#include "robot.h"
#include "shop.h"
#include "customer.h"
#include "sales_associate.h"
#include "order.h"

using namespace std;

int main() {
	Shop shop;
	View view(shop);
	Controller controller(view, shop);
	controller.cli();
}