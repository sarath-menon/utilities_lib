#pragma once
#include "safety_checks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#include "string_helper.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string.h>
#include <yaml-cpp/yaml.h>

class Logger {

private:
  /// Shared pointer var for global access
  std::shared_ptr<spdlog::logger> event_logger_;

  /// fstream for data logging
  std::fstream data_logger_;

  /// Contains the addresses of variables to be logged
  std::map<const std::string, const float *> log_address_book_;

  // // Mutex lock for data display
  // std::mutex m_;

public:
  // Constructor to initialize logger
  Logger(std::string event_log_path, std::string data_log_path);

  /// To log text information
  void log_info(std::string text);

  /// To log text error
  void log_error(std::string error);

  /// To log text error
  void log_data(float data);

  // Shutdown logger logger
  void shutdown();

  /// Shutdown data logger
  void shutdown_data_logger();

  /// To go to next line
  void log_next_line();

  /// Add variable to the log

  // template <typename T> void add_log(T variable, T &address){};

  void add_to_log(const std::string name, const float *const address);

  void log_now();

public:
  // To load setpoints from yaml
  void set_parameters(std::string path);

  // public:
  //   /// Getter function
  //   float x_position() const { return x_position_; }
};