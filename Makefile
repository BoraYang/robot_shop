CXX = g++ -g
CXXFLAGS = -std=c++11

all: main.o view.o controller.o robot.o shop.o
	$(CXX) -o robot_shop main.o view.o controller.o robot.o shop.o

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
shop.o: shop.cpp shop.h
	$(CXX) $(CXXFLAGS) -c shop.cpp

clean:
	rm -f *.o robot_shop
