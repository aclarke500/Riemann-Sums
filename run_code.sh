#!/bin/bash

C_file=$1

if ! [ -f "$C_file" ]; then

    echo "File does not exist in directory" >&2 
    exit 0
fi

len=${#file}
#remove the .c
compiled_file=${C_file%.*}

#compile file
gcc $C_file -o $compiled_file
#run it
./$compiled_file "${@:2}"
