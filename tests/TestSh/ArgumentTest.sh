#!/bin/bash

# Simple Test for the file

# Define variable for color red and green
green='\e[1;32m'
red='\e[0;31m'

declare -i nbrTest=0

echo -e "   2. Arguments test : "

# Test bad file
res=$(./nanotekspice titi 2>&1)

if test "$res" = "/!\ ERROR on \"nts::Parsing::readFile\"
 +--> The file \"titi\" doesn't exist"
then
echo -e "       - Bad file : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - Bad file : ${red}error \033[0m"
fi

# Test bad arguments :  "./nanotekspice Sample/Basics/or.nts a=0"
res=$(./nanotekspice Sample/Basics/or.nts a=0 2>&1)

if test "$res" = "/!\ ERROR on \"nts::Parsing::verifInput\"
 +--> The input type need a value."
then
echo -e "       - An input value is missing : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - An input value is missing : ${red}error \033[0m"
fi

# Test bad arguments :  "./nanotekspice Sample/Basics/or.nts a=0 b=0 titi=1"
res=$(./nanotekspice Sample/Basics/or.nts a=0 b=0 titi=0 2>&1)

if test "$res" = "/!\ ERROR on \"nts::Parsing::fillWithArg\"
 +--> The argument input name \"titi\" doesn't exist"
then
echo -e "       - An input name doesn't exist : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - An input name doesn't exist : ${red}error \033[0m"
fi

# Test bad arguments :  "./nanotekspice Sample/Basics/or.nts a=0 b=2"
res=$(./nanotekspice Sample/Basics/or.nts a=0 b=2 2>&1)

if test "$res" = "/!\ ERROR on \"nts::Parsing::makeArgs\"
 +--> Error with the input value argument.
 The value it's only 0 or 1"
then
echo -e "       - An input value doesn't exist : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - An input value doesn't exist : ${red}error \033[0m"
fi

# Result
if test "$nbrTest" = "4"
then
echo -e "   -> arguments tests: ${green}$nbrTest \033[0m / 4"
else
echo -e "   -> arguments tests: ${red}$nbrTest \033[0m / 4"
fi