#include "SonicDeckPlugin.h"

#include "SonicDeckAction.h"
#include "StreamDockCPPSDK/StreamDockSDK/HSDLogger.h"

namespace {
const std::string helloActionId = "com.sonicdeck.streamdock.hello.hello";
}

std::shared_ptr<HSDAction> SonicDeckPlugin::GetOrCreateAction(
    const std::string& action,
    const std::string& context) {
    const auto existing = actionsByContext.find(context);
    if (existing != actionsByContext.end()) {
        return existing->second;
    }

    if (action != helloActionId) {
        HSDLogger::LogMessage("Unknown action requested: " + action);
        return nullptr;
    }

    auto instance = std::make_shared<SonicDeckAction>(
        mConnectionManager,
        action,
        context);
    actionsByContext.emplace(context, instance);
    return instance;
}

std::shared_ptr<HSDAction> SonicDeckPlugin::FindAction(
    const std::string& action,
    const std::string& context) {
    const auto existing = actionsByContext.find(context);
    if (existing == actionsByContext.end() || existing->second->GetAction() != action) {
        return nullptr;
    }
    return existing->second;
}

bool SonicDeckPlugin::RemoveAction(
    const std::string& action,
    const std::string& context) {
    if (!FindAction(action, context)) {
        return false;
    }
    return actionsByContext.erase(context) != 0;
}
