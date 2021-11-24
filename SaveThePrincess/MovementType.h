#ifndef MOVEMENT_TYPE_H
#define MOVEMENT_TYPE_H
#pragma once

#include <cstdint>

class ResourceDB;
using MovementFlags = uint8_t;
enum class MovementType : MovementFlags {
	None	= 0,
	Ground	= 1 << 0,
	Air		= 1 << 1,
	Water	= 1 << 2,
};

namespace MovementUtils {
	bool HasFlag(const MovementFlags Flags, const MovementType Flag);
}
#endif // MOVEMENT_TYPE_H