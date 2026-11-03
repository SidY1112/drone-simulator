
cmake_minimum_required(VERSION 3.20)

project(DroneSimulator LANGUAGES CXX)

add_library(drone_physics
    src/PhysicsEngine.cpp
)

target_include_directories(drone_physics
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(drone_physics PUBLIC cxx_std_20)

add_executable(drone_simulator
    src/main.cpp
)

target_link_libraries(drone_simulator PRIVATE drone_physics)

enable_testing()

add_executable(physics_tests
    tests/PhysicsEngineTests.cpp
)

target_link_libraries(physics_tests PRIVATE drone_physics)

add_test(NAME PhysicsTests COMMAND physics_tests)
