#include "WeaponsComponent.h"
#include "ActorResource.h"
#include "GameContext.h"
#include "ResourceDB.h"
void WeaponsComponent::Init(const ActorResource& Resource, GameContext& Context) {
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