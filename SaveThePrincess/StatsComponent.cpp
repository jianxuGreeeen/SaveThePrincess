#include "StatsComponent.h"
#include "ActorResource.h"
#include "Characters.h"
#include "GameContext.h"

void StatsComponent::Init(const ActorResource& Resource, GameContext& Context) {
	StartingHealth = Resource.GetHealth();
	StartingArmor = Resource.GetArmor();

	Health = StartingHealth;
	Armor = StartingArmor;
}