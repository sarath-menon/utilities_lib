#pragma once
#include "safety_checks.h"
#include <matrix/math.hpp>
#include <string>
#include <yaml-cpp/yaml.h>

class WaypointSetter {

protected:
  // Position Setpoint
  matrix::Vector<float, 3> position_;

  // Velocity Setpoint
  matrix::Vector<float, 3> velocity_;

public:
  // To load setpoints from yaml
  void set_setpoints(std::string path);

public:
  /// Getter function
  float x_position() const { return position_(0); }
  /// Getter function
  float y_position() const { return position_(1); }
  /// Getter function
  float z_position() const { return position_(2); }
  /// Getter function
  float x_velocity() const { return velocity_(0); }
  /// Getter function
  float y_velocity() const { return velocity_(1); }
  /// Getter function
  float z_velocity() const { return velocity_(2); }
  /// Getter function
  matrix::Vector<float, 3> position() const { return position_; }
};