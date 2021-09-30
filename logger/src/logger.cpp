#include "logger.h"

void Logger::initialize_event_logger() {
  // Create logger
  std::vector<spdlog::sink_ptr> sinks;
  sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
  sinks.push_back(std::make_shared<spdlog::sinks::daily_file_sink_st>(
      "logs/text-log.txt", 23, 59));
  auto combined_logger =
      std::make_shared<spdlog::logger>("name", begin(sinks), end(sinks));
  // register logger to access it globally
  spdlog::register_logger(combined_logger);

  // Set globally available data logger
  combined_logger_ = spdlog::get("combined_logger");
}

void Logger::initialize_logger() {
  // Initiaize event logger
  initialize_event_logger();
}

void Logger::shutdown_logger() {
  // Initiaize event logger
  spdlog::shutdown();
}

void Logger::log_info(std::string text) { combined_logger_->info(text); }
