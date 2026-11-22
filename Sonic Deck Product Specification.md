# Sonic Deck — January 2027 Beta Specification

**Status:** Proposed beta commitment  
**Target:** January 2027  
**Product:** Sonic Deck plugin for MiraBox Stream Dock software

## 1. Product in one sentence

Sonic Deck puts essential Spotify controls and the currently playing track on a MiraBox Stream Dock, so a user can manage music without switching away from their current task.

## 2. Who it is for

The first beta is for the project owner and up to four testers who use Spotify on Windows and have a MiraBox Stream Dock device supported by the Stream Dock application. This matches Spotify's five-user Development Mode limit, which includes the app owner. Sonic Deck is a focused companion plugin, not a Spotify player or a general music service controller.

## 3. What ships by January 2027

The January beta will include an installable plugin with these five actions:

| Stream Dock action | What it does | Button appearance |
|---|---|---|
| Open Spotify | Launches the Spotify desktop app. If Spotify is already open, brings it to the foreground. | Spotify-inspired app icon; brief pressed state. |
| Play / Pause | Toggles playback on the user's active Spotify device. | Play or pause glyph reflects the latest known playback state. |
| Previous Track | Requests the previous track on the active device. | Previous-track glyph. |
| Next Track | Skips to the next track on the active device. | Next-track glyph. |
| Now Playing | Displays the current track title and artist. | Two-line, truncated text layout with a neutral idle state when nothing is playing. |

The actions will have a consistent visual style, recognizable at Stream Dock button size, with readable labels and clear unavailable, loading, and disconnected states. Dynamic states will update without requiring the user to press a key.

### Included setup and recovery experience

- A short setup guide covering plugin installation, Spotify sign-in, and common connection problems.
- An explicit Spotify account connection flow using the supported authorization method; tokens are stored locally and can be disconnected by the user.
- Clear feedback when Spotify is not signed in, the account lacks the required playback entitlement, there is no active Spotify device, or Spotify cannot be reached.
- Reconnection behavior after a temporary network/API failure, with rate-limit responses respected.
- A distributable plugin package and versioned source so the plugin can be updated and bug-fixed.

## 4. User experience

### First use

1. The user installs Sonic Deck in MiraBox Stream Dock software and adds the desired actions to keys.
2. On first use of a Spotify action, Sonic Deck asks the user to connect Spotify and opens Spotify's authorization page.
3. After authorization, the user returns to Stream Dock and presses a control key. Sonic Deck shows a short status or error if setup is incomplete.
4. The Now Playing key begins showing the current song and artist when Spotify playback information is available.

### Normal use

Playback keys issue one action per press. The Play/Pause key shows the latest state Sonic Deck has received. The Now Playing key refreshes periodically while connected and responds to track changes. If metadata is unavailable, it displays a concise state such as “Spotify not connected” or “Nothing playing,” rather than stale song information.

There may be a short delay between a press and the displayed state changing because commands and playback status are obtained through Spotify services. The UI must not imply success when Spotify reports that a command failed.

## 5. Requirements and acceptance criteria

The January beta is ready when all of these are true:

1. Every action listed in Section 3 can be added to a Stream Dock key and has its own finished icon/state design.
2. With a connected, eligible Spotify account and an active playback device, play/pause, previous, and next commands work and report failures clearly.
3. Open Spotify launches or foregrounds the Spotify desktop app on the supported release platform.
4. Now Playing shows the current track title and artist, updates on track changes, and handles no playback and unavailable metadata without showing stale details.
5. The user can connect and disconnect Spotify through the documented flow; credentials are not included in logs or the distributable package.
6. Temporary network/API failures do not crash the Stream Dock plugin. The plugin displays a useful state and can recover when service returns.
7. A clean installation guide, troubleshooting notes, beta package, and version number are included.
8. The beta can be shared with the project owner and a few testers who are permitted to use the Spotify app integration.

## 6. Explicitly deferred

These ideas are not part of the January delivery commitment:

