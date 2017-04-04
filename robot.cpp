#include "robot.h"




Robot_part :: Robot_part(string _name, int _model_number, double _cost, string _description, string _image_filename)
                         : name(_name), model_number(_model_number), cost(_cost), description(_description), image_filename(_image_filename) {}




Head :: Head(string _name, int _model_number, double _cost, string _description,
             string _image_filename, double _power) : Robot_part(_name, _model_number,
             _cost, _description, _image_filename), power(_power) {}


string Head::to_string() {
  string head = "Name: " + name + "\n" + "Model number: " + std::to_string(model_number) + "\n" + "Cost: " + std::to_string(cost) + "\n" +
                "Description: " + description + "\n" + "Image filename: " + image_filename + "\n" + "Power: " + std::to_string(power) + "\n\n";

  return head;
}





Torso :: Torso(string _name, int _model_number, double _cost, string _description,
               string _image_filename, int _battery_compartments, int _max_arms) : Robot_part(_name, _model_number,
               _cost, _description, _image_filename), battery_compartments(_battery_compartments), max_arms(_max_arms) {}



string Torso::to_string() {
  string torso = "Name: " + name + "\n" + "Model number: " + std::to_string(model_number) + "\n" + "Cost: " + std::to_string(cost) + "\n" +
                 "Description: " + description + "\n" + "Image filename: " + image_filename + "\n" + "Battery compartments: " +
                 std::to_string(battery_compartments) + "\n" + "Max arms: " + std::to_string(max_arms) + "\n\n";

  return torso;
}





Arm :: Arm(string _name, int _model_number, double _cost, string _description,
           string _image_filename, double _max_power) : Robot_part(_name, _model_number,
           _cost, _description, _image_filename), max_power(_max_power) {}



string Arm::to_string()
{
  string arm = "Name: " + name + "\n" + "Model number: " + std::to_string(model_number) + "\n" + "Cost: " + std::to_string(cost) + "\n" +
               "Description: " + description + "\n" + "Image filename: " + image_filename + "\n" + "Max power: " + std::to_string(max_power) + "\n\n";

  return arm;
}





Locomotor :: Locomotor(string _name, int _model_number, double _cost, string _description,
                       string _image_filename, double _max_power) : Robot_part(_name, _model_number,
                       _cost, _description, _image_filename), max_power(_max_power) {}




string Locomotor::to_string()
{
  string locomotor = "Name: " + name + "\n" + "Model number: " + std::to_string(model_number) + "\n" + "Cost: " + std::to_string(cost) + "\n" +
                     "Description: " + description + "\n" + "Image filename: " + image_filename + "\n" + "Max power: " + std::to_string(max_power) + "\n\n";

  return locomotor;
}





Battery :: Battery(string _name, int _model_number, double _cost, string _description, string _image_filename, 
                   double _power_availible, double _max_energy) : Robot_part(_name, _model_number,
                   _cost, _description, _image_filename), power_availible(_power_availible), max_energy(_max_energy) {}



string Battery::to_string()
{
  string battery = "Name: " + name + "\n" + "Model number: " + std::to_string(model_number) + "\n" + "Cost: " + std::to_string(cost) + "\n" +
                   "Description: " + description + "\n" + "Image filename: " + image_filename + "\n" +
                   "Power availible: " + std::to_string(power_availible) + "\n" + "Max energy: " + std::to_string(max_energy) + "\n\n";

  return battery;
}





Robot_model :: Robot_model(string _name, int _model_number, Head _head, Torso _torso, Arm _arm, Locomotor _locomotor, Battery _battery) : 
                           name(_name), model_number(_model_number), head(_head), torso(_torso), arm(_arm), locomotor(_locomotor), battery(_battery) {}




string Robot_model::to_string()
{
  string robot_model = "Name: " + name + "\n" + "Model number: " + std::to_string(model_number) + "\n" + head.to_string() + torso.to_string() +
                        arm.to_string() + locomotor.to_string() + battery.to_string() + "\n";

  return robot_model;
}


