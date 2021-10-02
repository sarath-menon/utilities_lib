#include "waypoint_setter.h"

void WaypointSetter::set_setpoints(std::string path) {
  // Safety check, see if file exists
  safety_checks::yaml_file_check(path);

  // Load yaml file containing quadcopter properties
  YAML::Node setpoint_yaml = YAML::LoadFile(path);

  // Load timescales from yaml file
  position_(0) = setpoint_yaml["x_position"].as<float>();
  position_(1) = setpoint_yaml["y_position"].as<float>();
  position_(2) = setpoint_yaml["z_position"].as<float>();
}