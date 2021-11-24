#include "GameStateExitGame.h"

#include "GameContext.h"
#include "GameStateMachine.h"

void GameStateExitGame::Update(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.LevelContext.CurrentLevel = nullptr;
	aContext.LevelContext.Player = nullptr;
	aContext.InputSystem = nullptr;
	aContext.RenderSystem = nullptr;
	aContext.PhysicsSystem = nullptr;
	aContext.ResourceDB = nullptr;
	aContext.UISystem = nullptr;
	aContext.AIPool = nullptr;
	aContext.QuitGame = true;
}
void GameStateExitGame::OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) {
}
void GameStateExitGame::OnExit(GameStateMachine& aStateMachine, GameContext& aContext) {

}