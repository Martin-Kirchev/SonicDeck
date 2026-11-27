# Sonic Deck

Sonic Deck is a Windows plugin for MiraBox Stream Dock software, intended to let users control Spotify playback from customizable Stream Dock buttons. The Spotify controls are planned; the working prototype currently verifies plugin loading and key events.

Sonic Deck does not play or stream audio. Spotify remains the player, and playback commands are sent to the user's active Spotify device.

## Planned January 2027 beta

The first beta is targeted for January 2027, is intended for Windows, and is for the project owner and up to four testers (five Spotify developer-mode users total). Its planned actions are:

| Action | Description |
| --- | --- |
| Open Spotify | Launch or bring the Spotify desktop app to the foreground. |
| Play / Pause | Toggle playback on the active Spotify device. |
| Previous Track | Request the previous track. |
| Next Track | Skip to the next track. |
| Now Playing | Display the current track title and artist. |

Buttons are planned to show playback state and useful feedback for loading, unavailable, disconnected, or failed requests. The Now Playing display should avoid showing stale track information when Spotify is disconnected or nothing is playing.

## Spotify connection and requirements

Users will connect their Spotify account through Spotify's authorization flow. The plugin is planned to store authorization tokens locally and provide a way to disconnect the account. Playback control depends on Spotify account eligibility and an available active playback device. Spotify's developer access limits mean the beta is intended for the project owner and up to four testers, not public distribution.

Spotify's API access policies and requirements may affect who can use the plugin. See Spotify's [Web API documentation](https://developer.spotify.com/documentation/web-api) for current details. Sonic Deck will report unavailable commands rather than implying that a failed command succeeded.

## Deferred features

The following features are outside the January 2027 beta commitment and may be considered later:

- Volume Up, Volume Down, and Mute / Unmute. These need Spotify volume API support or separate Windows audio-control work.
- Submission to the MiraBox plugin store. This can be reconsidered after the beta and if Spotify access supports broader distribution.
- Album artwork and playback progress or time display
- Shuffle and repeat controls
- Starting a selected album or playlist
- Selecting or changing the Spotify Connect device
- Searching Spotify, queue management, or support for music services other than Spotify
- macOS and Linux support, unless the plugin host and Spotify launch integration are verified early and can be supported without putting the core release at risk; Windows is the initial target platform

## Project status

The minimal C++ Hello Sonic Deck prototype has been built and tested in Stream Dock. It loads as an action, displays “Press me,” and changes to “It works!” with the success indicator when pressed. This confirms the local plugin package, loading, and key-event path; it does not yet implement or test Spotify authorization or playback controls.

The January 2027 goal remains a working beta for the project owner and up to four testers. Spotify developer access, the required playback features, and beta eligibility still need to be confirmed. Store submission and public distribution remain deferred. See the [test plugin guide](com.sonicdeck.streamdock.hello.sdPlugin/README.md) for local build and installation steps and the [product specification](Sonic%20Deck%20Product%20Specification.md) for the confirmed SDK version and package format.

The product specification is in [Sonic Deck Product Specification.md](Sonic%20Deck%20Product%20Specification.md), and the original concept is in [Sonic Deck Idea.md](Sonic%20Deck%20Idea.md).
