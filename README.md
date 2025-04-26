# Keychron K11 Custom Layout with QMK

This is a separate _userspace_ repository from [QMK Layouts](https://github.com/hrvthzslt/qmk-layouts) for the **Keychron K11 Max**. It handles differences between the forked repository and _userspace_.

## Installation

To install QMK itself, see: [QMK Layouts](https://github.com/hrvthzslt/qmk-layouts).

Clone Keychron's QMK firmware fork for the K11 source, and set up this repository as _userspace_.

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
