#!/bin/bash
i=0
ave=0
num_count=0
variation=0
var=0
while read num && [ $i -lt 50 ]
do 
	if [ ! -z "$num" ]
	then
		ave=$(( $ave+$num ))
		num_count=$(( $num_count+1 ))
		num_array=("${num_array[@]}" $num)
	fi
	i=$(( $i+1 ))
done
ave=$(( $ave/$num_count ))
for num in ${num_array[@]}
do
	var=$(( $num-$ave ))
	var=$(( $var*$var ))
	variation=$(( $variation+$var ))
done
variation=$(( $variation/$num_count ))
echo $ave
echo $variation
