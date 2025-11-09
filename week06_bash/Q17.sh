#! /bin/bash

file_wordcnt() {
	files=$(ls *.txt)
	for i in $files; do
		cnt=$(cat $i | wc -w)
		echo "$1 파일의 단어는 $cnt 개 입니다."
	done	
}

file_wordcnt 