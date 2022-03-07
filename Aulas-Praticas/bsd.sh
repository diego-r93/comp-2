#!/bin/bash

clear
echo "FreeBSD - gcc" 
read -p "Press any key to continue." -n1 -s
clear

make clean $1

read -p "Press any key to continue." -n1 -s
clear

make -DGCC -DANSI -DDEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make -DGCC -DC89 -DDEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make -DGCC -DC90 -DDEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make -DGCC -DC99 -DDEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make -DGCC -DC11 -DDEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

clear
echo "FreeBSD - clang" 
read -p "Press any key to continue." -n1 -s
clear

make -DCLANG -DANSI -DDEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make -DCLANG -DC89 -DDEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make -DCLANG -DC90 -DDEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make -DCLANG -DC99 -DDEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make -DCLANG -DC11 -DDEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear