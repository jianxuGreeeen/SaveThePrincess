#include "GameStateMachine.h"

#include <assert.h>

GameStateMachine::GameStateMachine(GameContext& aContextData, GameStateMap& aStates)
	: ContextData(aContextData), States(aStates)
{}

GameStateMachine::~GameStateMachine() {
	pCurrentState = nullptr;
}

void GameStateMachine::Change(GameStateEnums aNewState) {
	assert(States.find(aNewState) != States.end());

	if (pCurrentState != nullptr) {
		pCurrentState->OnExit(*this, ContextData);
	}

	pCurrentState = States[aNewState].get();

	if (pCurrentState != nullptr) {
		pCurrentState->OnEntry(*this, ContextData);
	}
}

void GameStateMachine::Update() {
	if (pCurrentState != nullptr) {
		pCurrentState->Update(*this, ContextData);
	}
}

void GameStateMachine::Draw() {
	if (pCurrentState != nullptr) {
		pCurrentState->Draw(*this, ContextData);
	}
}