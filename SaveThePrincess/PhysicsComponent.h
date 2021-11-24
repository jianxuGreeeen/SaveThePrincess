#ifndef PHYSICS_COMPONENT_H
#define PHYSICS_COMPONENT_H
#pragma once
#include "ComponentInterface.h"
#include "Point2.h"
/// <summary>
/// Processes player inputs, moving, attackin etc
/// </summary>
class PhysicsComponent final : public ComponentInterface {
public:
	virtual void Update(float DeltaTime, const GameContext& Context) override {}

	void ApplyVelocity(Point2 Velocity) {}

};

#endif // PHYSICS_COMPONENT_H
