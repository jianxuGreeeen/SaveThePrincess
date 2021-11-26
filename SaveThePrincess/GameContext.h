#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H
#pragma once

#include <memory>

#include "Resource/Resource.h"
#include "Systems/ObjectPool.h"
#include "Systems/Timer.h"

class AI;
class Level;
class LevelListResource;
class Player;
class ResourceDB;
class GameStateMachine;
class Physics;
class Renderer;
class Input;
class UI;

/// <summary>
///  Holds onto game data that persists throughout the entirely of a game
/// </summary>
struct GameContext final {
	GameContext();
	~GameContext();

	FrameTimer Timer;

	std::unique_ptr<Input> InputSystem;
	std::unique_ptr<Renderer> RenderSystem;
	std::unique_ptr<Physics> PhysicsSystem;
	std::unique_ptr<ResourceDB> ResourceDB;
	std::unique_ptr<UI> UISystem;
	std::unique_ptr<GameStateMachine> GameState;
	std::unique_ptr<ObjectPool<AI>> AIPool;
	std::unique_ptr<Level> CurrentLevel;
	std::unique_ptr<Player> Player;
	
	std::shared_ptr<const LevelListResource> Levels;
	ResourceID NextLevelRequest = Resource::InvalidID;

	bool QuitGame = false;
	bool EndLevel = false;
};

#endif // GAME_CONTEXT_H
