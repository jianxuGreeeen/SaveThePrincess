#ifndef OBJECT_H
#define OBJECT_H
#pragma once
#include "Point2.h"
#include "InputComponent.h"

#include "ComponentInterface.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include "StatsComponent.h"
#include "ActorResource.h"
#include <vector>
#include <memory>

struct GameContext;

class Object
{
public:
	Object() {}
	virtual ~Object() {}
	virtual void Update(float DeltaTime, const GameContext& Context) = 0;
	virtual void Draw(const GameContext& Context) = 0;

	void SetStartingPosition(Point2 Pos) {}

	RenderComponent& GetRender() { return Render; }
	PhysicsComponent& GetPhysics() { return Physics; }

protected:
	RenderComponent Render;
	PhysicsComponent Physics;
	StatsComponent Stats;
};

class AI : public Object {
public:
	virtual void Update(float DeltaTime, const GameContext& Context) override {}
	virtual void Draw(const GameContext& Context) override {}
private:
};

class Player final : public Object {
public:

	explicit Player(const ActorResource& Resource) {}

	virtual void Update(float DeltaTime, const GameContext& Context) override {}
	virtual void Draw(const GameContext& Context) override {}
private:
	PlayerInputComponent Input;
};


#endif // OBJECT_H
