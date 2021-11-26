#include "GameStateRunLevel.h"
#include "GameStateMachine.h"
#include "../GameContext.h"
#include "../Objects/Level.h"
#include "../Systems/Input.h"
#include "../Systems/Physics.h"
#include "../Systems/Renderer.h"
#include "../Systems/UI.h"
#include <assert.h>
void GameStateRunLevel::Update(GameStateMachine& aStateMachine, GameContext& aContext) {
	assert(aContext.CurrentLevel != nullptr);
	assert(aContext.InputSystem != nullptr);
	assert(aContext.PhysicsSystem != nullptr);
	assert(aContext.UISystem != nullptr);

	aContext.Timer.Update();

	float dt = aContext.Timer.GetDeltaTime();

	aContext.InputSystem->UpdateInputBuffers(dt, aContext);
	aContext.UISystem->ProcessScreenInput(dt, aContext);
	aContext.CurrentLevel->Update(dt, aContext);
	aContext.PhysicsSystem->Update(dt, aContext);

	if (aContext.EndLevel) {
		aStateMachine.Change(GameStateEnums::UnloadLevel);
	}
}
void GameStateRunLevel::Draw(GameStateMachine& aStateMachine, GameContext& aContext) {
	assert(aContext.CurrentLevel != nullptr);
	assert(aContext.RenderSystem != nullptr);
	assert(aContext.UISystem != nullptr);
	// need to ensure screens are drawing
	aContext.CurrentLevel->Draw(aContext);
	aContext.UISystem->DrawScreens(aContext);
	aContext.RenderSystem->Draw(aContext);
}
void GameStateRunLevel::OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) {
	assert(aContext.CurrentLevel != nullptr);
	assert(aContext.InputSystem != nullptr);
	assert(aContext.RenderSystem != nullptr);
	assert(aContext.PhysicsSystem != nullptr);
	assert(aContext.ResourceDB != nullptr);
	assert(aContext.UISystem != nullptr);
	assert(aContext.AIPool != nullptr);
	assert(aContext.Player != nullptr);
	assert(aContext.Levels != nullptr);
	
	aContext.EndLevel = false;
}
void GameStateRunLevel::OnExit(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.EndLevel = false;
}