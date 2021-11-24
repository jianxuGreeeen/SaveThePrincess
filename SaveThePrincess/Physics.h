#ifndef PHYSICS_H
#define PHYSICS_H
#pragma once
struct GameContext;
class PhysicsComponent;
class Physics final
{
public:
	void Update(float DeltaTime, GameContext& Context);

	void AddToWorld(PhysicsComponent& Component) {}
	void RemoveFromWorld(PhysicsComponent& Component) {}
};

#endif // PHYSICS_H