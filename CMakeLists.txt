cmake_minimum_required(VERSION 3.1)
project(mark)

#set(CMAKE_CXX_FLAGS "-std=c++14 -O2 ${SSE_FLAGS} -msse4")
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)

set(ALL_TARGET_LIBRARIES "")

find_package(OpenCV 3 REQUIRED)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})


add_executable(markdetection main.cpp markdetector.cpp)
target_link_libraries(markdetection ${ALL_TARGET_LIBRARIES} ${OpenCV_LIBRARIES})
