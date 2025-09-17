#!/bin/bash

# Useful flags to know for ls:
# l: longer format with more infor
# lt: sort by file modification time
# la: show hidden files in longer format
# ltr: sort by file modification time in reverse
# lu: sort by access time
# lc: sort by change time(inode)

mkdir dir1

ls -ltr / > dir1/root.txt
date
sleep 3

mkdir dir2
ls -ltr ~ > dir2/home.txt
date
sleep 3

# Make it more noicer with some logging

echo " Content of dir1/root.txt : "
cat dir1/root.txt
echo "\n"
echo "Content of dir2/home.txt : "
cat dir2/home.txt
echo "\n"
echo "Items in dir1: "
ls dir1
echo "\n"
echo "Items in dir2: "
ls dir2
echo "\n"
