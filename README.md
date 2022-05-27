# Intel MCS-51 (8051): development platform for [PlatformIO](https://platformio.org)
[![Build Status](https://github.com/platformio/platform-intel_mcs51/workflows/Examples/badge.svg)](https://github.com/platformio/platform-intel_mcs51/actions)

The Intel MCS-51 (commonly termed 8051) is an internally Harvard architecture, complex instruction set computer (CISC) instruction set, single chip microcontroller (µC) series developed by Intel in 1980 for use in embedded systems.

* [Home](https://registry.platformio.org/platforms/platformio/intel_mcs51) (home page in PlatformIO Registry)
* [Documentation](https://docs.platformio.org/page/platforms/intel_mcs51.html) (advanced usage, packages, boards, frameworks, etc.)

# Usage

1. [Install PlatformIO](https://platformio.org)
2. Create PlatformIO project and configure a platform option in [platformio.ini](https://docs.platformio.org/page/projectconf.html) file:

## Stable version

```ini
[env:stable]
platform = intel_mcs51
board = ...
...
```

## Development version

```ini
[env:development]
platform = https://github.com/platformio/platform-intel_mcs51.git
board = ...
...
```

# Configuration

Please navigate to [documentation](https://docs.platformio.org/page/platforms/intel_mcs51.html).
