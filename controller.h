#include <string>
#include <iostream>
#include <vector>
#include "shop.h"
#include "robot.h"
#include "view.h"
#include "customer.h"
#include "sales_associate.h"
#include "order.h"

using namespace std;

class Controller {
	public:
		Controller (View& view, Shop& shop) : view(view), shop(shop) {}
		void cli();
		void execute_cmd(int cmd);
	private:
		View& view;
		Shop& shop;
};