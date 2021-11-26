#include "StatsComponent.h"
#include "../GameContext.h"
#include "../Objects/Characters.h"
#include "../Resource/ActorResource.h"

void StatsComponent::Init(const ActorResource& Resource, GameContext& Context) {
	StartingHealth = Resource.GetHealth();
	StartingArmor = Resource.GetArmor();

	Health = StartingHealth;
	Armor = StartingArmor;
}