- Volume Up, Volume Down, and Mute / Unmute. These need Spotify volume API support or separate Windows audio-control work, so they are deferred from the first beta.
- Submission to the MiraBox plugin store. Store distribution can be reconsidered if the beta is successful and Spotify access supports a broader audience.
- Album artwork and progress/time display.
- Shuffle and repeat controls.
- Starting a chosen album or playlist.
- Selecting or changing the Spotify Connect device.
- Searching Spotify, queue management, or support for services other than Spotify.
- macOS/Linux support unless the chosen plugin host and Spotify launch integration are verified early and fit without risking the core release. The initial target platform is Windows.

These can be considered for a later release after the core plugin has been tested with users.

## 7. Important platform assumptions and release risk

- **Spotify account:** Playback control through Spotify's Web API requires Spotify Premium. Sonic Deck will not stream audio itself; Spotify remains the player.
- **Spotify developer access:** Spotify's published 2026 Development Mode limits include an active Premium subscription for the app owner and a limit of five users for a new app, including the app owner. The January goal is intentionally a working beta for the project owner and up to four testers, not a public release. Before inviting testers, confirm the app's current user limit and add only eligible testers through Spotify's developer dashboard.
- **Active device:** Spotify playback commands need an available Spotify playback device. Sonic Deck will not silently start an unrelated device or claim to select the desktop app.
- **MiraBox compatibility:** The exact Stream Dock software/SDK version and package format must be confirmed in the first development week. Store submission is deferred and is not part of the beta commitment.

These constraints must be checked early, before promising tester access. Spotify documents the Premium and development-mode restrictions in its [Web API reference](https://developer.spotify.com/documentation/web-api/reference/start-a-users-playback) and [February 2026 migration guide](https://developer.spotify.com/documentation/web-api/tutorials/february-2026-migration-guide); available permissions are listed in its [OAuth scopes reference](https://developer.spotify.com/documentation/web-api/concepts/scopes).

## 8. Plan for finishing by January 2027

The work is split into four stages. Each stage has a clear result so we can spot problems early and keep the January deadline realistic.

### Stage 1 — Check the basics (by November 30, 2026)

Before building every button, confirm that Sonic Deck can be made into a MiraBox Stream Dock plugin and can connect to Spotify on Windows. Get one Spotify command working and confirm that Sonic Deck can read the current playback state. Check that the project owner's Spotify developer account and the intended few testers can be added to the app.

**Ready to move on when:** the plugin can run in Stream Dock, connect to Spotify, send a command, and receive playback information on the target Windows setup.

**Why this comes first:** if Spotify access or the Stream Dock plugin format blocks the project, we need to know while there is still time to adjust the beta plan.

### Stage 2 — Build the required features (December 2026)

Build the Spotify sign-in and connection flow, the five required actions, Now Playing information, button designs, and useful messages for errors or unavailable controls. Do not add the deferred features from Section 6 during this stage.

**Ready to move on when:** every required action in Section 3 works on the target setup, including its normal display and its unavailable or error display.

### Stage 3 — Prepare the beta (early January 2027)

Create an installable beta version. Check that a fresh installation works, work through the acceptance criteria in Section 5, fix problems that prevent the beta from working, and finish the setup and troubleshooting instructions.

**Ready to move on when:** the required features pass the acceptance criteria and a tester can install and set up the plugin using the instructions.

### Stage 4 — Share the beta (by January 31, 2027)

Package the beta with a version number, release notes, and setup instructions. Share it with the project owner and a few testers who have been added to the Spotify developer app.

**What we can commit to:** preparing a working beta for the project owner and up to four permitted testers by the deadline. Public availability and MiraBox store submission are future decisions, after Spotify's access limits and the beta results are understood.

## 9. Definition of success

The beta succeeds if the project owner and up to four testers can install the plugin, connect eligible Spotify accounts, control active Spotify playback from Stream Dock, identify the current track, and understand when a command is unavailable. The beta is versioned and documented so it can be updated as issues are found. Public availability and store distribution are not goals for this milestone.

## 10. Terminology

**MiraBox Stream Dock** refers to the software and customizable buttons the plugin is designed for. Sonic Deck sends playback commands to the user's active Spotify device; Spotify remains responsible for playing and streaming audio. This project does not promise compatibility with Elgato Stream Deck or other button-controller platforms.
