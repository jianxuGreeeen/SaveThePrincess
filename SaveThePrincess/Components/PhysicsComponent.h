#ifndef PHYSICS_COMPONENT_H
#define PHYSICS_COMPONENT_H
#pragma once
#include "ComponentInterface.h"
#include "../MovementType.h"
#include "../Point2.h"

/// <summary>
/// Goal is for this to move the object, 
/// contain aabb for physics to do collision tests, etc
/// </summary>
class PhysicsComponent final : public ComponentInterface {
public:
	virtual void Update(Character& Owner, float DeltaTime, const GameContext& Context) override;
	virtual void Draw(const GameContext& Context) override;
	virtual void Init(const ActorResource& Resource, GameContext& Context) override;
	virtual void Cleanup(GameContext& Context) override;
	void ApplyVelocity(const Point2& NewVelocity) { Velocity = NewVelocity; }
private:
	
	Point2 Position;
	Point2 Velocity;
	Point2 MinBounds;
	Point2 MaxBounds;
};

#endif // PHYSICS_COMPONENT_H
