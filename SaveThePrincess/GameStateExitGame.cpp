#include "GameStateExitGame.h"

#include "GameContext.h"
#include "GameStateMachine.h"

void GameStateExitGame::Update(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.RenderSystem = nullptr;
	aContext.PhysicsSystem = nullptr;
	aContext.QuitGame = true;
}
void GameStateExitGame::OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) {
}
void GameStateExitGame::OnExit(GameStateMachine& aStateMachine, GameContext& aContext) {

}