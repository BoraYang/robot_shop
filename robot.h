#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <string>

using namespace std;

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
    void save();
};

class Head : public Robot_part{
private:
    double power;
public:
    Head(string _name, int _model_number, double _cost, string _description, string _image_filename, double _power);
    string to_string();
    string save();
};

class Torso : public Robot_part{
private:
    int battery_compartments;
    int max_arms;
public:
    Torso(string _name, int _model_number, double _cost, string _description, string _image_filename, int _battery_compartments, int _max_arms);
    string to_string();
    string save();
};

class Arm : public Robot_part{
private:
    double max_power;
public:
    Arm(string _name, int _model_number, double _cost, string _description, string _image_filename, double _max_power);
    string to_string();
    string save();
};

class Locomotor : public Robot_part{
private:
    double max_power;
public:
    Locomotor(string _name, int _model_number, double _cost, string _description, string _image_filename, double _max_power);
    string to_string();
    string save();
};

class Battery : public Robot_part{
private:
    double power_availible;
    double max_energy;
public:
    Battery(string _name, int _model_number, double _cost, string _description, string _image_filename, double _power_availible, double _max_energy);
    string to_string();
    string save();
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
    double max_speed();
    double max_battery_life();
};

#endif