#!/bin/bash
read var
f0=0
f1=1
fibonacci=0
i=0
while [ $i -lt $var ]
do
	echo "$f0"
	fibonacci=$(( $f0+$f1 ))
	f0=$f1
	f1=$fibonacci
	i=$(( $i+1 ))
done
