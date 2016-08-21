
# this target will compile all the file

SOURCE?=src
APP_NAME=FirstProjectC_Cpp
#CFLAGS = -Wall -Wextra -Werror -Wno-unknown-pragmas -O2 -g -fpermissive -D__PC__
PATH_HEADER= header/
INCFLAGS= -I $(PATH_HEADER)
all: program
program: main.o functionImplementation.o
	gcc $(INCFLAGS) main.o functionImplementation.o -o program
	
main.o: main.c
	gcc -c $(INCFLAGS) main.c
	
functionImplementation.o: $(SOURCE)/functionImplementation.c
	gcc -c $(INCFLAGS) $(SOURCE)/functionImplementation.c

clean:
	rm -rf *o program main.o functionImplementation.o

run:
	./program

#need to implement a single rule for build, for the moment used 2 targets
all1: programcpp
programcpp:main1.o implement.o
	g++  main1.o implement.o -o programcpp
main1.o:main1.cpp
	g++ -c $(INCFLAGS) main1.cpp
implement.o:implement.o
	g++ -c $(INCFLAGS) $(SOURCE)/implement.cpp
clean1:
	rm -rf *o programcpp main1.o implement.o
runi:
	./programcpp
