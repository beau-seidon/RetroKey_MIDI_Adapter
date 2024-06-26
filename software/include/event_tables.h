#pragma once
#include <Arduino.h>



enum EventType {
    UNUSED, DO_NOTHING, MAKE_ONLY, BREAK_ONLY,
    MIDI_NOTE_ON, MIDI_NOTE_OFF, ALL_NOTES_OFF,
    MIDI_CC_TOGGLE, MIDI_CC_ADJUST, MIDI_PITCHBEND,
    TRANSPOSE, CHANGE_VELOCITY, CHANGE_CHANNEL,
    FULL_RESET, PRINT, FUTURE
};


int scancode_to_event[4][132][2] = {
    {  // Table 0
        {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},                    {CHANGE_VELOCITY, -1},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},
        {UNUSED, 0},                    {DO_NOTHING, 0},                {DO_NOTHING, 0},                {CHANGE_VELOCITY, 1},
        {DO_NOTHING, 0},                {MIDI_NOTE_ON, 59},             {MIDI_NOTE_ON, 58},             {UNUSED, 0},
        {UNUSED, 0},                    {DO_NOTHING, 0},                {MIDI_NOTE_ON, 47},             {UNUSED, 0},
        {DO_NOTHING, 0},                {MIDI_NOTE_ON, 60},             {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {MIDI_NOTE_ON, 48},             {MIDI_NOTE_ON, 49},
        {DO_NOTHING, 0},                {MIDI_NOTE_ON, 62},             {MIDI_NOTE_ON, 61},             {UNUSED, 0},
        {UNUSED, 0},                    {MIDI_NOTE_ON, 52},             {MIDI_NOTE_ON, 50},             {MIDI_NOTE_ON, 51},
        {MIDI_NOTE_ON, 64},             {DO_NOTHING, 0},                {MIDI_NOTE_ON, 63},             {UNUSED, 0},
        {UNUSED, 0},                    {MIDI_CC_TOGGLE, 0x40FF},       {MIDI_NOTE_ON, 53},             {DO_NOTHING, 0},
        {MIDI_NOTE_ON, 67},             {MIDI_NOTE_ON, 65},             {MIDI_NOTE_ON, 66},             {UNUSED, 0},
        {UNUSED, 0},                    {MIDI_NOTE_ON, 57},             {MIDI_NOTE_ON, 55},             {MIDI_NOTE_ON, 56},
        {MIDI_NOTE_ON, 54},             {MIDI_NOTE_ON, 69},             {MIDI_NOTE_ON, 68},             {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {MIDI_NOTE_ON, 59},             {MIDI_NOTE_ON, 58},
        {MIDI_NOTE_ON, 71},             {MIDI_NOTE_ON, 70},             {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {MIDI_NOTE_ON, 60},             {DO_NOTHING, 0},                {MIDI_NOTE_ON, 72},
        {MIDI_NOTE_ON, 74},             {MIDI_NOTE_ON, 75},             {MIDI_NOTE_ON, 73},             {UNUSED, 0},
        {UNUSED, 0},                    {MIDI_NOTE_ON, 62},             {MIDI_NOTE_ON, 64},             {MIDI_NOTE_ON, 61},
        {MIDI_NOTE_ON, 63},             {MIDI_NOTE_ON, 76},             {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},
        {MIDI_NOTE_ON, 77},             {MIDI_NOTE_ON, 78},             {UNUSED, 0},                    {UNUSED, 0},
        {MIDI_NOTE_ON, 46},             {DO_NOTHING, 0},                {DO_NOTHING, 0},                {MIDI_NOTE_ON, 79},
        {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},                    {DO_NOTHING, 0},
        {DO_NOTHING, 0},                {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},
    },
    {  // Table 1 (EXT)
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {DO_NOTHING, 0},                {DO_NOTHING, 0},                {UNUSED, 0},
        {DO_NOTHING, 0},                {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},                    {DO_NOTHING, 0},
        {DO_NOTHING, 0},                {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},                {UNUSED, 0},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {MIDI_PITCHBEND, -1},           {UNUSED, 0},
        {DO_NOTHING, 0},                {MIDI_PITCHBEND, 1},            {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
    },
    {  // Table 2 (BREAK)
        {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},                    {DO_NOTHING, 0},
        {TRANSPOSE, -1},                {TRANSPOSE, -12},               {TRANSPOSE, 12},                {DO_NOTHING, 0},
        {UNUSED, 0},                    {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},
        {TRANSPOSE, 1},                 {MIDI_NOTE_OFF, 59},            {MIDI_NOTE_OFF, 58},            {UNUSED, 0},
        {UNUSED, 0},                    {DO_NOTHING, 0},                {MIDI_NOTE_OFF, 47},            {UNUSED, 0},
        {DO_NOTHING, 0},                {MIDI_NOTE_OFF, 60},            {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {MIDI_NOTE_OFF, 48},            {MIDI_NOTE_OFF, 49},
        {DO_NOTHING, 0},                {MIDI_NOTE_OFF, 62},            {MIDI_NOTE_OFF, 61},            {UNUSED, 0},
        {UNUSED, 0},                    {MIDI_NOTE_OFF, 52},            {MIDI_NOTE_OFF, 50},            {MIDI_NOTE_OFF, 51},
        {MIDI_NOTE_OFF, 64},            {DO_NOTHING, 0},                {MIDI_NOTE_OFF, 63},            {UNUSED, 0},
        {UNUSED, 0},                    {MIDI_CC_TOGGLE, 0x4000},       {MIDI_NOTE_OFF, 53},            {DO_NOTHING, 0},
        {MIDI_NOTE_OFF, 67},            {MIDI_NOTE_OFF, 65},            {MIDI_NOTE_OFF, 66},            {UNUSED, 0},
        {UNUSED, 0},                    {MIDI_NOTE_OFF, 57},            {MIDI_NOTE_OFF, 55},            {MIDI_NOTE_OFF, 56},
        {MIDI_NOTE_OFF, 54},            {MIDI_NOTE_OFF, 69},            {MIDI_NOTE_OFF, 68},            {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {MIDI_NOTE_OFF, 59},            {MIDI_NOTE_OFF, 58},
        {MIDI_NOTE_OFF, 71},            {MIDI_NOTE_OFF, 70},            {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {MIDI_NOTE_OFF, 60},            {DO_NOTHING, 0},                {MIDI_NOTE_OFF, 72},
        {MIDI_NOTE_OFF, 74},            {MIDI_NOTE_OFF, 75},            {MIDI_NOTE_OFF, 73},            {UNUSED, 0},
        {UNUSED, 0},                    {MIDI_NOTE_OFF, 62},            {MIDI_NOTE_OFF, 64},            {MIDI_NOTE_OFF, 61},
        {MIDI_NOTE_OFF, 63},            {MIDI_NOTE_OFF, 76},            {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},
        {MIDI_NOTE_OFF, 77},            {MIDI_NOTE_OFF, 78},            {UNUSED, 0},                    {UNUSED, 0},
        {MIDI_NOTE_OFF, 46},            {DO_NOTHING, 0},                {DO_NOTHING, 0},                {MIDI_NOTE_OFF, 79},
        {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},                    {DO_NOTHING, 0},
        {DO_NOTHING, 0},                {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {FULL_RESET, 911},              {DO_NOTHING, 0},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},
    },
    {  // Table 3 (EXT & BREAK)
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {DO_NOTHING, 0},                {DO_NOTHING, 0},                {UNUSED, 0},
        {DO_NOTHING, 0},                {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {ALL_NOTES_OFF, 123},           {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {DO_NOTHING, 0},                {UNUSED, 0},                    {DO_NOTHING, 0},
        {DO_NOTHING, 0},                {UNUSED, 0},                    {UNUSED, 0},                    {UNUSED, 0},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {DO_NOTHING, 0},                {UNUSED, 0},
        {DO_NOTHING, 0},                {DO_NOTHING, 0},                {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {MIDI_PITCHBEND, 0},            {UNUSED, 0},
        {DO_NOTHING, 0},                {MIDI_PITCHBEND, 0},            {UNUSED, 0},                    {UNUSED, 0},
        {UNUSED, 0},                    {UNUSED, 0},                    {DO_NOTHING, 0},                {DO_NOTHING, 0},
    }
};
