#include "Characters.h"
#include "../GameContext.h"
#include "../Resource/ActorResource.h"
#include "../Systems/Physics.h"

void Character::Update(float DeltaTime, GameContext& Context) {
	Stats.Update(*this, DeltaTime, Context);
	Physics.Update(*this, DeltaTime, Context);
	Weapons.Update(*this, DeltaTime, Context);
	Render.Update(*this, DeltaTime, Context);
}
void Character::Draw(GameContext& Context) {
	Stats.Draw(Context);
	Physics.Draw(Context);
	Weapons.Draw(Context);
	Render.Draw(Context);
}

void Character::Init(const ActorResource& Resource,GameContext& Context) {
	Stats.Init(Resource, Context);
	Physics.Init(Resource, Context);
	Weapons.Init(Resource, Context);
	Render.Init(Resource, Context);

	Context.PhysicsSystem->AddToWorld(Physics);
}

void Character::Cleanup(GameContext& Context) {
	Stats.Cleanup(Context);
	Physics.Cleanup(Context);
	Weapons.Cleanup(Context);
	Render.Cleanup(Context);

	Context.PhysicsSystem->RemoveFromWorld(Physics);
}

void AI::Init(const ActorResource& Resource, GameContext& Context) {
	Input.Init(Resource, Context);
	Character::Init(Resource, Context);
}
void AI::Update(float DeltaTime, GameContext& Context) {
	Input.Update(*this, DeltaTime, Context);
	Character::Update(DeltaTime, Context);
}
void AI::Draw(GameContext& Context) {
	Character::Draw(Context);
}

Player::Player(const ActorResource& Resource, GameContext& Context) {
	Init(Resource, Context); 
}
void Player::Init(const ActorResource& Resource, GameContext& Context) {
	Input.Init(Resource, Context);
	Character::Init(Resource, Context);
}
void Player::Update(float DeltaTime, GameContext& Context) {
	Input.Update(*this, DeltaTime, Context);
	Character::Update(DeltaTime, Context);
}
void Player::Draw(GameContext& Context) {
	Character::Draw(Context);
}