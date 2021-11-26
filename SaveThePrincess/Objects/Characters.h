#ifndef CHARACTERS_H
#define CHARACTERS_H
#pragma once

#include "../Components/InputComponent.h"
#include "../Components/PhysicsComponent.h"
#include "../Components/RenderComponent.h"
#include "../Components/StatsComponent.h"
#include "../Components/WeaponsComponent.h"
#include "../Point2.h"
#include <vector>
#include <memory>

class ActorResource;
struct GameContext;
/// <summary>
/// For the time being, a character class has all of the
/// components listed in the spec.
/// Stats to house health and armor
/// Physics for movement
/// Weapons for weapon
/// </summary>
class Character
{
public:
	Character() {}
	virtual ~Character() {}
	virtual void Update(float DeltaTime, GameContext& Context);
	virtual void Draw(GameContext& Context);

	void SetStartingPosition(Point2 Pos) {}
	virtual void Init(const ActorResource& Resource, GameContext& Context);
	virtual void Cleanup(GameContext& Context);

	PhysicsComponent& GetPhysics() { return Physics; }

protected:
	RenderComponent Render;
	PhysicsComponent Physics;
	StatsComponent Stats;
	WeaponsComponent Weapons;
};

class AI final: public Character {
public:
	AI() = default;

	virtual void Init(const ActorResource& Resource, GameContext& Context) override;
	virtual void Update(float DeltaTime, GameContext& Context) override;
	virtual void Draw(GameContext& Context) override;
private:
	AIInputComponent Input;
};

class Player final : public Character {
public:
	Player(const ActorResource& Resource, GameContext& Context);

	virtual void Init(const ActorResource& Resource, GameContext& Context) override;

	virtual void Update(float DeltaTime, GameContext& Context) override;
	virtual void Draw(GameContext& Context) override;
private:
	PlayerInputComponent Input;
};


#endif // CHARACTERS_H
