#!/usr/bin/env bash

here=$(pwd)
cd "$1"

num_file=$(find  -type f | wc -l)
num_dir=$(find  -type d | wc -l)

echo "There are" "$num_file" "files"
echo "There are" "$num_dir" "directories"

cd "$here"









