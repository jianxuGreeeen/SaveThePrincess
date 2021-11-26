#ifndef ACTOR_RESOURCE_H
#define ACTOR_RESOURCE_H
#pragma once

#include <array>
#include <vector>
#include "Resource.h"
#include "../MovementType.h"

class ResourceDB;
class ActorResource : public Resource {
public:

	explicit ActorResource(ResourceID aID)
		: Resource(aID) {}

	bool Load(ResourceFile& aFile) { return true; }

	int32_t GetHealth() const { return Health; }
	int32_t GetArmor() const { return Armor; }

	const std::vector<ResourceID>& GetWeapons() const { return WeaponResourceIDs; }
	MovementFlags GetMovementTypes() const { return MoveFlags; }

	static ResourceClass GetClass() { return ResourceClass::ActorResource; }

private:
	int32_t Health = 0;
	int32_t Armor = 0;

	std::vector<ResourceID> WeaponResourceIDs;
	MovementFlags MoveFlags = 0;
};

#endif // ACTOR_RESOURCE_H