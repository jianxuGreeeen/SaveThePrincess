#include "Game.h"

#include <assert.h>
#include "GameContext.h"
#include "GameStateMachine.h"
#include "GameStateInit.h"
#include "GameStateExitGame.h"

Game::Game() {}

Game::~Game() {}

void Game::Run() {

	GameContext context;
	GameStateMap stateMap;
	stateMap[GameStateEnums::Init] = std::make_unique<GameStateInit>();
	stateMap[GameStateEnums::Exit] = std::make_unique<GameStateExitGame>();

	GameStateMachine stateMachine(context, stateMap);
	stateMachine.Change(GameStateEnums::Init);

	while (!context.QuitGame) {
		stateMachine.Update();
	}
}