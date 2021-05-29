COMPILER=g++
VERSION=--std=c++17
OUTPUT=Application
LIBS=
FLAGS=-Wall

all: Application

Application: Binaries/Application.o Binaries/BuildCommand.o Binaries/Command.o Binaries/CreateCommand.o Binaries/InfoCommand.o Binaries/Main.o Binaries/MakeCommand.o Binaries/Makefile.o
	$(COMPILER) Binaries/Application.o  Binaries/BuildCommand.o  Binaries/Command.o  Binaries/CreateCommand.o  Binaries/InfoCommand.o  Binaries/Main.o  Binaries/MakeCommand.o  Binaries/Makefile.o $(LIBS) -o Builds/$(OUTPUT)

Binaries/Application.o : Sources/Application.cpp
	$(COMPILER) -c Sources/Application.cpp $(VERSION) $(FLAGS) -o Binaries/Application.o

Binaries/BuildCommand.o : Sources/BuildCommand.cpp
	$(COMPILER) -c Sources/BuildCommand.cpp $(VERSION) $(FLAGS) -o Binaries/BuildCommand.o

Binaries/Command.o : Sources/Command.cpp
	$(COMPILER) -c Sources/Command.cpp $(VERSION) $(FLAGS) -o Binaries/Command.o

Binaries/CreateCommand.o : Sources/CreateCommand.cpp
	$(COMPILER) -c Sources/CreateCommand.cpp $(VERSION) $(FLAGS) -o Binaries/CreateCommand.o

Binaries/InfoCommand.o : Sources/InfoCommand.cpp
	$(COMPILER) -c Sources/InfoCommand.cpp $(VERSION) $(FLAGS) -o Binaries/InfoCommand.o

Binaries/Main.o : Sources/Main.cpp
	$(COMPILER) -c Sources/Main.cpp $(VERSION) $(FLAGS) -o Binaries/Main.o

Binaries/MakeCommand.o : Sources/MakeCommand.cpp
	$(COMPILER) -c Sources/MakeCommand.cpp $(VERSION) $(FLAGS) -o Binaries/MakeCommand.o

Binaries/Makefile.o : Sources/Makefile.cpp
	$(COMPILER) -c Sources/Makefile.cpp $(VERSION) $(FLAGS) -o Binaries/Makefile.o
