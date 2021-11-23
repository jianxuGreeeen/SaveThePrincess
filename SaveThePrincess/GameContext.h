#pragma once

#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H

#include <memory>

#include "Physics.h"
#include "Renderer.h"
#include "Timer.h"

// holds onto game data that persists throughout the entirely of a game

struct GameContext final {
	FrameTimer Timer;

	std::unique_ptr<Renderer> RenderSystem = nullptr;
	std::unique_ptr<Physics> PhysicsSystem = nullptr;

	bool QuitGame = false;
};

#endif // GAME_CONTEXT_H
