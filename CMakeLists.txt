cmake_minimum_required(VERSION 3.23)
project(sort_visualization)

set(CMAKE_CXX_STANDARD 14)

add_executable(sort_visualization main.cpp)
set(SFML_STATIC_LIBARIES TRUE)
set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio REQUIRED)

include_directories(C:/SFML/SFML-2.5.1/include)
target_link_libraries(sort_visualization sfml-system sfml-window sfml-graphics sfml-audio)
