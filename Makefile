CXX = g++ -g
CXXFLAGS = -std=c++11

all: main.o view.o controller.o robot.o customer.o sales_associate.o order.o shop.o
	$(CXX) -o robot_shop main.o view.o controller.o robot.o customer.o sales_associate.o order.o shop.o 

debug: CXXFLAGS += -g
debug: all

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
view.o: view.cpp view.h
	$(CXX) $(CXXFLAGS) -c view.cpp
controller.o: controller.cpp controller.h
	$(CXX) $(CXXFLAGS) -c controller.cpp
robot.o: robot.cpp robot.h
	$(CXX) $(CXXFLAGS) -c robot.cpp
customer.o: customer.cpp customer.h
	$(CXX) $(CXXFLAGS) -c customer.cpp
sales_associate.o: sales_associate.cpp sales_associate.h
	$(CXX) $(CXXFLAGS) -c sales_associate.cpp
order.o: order.cpp order.h
	$(CXX) $(CXXFLAGS) -c order.cpp
shop.o: shop.cpp shop.h
	$(CXX) $(CXXFLAGS) -c shop.cpp

clean:
	rm -f *.o robot_shop
