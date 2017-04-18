CXXFLAGS = -w -std=c++11 -I/opt/local/include 
LDFLAGS = -L/usr/local/lib -lm -Wl, -lfltk_images -lfltk -lpthread -framework Cocoa

all: gui

debug: CXXFLAGS += -g
debug: gui

rebuild: clean gui

gui: robot_shop_gui.cpp
	$(CXX) $(CXXFLAGS) $(fltk-config --use-images --cxxflags) -o gui robot_shop_gui.cpp $(LDFLAGS)

cli: robot_shop_cli.cpp
	$(CXX) $(CXXFLAGS) -o cli robot_shop_cli.cpp

clean:
	-rm -f *.o gui cli