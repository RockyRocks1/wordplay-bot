cmake_minimum_required(VERSION 3.27)
project(wordplay-bot CXX)

add_subdirectory(external)

add_executable(${PROJECT_NAME}
	src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/external/controller
    ${CMAKE_CURRENT_SOURCE_DIR}/external/shared
)

target_link_libraries(${PROJECT_NAME} PRIVATE pico-bt-remote-controller)