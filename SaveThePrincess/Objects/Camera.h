#ifndef CAMERA_H
#define CAMERA_H
#pragma once
#include "../Point2.h"

class Character;

class Camera final
{
public:
	void FollowTarget(const Character& Target);
	void FocusOnTarget(const Character& Target);
private:
	Point2 Position;
};

#endif // LEVEL_H
