# Colemak layout for the Kimiko Rev.1 from Keycapss

For the last couple of weeks, I've been working on a layout to work with this nice split keyboard. I've wanted to try out the Colemak layout but was in need of some specific letters from the French alphabet as I work in the French-speaking part of Switzerland.

Also as I need to switch between MacOS and Ubuntu I've created a way to switch from one to the other and still have the same shortcuts positioning (`ctrl` and `cmd` have been inverted).

You can download this and install it as is on your Kimiko or feel free to create a fork for your own needs.

## How to install

This supposes that you have already installed the QMK environment. If you haven't yet please follow the steps from their tutorial (currently found [here](https://docs.qmk.fm/#/newbs_getting_started)). Please also check the doc for any steps that would be unclear.

Then follow these steps:

1. go to the folder containing the Keycapsss layout
2. clone this project there
3. compile the layout
4. flash the layout to the two halves of your keyboard

I hope you will appreciate the work done on the layout.

## Layouts

Be aware that `ctrl` and `cmd` have been inverted on the Mac layout as to be able to use the same muscle memory for shortcuts.

### Default layout

```
,--------------------------------------------.                    ,----------------------------------------------.
|   ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  BackSP   |
|---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
|   Tab   |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   É  |  È        |
|---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
|  LShift |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '        |
|---------+------+------+------+------+------|   ^   |    |    À  |------+------+------+------+------+-----------|
|  LCTRL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   -  |  RShift   |
`--------------------------------------------|       /     \      \----------------------------------------------'
                 | MEDIA | LGUI | LATL | LOWER|Space /       \Enter \  |  RAISE  |Delete| RGUI | RALT |
                 `----------------------------------'         '------------------------------------'
```

### Lower / Numpad layout

```
,--------------------------------------------.                    ,----------------------------------------------.
|   ESC   |      |      |      |      |LRESET|                    | PRSC |      |      |      |      |  Delete   |
|---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
|   Tab   |      | Home |  Up  |  End |      |                    | CAPS |   7  |   8  |   9  |   '  |           |
|---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
|  LShift |      | Left | Down | Right|      |-------.    ,-------|   /  |   4  |   5  |   6  |   -  |           |
|---------+------+------+------+------+------|   Ç   |    |   `   |------+------+------+------+------+-----------|
|  LCTRL  |   `  | Sup.L|      | Sup.R|      |-------|    |-------|   *  |   1  |   2  |   3  |   +  |           |
`--------------------------------------------|       /     \      \-----------------------------------------------'
                 |MEDIA | LGUI | LATL |LOWER |Space /      \Enter \RAISE |   0  |   .  |      |
                 `----------------------------------'       '------------------------------------'
```

### Raise / Unicode layout

```
,--------------------------------------------.                    ,----------------------------------------------.
|   ESC   |      |      |   <  |   >  |LRESET|                    |      |      |      |      |      |  Delete   |
|---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
|   Tab   |      |      |   [  |   ]  |      |                    |      |   %  |   #  |   |  |   '  |           |
|---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
|  LShift |      |      |   (  |   )  |      |-------.    ,-------|      |   $  |   @  |   =  |   ~  |           |
|---------+------+------+------+------+------|  LOCK |    |SW_MAC |------+------+------+------+------+-----------|
|  LCTRL  |      |      |   {  |   }  |      |-------|    |-------|      |   &  |   "  |   !  |      |  RShift   |
`--------------------------------------------|       /     \      \----------------------------------------------'
                 | MEDIA| LGUI | LATL |LOWER| Space /      \Enter \RAISE |BackSP| RGUI | RALT |
                 `----------------------------------'      '----------------------------------'
```

### Media layout

```
,-------------------------------------------.                    ,-----------------------------------------.
|   ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |BackSP|
|--------+------+------+------+------+------|                    |------+------+------+------+------+------|
| RGB ON | HUE+ | SAT+ | VAL+ |      |      |                    |      | PREV | PLAY | NEXT |      |      |
|--------+------+------+------+------+------|                    |------+------+------+------+------+------|
| MODE   | HUE- | SAT- | VAL- |      |      |-------.    ,-------|      | VOL- | MUTE | VOL+ |      |      |
|--------+------+------+------+------+------|   <   |    |SW_MAC |------+------+------+------+------+------|
|        |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
`-------------------------------------------|       /     \      \-----------------------------------------'
                | MEDIA| LGUI | LATL |LOWER| Space /      \Enter \RAISE |BackSP| RGUI | RALT |
                `----------------------------------'      '----------------------------------'
```

## Special thanks

A big thank you to the Keycapsss team for their great work on the keyboard and on giving the default layout from which I've been able to branch from.