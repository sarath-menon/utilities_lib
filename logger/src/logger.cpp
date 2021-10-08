#include "logger.h"

Logger::Logger(std::string event_log_path, std::string data_log_path) {

  // Create folders to store log files
  std::filesystem::create_directories(data_log_path);
  std::filesystem::create_directories(event_log_path);

  // Initiaize event logger
  std::vector<spdlog::sink_ptr> sinks;
  sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());

  // Disable spdlog text logging for now
  // sinks.push_back(std::make_shared<spdlog::sinks::daily_file_sink_st>(
  //     event_log_path, 23, 59));

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
  std::string extension = "txt";

  data_log_path = data_log_path + file_name + extension;

  std::cout << "data log path:" << data_log_path << '\n';

  data_logger_.open(data_log_path,
                    std::ios::trunc | std::ios::out | std::ios::in);

  // // Data logger headings
  // // Vector of headings
  // std::vector<std::string> headings = {
  //     "x",
  //     "y",
  //     "z",
  //     "roll",
  //     "pitch",
  //     "yaw",
  //     "net_thrust",
  //     "torque_x",
  //     "torque_y",
  //     "torque_z",
  //     "motor_0_command",
  //     "motor_1_command",
  //     "motor_2_command",
  //     "motor_3_command",
  // };

  // // Write headings
  // for (int i = 0; i < headings.size(); i++) {
  //   data_logger_ << headings[i] << '\t';
  // }
  // data_logger_ << std::endl;
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

void Logger::log_data(float data) {
  // // Lock mutex
  // std::scoped_lock<std::mutex> lock(m_);

  // Write data to console
  data_logger_ << data << '\t';
}

void Logger::log_next_line() { data_logger_ << '\n'; }

void Logger::set_parameters(std::string path) {
  // Safety check, see if file exists
  safety_checks::yaml_file_check(path);

  // Load yaml file containing quadcopter properties
  YAML::Node logger_yaml = YAML::LoadFile(path);
}

void Logger::add_to_log(const std::string name, const float *const address) {
  log_address_book_.insert({name, address});
};

void Logger::log_now() {

  for (const auto &[key, value] : log_address_book_) {
    data_logger_ << *value << '\t';
  }
}
