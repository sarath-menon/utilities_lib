#include "logger.h"

Logger::Logger() {
  // Initiaize event logger
  std::vector<spdlog::sink_ptr> sinks;
  sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
  sinks.push_back(std::make_shared<spdlog::sinks::daily_file_sink_st>(
      "logs/text-log.txt", 23, 59));
  combined_logger_ =
      std::make_shared<spdlog::logger>("name", begin(sinks), end(sinks));
}

void Logger::shutdown_logger() {
  // Initiaize event logger
  spdlog::shutdown();
}

void Logger::log_info(std::string text) { combined_logger_->info(text); }

void Logger::log_error(std::string text) { combined_logger_->error(text); }
