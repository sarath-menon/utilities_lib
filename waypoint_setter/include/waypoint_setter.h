#pragma once
#include "geometry_msgs/msgs/Pose.h"
#include "quadcopter_msgs/msgs/QuadPositionCmd.h"
#include "safety_checks.h"
#include <matrix/math.hpp>
#include <string>
#include <yaml-cpp/yaml.h>

class WaypointSetter {

protected:
  // Pose setpoint
  cpp_msg::Pose pose_setpoint_{};

  // Position setpoint
  cpp_msg::QuadPositionCmd pos_setpoint_{};

public:
  // To load setpoints from yaml
  void set_setpoints(std::string path);

public:
  /// Getter function
  const cpp_msg::Pose &pose() const { return pose_setpoint_; }

  /// Getter function
  const cpp_msg::QuadPositionCmd &pos_setpoint() const { return pos_setpoint_; }
};