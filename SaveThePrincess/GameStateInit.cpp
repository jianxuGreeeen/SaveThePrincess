#include "GameStateInit.h"
#include "GameContext.h"
#include "GameStateMachine.h"
void GameStateInit::Update(GameStateMachine& aStateMachine, GameContext& aContext) {

	aStateMachine.Change(GameStateEnums::Idle);
}
void GameStateInit::OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.RenderSystem = std::make_unique<Renderer>();
	aContext.PhysicsSystem = std::make_unique<Physics>();
}
void GameStateInit::OnExit(GameStateMachine& aStateMachine, GameContext& aContext) {

}
