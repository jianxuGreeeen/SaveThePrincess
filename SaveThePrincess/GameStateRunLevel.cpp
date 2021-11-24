#include "GameStateRunLevel.h"
#include "GameContext.h"
#include "GameStateMachine.h"


void GameStateRunLevel::Update(GameStateMachine& aStateMachine, GameContext& aContext) {

	aContext.Timer.Update();

	float dt = aContext.Timer.GetDeltaTime();

	aContext.InputSystem->UpdateInputBuffers(dt, aContext);
	aContext.UISystem->ProcessScreenInput(dt, aContext);
	aContext.LevelContext.CurrentLevel->Update(dt, aContext);
	aContext.PhysicsSystem->Update(dt, aContext);
}
void GameStateRunLevel::Draw(GameStateMachine& aStateMachine, GameContext& aContext) {
	// need to ensure screens are drawing
	aContext.LevelContext.CurrentLevel->Draw(aContext);
	aContext.UISystem->DrawScreens(aContext);
	aContext.RenderSystem->Draw(aContext);
}
void GameStateRunLevel::OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) {

}
void GameStateRunLevel::OnExit(GameStateMachine& aStateMachine, GameContext& aContext) {

}