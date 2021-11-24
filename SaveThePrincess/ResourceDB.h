#ifndef RESOURCE_DB_H
#define RESOURCE_DB_H
#pragma once
#include <memory>
#include <unordered_map>
#include "Resource.h"


class Resource;
class LevelListResource;
class ActorResource;
class ResourceDB final
{
public:

	bool Load(const std::string& FilePath);

	template<class ResourceType>
	const ResourceType* GetResource(const ResourceID aID) const { return nullptr; }

	// Dealing with some special cases to quickly grab resources 
	// we know we'll need
	const LevelListResource* GetLevelList() { return nullptr; }
	const ActorResource* GetPlayer() { return nullptr; }

private:
	void AddResourceToDB(Resource* pResource) {}
	bool FindAndCachePlayer() { return true; }
	bool FindAndCacheLevelList() { return true; }

	bool ValidateResourceOfType(const ResourceClass aClass) { return true; }
};
#endif // RESOURCE_DB_H

