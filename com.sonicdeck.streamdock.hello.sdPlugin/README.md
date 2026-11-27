# Sonic Deck Hello (C++)

This minimal MiraBox Stream Dock plugin exercises plugin loading and key events. Add **Hello Sonic Deck** to a key. It displays **Press me** and changes to **It works!** with the Stream Dock success indicator when pressed.

## Requirements

- Windows 10 or newer
- MiraBox Stream Dock software 2.9 or newer
- Visual Studio 2022 or newer with the C++ desktop workload, MSVC x64/x86 build tools, and a Windows SDK
- CMake 3.25 or newer

## Build and install for a local test

Open **Developer PowerShell for Visual Studio** (the version installed on your computer) so the MSVC build environment is initialized. From the project root, run:

```powershell
cmake -S cpp -B cpp/build -A x64
cmake --build cpp/build --config Release
Copy-Item cpp/build/Release/sonicDeckStreamDockHello.exe com.sonicdeck.streamdock.hello.sdPlugin/
Copy-Item -Recurse com.sonicdeck.streamdock.hello.sdPlugin "$env:APPDATA/Hotspot/StreamDock/plugins/"
```

Restart Stream Dock, find **Hello Sonic Deck** in the action list, and drag it onto a key. Press the key; its title should change and the success indicator should flash.

This test has been completed successfully on the project owner's Windows setup. It confirms plugin loading and key events only; Spotify integration is not implemented in this prototype.

The CMake project uses the dependency archives bundled in `cpp/StreamDockCPPSDK/Vendor`; the first CMake configure extracts those local archives. This folder is a development plugin, not a signed or store-ready release package.

The local install is a `.sdPlugin` package folder copied into `%APPDATA%\Hotspot\StreamDock\plugins\`. The folder contains `manifest.json`, the built Windows executable, and image assets. For this prototype, `manifest.json` declares `SDKVersion` 3. This is a development folder package; it is not a signed installer or a plugin-store release.

## SDK source and license

The C++ runtime and bundled SDK dependencies are from MiraBox's [StreamDock Plugin SDK](https://github.com/MiraboxSpace/StreamDock-Plugin-SDK). The SDK sources retain their included license and copyright notices. The SDK template is MIT licensed; see [the SDK license](../cpp/LICENSE).
