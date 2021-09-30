#pragma once
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#include <string.h>

class Logger {

private:
  /// Shared pointer var for global access
  std::shared_ptr<spdlog::logger> combined_logger_;

public:
  // Constructor to initialize logger
  Logger();

  /// To log text information
  void log_info(std::string text);

  /// To log text error
  void log_error(std::string error);

  // Initialize data logger
  void shutdown_logger();

  // public:
  //   /// Getter function
  //   float x_position() const { return x_position_; }
};