#ifndef WEAPON_RESOURCE_H
#define WEAPON_RESOURCE_H
#pragma once

#include "Resource.h"
#include "../Objects/ResourceFile.h"

/// <summary>
/// Data to define weapons.
/// Can utitlize this to eventually add data to customize weapon.
/// Damage, projectile, etc
/// </summary>
class WeaponResource : public Resource {
public:
	explicit WeaponResource(ResourceID aID)
		: Resource(aID) {}

	virtual void LoadImpl(ResourceFile& aFile) override {}

	static ResourceClass GetClass() { return ResourceClass::WeaponResource; }

private:
};

#endif // WEAPON_RESOURCE_H