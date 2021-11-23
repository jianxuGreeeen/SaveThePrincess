#pragma once
#ifndef SYSTEM_INTERFACE_H
#define SYSTEM_INTERFACE_H

/// <summary>
/// Interface for a game system.
/// </summary>
class SystemInterface
{
public:
	SystemInterface() = default;
	virtual ~SystemInterface() = default;

	virtual void Update(float DeltaTime) = 0;
};

#endif // SYSTEM_INTERFACE_H

