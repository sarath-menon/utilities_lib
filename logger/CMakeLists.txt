
add_library(logger STATIC
src/logger.cpp
)

target_include_directories(logger PUBLIC
include
coding_helper
)

target_link_libraries(logger PRIVATE
spdlog::spdlog
yaml-cpp
)

