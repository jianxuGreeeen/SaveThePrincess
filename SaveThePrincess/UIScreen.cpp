#include "UIScreen.h"
#include "GameContext.h"
#include "GameStateMachine.h"
#include "Input.h"
#include "LevelResource.h"

ScreenInputResult MainMenuScreen::ProcessScreenInput(float DeltaTime, GameContext& Context) {
	
	// Example usage:
	if (Context.InputSystem->GetButtonPressed(InputKey::Enter)) {
		Context.NextLevelRequest = Context.Levels->GetLevels()[0];
		Context.GameState->Change(GameStateEnums::LoadLevel);
	}
	else if (Context.InputSystem->GetButtonPressed(InputKey::Exit)) {
		Context.GameState->Change(GameStateEnums::Exit);
	}

	return ScreenInputResult::Stop; // main menu is usually the last screen. stop process the rest of the stack
}