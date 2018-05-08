#!/bin/bash

# Simple tests for the compilation

# Define variable for color red and green
green='\e[1;32m'
red='\e[0;31m'

declare -i nbrTest=0

echo -e "   1. Rules tests : "

# Test clean
res=$(make clean 2>&1)
res=$(echo $?)

if test "$res" = "0"
then
echo -e "       - clean : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - clean : ${red}error \033[0m"
fi

# Test fclean
res=$(make fclean 2>&1)
res=$(echo $?)

if test "$res" = "0"
then
echo -e "       - fclean : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - fclean : ${red}error \033[0m"
fi

# Test make
res=$(make 2>&1)
res=$(echo $?)

if test "$res" = "0"
then
echo -e "       - all : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - all : ${red}error \033[0m"
fi

# Test re
res=$(make re fclean 2>&1)
res=$(echo $?)

if test "$res" = "0"
then
echo -e "       - re : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - re : ${red}error \033[0m"
fi

# Result
if test "$nbrTest" = "4"
then
echo -e "   -> rules tests: ${green}$nbrTest \033[0m / 4"
else
echo -e "   -> rules tests: ${red}$nbrTest \033[0m / 4"
fi