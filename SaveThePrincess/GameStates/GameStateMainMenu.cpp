#include "GameStateMainMenu.h"
#include "GameStateMachine.h"
#include "../GameContext.h"
#include "../Systems/Input.h"
#include "../Systems/Renderer.h"
#include "../Systems/UI.h"
#include <assert.h>

void GameStateMainMenu::Update(GameStateMachine& aStateMachine, GameContext& aContext) {
	assert(aContext.InputSystem != nullptr);
	assert(aContext.PhysicsSystem != nullptr);
	assert(aContext.ResourceDB != nullptr);
	assert(aContext.AIPool != nullptr);
	assert(aContext.Player != nullptr);
	assert(aContext.Levels != nullptr);

	aContext.Timer.Update();

	float dt = aContext.Timer.GetDeltaTime();

	aContext.InputSystem->UpdateInputBuffers(dt, aContext);
	aContext.UISystem->ProcessScreenInput(dt, aContext);
}

void GameStateMainMenu::Draw(GameStateMachine& aStateMachine, GameContext& aContext) {
	assert(aContext.RenderSystem != nullptr);
	assert(aContext.UISystem != nullptr);
	
	aContext.UISystem->DrawScreens(aContext);
	aContext.RenderSystem->Draw(aContext);
}

void GameStateMainMenu::OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) {
	assert(aContext.InputSystem != nullptr);
	assert(aContext.RenderSystem != nullptr);
	assert(aContext.PhysicsSystem != nullptr);
	assert(aContext.ResourceDB != nullptr);
	assert(aContext.UISystem != nullptr);
	assert(aContext.AIPool != nullptr);
	assert(aContext.Player != nullptr);
	assert(aContext.Levels != nullptr);
	assert(aContext.CurrentLevel == nullptr);
	aContext.UISystem->ClearAndSetScreen<MainMenuScreen>();
}
void GameStateMainMenu::OnExit(GameStateMachine& aStateMachine, GameContext& aContext) {
	
}