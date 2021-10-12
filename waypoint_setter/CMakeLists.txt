
add_library(waypoint_setter STATIC
src/waypoint_setter.cpp
)

target_include_directories(waypoint_setter PUBLIC include)

target_link_libraries(waypoint_setter PRIVATE
yaml-cpp
comm_lib
)