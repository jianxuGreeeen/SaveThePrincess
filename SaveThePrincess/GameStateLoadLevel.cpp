#include "GameStateLoadLevel.h"
#include "GameContext.h"
#include "GameStateMachine.h"
#include "Level.h"
#include "Renderer.h"
#include "ResourceDB.h"
#include "UI.h"
#include "UIScreen.h"

void GameStateLoadLevel::Update(GameStateMachine& aStateMachine, GameContext& aContext) {

	aContext.Timer.Update();

	float dt = aContext.Timer.GetDeltaTime();

	auto splevelResource = aContext.ResourceDB->GetResource<LevelResource>(aContext.NextLevelRequest);
	if (splevelResource != nullptr) {
		
		// Load and move to running the level
		aContext.CurrentLevel = Level::LoadFromResource(*splevelResource, aContext);
		aStateMachine.Change(GameStateEnums::RunLevel);
	}
	else {
		// We'll want to log this issue somehow.
		aStateMachine.Change(GameStateEnums::MainMenu);
	}
}
void GameStateLoadLevel::Draw(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.UISystem->DrawScreens(aContext);
	aContext.RenderSystem->Draw(aContext);
}
void GameStateLoadLevel::OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.UISystem->ClearAndSetScreen<LoadingScreen>();
}
void GameStateLoadLevel::OnExit(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.NextLevelRequest = Resource::InvalidID;
}
