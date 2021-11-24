#ifndef RESOURCE_DB_H
#define RESOURCE_DB_H
#pragma once
#include "Resource.h"

#include <memory>
#include <unordered_map>

class Resource;
class LevelListResource;
class ActorResource;

/// <summary>
/// Goal is to be a container for loaded resources.
/// This acts as a central point for the game to grab resource info
/// </summary>
class ResourceDB final
{
public:

	bool Load(const std::string& FilePath);

	template<class ResourceType>
	std::shared_ptr<const ResourceType> GetResource(const ResourceID aID) const { return nullptr; }

	// Dealing with some special cases to quickly grab resources 
	// we know we'll need
	std::shared_ptr<const LevelListResource> GetLevelList() { return nullptr; }
	std::shared_ptr<const ActorResource> GetPlayer() { return nullptr; }

private:
	void AddResourceToDB(Resource* pResource) {}
	bool FindAndCachePlayer() { return true; }
	bool FindAndCacheLevelList() { return true; }

	bool ValidateResourceOfType(const ResourceClass aClass) { return true; }
};
#endif // RESOURCE_DB_H

