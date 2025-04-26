# Keychron K11 Custom Layout with QMK

Separate _userspace_ repository from [QMK Layouts](https://github.com/hrvthzslt/qmk-layouts) for **Keychron K11 Max**, for handling fork repository and _userspace_ differences.

## Install

For installing QMK itself check: [QMK Layouts](https://github.com/hrvthzslt/qmk-layouts)

Clone Keychron's QMK firmware fork for k11 source, and setup this repository as _userspace_.

```bash
make install
```

## Keychron K11 Max (ANSI Encoder RGB)

Compile the keyboard firmware with the new layout.

```bash
make k11-compile
```

Flash the firmware to the keyboard.

```bash
make k11-flash
```
