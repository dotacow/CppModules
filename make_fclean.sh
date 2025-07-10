#!/bin/bash

any_cleaned=false

for dir in C*/ex*/; do
	if [ -d "$dir/ofiles" ] && [ -f "$dir/Makefile" ]; then
		echo "Cleaning in $dir"
		make -C "$dir" fclean
		any_cleaned=true
	fi
done

if ! $any_cleaned; then
	echo -e "\033[32mall clean\033[0m"
fi
