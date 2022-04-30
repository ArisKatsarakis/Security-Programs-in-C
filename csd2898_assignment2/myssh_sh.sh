#!/bin/bash
destination=$1
echo  $destination

strace -f -s 9  -e read -o data.txt ssh $destination
