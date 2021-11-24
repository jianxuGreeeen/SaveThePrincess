#include "GameStateMainMenu.h"
#include "GameContext.h"
#include "GameStateMachine.h"
#include "Input.h"
#include "Renderer.h"
#include "UI.h"

void GameStateMainMenu::Update(GameStateMachine& aStateMachine, GameContext& aContext) {

	aContext.Timer.Update();

	float dt = aContext.Timer.GetDeltaTime();

	aContext.InputSystem->UpdateInputBuffers(dt, aContext);
	aContext.UISystem->ProcessScreenInput(dt, aContext);
}

void GameStateMainMenu::Draw(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.UISystem->DrawScreens(aContext);
	aContext.RenderSystem->Draw(aContext);
}

void GameStateMainMenu::OnEntry(GameStateMachine& aStateMachine, GameContext& aContext) {
	aContext.UISystem->ClearAndSetScreen<MainMenuScreen>();
}
void GameStateMainMenu::OnExit(GameStateMachine& aStateMachine, GameContext& aContext) {
	
}