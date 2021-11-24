#ifndef GAME_STATE_MAIN_MENU_H
#define GAME_STATE_MAIN_MENU_H
#pragma once
#include "GameStateTypes.h"
/// <summary>
/// Main menu
/// </summary>
class GameStateMainMenu final : public GameStateInterface
{
public:
	virtual void Update(GameStateMachine& aStateMachine, GameContext& aContext) override;
	virtual void Draw(GameStateMachine& aStateMachine, GameContext& aContext) override;
	virtual void OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) override;
	virtual void OnExit(GameStateMachine& aStateMachine, GameContext& aContext) override;
};
#endif // GAME_STATE_INIT_H

