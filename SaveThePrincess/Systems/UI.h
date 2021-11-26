#ifndef UI_H
#define UI_H
#pragma once
#include "../Menu/UIScreen.h"
#include <vector>

struct GameContext;
class UI final
{
public:
	void ProcessScreenInput(float DeltaTime, GameContext& Context) {}
	void DrawScreens(GameContext& Context) {}

	template <class Screen>
	void PushScreen() {}

	template <class Screen>
	void ClearAndSetScreen() {}

	void ClearScreens() {}

private:
	// represents a stack of screens so we can draw multiple screens
	std::vector< UIScreenInterface > ScreenStack;
};
#endif // UI_H

