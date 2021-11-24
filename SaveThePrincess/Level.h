#ifndef LEVEL_H
#define LEVEL_H
#pragma once
#include <memory>
#include <vector>
#include "Object.h"
#include "Camera.h"
#include "LevelResource.h"


/// <summary>
/// Level defines the life time of our entities. Once the level ends,
/// Objects needs to be cleaned up.
/// </summary>
class Level final
{
public:
	Level() = default;
	~Level() = default;

	static std::unique_ptr<Level> LoadFromResource(const LevelResource& Resource, GameContext& aContext);

	void Update(float DeltaTime, GameContext& Context);
	void Draw(GameContext& Context);

private:
	void UpdateCamera(float DeltaTime, GameContext& Context) {}
	void UpdateEntities(float DeltaTime, GameContext& Context) {}
	void DrawEntities(GameContext& Context) {}

	void InitCamera(const Player& aPlayer) {}
	void InitPlayerPosition(const LevelResource& Resource, GameContext& aContext) {}

	std::vector<std::weak_ptr<AI>> AIs;

	Camera CameraObject;
};

#endif // LEVEL_H
