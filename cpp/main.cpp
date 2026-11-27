#include "SonicDeckPlugin.h"
#include "StreamDockCPPSDK/StreamDockSDK/HSDMain.h"

int main(int argc, const char** argv) {
    auto plugin = std::make_shared<SonicDeckPlugin>();
    return esd_main(argc, argv, plugin);
}
