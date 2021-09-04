#This is the configuration file of MakeLoader.
#All these variables will be paste in the makefile.
#================Global variables===============

COMPILER=g++
VERSION=-std=c++17
OUTPUT=makeloader
LINKER_FLAGS=-O2
COMPILER_FLAGS=-Wall -Wextra -Wold-style-cast
LIBS=

#================Commands===============


all: Application

clean: 
	rm Builds/$(OUTPUT)

#================Linker===============


Application: Objects/Main.o Objects/Application.o Objects/CreateCommand.o Objects/InfoCommand.o Objects/BuildCommand.o Objects/Command.o Objects/MakeCommand.o Objects/MakeFile.o Objects/LoaderFile.o Objects/File.o
	$(COMPILER) $(LINKER_FLAGS) Objects/Main.o Objects/Application.o Objects/CreateCommand.o Objects/InfoCommand.o Objects/BuildCommand.o Objects/Command.o Objects/MakeCommand.o Objects/MakeFile.o Objects/LoaderFile.o Objects/File.o $(LIBS) -o Builds/$(OUTPUT)

#================Compiler===============


Objects/Main.o : Sources/Main.cpp
	$(COMPILER) -c Sources/Main.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/Main.o

Objects/Application.o : Sources/Core/Application.cpp
	$(COMPILER) -c Sources/Core/Application.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/Application.o

Objects/CreateCommand.o : Sources/Commands/CreateCommand.cpp
	$(COMPILER) -c Sources/Commands/CreateCommand.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/CreateCommand.o

Objects/InfoCommand.o : Sources/Commands/InfoCommand.cpp
	$(COMPILER) -c Sources/Commands/InfoCommand.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/InfoCommand.o

Objects/BuildCommand.o : Sources/Commands/BuildCommand.cpp
	$(COMPILER) -c Sources/Commands/BuildCommand.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/BuildCommand.o

Objects/Command.o : Sources/Commands/Command.cpp
	$(COMPILER) -c Sources/Commands/Command.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/Command.o

Objects/MakeCommand.o : Sources/Commands/MakeCommand.cpp
	$(COMPILER) -c Sources/Commands/MakeCommand.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/MakeCommand.o

Objects/MakeFile.o : Sources/Files/MakeFile.cpp
	$(COMPILER) -c Sources/Files/MakeFile.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/MakeFile.o

Objects/LoaderFile.o : Sources/Files/LoaderFile.cpp
	$(COMPILER) -c Sources/Files/LoaderFile.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/LoaderFile.o

Objects/File.o : Sources/Files/File.cpp
	$(COMPILER) -c Sources/Files/File.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/File.o

