#!/bin/bash

# Main for the differents

echo -e ""
echo -e "Welcome in tests for Nanotekspice!"
echo -e ""

./tests/TestSh/SimpleTest.sh
echo -e ""
./tests/TestSh/ArgumentTest.sh
echo -e ""
./tests/TestSh/InFileTest.sh
echo -e ""

echo -e "   4. Criterion tests : "
res=$(cd tests && make tests_run && ./unit-tests)


res=$(make fclean 2>&1)