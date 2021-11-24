#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H
#pragma once

#include <cstdint>
#include <memory>

/// <summary>
/// A block of instantiated memory of InstanceType
/// Users can get initialized instances out
/// </summary>
/// <typeparam name="InstanceType">Defines the instance class that the pool holds.</typeparam>
template <class InstanceType>
class ObjectPool final
{
public:
	ObjectPool(uint32_t Size) {};
	~ObjectPool() {}

	std::weak_ptr<InstanceType> TryCreate() {return std::weak_ptr<InstanceType>(); }
	void ReleaseUsed() {}
};

#endif // OBJECT_POOL_H

