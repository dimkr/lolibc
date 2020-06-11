#!/bin/sh -xe

meson --buildtype=release build
ninja -C build

for i in arm-any32-linux-musleabi mips-any32-linux-musl
do
	meson --buildtype=release --cross-file=$i build-$i
	ninja -C build-$i
done
