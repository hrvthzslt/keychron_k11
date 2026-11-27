# Keychron K11 Custom Layout with QMK

This is a separate _userspace_ repository from [QMK Layouts](https://github.com/hrvthzslt/qmk-layouts) for the **Keychron K11 Max**. It handles differences between the forked repository and _userspace_.

## Prerequisites

- Python 3
- Git

## Installation

To install QMK itself, see: [QMK Layouts](https://github.com/hrvthzslt/qmk-layouts).

Clone Keychron's QMK firmware fork for the K11 source and set it up with the installed QMK CLI:

```bash
make install
```

This will:
1. Clone the Keychron QMK firmware repository
2. Set up the fork and its dependencies with `qmk setup`
3. Configure QMK to use the Keychron fork

## Keychron K11 Max (ANSI Encoder RGB)

Compile the keyboard firmware with the new layout:

```bash
make k11-compile
```

Flash the firmware to the keyboard:

```bash
make k11-flash
```

## Troubleshooting

If QMK reports missing firmware dependencies, rerun `qmk setup -H ~/qmk_firmware_keychron`.
