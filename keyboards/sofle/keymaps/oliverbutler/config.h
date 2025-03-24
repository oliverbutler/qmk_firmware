// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Configure TAPPING_TERM
// The time (in milliseconds) that a key must be held to register as a "hold" action
// Increased from default 200ms to make taps more reliable, especially for the Enter key
// Higher values make it easier to register taps, but might make holds feel slightly delayed
#define TAPPING_TERM 225

// When enabled, releasing a dual-function key without pressing another key will
// always send the tap action (Enter in your case), even if you held it longer than TAPPING_TERM
// This prevents "lost" Enter keypresses when you hold slightly too long
#define RETRO_TAPPING

// If you tap a dual-function key twice quickly (within this many milliseconds),
// the second press will be registered as a tap rather than starting a hold
// This makes double-tapping Enter work reliably even if you're typing quickly
#define QUICK_TAP_TERM 120

#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_UPPER_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4
