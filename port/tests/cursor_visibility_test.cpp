// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2026 the OpenRAC contributors
//
// A keyboard/mouse mod may release relative capture for native PC-style menu
// hover. The OS cursor must then be visible, unlike in normal gameplay.

#include "check.h"
#include "game/common/frontend/cursor_visibility.h"

int main() {
    using openrac::frontend::cursor_visible;

    // The original game, without a mouse mod, keeps hiding its cursor.
    CHECK(!cursor_visible(false, false, false, true));
    CHECK(!cursor_visible(false, false, true, true));

    // A mod that takes the mouse releases capture on the menu: pointer shown.
    CHECK(cursor_visible(false, true, false, true));

    // Gameplay capture still keeps the pointer invisible.
    CHECK(!cursor_visible(false, true, true, true));

    // Lost window focus cannot make the mod show the pointer in that window.
    CHECK(!cursor_visible(false, true, false, false));

    // OpenRAC's own overlay may show its cursor independently of mouse mods.
    CHECK(cursor_visible(true, false, false, true));
    CHECK(cursor_visible(true, true, false, true));

    return openrac::test::result();
}
