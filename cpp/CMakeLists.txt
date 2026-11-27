cmake_minimum_required(VERSION 3.25)

project(sonicdeck_streamdock_hello VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
  add_definitions("/Zc:__cplusplus" -DUNICODE=1)
endif()

include_directories("${CMAKE_SOURCE_DIR}")

add_subdirectory(StreamDockCPPSDK/Vendor)
add_subdirectory(StreamDockCPPSDK/StreamDockSDK)

add_executable(sonicDeckStreamDockHello
  main.cpp
  SonicDeckAction.cpp
  SonicDeckPlugin.cpp
)

target_link_libraries(sonicDeckStreamDockHello PRIVATE StreamDockSDK)
