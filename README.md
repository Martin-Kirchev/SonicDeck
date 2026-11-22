# Sonic Deck

Sonic Deck is a planned plugin for MiraBox Stream Dock software. It will let users control Spotify playback from customizable Stream Dock buttons, so they can manage music without leaving their current task.

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

The project is in the planning stage. The January 2027 goal is a working beta for the project owner and up to four testers. Stream Dock SDK and package requirements and Spotify access still need to be confirmed. Public release and MiraBox plugin store submission are deferred until after the beta and a review of Spotify's access limits.

The product specification is in [Sonic Deck Product Specification.md](Sonic%20Deck%20Product%20Specification.md), and the original concept is in [Sonic Deck Idea.md](Sonic%20Deck%20Idea.md).
