add_library(utilities_lib INTERFACE)

target_link_libraries(utilities_lib INTERFACE
waypoint_setter
math_helper
)

add_subdirectory(waypoint_setter)
add_subdirectory(math_helper)