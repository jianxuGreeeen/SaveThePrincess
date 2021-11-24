#include "GameStateExitGame.h"
#include "Characters.h"
#include "GameContext.h"
#include "GameStateMachine.h"
#include "Input.h"
#include "Level.h"
#include "Physics.h"
#include "Renderer.h"
#include "ResourceDB.h"
#include "UI.h"

void GameStateExitGame::Update(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.Levels = nullptr;
	aContext.CurrentLevel = nullptr;
	aContext.Player = nullptr;
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