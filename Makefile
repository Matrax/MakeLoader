COMPILER=g++
FLAGS=-Wall
VERSION=--std=c++17
LIBS=

all: Application

Application: Binaries/Application.o Binaries/Main.o Binaries/Makefile.o
	$(COMPILER) Binaries/Makefile.o Binaries/Application.o Binaries/Main.o $(LIBS) -o Builds/Application

Binaries/Application.o: Sources/Application.cpp
	$(COMPILER) -c Sources/Application.cpp $(VERSION) $(FLAGS) -o Binaries/Application.o

Binaries/Makefile.o: Sources/Makefile.cpp
	$(COMPILER) -c Sources/Makefile.cpp $(VERSION) $(FLAGS) -o Binaries/Makefile.o
	
Binaries/Main.o: Sources/Main.cpp
	$(COMPILER) -c Sources/Main.cpp $(VERSION) $(FLAGS) -o Binaries/Main.o