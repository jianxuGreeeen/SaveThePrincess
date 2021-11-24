#ifndef PHYSICS_H
#define PHYSICS_H
#pragma once
struct GameContext;

class Physics final
{
public:
	void Update(float DeltaTime, GameContext& Context);
};

#endif // PHYSICS_H