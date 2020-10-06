#!/usr/bin/env bash

here=$(pwd)
cd "$1"

num_file=$(find  -type f | wc -l)
num_dir=$(find  -type d | wc -l)

echo "There were" "$num_dir" "directories."
echo "There were" "$num_file" "regular files."

cd "$here"









