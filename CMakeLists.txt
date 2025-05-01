cmake_minimum_required(VERSION 3.10.0)
project(video_capture_h264)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories from OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

include(CTest)
enable_testing()

add_executable(video_capture_h264 main.cpp)

# Link OpenCV libraries
target_link_libraries(video_capture_h264 ${OpenCV_LIBS})

set_property(TARGET video_capture_h264 PROPERTY CXX_STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


