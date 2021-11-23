#pragma once
#include "SystemInterface.h"
class Physics final : public SystemInterface
{
public:
	virtual void Update(float DeltaTime) override;
};

