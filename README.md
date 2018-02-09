# platform-mcs51
MCS51: development platform for PlatformIO https://github.com/platformio/platform-mcs51/wiki

**This platform is EXPERIMENTAL, expect things to fail.**

# HOWTO (Setup Platform.io for MCS-51)

You only need one magic command:

- `$ platformio platforms install https://github.com/platformio/platform-mcs51.git`

# HOWTO (Setup your MCS-51 project)
## The simple way:

1. PlatformIO -> Initialize or Update PlatformIO Project
2. Select Board -> Nuvoton -> n79e85x
3. Choose a directory
4. Process!

## The manual way:

1. Add your project folder
2. move your project into PlatformIO layout (that is, source codes in `/src`, and library files in `/lib`)
3. create `platformio.ini`, and put in the following content:
```
[env:n79e85x]
platform = mcs51
board = n79e85x ;
framework = naked
```

## mcu support
### Nuvoton
* n79e85x
### STC
(Experimental!)
* STC15F204EA (Ram: 256, Flash: 4k)
* STC15W404AS (Ram: 256 + 256, Flash: 4k)
* STC15W408AS (Ram: 256 + 256, Flash: 8k)

example:
```
board = stc15w408as
upload_protocol = stcgal
upload_port = /dev/ttyUSB0
```
