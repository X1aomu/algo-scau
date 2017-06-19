#!/bin/bash

dir_name=$(basename $(pwd))

make

for f in *.cc *.c
do
    echo

    if [ $f = "*.cc" ] || [ $f = "*.c" ]; then
        break
    fi

    echo "now testing $f ..."

    exe=$(echo $f | cut -f1 -d.)
    my_file="$exe.txt"
    sample_input_file="../../sample/input-$dir_name.txt"
    sample_output_file="../../sample/output-$dir_name.txt"

    ./$exe < $sample_input_file > $my_file

    if $(diff -q $sample_output_file $my_file > /dev/null);
    then
        echo "$f is the right one :)"
    else
        echo "$f is not right :("
        diff -u --color=always $sample_output_file $my_file
    fi
done
