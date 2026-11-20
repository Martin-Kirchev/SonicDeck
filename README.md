# Sonic Deck

Sonic Deck is a planned plugin for MiraBox Stream Dock software. It will let users control Spotify playback from customizable Stream Dock buttons, so they can manage music without leaving their current task.

Sonic Deck does not play or stream audio. Spotify remains the player, and playback commands are sent to the user's active Spotify device.

## Planned first release

The initial release is targeted for January 2027 and is intended for Windows. Its planned actions are:

| Action | Description |
| --- | --- |
| Open Spotify | Launch or bring the Spotify desktop app to the foreground. |
| Play / Pause | Toggle playback on the active Spotify device. |
| Previous Track | Request the previous track. |
| Next Track | Skip to the next track. |
| Volume Up / Down | Adjust Spotify device volume by a documented step, when supported by the device. |
| Mute / Unmute | Toggle mute and restore the last non-zero volume observed by Sonic Deck. |
| Now Playing | Display the current track title and artist. |

Buttons are planned to show playback state and useful feedback for loading, unavailable, disconnected, or failed requests. The Now Playing display should avoid showing stale track information when Spotify is disconnected or nothing is playing.

## Spotify connection and requirements

Users will connect their Spotify account through Spotify's authorization flow. The plugin is planned to store authorization tokens locally and provide a way to disconnect the account. Playback control depends on Spotify account eligibility and an available active playback device. Some devices may not support Spotify volume control.

Spotify's API access policies and requirements may affect who can use the plugin. See Spotify's [Web API documentation](https://developer.spotify.com/documentation/web-api) for current details. Sonic Deck will report unavailable commands rather than silently changing system volume or implying that a failed command succeeded.

## Deferred features

The following features are explicitly outside the January 2027 release commitment and may be considered for a later release:

- Album artwork and playback progress or time display
- Shuffle and repeat controls
- Starting a selected album or playlist
- Selecting or changing the Spotify Connect device
- Searching Spotify, queue management, or support for music services other than Spotify
- macOS and Linux support, unless the plugin host and Spotify launch integration are verified early and can be supported without putting the core release at risk; Windows is the initial target platform

## Project status

The project is in the planning stage. The January 2027 release is a target; Stream Dock SDK and package requirements, Spotify access, and store submission requirements still need to be confirmed. A MiraBox plugin store listing is conditional on the store accepting third-party submissions and on Spotify access permitting the intended distribution.

The product specification is in [Sonic Deck Product Specification.md](Sonic%20Deck%20Product%20Specification.md), and the original concept is in [Sonic Deck Idea.md](Sonic%20Deck%20Idea.md).
