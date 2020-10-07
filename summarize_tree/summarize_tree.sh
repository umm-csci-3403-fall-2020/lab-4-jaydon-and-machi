#!/usr/bin/env bash

here=$(pwd)
cd "$1"

num_file=$(find  -type f | wc -l) #Find file types and count
num_dir=$(find  -type d | wc -l) #Find directory types and count

echo "There were" "$num_dir" "directories."
echo "There were" "$num_file" "regular files."

cd "$here"









