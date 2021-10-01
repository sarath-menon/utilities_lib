#pragma once
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#include "string_helper.h"
#include <filesystem>
#include <fstream>
#include <string.h>

class Logger {

private:
  /// Shared pointer var for global access
  std::shared_ptr<spdlog::logger> event_logger_;

  /// fstream for data logging
  std::fstream data_logger_;

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

  // Shutdown data logger
  void shutdown_data_logger();

  // public:
  //   /// Getter function
  //   float x_position() const { return x_position_; }
};