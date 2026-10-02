cmake_minimum_required(VERSION 3.27)
project(wordplay-bot CXX)

include(FetchContent)

FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
)
FetchContent_MakeAvailable(json)

add_subdirectory(external)

add_executable(${PROJECT_NAME}
	src/main.cpp
    src/puzzle/TrieEngine.cpp
    src/puzzle/SolverEngine.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/external/host
    ${CMAKE_CURRENT_SOURCE_DIR}/external/shared
)
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    pico-bt-remote-host
    nlohmann_json
)