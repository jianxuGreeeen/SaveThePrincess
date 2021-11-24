#include "Level.h"
#include "GameContext.h"
#include <cstdint>

std::unique_ptr<Level> Level::LoadFromResource(const LevelResource& Resource, GameContext& aContext) {
	
	std::unique_ptr<Level> level = nullptr;

	// Consider adding a logging system so we can push issues
	// to a visible spot instead of failing silently
	auto* pplayerResource = aContext.ResourceDB->GetPlayer();
	bool success = pplayerResource != nullptr;

	level = std::make_unique<Level>();

	for (const auto& AIResource : Resource.GetEntityResourceIDs())
	{
		const auto* presource = aContext.ResourceDB->GetResource<ActorResource>(AIResource.Entity);

		if (presource) {
			level->AIs.push_back(aContext.AIPool->TryCreate(*presource));
		}
	}

	level->InitPlayerPosition(Resource, aContext);
	level->InitCamera(*aContext.LevelContext.Player);

	return level;
}

void Level::Update(float DeltaTime, GameContext& Context) {
	Context.LevelContext.Player->Update(DeltaTime, Context);
	
	UpdateEntities(DeltaTime, Context);
	UpdateCamera(DeltaTime, Context);
}

void Level::Draw(GameContext& Context) {
	Context.LevelContext.Player->Draw(Context);
	DrawEntities(Context);
}