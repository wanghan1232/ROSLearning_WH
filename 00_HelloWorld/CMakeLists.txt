cmake_minimum_required(VERSION 3.10)

project(HelloWorldProject LANGUAGES CXX)


add_executable(hello_world
    main.cpp
    src/HelloWorld.cpp
)

target_include_directories(hello_world PRIVATE include)

 set_target_properties(hello_world PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
  )