#!/bin/bash

clear
echo "Linux - gcc"
read -p "Press any key to continue." -n1 -s
clear

make clean $1

read -p "Press any key to continue." -n1 -s
clear

make cc=GCC dialeto=ANSI debug=DEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make cc=GCC dialeto=C89 debug=DEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make cc=GCC dialeto=C90 debug=DEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make cc=GCC dialeto=C99 debug=DEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make cc=GCC dialeto=C11 debug=DEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

clear
echo "Linux - clang" 
read -p "Press any key to continue." -n1 -s
clear

make cc=CLANG dialeto=ANSI debug=DEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make cc=CLANG dialeto=C89 debug=DEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make cc=CLANG dialeto=C90 debug=DEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make cc=CLANG dialeto=C99 debug=DEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear

make cc=CLANG dialeto=C11 debug=DEPURACAO clean $1

read -p "Press any key to continue." -n1 -s
clear