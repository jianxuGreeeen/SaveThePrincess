#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H
#pragma once

#include <memory>

#include "GameStateMachine.h"
#include "Input.h"
#include "Level.h"
#include "ObjectPool.h"
#include "Object.h"
#include "Physics.h"
#include "Renderer.h"
#include "ResourceDB.h"
#include "Timer.h"
#include "UI.h"

/// <summary>
/// Data relevant to the level.
/// Controls the life time of a level and all of its objects
/// </summary>
struct LevelContext final {
	std::unique_ptr<Level> CurrentLevel = nullptr;
	std::unique_ptr<Player> Player = nullptr;
};


/// <summary>
///  Holds onto game data that persists throughout the entirely of a game
/// </summary>
struct GameContext final {
	FrameTimer Timer;

	std::unique_ptr<Input> InputSystem = nullptr;
	std::unique_ptr<Renderer> RenderSystem = nullptr;
	std::unique_ptr<Physics> PhysicsSystem = nullptr;
	std::unique_ptr<ResourceDB> ResourceDB = nullptr;
	std::unique_ptr<UI> UISystem = nullptr;
	std::unique_ptr<GameStateMachine> GameState = nullptr;
	std::unique_ptr<ObjectPool<AI, ActorResource>> AIPool = nullptr;
	ResourceID NextLevelRequest = Resource::InvalidID;
	LevelContext LevelContext;

	bool QuitGame = false;
};

#endif // GAME_CONTEXT_H
