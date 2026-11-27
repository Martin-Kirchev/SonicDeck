#include "SonicDeckAction.h"

void SonicDeckAction::WillAppear(const nlohmann::json&) {
    SetTitle("Press me");
}

void SonicDeckAction::KeyUp(const nlohmann::json&) {
    SetTitle("It works!");
    ShowOK();
}
