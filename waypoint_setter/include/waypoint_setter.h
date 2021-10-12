#pragma once
#include "geometry_msgs/msgs/Pose.h"
#include "safety_checks.h"
#include <matrix/math.hpp>
#include <string>
#include <yaml-cpp/yaml.h>

class WaypointSetter {

protected:
  // // Position Setpoint
  // matrix::Vector<float, 3> position_;

  // // Velocity Setpoint
  // matrix::Vector<float, 3> velocity_;

  // Pose setpoint
  msgs::Pose pose_setpoint_;

public:
  // To load setpoints from yaml
  void set_setpoints(std::string path);

public:
  /// Getter function
  const msgs::Pose &pose() const { return pose_setpoint_; }
};