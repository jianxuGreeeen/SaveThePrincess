#ifndef STATS_COMPONENT_H
#define STATS_COMPONENT_H
#pragma once
#include "ComponentInterface.h"
#include <cstdint>
/// <summary>
/// contains health and armor
/// </summary>
class StatsComponent final {
public:
	StatsComponent() = default;

	void SetInitialHealthAndArmor(int32_t HP, int32_t Armor) {}

private:
	int32_t StartingHealth = 0;
	int32_t StartingArmor = 0;
	int32_t Health = 0;
	int32_t Armor = 0;
};

#endif // STATS_COMPONENT_H
