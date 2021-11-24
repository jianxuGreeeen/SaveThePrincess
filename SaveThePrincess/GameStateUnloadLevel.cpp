#include "GameStateUnloadLevel.h"
#include "GameContext.h"
#include "GameStateMachine.h"
#include "Level.h"
#include "UI.h"
#include "Renderer.h"

void GameStateUnloadLevel::Update(GameStateMachine& aStateMachine, GameContext& aContext) {

	aContext.Timer.Update();

	float dt = aContext.Timer.GetDeltaTime();

	// we're relying on the fact that the level is the owner
	// of all its objects to "unload".
	// This will run through and delete a level.

	// This forces a clean slate for everyone.
	// A potential improvement especially if we're just
	// restarting a level would be to add a "Revert" ability.
	// Then we could just call revert on the level to restore everything
	// back to its original state without having to deallocate/reallocate
	aContext.CurrentLevel->Cleanup(aContext);
	aContext.CurrentLevel = nullptr;

	// Clean up object pools
	aContext.AIPool->ReleaseUsed();

	// If there's a next level, transition to next level via load level.
	if (aContext.NextLevelRequest != Resource::InvalidID) {
		aStateMachine.Change(GameStateEnums::LoadLevel);
	}
	else {
		aStateMachine.Change(GameStateEnums::MainMenu);
	}
}
void GameStateUnloadLevel::Draw(GameStateMachine& aStateMachine, GameContext& aContext) {
	// need to ensure screens are drawing
	aContext.UISystem->DrawScreens(aContext);
	aContext.RenderSystem->Draw(aContext);
}
void GameStateUnloadLevel::OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) {
	// pop the loading screen up
	aContext.UISystem->ClearAndSetScreen<LoadingScreen>();
}
void GameStateUnloadLevel::OnExit(GameStateMachine& aStateMachine, GameContext& aContext) {

}