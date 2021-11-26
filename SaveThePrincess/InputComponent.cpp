#include "InputComponent.h"
#include "Input.h"
#include "ActorResource.h"
#include "Characters.h"
#include "Physics.h"
#include "GameContext.h"
#include <assert.h>

namespace InputUtils {
	/// <summary>
	/// Functions that will take the input, transform it and update physics with it.
	/// </summary>
	/// <param name="Owner"></param>
	/// <param name="Velocity"></param>
	void PerformGroundMove(Character& Owner, Point2 Velocity ) {
		//Super simple ex:
		Owner.GetPhysics().ApplyVelocity(Velocity);
	}
	void PerformAirMove(Character& Owner, float DeltaTime ) {}
	void PerformWaterMove(Character& Owner, float DeltaTime ) {}
}

void InputComponent::Update(Character& Owner, float DeltaTime, const GameContext& Context) {
	assert(Context.InputSystem != nullptr);
}
void InputComponent::Draw(const GameContext& Context) {}
void InputComponent::Init(const ActorResource& Resource, GameContext& Context) {
	assert(Context.InputSystem != nullptr);
	MoveFlags = Resource.GetMovementTypes();
}
void InputComponent::Cleanup(GameContext& Context) {}

void PlayerInputComponent::Update(Character& Owner, float DeltaTime, const GameContext& Context) {
	assert(Context.InputSystem != nullptr);
	// move based on move type
	Point2 Velocity;
	if (Context.InputSystem->GetButtonPressed(InputKey::Left)) {
		Velocity.x -= 1.0f;
	}
	InputUtils::PerformGroundMove(Owner, Velocity);
}
void PlayerInputComponent::Draw(const GameContext& Context) {}
void PlayerInputComponent::Init(const ActorResource& Resource, GameContext& Context) {
	assert(Context.InputSystem != nullptr);
	InputComponent::Init(Resource, Context);
}
void PlayerInputComponent::Cleanup(GameContext& Context) {
	InputComponent::Cleanup(Context);
}

void AIInputComponent::Update(Character& Owner, float DeltaTime, const GameContext& Context) {
	// move based on move type
	assert(Context.InputSystem != nullptr);
}
void AIInputComponent::Draw(const GameContext& Context) {}
void AIInputComponent::Init(const ActorResource& Resource, GameContext& Context) {
	assert(Context.InputSystem != nullptr);
	InputComponent::Init(Resource, Context);
}
void AIInputComponent::Cleanup(GameContext& Context) {
	InputComponent::Cleanup(Context);
}