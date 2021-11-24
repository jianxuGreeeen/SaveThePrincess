#ifndef TIMER_H
#define TIMER_H
#pragma once
#include <cstdint>

class FrameTimer final{
public:

	FrameTimer();

	void Update();
	float GetDeltaTime() const;
private:
	int64_t	StartTime = 0;
	float	DeltaTime = 0.0f;
};
#endif // TIMER_H
