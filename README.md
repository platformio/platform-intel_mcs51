# Intel MCS-51 (8051): development platform for [PlatformIO](http://platformio.org)
[![Build Status](https://travis-ci.org/platformio/platform-intel_mcs51.svg?branch=develop)](https://travis-ci.org/platformio/platform-intel_mcs51)
[![Build status](https://ci.appveyor.com/api/projects/status/0207sb475heyoaxa/branch/develop?svg=true)](https://ci.appveyor.com/project/ivankravets/platform-intel-mcs51/branch/develop)

The Intel MCS-51 (commonly termed 8051) is an internally Harvard architecture, complex instruction set computer (CISC) instruction set, single chip microcontroller (µC) series developed by Intel in 1980 for use in embedded systems.

* [Home](http://platformio.org/platforms/intel_mcs51) (home page in PlatformIO Registry)
* [Documentation](http://docs.platformio.org/page/platforms/intel_mcs51.html) (advanced usage, packages, boards, frameworks, etc.)

# Usage

1. [Install PlatformIO](http://platformio.org)
2. Create PlatformIO project and configure a platform option in [platformio.ini](http://docs.platformio.org/page/projectconf.html) file:

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

Please navigate to [documentation](http://docs.platformio.org/page/platforms/intel_mcs51.html).
