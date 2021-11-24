#ifndef RESOURCE_H
#define RESOURCE_H
#pragma once

#include <cstdint>

class ResourceFile;

using ResourceID = uint32_t;

enum class ResourceClass {
	ActorResource,
	LevelResource,
	WeaponResource
};

/// <summary>
/// Base definition for a resource.
/// Resource is a piece of data loaded in and used by the game.
/// These would be the resources:
/// Character    Health      Armor       Weapon          Movement
/// Player       100         100         Shotgun         Ground
/// Princess     80          0           None            Ground
/// Boss         500         100         Fireball/Axe    Ground/Air
/// Squab        50          0           Bomb            Air
/// Turtle       60          50          Shell Rock      Ground
/// Puffer       60          20          Poison Touch    Water
/// In the game, we would use this to create instances of them
/// </summary>
class Resource {
public:
	static constexpr ResourceID InvalidID = 0;

	explicit Resource(ResourceID aID) : ID(aID) {}
	virtual ~Resource() {};

	ResourceID GetID() const { return ID; }

	void Load(ResourceFile& aFile);
	virtual void LoadImpl(ResourceFile& aFile) {}

	template <class TypeName>
	static ResourceClass GetClass() { return TypeName::GetClass(); }

private:

	void LoadID(ResourceFile& aFile);

	ResourceID ID = InvalidID;
};

#endif // RESOURCE_H