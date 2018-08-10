# Intel ARC32: development platform for [PlatformIO](http://platformio.org)
[![Build Status](https://travis-ci.org/platformio/platform-intel_8051.svg?branch=develop)](https://travis-ci.org/platformio/platform-intel_8051)
[![Build status](https://ci.appveyor.com/api/projects/status/o2mw4111t1yjqch7/branch/develop?svg=true)](https://ci.appveyor.com/project/ivankravets/platform-intel_8051/branch/develop)

ARC embedded processors are a family of 32-bit CPUs that are widely used in SoC devices for storage, home, mobile, automotive, and Internet of Things applications.

* [Home](http://platformio.org/platforms/intel_8051) (home page in PlatformIO Platform Registry)
* [Documentation](http://docs.platformio.org/page/platforms/intel_8051.html) (advanced usage, packages, boards, frameworks, etc.)

# Usage

1. [Install PlatformIO](http://platformio.org)
2. Create PlatformIO project and configure a platform option in [platformio.ini](http://docs.platformio.org/page/projectconf.html) file:

## Stable version

```ini
[env:stable]
platform = intel_8051
board = ...
...
```

## Development version

```ini
[env:development]
platform = https://github.com/platformio/platform-intel_8051.git
board = ...
...
```

# Configuration

Please navigate to [documentation](http://docs.platformio.org/page/platforms/intel_8051.html).
