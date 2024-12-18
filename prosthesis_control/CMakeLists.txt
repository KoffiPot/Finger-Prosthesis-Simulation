cmake_minimum_required(VERSION 3.8)
project(prosthesis_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# for unix platform, define install directories.
include(GNUInstallDirs)

# Inspired by
# https://stackoverflow.com/a/35084851
# https://docs.julialang.org/en/v1/manual/embedding/
execute_process (
    COMMAND bash -c "julia -e 'print(joinpath(Sys.BINDIR, Base.DATAROOTDIR, \"julia\"))'"
    OUTPUT_VARIABLE JL_SHARE
)

#include(FindPkgConfig)
#pkg_check_modules(CURLPP REQUIRED curlpp)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3)
# find_package(CURLPP REQUIRED curlpp)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# Adapted from https://robotics.stackexchange.com/questions/99234/how-to-write-header-file-for-ros-2-publisher
set(LIBS src/prosthesis-controller.cpp src/prosthesis-model.cpp)
add_executable(prosthesis-controller src/main.cpp ${LIBS})

# Inspired by 
# https://stackoverflow.com/a/38610804
# https://stackoverflow.com/questions/47867368/how-to-embed-julia-into-a-c-cmake-application-built-with-gcc
# https://stackoverflow.com/a/13703725
set(JULIA_LIBS
    ${JL_SHARE}/../..
)
add_library(julia OBJECT ${JULIA_LIBS}/lib/libjulia.so)
include_directories(${JULIA_LIBS}/include/julia/)
target_link_libraries(prosthesis-controller ${JULIA_LIBS}/lib/libjulia.so)
ament_target_dependencies(prosthesis-controller rclcpp std_msgs sensor_msgs Eigen3)
target_include_directories(prosthesis-controller PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(prosthesis-controller PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS prosthesis-controller
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
