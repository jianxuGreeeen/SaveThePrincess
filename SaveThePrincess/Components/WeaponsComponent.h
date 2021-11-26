#ifndef WEAPONS_COMPONENT_H
#define WEAPONS_COMPONENT_H
#pragma once

#include "ComponentInterface.h"
#include "../Resource/WeaponResource.h"
#include <memory>
#include <vector>

/// <summary>
/// Contains weapons
/// For now, all we care about is the weapon's stats if it had any.
/// So just hold onto the resources.
/// If we go to something fancier, we may want instances of them.
/// In which case, we may want a object pool similar to characters to create from
/// </summary>
class WeaponsComponent final : public ComponentInterface {
public:
	WeaponsComponent() = default;

	virtual void Update(Character& Owner, float DeltaTime, const GameContext& Context) override {}
	virtual void Draw(const GameContext& Context) override {}
	virtual void Init(const ActorResource& Resource, GameContext& Context) override;
	virtual void Cleanup(GameContext& Context) override;

	void AddWeapon(std::shared_ptr<const WeaponResource> Resource) { Weapons.push_back(Resource); }

private:
	std::vector<std::shared_ptr<const WeaponResource>> Weapons;
};

#endif // STATS_COMPONENT_H
