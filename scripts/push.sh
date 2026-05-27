#!/bin/bash

filepath="$1"

if [ ! -f "$filepath" ]; then
    echo "File does not exist"
    exit 1
fi

filename=$(basename "$filepath")
qnum="${filename%.*}"

git add "$filepath" >/dev/null 2>&1
git commit -m "added $qnum" >/dev/null 2>&1
git push >/dev/null 2>&1

echo "Pushed $filename"