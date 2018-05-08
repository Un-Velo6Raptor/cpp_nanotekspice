##
## EPITECH PROJECT, 2018
## nanotekspice
## File description:
## Makefile Criterion
##

SRC		=       ../Src/Component/Special/Input.cpp		\
			../Src/Component/Special/Output.cpp		\
	 		../Src/Component/Special/False.cpp		\
			../Src/Component/Special/Clock.cpp		\
			../Src/Component/Special/True.cpp		\
			../Src/Component/Gate/AndGate.cpp		\
			../Src/Component/Gate/OrGate.cpp		\
	 		../Src/Component/Gate/NorGate.cpp		\
	 		../Src/Component/Gate/NandGate.cpp      	\
	 		../Src/Component/Gate/XorGate.cpp		\
	 		../Src/Component/Gate/NotGate.cpp		\
	 		../Src/Component/Gate/LatchGate.cpp		\
	 		../Src/Component/Gate/LittleDecoderGate.cpp	\
			../Src/Component/Gate/SumGate.cpp		\
			../Src/Component/Gate/CounterGate.cpp		\
			../Src/Component/HEF4071B.cpp			\
			../Src/Component/HCF4081B.cpp			\
			../Src/Component/HEF4001B.cpp			\
			../Src/Component/CD4011B.cpp               	\
			../Src/Component/CD4030C.cpp			\
			../Src/Component/CD4069UBC.cpp			\
			../Src/Component/CD4514BC.cpp			\
			../Src/Component/CD4008BMS.cpp			\
			../Src/Component/MC14040B.cpp			\
			../Src/Component/AbstractComponent.cpp     	\
                        ../Src/Statement/Chipsets.cpp        		\
			../Src/Statement/Links.cpp             		\
			../Src/Statement/AbstractStatement.cpp         	\
			../Src/Parsing/Parsing.cpp       		\
			../Src/Parsing/CreateComponent.cpp		\
			../Src/Parsing/Factory.cpp			\
			../Src/Exception/ExceptionComponent.cpp		\
	 		../Src/Exception/ExceptionParsing.cpp  		\
			../Src/Read/Read.cpp				\

SRC_TEST	=       ./Src/GateTest.cpp

CPPFLAGS	=	-W -Wall -Wextra -std=c++11		\

LDFLAGS		=	-lcriterion -lgcov  --coverage          \
			-I ../Include/Interface/		\
			-I ../Include/Abstract/			\
			-I ../Include/Exception                	\
			-I ../Include/Class/Gate		\
			-I ../Include/Class/Component		\
			-I ../Include/Class/Component/Special	\
			-I ../Include/Class/Statement           \
			-I ../Include/Class/Read          	\
			-I ../Include/Class/Parsing		\

NAME		=	unit-tests

all:			tests_run

tests_run:  		$(NAME)

$(NAME):
		g++ -o $(NAME) $(SRC_TEST) $(SRC) $(LDFLAGS) -std=c++11

clean:
		rm -f $(NAME)
		rm -f *.gcda
		rm -f *.gcno

fclean: clean

re:		clean all

.PHONY: all clean fclean re tests_run
