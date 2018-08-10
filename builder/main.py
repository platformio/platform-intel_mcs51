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

from SCons.Script import ARGUMENTS, AlwaysBuild, Default, DefaultEnvironment


def __getSize(size_type, env):
    # FIXME: i don't really know how to do this right. see:
    #        https://community.platformio.org/t/missing-integers-in-board-extra-flags-in-board-json/821
    return str(env.BoardConfig().get("build", {
        # defaults
        "size_heap": 1024,
        "size_iram": 256,
        "size_xram": 65536,
        "size_code": 65536,
    })[size_type])


env = DefaultEnvironment()

env.Replace(
    AR="sdar",
    AS="sdas8051",
    CC="sdcc",
    LD="sdld",
    RANLIB="sdranlib",
    OBJCOPY="sdobjcopy",
    OBJSUFFIX=".rel",
    LIBSUFFIX=".lib",

    # SIZEPRINTCMD='$SIZETOOL --mcu=$BOARD_MCU -C -d $SOURCES',

    PROGNAME="firmware",
    PROGSUFFIX=".ihx"
)

env.Append(
    ASFLAGS=env.get("CCFLAGS", [])[:],

    CFLAGS=[
        "--std-sdcc11"
    ],

    CCFLAGS=[
        "--opt-code-size",  # optimize for size
        "--peep-return",    # peephole optimization for return instructions
        "-m$BOARD_MCU"
    ],

    CPPDEFINES=[
        "F_CPU=$BOARD_F_CPU",
        "HEAP_SIZE=" + __getSize("size_heap", env)
    ],

    LINKFLAGS=[
        "-m$BOARD_MCU",
        "--iram-size", __getSize("size_iram", env),
        "--xram-size", __getSize("size_xram", env),
        "--code-size", __getSize("size_code", env),
        "--out-fmt-ihx"
    ],

    # LIBS=["m"],
)

if int(ARGUMENTS.get("PIOVERBOSE", 0)):
    env.Prepend(UPLOADERFLAGS=["-v"])

#
# Target: Build executable and linkable firmware
#

target_firm = env.BuildProgram()
AlwaysBuild(env.Alias("nobuild", target_firm))
target_buildprog = env.Alias("buildprog", target_firm, target_firm)

#
# Target: Upload by default .hex file
#

# options for stcgal uploader tool
# https://github.com/grigorig/stcgal

if env.subst("$UPLOAD_PROTOCOL") == "stcgal":
    if "BOARD" in env and env.BoardConfig().get("vendor") == "STC":
        f_cpu_khz = int(env.BoardConfig().get("build.f_cpu")) / 1000
        env.Replace(
            UPLOAD_OPTIONS=["-p", "$UPLOAD_PORT", "-t",
                            int(f_cpu_khz), "-a"],
            STCGALCMD="stcgal",
            UPLOADHEXCMD="$STCGALCMD $UPLOAD_OPTIONS $UPLOAD_FLAGS $SOURCE")

upload = env.Alias(["upload"], target_firm, [
    env.VerboseAction(env.AutodetectUploadPort, "Looking for upload port..."),
    env.VerboseAction("$UPLOADHEXCMD", "Uploading $SOURCE")
])
AlwaysBuild(upload)

#
# Setup default targets
#

Default([target_buildprog])
