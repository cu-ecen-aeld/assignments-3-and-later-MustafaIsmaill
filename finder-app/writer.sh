#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Error: Please provide both writefile and writestr arguments."
    exit 1
fi

writefile=$1
writestr=$2

mkdir -p "$(dirname "$writefile")"

echo "$writestr" > "$writefile"

if [ $? -ne 0 ]; then
    echo "Error: Could not create the file $writefile."
    exit 1
fi

echo "File $writefile created successfully with content:"
echo "$writestr"
