#include "PhysicsComponent.h"
#include "../GameContext.h"
#include "../Resource/ActorResource.h"
#include "../Systems/Physics.h"
#include <assert.h>

void PhysicsComponent::Init(const ActorResource& Resource, GameContext& Context) { 
	assert(Context.PhysicsSystem != nullptr);
}

void PhysicsComponent::Update(Character& Owner, float DeltaTime, const GameContext& Context) {
	assert(Context.PhysicsSystem != nullptr);
}
void PhysicsComponent::Draw(const GameContext& Context) {}

void PhysicsComponent::Cleanup(GameContext& Context)  {

}
