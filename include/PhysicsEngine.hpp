#pragma once

#include "DroneState.hpp"

class PhysicsEngine {
public:
    void update(DroneState& state, double deltaTimeSeconds);
};