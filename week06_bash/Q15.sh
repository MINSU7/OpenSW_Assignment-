#! /bin/bash

file_wordcnt() {
	cnt=$(cat $1 | wc -w)
	echo "$1 파일의 단어는 $cnt 개 입니다."
}

read -p "Enter a file name: " FILE

file_wordcnt $FILE