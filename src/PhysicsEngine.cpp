
#include "PhysicsEngine.hpp"

void PhysicsEngine::update(DroneState& state, double deltaTimeSeconds)
{
    state.altitudeMeters +=
        state.verticalVelocityMetersPerSecond * deltaTimeSeconds;
}
