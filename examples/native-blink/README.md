How to build PlatformIO based project
=====================================

1. [Install PlatformIO Core](http://docs.platformio.org/page/core.html)
2. Download [development platform with examples](https://github.com/platformio/platform-intel_mcs51/archive/develop.zip)
3. Extract ZIP archive
4. Run these commands:

```shell
# Change directory to example
$ cd platform-intel_mcs51/examples/native-blink

# Build project
$ pio run

# Upload firmware
$ pio run --target upload

# Build specific environment
$ pio run -e stc15f204ea

# Upload firmware for the specific environment
$ pio run -e stc15f204ea --target upload

# Clean build files
$ pio run --target clean
```
