cmake_minimum_required(VERSION 3.27)
project(wordplay-bot CXX)

include(FetchContent)

FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
    cpp-httplib
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib
    GIT_TAG        v0.56.0
)
FetchContent_MakeAvailable(cpp-httplib)

add_subdirectory(external)

add_executable(${PROJECT_NAME}
	src/main.cpp
    src/puzzle/TrieEngine.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/external/controller
    ${CMAKE_CURRENT_SOURCE_DIR}/external/shared
)
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    pico-bt-remote-controller
    httplib::httplib
    nlohmann_json
)