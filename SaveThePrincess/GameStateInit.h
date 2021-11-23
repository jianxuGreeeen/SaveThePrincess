#pragma once
#ifndef GAME_STATE_INIT_H
#define GAME_STATE_INIT_H
#include "GameStateTypes.h"
/// <summary>
/// Used to initialize the game.
/// This means loading in data such as:
/// maps
/// assets
/// game data
/// </summary>
class GameStateInit final : public GameStateInterface
{
public:
	virtual void Update(GameStateMachine& aStateMachine, GameContext& aContext) override;
	virtual void OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) override;
	virtual void OnExit(GameStateMachine& aStateMachine, GameContext& aContext) override;
};
#endif // GAME_STATE_INIT_H

