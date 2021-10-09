add_library(utilities_lib INTERFACE)


# target_include_directories(utilities_lib INTERFACE
# coding_helper
# )

target_link_libraries(utilities_lib INTERFACE
waypoint_setter
logger
)


add_subdirectory(waypoint_setter)
add_subdirectory(logger)
