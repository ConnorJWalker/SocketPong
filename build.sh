#!/bin/bash
runProgram=false
runCmake=false

while test $# -gt 0; do
    case "$1" in 
        -r)
            runProgram=true
            shift
            ;;
        -b)
            runCmake=true
            shift
            ;;
        *)
            break
            ;;
    esac
done

cd Client/

if [ "$runCmake" = true ] ; then
    cmake .
fi

make
cd ..

if [ "$runProgram" = true ] ; then 
    ./run.sh
fi
