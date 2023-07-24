#!/bin/bash
regex1="total [0-9]*([0-9])"
file_bool=0
dir_bool=0
exe_bool=0
str=""
i=1
per_value=0
while read line
do
    if [[ ! $line == $regex1 ]]
    then
    	first_char=${line:0:1}
    	obj_name=${line##* }
    	if [[ $first_char == $"d" ]]
    	then
    		dir_bool=1
    	elif [[ $first_char == $"-" ]]
    	then
    		dir_bool=0
    	fi
    	permissions=${line:0:10}
    	while [ ! $i -eq 10 ]
    	do
    		substr1=${permissions:$i:3}
    		char1=${substr1:0:1}
    		char2=${substr1:1:1}
    		char3=${substr1:2:1}
    		if [[ $char1 == $"r" ]]
    		then
    			per_value=$(( $per_value+4 ))
    		fi
    		if [[ $char2 == $"w" ]]
    		then
    			per_value=$(( $per_value+2 ))
    		fi
    		if [[ $char3 == $"x" ]]
    		then
    			per_value=$(( $per_value+1 ))

    		fi
    		str+="$per_value"
    		if [ $i -eq 1 ] && [[ $char3 == $"x" ]]
    		then
    			exe_bool=1
    		fi
    		i=$(( $i+3 ))
    		per_value=0
    	done
    	i=1
    	if [ $dir_bool -eq 1 ]
    	then
    		echo "$obj_name/ $str"
    	elif [ $dir_bool -eq 0 ] && [ $exe_bool -eq 0 ]
    	then
    		echo "$obj_name $str"
    	elif [ $dir_bool -eq 0 ] && [ $exe_bool -eq 1 ]
    	then
    		echo "$obj_name* $str"
    	fi
    	str=""
    	exe_bool=0
   	fi
done

