
add_library(math_helper STATIC
src/math_helper.cpp
)

target_include_directories(math_helper PUBLIC include)

# target_link_libraries(waypoint_setter PRIVATE
# yaml-cpp
# )