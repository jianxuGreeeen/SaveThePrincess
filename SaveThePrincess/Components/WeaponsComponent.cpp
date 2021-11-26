#include "WeaponsComponent.h"
#include "../GameContext.h"
#include "../Resource/ActorResource.h"
#include "../Systems/ResourceDB.h"
#include <assert.h>
void WeaponsComponent::Init(const ActorResource& Resource, GameContext& Context) {
	assert(Context.ResourceDB != nullptr);
	Weapons.clear();
	
	for (auto resourceID : Resource.GetWeapons()) {
		auto spresource = Context.ResourceDB->GetResource<WeaponResource>(resourceID);
		if (spresource) {
			Weapons.push_back(spresource);
		}
	}
}

void WeaponsComponent::Cleanup(GameContext& Context) {
	Weapons.clear();
}