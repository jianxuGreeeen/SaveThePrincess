#pragma once
#ifndef GAME_STATE_EXIT_GAME_H
#define GAME_STATE_EXIT_GAME_H
#include "GameStateTypes.h"
class GameStateExitGame final : public GameStateInterface
{
public:
	virtual void Update(GameStateMachine& aStateMachine, GameContext& aContext) override;
	virtual void OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) override;
	virtual void OnExit(GameStateMachine& aStateMachine, GameContext& aContext) override;
};
#endif // GAME_STATE_EXIT_GAME_H

