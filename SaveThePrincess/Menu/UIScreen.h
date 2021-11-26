#ifndef UI_SCREEN_H
#define UI_SCREEN_H
#pragma once

struct GameContext;
/// <summary>
/// States for dealing with a stack of screens.
/// Ex: if message pop up comes up first, we want it to handle the work.
/// 
/// </summary>
enum class ScreenInputResult {
	Continue,
	Consume,
	Stop
};

class UIScreenInterface{
public:
	virtual ScreenInputResult ProcessScreenInput(float DeltaTime, GameContext& Context) = 0;
	virtual void Draw(float DeltaTime, GameContext& Context) = 0;
};

class MainMenuScreen final : public UIScreenInterface {
public:
	virtual ScreenInputResult ProcessScreenInput(float DeltaTime, GameContext& Context) override;
	virtual void Draw(float DeltaTime, GameContext& Context) override {}
};

class LoadingScreen final : public UIScreenInterface {
public:
	virtual ScreenInputResult ProcessScreenInput(float DeltaTime, GameContext& Context) override {}
	virtual void Draw(float DeltaTime, GameContext& Context) override {}
};

#endif // UI_H
