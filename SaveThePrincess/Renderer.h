#pragma once
#ifndef RENDERER_H
#define RENDERER_H
#include "SystemInterface.h"
class Renderer final : public SystemInterface
{
public:
	virtual void Update(float DeltaTime) override;
};
#endif // RENDERER_H

