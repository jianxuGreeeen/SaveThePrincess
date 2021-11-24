#ifndef COMPONENT_INTERFACE_H
#define COMPONENT_INTERFACE_H
#pragma once

struct GameContext;

enum class ComponentID {
	PlayerInput,
	AIController,
	Physics,
	Stats,
	Weapons
};

/// <summary>
/// Interface for a game component.
/// </summary>
class ComponentInterface
{
public:
	ComponentInterface() = default;
	virtual ~ComponentInterface() = default;

	virtual void Update(float DeltaTime, const GameContext& Context) = 0;
};

#endif // COMPONENT_INTERFACE_H

