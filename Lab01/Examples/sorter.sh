#!/bin/bash

# To run each command uncomment it!
# If the file doesn't have execution permission, run: chmod +x sorter.sh
#


if [[ ! -f namelist ]]; then
    echo "namelist not found"
fi

# Note: If you want to sort the names in case-insensitive manner use flag -f

echo -e "Sorted in alphabetical order:\n"
# Sorting in alphabetical order
sort -n namelist

echo -e "===============(^ _ ^)===============\n"

# Sorting in reverse alphabetical
sort -n -r namelist 

echo -e "===============(^ _ ^)===============\n"
echo -e "Sorted in reverse alphabetical order:\n"

# Sorting in reverse alphabetical order and directing the results to another file
sort -n -r namelist > namelist.sorted
cat namelist.sorted
echo "===============(^ _ ^)==============="
