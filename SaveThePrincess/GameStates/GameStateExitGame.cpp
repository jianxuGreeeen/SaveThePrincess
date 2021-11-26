#include "GameStateExitGame.h"
#include "GameStateMachine.h"
#include "../GameContext.h"
#include "../Objects/Characters.h"
#include "../Objects/Level.h"
#include "../Systems/Input.h"
#include "../Systems/Physics.h"
#include "../Systems/Renderer.h"
#include "../Systems/ResourceDB.h"
#include "../Systems/UI.h"

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