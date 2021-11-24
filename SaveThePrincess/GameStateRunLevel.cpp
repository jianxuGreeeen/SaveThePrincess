#include "GameStateRunLevel.h"
#include "GameContext.h"
#include "GameStateMachine.h"
#include "Input.h"
#include "Level.h"
#include "Physics.h"
#include "Renderer.h"
#include "UI.h"
void GameStateRunLevel::Update(GameStateMachine& aStateMachine, GameContext& aContext) {

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
	// need to ensure screens are drawing
	aContext.CurrentLevel->Draw(aContext);
	aContext.UISystem->DrawScreens(aContext);
	aContext.RenderSystem->Draw(aContext);
}
void GameStateRunLevel::OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.EndLevel = false;
}
void GameStateRunLevel::OnExit(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.EndLevel = false;
}