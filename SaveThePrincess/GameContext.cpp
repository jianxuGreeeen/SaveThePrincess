#include "GameContext.h"

#include "Characters.h"
#include "GameStateMachine.h"
#include "Input.h"
#include "Level.h"
#include "Physics.h"
#include "Renderer.h"
#include "ResourceDB.h"
#include "UI.h"

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