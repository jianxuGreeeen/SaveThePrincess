#include "UIScreen.h"
#include "GameContext.h"

ScreenInputResult MainMenuScreen::ProcessScreenInput(float DeltaTime, GameContext& Context) {
	
	if (Context.InputSystem->GetButtonPressed(InputKey::Enter)) {
		Context.NextLevelRequest = 1;
		Context.GameState->Change(GameStateEnums::LoadLevel);
	}

	return ScreenInputResult::Stop; // main menu is usually the last screen. stop process the rest of the stack
}