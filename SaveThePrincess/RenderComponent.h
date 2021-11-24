#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H
#pragma once
#include "ComponentInterface.h"
#include "ActorResource.h"
#include "GameContext.h"
/// <summary>
/// Used to draw the given object
/// </summary>
class RenderComponent final : public ComponentInterface{
public:
	virtual void Update(Character& Owner, float DeltaTime, const GameContext& Context) override {}
	virtual void Draw(const GameContext& Context) override {}
	virtual void Init(const ActorResource& Resource, GameContext& Context) override {  }
	virtual void Cleanup(GameContext& Context) override { }
};

#endif // RENDER_COMPONENT_H
