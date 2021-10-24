#pragma once
#include "geometry_msgs/msgs/Pose.h"
#include "safety_checks.h"
#include <matrix/math.hpp>
#include <string>
#include <yaml-cpp/yaml.h>

class WaypointSetter {

protected:
  // Pose setpoint
  cpp_msg::Pose pose_setpoint_{};

public:
  // To load setpoints from yaml
  void set_setpoints(std::string path);

public:
  /// Getter function
  const cpp_msg::Pose &pose() const { return pose_setpoint_; }
};