#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H
#include "ComponentInterface.h"
#pragma once
/// <summary>
/// Processes player inputs, moving, attackin etc
/// </summary>
class PlayerInputComponent final : public ComponentInterface {
public:
	virtual void Update(float DeltaTime, const GameContext& Context) override {}

};

#endif // INPUT_COMPONENT_H
