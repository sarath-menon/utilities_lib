#include "waypoint_setter.h"

void WaypointSetter::set_setpoints(std::string path) {
  // Load yaml file containing quadcopter properties
  YAML::Node setpoint_yaml = YAML::LoadFile(path);

  // Load timescales from yaml file
  x_position_ = setpoint_yaml["x_position"].as<float>();
  y_position_ = setpoint_yaml["y_position"].as<float>();
  z_position_ = setpoint_yaml["z_position"].as<float>();
}