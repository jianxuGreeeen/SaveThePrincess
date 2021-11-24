#ifndef LEVEL_RESOURCE_H
#define LEVEL_RESOURCE_H
#pragma once

#include <vector>
#include "Point2.h"
#include "Resource.h"
#include "ResourceFile.h"

/// <summary>
/// Each object in a level is represented by this
/// </summary>
struct LevelEntityData final {
	ResourceID Entity;
	Point2 Pos;
};
/// <summary>
/// Houses actor resources and their positions
/// </summary>
class LevelResource : public Resource {
public:

	explicit LevelResource(ResourceID aID)
		: Resource(aID) {}

	virtual void LoadImpl(ResourceFile& aFile) override {}

	const std::vector<LevelEntityData>& GetEntityResourceIDs() const { return EntityResourceIDs; }

	Point2 GetPlayerPos() { return PlayerPos; }

	static ResourceClass GetClass() { return ResourceClass::LevelResource; }

private:
	std::vector<LevelEntityData> EntityResourceIDs;
	Point2 PlayerPos;
};
/// <summary>
/// A list of levels. Used to go to the next level
/// </summary>
class LevelListResource : public Resource {
public:
	explicit LevelListResource(ResourceID aID)
		: Resource(aID) {}

	const std::vector<ResourceID>& GetLevels() const { return LevelList; }
private:
	std::vector<ResourceID> LevelList; // 0 is first level
};

#endif //LEVEL_RESOURCE_H