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