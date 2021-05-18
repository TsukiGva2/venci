<!---
 i edited this thing with venci, it -kind of- ran well
-->

- ESC    switch mode, I(default) or N

## N mode commands

- D    delete line
- u    undo changes on line (since last save)

- hjkl move around

- <    insert a space before the cursor
- \>    insert a space after the cursor

- J    move downwards X lines
- K    move upwards X lines

- p    insert a string before the cursor

- [    copy a line
- {    append a line to the copy buffer
- ]    paste whatever is on the copy buffer

## General commands (stuff that works in all modes)

- Ctrl-S     save current file, asks for a filename if no file was opened
- Ctrl-Q     quits venci
- Tab        insert ec.ts spaces (default: 2), or a '\t' if ec.expand is FALSE

## Common editing stuff that also works on both modes

- Enter        works like you'd expect
- Backspace
- Delete       works, but does the same as Backspace
- Space
- Arrow keys
- HOME, END    ~~should~~ work
- PAGE UP/DOWN go to beginning/end of file
