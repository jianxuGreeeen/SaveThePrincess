#ifndef GAME_STATE_LOAD_LEVEL_H
#define GAME_STATE_LOAD_LEVEL_H
#pragma once
#include "GameStateTypes.h"
/// <summary>
/// Loads a level
/// </summary>
class GameStateLoadLevel final : public GameStateInterface
{
public:
	virtual void Update(GameStateMachine& aStateMachine, GameContext& aContext) override;
	virtual void Draw(GameStateMachine& aStateMachine, GameContext& aContext) override;
	virtual void OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) override;
	virtual void OnExit(GameStateMachine& aStateMachine, GameContext& aContext) override;
};
#endif // GAME_STATE_LOAD_LEVEL_H
