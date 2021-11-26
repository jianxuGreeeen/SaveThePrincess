#ifndef COMPONENT_INTERFACE_H
#define COMPONENT_INTERFACE_H
#pragma once

class ActorResource;
class Character;
struct GameContext;

/// <summary>
/// Interface for a game component.
/// </summary>
class ComponentInterface
{
public:
	ComponentInterface() = default;
	virtual ~ComponentInterface() = default;

	virtual void Update(Character& Owner, float DeltaTime, const GameContext& Context) = 0;
	virtual void Draw(const GameContext& Context) = 0;

	virtual void Init(const ActorResource& Resource, GameContext& Context) = 0;
	virtual void Cleanup(GameContext& Context) = 0;
};

#endif // COMPONENT_INTERFACE_H

