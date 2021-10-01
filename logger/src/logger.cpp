#include "logger.h"

Logger::Logger(std::string event_log_path, std::string data_log_path) {

  // Create folders to store log files
  std::filesystem::create_directories("logs/data_logs");
  std::filesystem::create_directories("logs/event_logs");

  // Initiaize event logger
  std::vector<spdlog::sink_ptr> sinks;
  sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
  sinks.push_back(std::make_shared<spdlog::sinks::daily_file_sink_st>(
      event_log_path, 23, 59));
  event_logger_ = std::make_shared<spdlog::logger>("event_logger", begin(sinks),
                                                   end(sinks));
  spdlog::register_logger(event_logger_);

  // Initialize data logger

  // Buffer to store file name
  char buffer[80];
  // Get current time
  time_t t = std::time(nullptr);
  // Set date+time as filename
  strftime(buffer, sizeof(buffer), "%F %r.", std::localtime(&t));

  const int buffer_size = sizeof(buffer) / sizeof(char);
  std::string file_name = string_helper::convertToString(buffer, buffer_size);
  data_log_path = data_log_path + file_name;

  data_logger_.open(data_log_path,
                    std::ios::trunc | std::ios::out | std::ios::in);
}

void Logger::shutdown() {
  // Initiaize event logger

  data_logger_.close();
  spdlog::drop("event_logger");
  spdlog::shutdown();
}

void Logger::shutdown_data_logger() { data_logger_.close(); }

void Logger::log_info(std::string text) { event_logger_->info(text); }

void Logger::log_error(std::string text) { event_logger_->error(text); }

void Logger::log_data(float data) { data_logger_ << data; }
