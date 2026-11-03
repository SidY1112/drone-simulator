
#include "DroneState.hpp"
#include "PhysicsEngine.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

bool approximatelyEqual(double a, double b) {
    return std::abs(a - b) < 1e-9;
}

void testClimbing() {
    DroneState state{100.0, 5.0, 80.0};
    PhysicsEngine physics;

    physics.update(state, 2.0);

    assert(approximatelyEqual(state.altitudeMeters, 110.0));
    assert(approximatelyEqual(state.batteryPercentage, 80.0));
}

void testDescending() {
    DroneState state{100.0, -5.0, 80.0};
    PhysicsEngine physics;

    physics.update(state, 2.0);

    assert(approximatelyEqual(state.altitudeMeters, 90.0));
}

void testZeroVelocity() {
    DroneState state{100.0, 0.0, 80.0};
    PhysicsEngine physics;

    physics.update(state, 2.0);

    assert(approximatelyEqual(state.altitudeMeters, 100.0));
}

int main() {
    testClimbing();
    testDescending();
    testZeroVelocity();

    std::cout << "All physics tests passed!\n";
    return 0;
}
