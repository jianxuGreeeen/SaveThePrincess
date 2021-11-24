#ifndef RESOURCE_FILE_H
#define RESOURCE_FILE_H
#pragma once
#include <string>
class Resource;
/// <summary>
/// Represents data that needs to be loaded into game.
/// For example, the table of players, enemies, weapons, etc
/// </summary>
class ResourceFile
{
public:
	explicit ResourceFile(const std::string& ResourcePath) {}
	bool Open() { return true; }
	bool Close() { return true; }
	bool HasNextResource() { return true; }
	Resource* LoadNextResource() { return nullptr; }
};
#endif // RESOURCE_FILE_H

