#include "Level.h"
#include "Characters.h"
#include "../GameContext.h"
#include "../Resource/LevelResource.h"
#include "../Systems/ResourceDB.h"
#include <assert.h>
#include <cstdint>

std::unique_ptr<Level> Level::LoadFromResource(const LevelResource& Resource, GameContext& aContext) {
	assert(aContext.Player != nullptr);
	std::unique_ptr<Level> level = nullptr;

	// Consider adding a logging system so we can push issues
	// to a visible spot instead of failing silently
	level = std::make_unique<Level>();
	assert(level != nullptr);
	for (const auto& AIResource : Resource.GetEntityResourceIDs())
	{
		auto spresource = aContext.ResourceDB->GetResource<ActorResource>(AIResource.Entity);
		if (spresource) {

			auto wkPtr = aContext.AIPool->TryCreate();
			auto spAI = wkPtr.lock();
			if (spAI) {
				spAI->Init(*spresource, aContext);
				level->AIs.push_back(spAI);
			}
			
		}
	}

	level->InitPlayerPosition(Resource, aContext);
	level->InitCamera(*aContext.Player);

	return level;
}

void Level::Update(float DeltaTime, GameContext& Context) {
	assert(Context.Player != nullptr);
	Context.Player->Update(DeltaTime, Context);
	
	UpdateEntities(DeltaTime, Context);
	UpdateCamera(DeltaTime, Context);
}

void Level::Draw(GameContext& Context) {
	assert(Context.Player != nullptr);
	Context.Player->Draw(Context);
	DrawEntities(Context);
}

void Level::Cleanup(GameContext& Context) {
	for (auto wkptr : AIs) {
		auto spAI = wkptr.lock();
		if (spAI) {
			spAI->Cleanup(Context);
		}
	}
}

void Level::UpdateCamera(float DeltaTime, GameContext& Context) {}
void Level::UpdateEntities(float DeltaTime, GameContext& Context) {}
void Level::DrawEntities(GameContext& Context) {}
void Level::InitCamera(const Player& aPlayer) {}
void Level::InitPlayerPosition(const LevelResource& Resource, GameContext& aContext) {}