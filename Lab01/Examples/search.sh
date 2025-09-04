#!/bin/bash

# > for overwrite, >> for append
grep -r --include='*task*' -l '' /proc > output.txt 2> errors.txt

# this is another way as wellfind
# find /proc -type f -name '*task*' > output.txt 2> errors.txt

head -n 3 output.txt
head -n 3 errors.txt

