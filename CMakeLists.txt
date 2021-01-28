project(concur)
cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -Wall")

aux_source_directory(. SRC_LIST)

set(HEADERS spinlock.h worker.h)


add_executable(${PROJECT_NAME} ${SRC_LIST} ${HEADERS})

target_link_libraries(concur pthread)

