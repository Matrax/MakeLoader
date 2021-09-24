#================Header===============

COMPILER=g++
ARCHIVER=ar
VERSION=-std=c++17
COMPILER_OUTPUT=makeloader
ARCHIVER_OUTPUT=
LINKER_FLAGS=-O2
COMPILER_FLAGS=-Wall -Wextra -Wold-style-cast
LIBS=

#================Commands===============

all: Application

app: Application

static-lib: StaticLibrary

clean: 
	rm Builds/$(OUTPUT)

#================Linker===============

Application: Objects/BuildCommand.o Objects/Command.o Objects/CreateCommand.o Objects/InfoCommand.o Objects/Application.o Objects/ApplicationFile.o Objects/LoaderFile.o Objects/MakeFile.o Objects/Main.o
	$(COMPILER) $(LINKER_FLAGS) Objects/BuildCommand.o Objects/Command.o Objects/CreateCommand.o Objects/InfoCommand.o Objects/Application.o Objects/ApplicationFile.o Objects/LoaderFile.o Objects/MakeFile.o Objects/Main.o $(LIBS) -o Builds/$(COMPILER_OUTPUT)


StaticLibrary: Objects/BuildCommand.o Objects/Command.o Objects/CreateCommand.o Objects/InfoCommand.o Objects/Application.o Objects/ApplicationFile.o Objects/LoaderFile.o Objects/MakeFile.o Objects/Main.o
	$(ARCHIVER) rcs Builds/$(ARCHIVER_OUTPUT) Objects/BuildCommand.o Objects/Command.o Objects/CreateCommand.o Objects/InfoCommand.o Objects/Application.o Objects/ApplicationFile.o Objects/LoaderFile.o Objects/MakeFile.o Objects/Main.o

#================Compiler===============

Objects/BuildCommand.o : Sources/Commands/BuildCommand.cpp
	$(COMPILER) -c Sources/Commands/BuildCommand.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/BuildCommand.o

Objects/Command.o : Sources/Commands/Command.cpp
	$(COMPILER) -c Sources/Commands/Command.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/Command.o

Objects/CreateCommand.o : Sources/Commands/CreateCommand.cpp
	$(COMPILER) -c Sources/Commands/CreateCommand.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/CreateCommand.o

Objects/InfoCommand.o : Sources/Commands/InfoCommand.cpp
	$(COMPILER) -c Sources/Commands/InfoCommand.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/InfoCommand.o

Objects/Application.o : Sources/Core/Application.cpp
	$(COMPILER) -c Sources/Core/Application.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/Application.o

Objects/ApplicationFile.o : Sources/Files/ApplicationFile.cpp
	$(COMPILER) -c Sources/Files/ApplicationFile.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/ApplicationFile.o

Objects/LoaderFile.o : Sources/Files/LoaderFile.cpp
	$(COMPILER) -c Sources/Files/LoaderFile.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/LoaderFile.o

Objects/MakeFile.o : Sources/Files/MakeFile.cpp
	$(COMPILER) -c Sources/Files/MakeFile.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/MakeFile.o

Objects/Main.o : Sources/Main.cpp
	$(COMPILER) -c Sources/Main.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/Main.o

