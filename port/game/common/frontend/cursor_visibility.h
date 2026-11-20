// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2026 the OpenRAC contributors
//
// Cursor visibility policy shared by the window and a no-window regression
// test. Mods that take the mouse need a visible pointer when they release
// relative capture to let the player hover over the game's menus.

#pragma once

namespace openrac::frontend {

// The port's own overlay still controls the cursor as before. A mouse mod
// opts into a system cursor for menus by taking OPENRAC_INPUT_MOUSE; without
// that opt-in the game's existing hidden-cursor behaviour is unchanged.
// Relative mouse capture always hides the normal in-game pointer.
constexpr bool cursor_visible(
    bool overlay_wants_cursor, bool mod_took_mouse, bool captured, bool focused
) {
    return overlay_wants_cursor || (mod_took_mouse && !captured && focused);
}

}  // namespace openrac::frontend
