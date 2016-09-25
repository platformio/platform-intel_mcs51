# platform-mcs51
MCS51: development platform for PlatformIO https://github.com/Palatis/platform-mcs51/wiki

**This platform is EXPERIMENTAL, expect things to fail.**

# HOWTO (Setup Platform.io for MCS-51)

You only need one magic command:

- `$ platformio platforms install https://github.com/Palatis/platform-mcs51.git`

# HOWTO (Setup your MCS-51 project)
## The simple way:

1. PlatformIO -> Initialize or Update PlatformIO Project
2. Select Board -> Nuvoton -> n79e85x (because this is the only "supported" board right now...)
3. Choose a directory
4. Process!

## The manual way:

1. Add your project folder
2. move your project into PlatformIO layout (that is, source codes in `/src`, and library files in `/lib`)
3. create `platformio.ini`, and put in the following content:
```
[env:n79e85x]
platform = mcs51
board = n79e85x ; because this is the only "supported" board right now...
framework = naked
