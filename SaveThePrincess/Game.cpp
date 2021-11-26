#include "Game.h"

#include <assert.h>
#include <memory>
#include "GameContext.h"
#include "GameStates/GameStateMachine.h"
#include "GameStates/GameStateInit.h"
#include "GameStates/GameStateExitGame.h"
#include "GameStates/GameStateLoadLevel.h"
#include "GameStates/GameStateRunLevel.h"
#include "GameStates/GameStateUnloadLevel.h"
#include "GameStates/GameStateMainMenu.h"

Game::Game() {}

Game::~Game() {}

void Game::Run() {

	GameContext context;
	GameStateMap stateMap;
	stateMap[GameStateEnums::Init] = std::make_unique<GameStateInit>();
	stateMap[GameStateEnums::Exit] = std::make_unique<GameStateExitGame>();
	stateMap[GameStateEnums::LoadLevel] = std::make_unique<GameStateLoadLevel>();
	stateMap[GameStateEnums::RunLevel] = std::make_unique<GameStateRunLevel>();
	stateMap[GameStateEnums::UnloadLevel] = std::make_unique<GameStateUnloadLevel>();
	stateMap[GameStateEnums::MainMenu] = std::make_unique<GameStateMainMenu>();

	context.GameState = std::make_unique<GameStateMachine>(context, stateMap);
	context.GameState->Change(GameStateEnums::Init);

	while (!context.QuitGame) {
		context.GameState->Update();
		context.GameState->Draw();
	}
}