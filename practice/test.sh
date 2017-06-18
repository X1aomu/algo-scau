#!/bin/bash

make

for f in *.cc
do
    echo "now doing $f"
    exe=$(echo $f | cut -f1 -d.)
    ./$exe < ../sample/input-$exe.txt > $exe.txt
    diff -u ../sample/output-$exe.txt $exe.txt
    echo
done
