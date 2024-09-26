#!/bin/bash

# This script locally installs dependencies libraries

DEPENDENCIES="ffmpeg opencv"

THIS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"

# Iterate the string variable using for loop
for val in $DEPENDENCIES; do
    echo "---------------------------------------"
    echo " Installing $val..."
    echo "---------------------------------------"
    bash 'setup_'$val'.sh'
    source 'setup_'$val'_vars.sh'
    echo "DONE!"
done
