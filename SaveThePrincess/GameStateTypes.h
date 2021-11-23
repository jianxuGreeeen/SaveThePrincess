#pragma once
#ifndef GAME_STATE_ENUM_H
#define GAME_STATE_ENUM_H

#include <cstdint>
#include <memory>
#include <unordered_map>

/// <summary>
/// Enum that defines the different states the game can be in
/// </summary>
enum class GameStateEnums : uint8_t{
	Init,
	Idle,
	LoadLevel,
	RunLevel,
	UnloadLevel,
	Exit
};

struct GameContext;
class GameStateMachine;
/// <summary>
/// Interface for a game state.
/// A game state is a helper class to perform certain types of work
/// and also represent the current state the game is in.
/// </summary>
class GameStateInterface {
public:
	virtual void Update(GameStateMachine& aStateMachine, GameContext& aContext) = 0;
	virtual void OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) = 0;
	virtual void OnExit(GameStateMachine& aStateMachine, GameContext& aContext) = 0;
};

using GameStateMap = std::unordered_map< GameStateEnums, std::unique_ptr< GameStateInterface> >;

#endif // GAME_STATE_ENUM_H
