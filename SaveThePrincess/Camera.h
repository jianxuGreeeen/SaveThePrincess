#ifndef CAMERA_H
#define CAMERA_H
#pragma once
#include "Point2.h"

class Object;

class Camera final
{
public:
	void FollowTarget(const Object& Target);
	void FocusOnTarget(const Object& Target);
private:
	Point2 Position;
};

#endif // LEVEL_H
