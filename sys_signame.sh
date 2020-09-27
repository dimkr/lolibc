#!/bin/sh -e

count=1
for i in `/bin/kill -l`
do
	echo \"$i\",
	count=$(($count + 1))
done > $1

for i in `seq 0 $((64 - $count))`
do
	echo \"RT$i\",
done >> $1