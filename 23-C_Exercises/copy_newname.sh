#!/bin/bash


INPUT_FILE=$1
OUTPUT_DIR=$2
FILE_ROOT_NAME=$3
START=$4
END=$5
EXTENSION=$6

for ((i = $START ; i <= $END ; i++)); do  
    cp $INPUT_FILE $OUTPUT_DIR/$FILE_ROOT_NAME$i.$EXTENSION
done

echo "Done!"