#pragma once
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/spdlog.h"
#include <string.h>

class Logger {

private:
  // Shared pointer var for global access
  std::shared_ptr<spdlog::logger> combined_logger_;

public:
  void initialize_logger();

  void log_info(std::string text);

private:
  // Initialize data logger
  void initialize_data_logger();
  // Initialize event logger
  void initialize_event_logger();

  // Initialize data logger
  void shutdown_logger();

  // public:
  //   /// Getter function
  //   float x_position() const { return x_position_; }
};