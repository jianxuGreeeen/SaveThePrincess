#include "GameContext.h"

#include "GameStates/GameStateMachine.h"
#include "Objects/Characters.h"
#include "Objects/Level.h"
#include "Systems/Input.h"
#include "Systems/Physics.h"
#include "Systems/Renderer.h"
#include "Systems/ResourceDB.h"
#include "Systems/UI.h"

GameContext::GameContext() = default;
GameContext::~GameContext() {
	Levels = nullptr;
	CurrentLevel = nullptr;
	InputSystem = nullptr;
	RenderSystem = nullptr;
	PhysicsSystem = nullptr;
	ResourceDB = nullptr;
	UISystem = nullptr;
	GameState = nullptr;
	AIPool = nullptr;
	Player = nullptr;
}