#pragma once
#include "safety_checks.h"
#include <string>
#include <yaml-cpp/yaml.h>

class WaypointSetter {

protected:
  // Position Setpoints
  float x_position_ = 0;
  float y_position_ = 0;
  float z_position_ = 0;

  // Velocity Setpoints
  float x_velocity_ = 0;
  float y_velocity_ = 0;
  float z_velocity_ = 0;

public:
  // To load setpoints from yaml
  void set_setpoints(std::string path);

public:
  /// Getter function
  float x_position() const { return x_position_; }
  /// Getter function
  float y_position() const { return y_position_; }
  /// Getter function
  float z_position() const { return z_position_; }
  /// Getter function
  float x_velocity() const { return x_velocity_; }
  /// Getter function
  float y_velocity() const { return y_velocity_; }
  /// Getter function
  float z_velocity() const { return z_velocity_; }
};