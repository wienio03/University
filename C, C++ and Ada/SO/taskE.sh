#!/bin/bash
curr_max=1
max=10000
i=0
j=0
index=0
while read line
do
	line_array=("${line_array[@]}" $line)
done
while [ $i -lt ${#line_array[@]} ]
do
	while [ $j -lt ${#line_array[@]} ]
	do
		if [[ "${line_array[$j]}" == "${line_array[$i]}" ]] && [ ! $i -eq $j ]
		then
			curr_max=$(( $curr_max+1 ))
		fi
		j=$(( $j+1 ))
	done
	if [ $curr_max -lt $max ]
	then
		index=$i
		max=$curr_max
	fi	
	curr_max=1
	j=0
	i=$(( $i+1 ))
done
echo "${line_array[$index]} $max"
