#!/bin/sh -e

for i in `/bin/kill -l`
do
	echo \"$i\",
done > $1
