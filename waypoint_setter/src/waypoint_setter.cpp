#include "waypoint_setter.h"

void WaypointSetter::set_setpoints(std::string path) {
  // Safety check, see if file exists
  safety_checks::yaml_file_check(path);

  // Load yaml file containing quadcopter properties
  YAML::Node setpoint_yaml = YAML::LoadFile(path);

  // Load timescales from yaml file
  pose_setpoint_.position.x = setpoint_yaml["x_position"].as<float>();
  pose_setpoint_.position.y = setpoint_yaml["y_position"].as<float>();
  pose_setpoint_.position.z = setpoint_yaml["z_position"].as<float>();

  pos_setpoint_.position.x = setpoint_yaml["x_position"].as<float>();
  pos_setpoint_.position.y = setpoint_yaml["y_position"].as<float>();
  pos_setpoint_.position.z = setpoint_yaml["z_position"].as<float>();
}