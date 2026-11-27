#pragma once

#include "StreamDockCPPSDK/StreamDockSDK/HSDAction.h"

class SonicDeckAction : public HSDAction {
public:
    using HSDAction::HSDAction;

    void KeyUp(const nlohmann::json& payload) override;
    void WillAppear(const nlohmann::json& payload) override;
};
