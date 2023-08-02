cmake_minimum_required(VERSION 3.22)

set (project-name hello-scxml)
project (project-name)

find_package(Qt6 COMPONENTS Scxml Core REQUIRED)

# set up our program
add_executable(project-name)
 
# declare our source files
target_sources(project-name PRIVATE main.cpp)

target_link_libraries(project-name PRIVATE Qt6::Core Qt6::Scxml)

qt6_add_statecharts(project-name MyStateMachine.scxml)

