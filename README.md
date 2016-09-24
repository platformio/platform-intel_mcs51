# platform-mcs51
MCS51: development platform for PlatformIO https://github.com/Palatis/platform-mcs51/wiki

# HOWTO (Setup Platform.io for MCS-51)
These instructions are targeted for Linux. If you're on another platform, you're on your own.

However, the steps are pretty similar, you just have to put the files to the correct location...

1. `$ cd ~/.platformio/frameworks`
2. `$ git clone https://github.com/Palatis/platform-mcs51.git mcs51`
3. `$ cd ~/.platformio/packages`
4. `$ git clone https://github.com/Palatis/framework-nakedmcs51.git framework-nakedmcs51`
5. Go to [SDCC](http://sdcc.sourceforge.net/) and download the snapshot matching your host platform. I'm using [sdcc-snapshot-amd64-unknown-linux2.5-20160924-9771.tar.bz2](http://sourceforge.net/projects/sdcc/files/snapshot_builds/amd64-unknown-linux2.5/sdcc-snapshot-amd64-unknown-linux2.5-20160924-9771.tar.bz2/download) because I'm on Linux AMD64.
6. `$ git clone https://github.com/Palatis/toolchain-sdcc.git toolchain-sdcc`
7. `$ cd toolchain-sdcc`
8. `$ tar vxf <path>/<to>/<download>/sdcc-snapshot-amd64-unknown-linux2.5-20160924-9771.tar.bz2`

# HOWTO (Setup your MCS-51 project)
## The simple way:

1. PlatformIO -> Initialize or Update PlatformIO Project
2. Select Board -> Nuvoton -> n79e85x (because this is the only "supported" board right now...)
3. Choose a directory
4. Process!

## The manual way:

1. Add your project folder
2. move your project into PlatformIO layout (that is, source codes in `/src`, and library files in `lib`)
3. create `platformio.ini`, and put in the following content:
```
[env:n79e85x]
platform = mcs51
board = n79e85x ; because this is the only "supported" board right now...
framework = naked
