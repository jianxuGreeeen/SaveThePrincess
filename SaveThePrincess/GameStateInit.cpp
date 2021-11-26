#include "GameStateInit.h"
#include "GameContext.h"
#include "GameStateMachine.h"
#include "Characters.h"
#include "Input.h"
#include "Physics.h"
#include "Renderer.h"
#include "ResourceDB.h"
#include "UI.h"
#include <assert.h>
#include <string>

namespace {
	const std::string GameAssetFile = "Assets";
	constexpr uint32_t ActorLimit = 1024;
}

void GameStateInit::Update(GameStateMachine& aStateMachine, GameContext& aContext) {
	
	aContext.Timer.Update();
	// Right now it's non async.
	// An improvement would be to make an async load.
	// We would want to have 2 sections -
	// 1) a start up non async load that would load up a splash screen.
	//		Then we would pop up the screen
	// 2) Then start an async load of assets
	// By doing the two step approach, the app would look responsive
	if (aContext.ResourceDB->Load(GameAssetFile)) {
		
		auto spplayerResource = aContext.ResourceDB->GetPlayer();

		aContext.Player = std::make_unique<Player>(*spplayerResource, aContext);
		aContext.Levels = aContext.ResourceDB->GetLevelList();

		assert(aContext.Player != nullptr);
		assert(aContext.Levels != nullptr);

		aStateMachine.Change(GameStateEnums::MainMenu);
	}
	else {
		aStateMachine.Change(GameStateEnums::Exit);
	}
}

void GameStateInit::Draw(GameStateMachine& aStateMachine, GameContext& aContext) {

}

void GameStateInit::OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.InputSystem = std::make_unique<Input>();
	aContext.RenderSystem = std::make_unique<Renderer>();
	aContext.PhysicsSystem = std::make_unique<Physics>();
	aContext.ResourceDB = std::make_unique<ResourceDB>();
	aContext.UISystem = std::make_unique<UI>();
	aContext.AIPool = std::make_unique<ObjectPool<AI>>(ActorLimit);

	assert(aContext.InputSystem != nullptr);
	assert(aContext.RenderSystem != nullptr);
	assert(aContext.PhysicsSystem != nullptr);
	assert(aContext.ResourceDB != nullptr);
	assert(aContext.UISystem != nullptr);
	assert(aContext.AIPool != nullptr);
}
void GameStateInit::OnExit(GameStateMachine& aStateMachine, GameContext& aContext) {

}
