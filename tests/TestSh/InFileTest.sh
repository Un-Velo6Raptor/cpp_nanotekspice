#!/bin/bash

# Simple Test in the file

# Define variable for color red and green
green='\e[1;32m'
red='\e[0;31m'

declare -i nbrTest=0

echo -e "   3. In file test : "

# Test false comment
res=$(./nanotekspice ./Sample/False/comments.nts 2>&1)

if test "$res" = "/!\ ERROR on \"nts::Parsing::fillVector\"
 +--> The line : \"Admiral Business Machines 1954-2042\" is incorrect."
then
echo -e "       - Bad comment : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - Bad comment : ${red}error \033[0m"
fi

# Test without chipsets part
res=$(./nanotekspice ./Sample/False/chipsets.nts a=0 b=0 2>&1)

if test "$res" = "/!\ ERROR on \"nts::Parsing::fillWithArg\"
 +--> The argument input name \"a\" doesn't exist"
then
echo -e "       - Doesn't have chipsets part : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - Doesn't have chipsets part : ${red}error \033[0m"
fi

# Test without links part
res=$(./nanotekspice ./Sample/False/links.nts a=0 b=0 2>&1)

if test "$res" = "/!\ ERROR on \"nts::Parsing::verifType\"
 +--> The type \"a:1\" doesn't exist."
then
echo -e "       - Doesn't have links part : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - Doesn't have links part : ${red}error \033[0m"
fi

# Test with false link (name)
res=$(./nanotekspice ./Sample/False/linksName.nts a=0 b=0 2>&1)

if test "$res" = "/!\ ERROR on \"nts::Parsing::verifNameLink\"
 +--> The name \"toto\" doesn't exist"
then
echo -e "       - A name in a link doesn't exist : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - A name in a link doesn't exist : ${red}error \033[0m"
fi

# Test with false link (pin)
res=$(./nanotekspice ./Sample/False/linksPin.nts a=0 b=0 2>&1)

if test "$res" = "ERROR: gate
+--> SetLinkError: Can't access to this pin
/!\ ERROR on a
 +--> SetLinkError: Can't define this pin"
then
echo -e "       - A pin in a link doesn't exist : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - A pin in a link doesn't exist : ${red}error \033[0m"
fi

# Test with a chipset false (pin)
res=$(./nanotekspice ./Sample/False/chipsetsPinFalse.nts a=0 b=0 2>&1)

if test "$res" = "/!\ ERROR on \"nts::Parsing::findValue\"
 +--> For the type : \"input\" is only '0' or '1'"
then
echo -e "       - A pin in a chipset doesn't exist : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - A pin in a chipset doesn't exist : ${red}error \033[0m"
fi

# Test with a redefine chipsets true
res=$(./nanotekspice ./Sample/False/chipsetsTrue.nts a=0 b=0 x=0 2>&1)

if test "$res" = "/!\ ERROR on \"nts::Parsing::fillWithArg\"
 +--> The argument input name \"x\" doesn't exist"
then
echo -e "       - Redefine a true chipsets : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - Redefine a true chipsets : ${red}error \033[0m"
fi

# Test with a redefine chipsets false
res=$(./nanotekspice ./Sample/False/chipsetsFalse.nts a=0 b=0 x=0 2>&1)
if test "$res" = "/!\ ERROR on \"nts::Parsing::fillWithArg\"
 +--> The argument input name \"x\" doesn't exist"
then
echo -e "       - Redefine a false chipsets : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - Redefine a false chipsets : ${red}error \033[0m"
fi

# Test with a false component
res=$(./nanotekspice ./Sample/False/componentFalse.nts a=0 b=0 2>&1)
if test "$res" = "/!\ ERROR on \"nts::Parsing::verifType\"
 +--> The type \"4111\" doesn't exist."
then
echo -e "       - A component who doesn't exist : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - A component who doesn't exist : ${red}error \033[0m"
fi

# Test with a component not yet realized
res=$(./nanotekspice ./Sample/False/componentNotMade.nts a=0 b=0 2>&1)
if test "$res" = "/!\ ERROR on \"nts::Factory::createCompo\"
 +--> The component : \"4013\" doesn't exist."
then
echo -e "       - A component not yet realized : ${green}ok \033[0m"
 nbrTest=nbrTest+1;
else
echo -e "       - A component not yet realized : ${red}error \033[0m"
fi

# Result
if test "$nbrTest" = "10"
then
echo -e "   -> file tests: ${green}$nbrTest \033[0m / 10"
else
echo -e "   -> file tests: ${red}$nbrTest \033[0m / 10"
fi