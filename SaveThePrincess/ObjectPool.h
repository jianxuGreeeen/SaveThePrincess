#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H
#pragma once

#include <cstdint>
#include <memory>

enum class ObjectState {
	Used,
	Unused
};

template <class InstanceType, class ResourceType>
class ObjectPool final
{
public:
	ObjectPool(uint32_t Size) {};
	~ObjectPool() {}

	std::weak_ptr<InstanceType> TryCreate(const ResourceType& Resource) { return std::weak_ptr<InstanceType>(); }
	void MarkAllUnused() {}
private:
};

#endif // OBJECT_POOL_H

