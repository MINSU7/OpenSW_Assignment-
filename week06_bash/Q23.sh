#! /bin/bash

factorial(){
	cnt=1
	for i in $(seq 1 $1); do
		cnt=$((cnt * $i))
	done
	echo "Factorial of $1 is $cnt"
}

read -p "Enter a number: " NUM
factorial $NUM