COMPILER=g++
VERSION=-std=c++17
OUTPUT=makeloader.exe
FLAGS=-Wall
LIBS=

all: Application

Application: Objects/BuildCommand.o Objects/Command.o Objects/CreateCommand.o Objects/InfoCommand.o Objects/MakeCommand.o Objects/Application.o Objects/File.o Objects/LoaderFile.o Objects/MakeFile.o Objects/Main.o
	$(COMPILER) Objects/BuildCommand.o Objects/Command.o Objects/CreateCommand.o Objects/InfoCommand.o Objects/MakeCommand.o Objects/Application.o Objects/File.o Objects/LoaderFile.o Objects/MakeFile.o Objects/Main.o $(LIBS) -o Builds/$(OUTPUT)

Objects/BuildCommand.o : Sources/Commands/BuildCommand.cpp
	$(COMPILER) -c Sources/Commands/BuildCommand.cpp $(VERSION) $(FLAGS) -o Objects/BuildCommand.o

Objects/Command.o : Sources/Commands/Command.cpp
	$(COMPILER) -c Sources/Commands/Command.cpp $(VERSION) $(FLAGS) -o Objects/Command.o

Objects/CreateCommand.o : Sources/Commands/CreateCommand.cpp
	$(COMPILER) -c Sources/Commands/CreateCommand.cpp $(VERSION) $(FLAGS) -o Objects/CreateCommand.o

Objects/InfoCommand.o : Sources/Commands/InfoCommand.cpp
	$(COMPILER) -c Sources/Commands/InfoCommand.cpp $(VERSION) $(FLAGS) -o Objects/InfoCommand.o

Objects/MakeCommand.o : Sources/Commands/MakeCommand.cpp
	$(COMPILER) -c Sources/Commands/MakeCommand.cpp $(VERSION) $(FLAGS) -o Objects/MakeCommand.o

Objects/Application.o : Sources/Core/Application.cpp
	$(COMPILER) -c Sources/Core/Application.cpp $(VERSION) $(FLAGS) -o Objects/Application.o

Objects/File.o : Sources/Files/File.cpp
	$(COMPILER) -c Sources/Files/File.cpp $(VERSION) $(FLAGS) -o Objects/File.o

Objects/LoaderFile.o : Sources/Files/LoaderFile.cpp
	$(COMPILER) -c Sources/Files/LoaderFile.cpp $(VERSION) $(FLAGS) -o Objects/LoaderFile.o

Objects/MakeFile.o : Sources/Files/MakeFile.cpp
	$(COMPILER) -c Sources/Files/MakeFile.cpp $(VERSION) $(FLAGS) -o Objects/MakeFile.o

Objects/Main.o : Sources/Main.cpp
	$(COMPILER) -c Sources/Main.cpp $(VERSION) $(FLAGS) -o Objects/Main.o

