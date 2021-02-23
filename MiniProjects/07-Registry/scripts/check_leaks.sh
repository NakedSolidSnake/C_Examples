#!/bin/bash



#valgrind --leak-check=full

target="/media/cssouza/SOLIDCRIS/repositories/c_language/16-SmallProjects/01-Registry/build/bin/tests"
for f in "$target"/*
do
    # echo $(basename $f)    
    echo "<Analising $(basename $f)>----------------------------------------------------------"
    valgrind --leak-check=full $f
    
done
echo ""