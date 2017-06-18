#!/bin/bash

make

for f in *.cc
do
    echo "generating ../simple/output-$f.txt ..."
    exe=$(echo $f | cut -f1 -d.)
    ./$exe < ../sample/input-$exe.txt > ../sample/output-$exe.txt
done
