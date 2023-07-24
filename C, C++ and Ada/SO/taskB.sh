#!/bin/bash
regex1="[a-zA-Z]"
regex2="[a-zA-Z]="
read var
if [[ $var == $regex1 ]] 
then
	while read -r line;
	do
		upper_char=${var^}
		lower_char=${var,}
		line_upper="${line//[^$upper_char]/}"
		line_lower="${line//[^$lower_char]/}"
		var1=${#line_upper}
		var2=${#line_lower}
		echo $(( $var1+$var2 ))
	done
fi
if [[ $var == $regex2 ]]
then
	var="${var//=}"
	while read -r line;
	do 
		line="${line//[^$var]/}"
		echo -n $line | wc -c 
	done
fi
