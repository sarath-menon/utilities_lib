add_library(utilities_lib INTERFACE)

target_link_libraries(utilities_lib INTERFACE
waypoint_setter
)

add_subdirectory(waypoint_setter)