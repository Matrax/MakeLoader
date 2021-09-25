#================Header===============

COMPILER_COMMAND=g++
COMPILER_FLAGS=-Wall -Wextra -Wold-style-cast
LINKER_OUTPUT=makeloader
LINKER_FLAGS=-O2
VERSION=-std=c++17
LIBS=
ARCHIVER_COMMAND=ar
ARCHIVER_ARGUMENTS=rcs
ARCHIVER_OUTPUT=

#================Commands===============

all: Application

app: Application

static-lib: StaticLibrary

clean: 
	rm Builds/$(OUTPUT)

#================Linker===============

Application: Objects/BuildCommand.o Objects/Command.o Objects/CreateCommand.o Objects/InfoCommand.o Objects/Application.o Objects/ApplicationFile.o Objects/LoaderFile.o Objects/MakeFile.o Objects/Main.o
	$(COMPILER_COMMAND) $(LINKER_FLAGS) Objects/BuildCommand.o Objects/Command.o Objects/CreateCommand.o Objects/InfoCommand.o Objects/Application.o Objects/ApplicationFile.o Objects/LoaderFile.o Objects/MakeFile.o Objects/Main.o $(LIBS) -o Builds/$(LINKER_OUTPUT)


StaticLibrary: Objects/BuildCommand.o Objects/Command.o Objects/CreateCommand.o Objects/InfoCommand.o Objects/Application.o Objects/ApplicationFile.o Objects/LoaderFile.o Objects/MakeFile.o Objects/Main.o
	$(ARCHIVER_COMMAND) $(ARCHIVER_ARGUMENTS) Builds/$(ARCHIVER_OUTPUT) Objects/BuildCommand.o Objects/Command.o Objects/CreateCommand.o Objects/InfoCommand.o Objects/Application.o Objects/ApplicationFile.o Objects/LoaderFile.o Objects/MakeFile.o Objects/Main.o

#================Compiler===============

Objects/BuildCommand.o : Sources/Commands/BuildCommand.cpp
	$(COMPILER_COMMAND) -c Sources/Commands/BuildCommand.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/BuildCommand.o

Objects/Command.o : Sources/Commands/Command.cpp
	$(COMPILER_COMMAND) -c Sources/Commands/Command.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/Command.o

Objects/CreateCommand.o : Sources/Commands/CreateCommand.cpp
	$(COMPILER_COMMAND) -c Sources/Commands/CreateCommand.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/CreateCommand.o

Objects/InfoCommand.o : Sources/Commands/InfoCommand.cpp
	$(COMPILER_COMMAND) -c Sources/Commands/InfoCommand.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/InfoCommand.o

Objects/Application.o : Sources/Core/Application.cpp
	$(COMPILER_COMMAND) -c Sources/Core/Application.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/Application.o

Objects/ApplicationFile.o : Sources/Files/ApplicationFile.cpp
	$(COMPILER_COMMAND) -c Sources/Files/ApplicationFile.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/ApplicationFile.o

Objects/LoaderFile.o : Sources/Files/LoaderFile.cpp
	$(COMPILER_COMMAND) -c Sources/Files/LoaderFile.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/LoaderFile.o

Objects/MakeFile.o : Sources/Files/MakeFile.cpp
	$(COMPILER_COMMAND) -c Sources/Files/MakeFile.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/MakeFile.o

Objects/Main.o : Sources/Main.cpp
	$(COMPILER_COMMAND) -c Sources/Main.cpp $(VERSION) $(COMPILER_FLAGS) -o Objects/Main.o

