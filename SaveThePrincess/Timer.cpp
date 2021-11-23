#include "Timer.h"

FrameTimer::FrameTimer() {
	// Initialize start time and any other we might need
	StartTime = 0; 
}

void FrameTimer::Update() {
	// Here we'll update delta time
	// For the purpose of this exercise, I'm going to pretend we're always
	// running at a delta time that provides 30 fps.
	constexpr float fps = 30.0f;
	constexpr float fpsDeltaTime = 1.0f / fps;
	DeltaTime = fpsDeltaTime;
}

float FrameTimer::GetDeltaTime() const {
	return DeltaTime;
}