#!/bin/bash
destination=$1
echo  $destination

strace -f -s 9  -e read -o data.txt ssh $destination
#remove alias

"bash /home/ugrads/class11/katsar/myssh_sh.sh"