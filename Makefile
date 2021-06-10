COMPILER=g++
VERSION=--std=c++17
OUTPUT=makeloader
LIBS=
FLAGS=-Wall

all: Application

Application: Binaries/Application.o Binaries/BuildCommand.o Binaries/Command.o Binaries/CreateCommand.o Binaries/InfoCommand.o Binaries/Main.o Binaries/MakeCommand.o Binaries/Makefile.o
	$(COMPILER) Binaries/Application.o  Binaries/BuildCommand.o  Binaries/Command.o  Binaries/CreateCommand.o  Binaries/InfoCommand.o  Binaries/Main.o  Binaries/MakeCommand.o  Binaries/Makefile.o $(LIBS) -o Builds/$(OUTPUT)

Binaries/Application.o : Sources/Core/Application.cpp
	$(COMPILER) -c Sources/Core/Application.cpp $(VERSION) $(FLAGS) -o Binaries/Application.o

Binaries/BuildCommand.o : Sources/Commands/BuildCommand.cpp
	$(COMPILER) -c Sources/Commands/BuildCommand.cpp $(VERSION) $(FLAGS) -o Binaries/BuildCommand.o

Binaries/Command.o : Sources/Commands/Command.cpp
	$(COMPILER) -c Sources/Commands/Command.cpp $(VERSION) $(FLAGS) -o Binaries/Command.o

Binaries/CreateCommand.o : Sources/Commands/CreateCommand.cpp
	$(COMPILER) -c Sources/Commands/CreateCommand.cpp $(VERSION) $(FLAGS) -o Binaries/CreateCommand.o

Binaries/InfoCommand.o : Sources/Commands/InfoCommand.cpp
	$(COMPILER) -c Sources/Commands/InfoCommand.cpp $(VERSION) $(FLAGS) -o Binaries/InfoCommand.o

Binaries/Main.o : Sources/Main.cpp
	$(COMPILER) -c Sources/Main.cpp $(VERSION) $(FLAGS) -o Binaries/Main.o

Binaries/MakeCommand.o : Sources/Commands/MakeCommand.cpp
	$(COMPILER) -c Sources/MakeCommand.cpp $(VERSION) $(FLAGS) -o Binaries/MakeCommand.o

Binaries/Makefile.o : Sources/Core/Makefile.cpp
	$(COMPILER) -c Sources/Core/Makefile.cpp $(VERSION) $(FLAGS) -o Binaries/Makefile.o
