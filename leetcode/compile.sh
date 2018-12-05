#!/bin/bash

function compile () {
    echo "compiling problem $1 .........";
    cd $1; c++ -g main.cpp -w -o main; cd ..;
    echo "compiling problem $1 finished!";
    echo "";
}

if [ "$1" = all ]; then
    for d in `ls -d */`; do
        compile $d
    done
else
    compile $1
fi
