#ifndef GAME_H
#define GAME_H
#pragma once

class Game final
{
public:
	Game();
	~Game();
	Game(const Game& Other) = delete;
	Game(Game&& Other) = delete;
	Game& operator = (const Game& Other) = delete;
	Game& operator = (Game&& Other) = delete;

	void Run();

private:
};
#endif // GAME_H

