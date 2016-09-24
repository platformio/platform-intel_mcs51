# Copyright 2014-present PlatformIO <contact@platformio.org>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""
    Builder for MCS-51 series of microcontrollers
"""

from os.path import join
from time import sleep

from SCons.Script import (ARGUMENTS, COMMAND_LINE_TARGETS, AlwaysBuild,
                          Builder, Default, DefaultEnvironment)

from platformio.util import get_serialports


def BeforeUpload(target, source, env):  # pylint: disable=W0613,W0621

    if "program" in COMMAND_LINE_TARGETS:
        return

    upload_options = {}
    if "BOARD" in env:
        upload_options = env.BoardConfig().get("upload", {})

    # Deprecated: compatibility with old projects. Use `program` instead
    if "usb" in env.subst("$UPLOAD_PROTOCOL"):
        upload_options['require_upload_port'] = False
        env.Replace(UPLOAD_SPEED=None)

    if env.subst("$UPLOAD_SPEED"):
        env.Append(UPLOADERFLAGS=["-b", "$UPLOAD_SPEED"])

    if upload_options and not upload_options.get("require_upload_port", False):
        return

    env.AutodetectUploadPort()
    env.Append(UPLOADERFLAGS=["-P", '"$UPLOAD_PORT"'])

    if not upload_options.get("disable_flushing", False):
        env.FlushSerialBuffer("$UPLOAD_PORT")

    before_ports = get_serialports()


env = DefaultEnvironment()

env.Replace(
    AR="sdar",
    AS="sdas8051",
    CC="sdcc",
    # CXX="sdcc",
    OBJCOPY="sdobjcopy",
    # RANLIB="avr-ranlib",
    # SIZETOOL="avr-size",

    # ARFLAGS=["rcs"],

    # ASFLAGS=["-x", "assembler-with-cpp"],

    CFLAGS=[
        "--std-c11"
    ],

    CCFLAGS=[
        "--opt-code-size",  # optimize for size
        "--peep-asm", # peephole optimization on inline assembly
        "--peep-return", # peephole optimization for return instructions
        "-m$BOARD_MCU"
    ],

    #CXXFLAGS=[
    #    "-fno-exceptions",
    #    "-fno-threadsafe-statics",
    #    "-std=gnu++11"
    #],

    CPPDEFINES=[
        "F_CPU=$BOARD_F_CPU",
        "F_OSC=$BOARD_F_FLASH", # FIXME: using $BOARD_F_FLASH here because
                                #        I don't know how to add an env var in
                                #        Platform.IO...
    ],

    LINKFLAGS=[
        # "-Os",
        "-m$BOARD_MCU",
    #    "-Wl,--gc-sections,--relax"
    ],

    LIBS=["m"],

    # SIZEPRINTCMD='$SIZETOOL --mcu=$BOARD_MCU -C -d $SOURCES',

    PROGNAME="firmware",
    PROGSUFFIX=".elf"
)

env.Append(
    ASFLAGS=env.get("CCFLAGS", [])[:],

    BUILDERS=dict(
        ElfToEep=Builder(
            action=env.VerboseAction(" ".join([
                "$OBJCOPY",
                "-O",
                "ihex",
                "-j",
                ".eeprom",
                '--set-section-flags=.eeprom="alloc,load"',
                "--no-change-warnings",
                "--change-section-lma",
                ".eeprom=0",
                "$SOURCES",
                "$TARGET"
            ]), "Building $TARGET"),
            suffix=".eep"
        ),

        ElfToHex=Builder(
            action=env.VerboseAction(" ".join([
                "$OBJCOPY",
                "-O",
                "ihex",
                "-R",
                ".eeprom",
                "$SOURCES",
                "$TARGET"
            ]), "Building $TARGET"),
            suffix=".hex"
        )
    )
)

env.Replace(
    UPLOADER="avrdude",
    UPLOADERFLAGS=[
        "-p", "$BOARD_MCU",
        "-C",
        '"%s"' % join(
            env.PioPlatform().get_package_dir("tool-srecord") or "",
	    "avrdude.conf"),
        "-c", "$UPLOAD_PROTOCOL"
    ],
    UPLOADHEXCMD='$UPLOADER $UPLOADERFLAGS -D -U flash:w:$SOURCES:i',
    UPLOADEEPCMD='$UPLOADER $UPLOADERFLAGS -U eeprom:w:$SOURCES:i',
    PROGRAMHEXCMD='$UPLOADER $UPLOADERFLAGS -U flash:w:$SOURCES:i'
)
if int(ARGUMENTS.get("PIOVERBOSE", 0)):
    env.Prepend(UPLOADERFLAGS=["-v"])

#
# Target: Build executable and linkable firmware
#

target_elf = env.BuildProgram()

#
# Target: Build the .hex file
#

if "uploadlazy" in COMMAND_LINE_TARGETS:
    target_firm = join("$BUILD_DIR", "firmware.hex")
else:
    target_firm = env.ElfToHex(join("$BUILD_DIR", "firmware"), target_elf)

#
# Target: Print binary size
#

target_size = env.Alias(
    "size", target_elf,
    env.VerboseAction("$SIZEPRINTCMD", "Calculating size $SOURCE"))
AlwaysBuild(target_size)

#
# Target: Upload by default .hex file
#

upload = env.Alias(
    ["upload", "uploadlazy"], target_firm,
    [env.VerboseAction(BeforeUpload, "Looking for upload port..."),
     env.VerboseAction("$UPLOADHEXCMD", "Uploading $SOURCE")])
AlwaysBuild(upload)

#
# Target: Upload EEPROM data (from EEMEM directive)
#

uploadeep = env.Alias(
    "uploadeep", env.ElfToEep(join("$BUILD_DIR", "firmware"), target_elf),
    [env.VerboseAction(BeforeUpload, "Looking for upload port..."),
     env.VerboseAction("$UPLOADEEPCMD", "Uploading $SOURCE")])
AlwaysBuild(uploadeep)

#
# Target: Upload firmware using external programmer
#

program = env.Alias(
    "program", target_firm,
    [env.VerboseAction(BeforeUpload, "Looking for upload port..."),
     env.VerboseAction("$PROGRAMHEXCMD", "Programming $SOURCE")])

AlwaysBuild(program)


#
# Setup default targets
#

Default([target_firm, target_size])
