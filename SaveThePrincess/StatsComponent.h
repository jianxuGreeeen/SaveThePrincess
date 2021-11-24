#ifndef STATS_COMPONENT_H
#define STATS_COMPONENT_H
#pragma once
#include "ComponentInterface.h"
#include <cstdint>

/// <summary>
/// contains health and armor
/// </summary>
class StatsComponent final : public ComponentInterface {
public:
	StatsComponent() = default;

	virtual void Update(Character& Owner, float DeltaTime, const GameContext& Context) override {}
	virtual void Draw(const GameContext& Context) override {}
	virtual void Init(const ActorResource& Resource, GameContext& Context) override;
	virtual void Cleanup(GameContext& Context) override { }

private:
	int32_t StartingHealth = 0;
	int32_t StartingArmor = 0;
	int32_t Health = 0;
	int32_t Armor = 0;
};

#endif // STATS_COMPONENT_H
