#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H
#pragma once

#include "ComponentInterface.h"
#include "MovementType.h"

class InputComponent : public ComponentInterface {
protected:
	virtual void Update(Character& Owner, float DeltaTime, const GameContext& Context) override;
	virtual void Draw(const GameContext& Context) override;
	virtual void Init(const ActorResource& Resource, GameContext& Context) override;
	virtual void Cleanup(GameContext& Context) override;

	MovementFlags MoveFlags = 0;
};
/// <summary>
/// Processes player inputs, moving, attackin etc
/// </summary>
class PlayerInputComponent final : public InputComponent {
public:
	virtual void Update(Character& Owner, float DeltaTime, const GameContext& Context)override;
	virtual void Draw(const GameContext& Context) override;
	virtual void Init(const ActorResource& Resource, GameContext& Context) override;
	virtual void Cleanup(GameContext& Context) override;
};

/// <summary>
/// Processes AI inputs, moving, attackin etc
/// This would contain AI logic to alter movement
/// </summary>
class AIInputComponent final : public InputComponent {
public:
	virtual void Update(Character& Owner, float DeltaTime, const GameContext& Context) override;
	virtual void Draw(const GameContext& Context) override;
	virtual void Init(const ActorResource& Resource, GameContext& Context) override;
	virtual void Cleanup(GameContext& Context) override;

};

#endif // INPUT_COMPONENT_H
