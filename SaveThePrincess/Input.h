#ifndef INPUT_H
#define INPUT_H
#pragma once
#include <string>

struct GameContext;

enum class InputKey : uint32_t {
	Enter,
	// represents the key that the user is pressing. 
	// Assumption here is keyboard for now.
};

class Input final
{
public:
	void UpdateInputBuffers(float DeltaTime, GameContext& Context) {}

	bool GetButtonPressed(const InputKey Key) { return true; }

};
#endif // INPUT_H

