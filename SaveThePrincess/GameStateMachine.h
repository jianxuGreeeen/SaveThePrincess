#ifndef GAME_STATE_MACHINE_H
#define GAME_STATE_MACHINE_H
#pragma once

#include "GameStateTypes.h"

/// <summary>
/// State machine that our game uses to transition between game states.
/// </summary>
class GameStateMachine final {
public:
	GameStateMachine(GameContext& aContextData, GameStateMap& aStates);
	~GameStateMachine();

	void Change(GameStateEnums aNewState);
	void Update();
	void Draw();

private:
	GameContext& ContextData;
	GameStateMap& States;
	GameStateInterface* pCurrentState = nullptr;
};
#endif // GAME_STATE_MACHINE_H
