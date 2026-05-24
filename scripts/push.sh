#!/bin/bash

# Ask for question number
read -p "Enter question number: " qnum

echo "Choose language:"
echo "1) cpp"
echo "2) py"
echo "3) c"
echo "4) sql"
echo "5) ts"
echo "6) js"
echo "Press Enter for default (cpp)"

read -p "Enter option: " choice

# Map option to extension
case $choice in
    1|"")
        ext="cpp"
        ;;
    2)
        ext="py"
        ;;
    3)
        ext="c"
        ;;
    4)
        ext="sql"
        ;;
    5)
        ext="ts"
        ;;
    6)
        ext="js"
        ;;
    *)
        echo "Invalid option"
        exit 1
        ;;
esac

# File name
filename="${qnum}.${ext}"

# Check if file exists
if [ ! -f "$filename" ]; then
    echo "Error: File '$filename' does not exist."
    exit 1
fi

# Run git commands silently
git add "$filename" >/dev/null 2>&1
git commit -m "added ${qnum}" >/dev/null 2>&1
git push origin main >/dev/null 2>&1

# Check status
if [ $? -eq 0 ]; then
    echo "Successfully pushed ${filename} to origin/main"
else
    echo "Git operation failed"
fi