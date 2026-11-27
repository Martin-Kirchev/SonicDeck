#pragma once

#include "StreamDockCPPSDK/StreamDockSDK/HSDPlugin.h"

#include <map>
#include <memory>
#include <string>

class SonicDeckPlugin : public HSDPlugin {
public:
    std::shared_ptr<HSDAction> GetOrCreateAction(
        const std::string& action,
        const std::string& context) override;

    std::shared_ptr<HSDAction> FindAction(
        const std::string& action,
        const std::string& context) override;

    bool RemoveAction(
        const std::string& action,
        const std::string& context) override;

private:
    std::map<std::string, std::shared_ptr<HSDAction>> actionsByContext;
};
