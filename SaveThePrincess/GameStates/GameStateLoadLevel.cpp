#include "GameStateLoadLevel.h"
#include "GameStateMachine.h"
#include "../GameContext.h"
#include "../Menu/UIScreen.h"
#include "../Objects/Level.h"
#include "../Systems/Renderer.h"
#include "../Systems/ResourceDB.h"
#include "../Systems/UI.h"
#include <assert.h>
#include <cassert>
void GameStateLoadLevel::Update(GameStateMachine& aStateMachine, GameContext& aContext) {
	assert(aContext.RenderSystem != nullptr);
	assert(aContext.ResourceDB != nullptr);
	assert(aContext.UISystem != nullptr);
	assert(aContext.Player != nullptr);
	assert(aContext.Levels != nullptr);

	aContext.Timer.Update();

	float dt = aContext.Timer.GetDeltaTime();

	auto splevelResource = aContext.ResourceDB->GetResource<LevelResource>(aContext.NextLevelRequest);
	assert(splevelResource != nullptr);
	if (splevelResource != nullptr) {
		
		// Load and move to running the level
		aContext.CurrentLevel = Level::LoadFromResource(*splevelResource, aContext);
		assert(aContext.CurrentLevel != nullptr);
		aStateMachine.Change(GameStateEnums::RunLevel);
	}
	else {
		// We'll want to log this issue somehow.
		aStateMachine.Change(GameStateEnums::MainMenu);
	}
}
void GameStateLoadLevel::Draw(GameStateMachine& aStateMachine, GameContext& aContext) {
	assert(aContext.RenderSystem != nullptr);
	assert(aContext.UISystem != nullptr);

	aContext.UISystem->DrawScreens(aContext);
	aContext.RenderSystem->Draw(aContext);
}
void GameStateLoadLevel::OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) {
	assert(aContext.RenderSystem != nullptr);
	assert(aContext.ResourceDB != nullptr);
	assert(aContext.UISystem != nullptr);
	assert(aContext.Player != nullptr);
	assert(aContext.Levels != nullptr);
	assert(aContext.CurrentLevel == nullptr);
	assert(aContext.NextLevelRequest != Resource::InvalidID);
	aContext.UISystem->ClearAndSetScreen<LoadingScreen>();
}
void GameStateLoadLevel::OnExit(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.NextLevelRequest = Resource::InvalidID;
}
