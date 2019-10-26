#!/bin/sh -xe

meson --buildtype=release build
ninja -C build
