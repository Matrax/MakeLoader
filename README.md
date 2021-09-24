# MakeLoader 1.0 (BETA)

## Description
MakeLoader is a program that generate for you all the C/C++ project folders and the makefile with GCC or G++ compilation associated with it using
all the sources files in the "Sources" directory.
<br/><br/>
MakeLoader will generate with the "create" command the makeloader.json file that contains all options used in the makefile
and all the directories for your project.
<br/><br/>

## How it works
Configure all the compiler options in the makeloader.json,
program your application using the "Sources" and "Headers" directories, add all the headers used in the "Includes" directory, and generate
the makefile using the "build" command. It will find recursively your sources files in the "Sources" directory.
The makefile is configured to produce an executable or a static library.

## Installation
- Clone the repository.
- Use "make" to generate the executable of MakeLoader in the Builds folder.
- Now you can execute MakeLoader in your terminal (On Windows, you can put MakeLoader.exe in the PATH of your environment variables).
- Type "makeloader info" to have the list of commands available.

## Project folders created
Folders | Uses
------------ | -------------
Objects | Folder that contains all the object files generated by your compiler.
Builds | Folder that contains your executable.
Headers | Folder that contains all your headers files (.h, .hpp ...).
Sources | Folder that contains all your sources files (.c, .cpp ...).
Includes | Folder that contains your includes headers files (.h, .hpp).

## Available commands in MakeLoader
Commands | Uses
------------ | -------------
create | Generate all the folders of your project and the makeloader.json.
build | Generate a makefile for your project using all the sources in the "Sources" folder.
info | Give informations about MakeLoader.

## Compilation of your project
Commands | Uses
------------ | -------------
make app | Build the executable of your application.
make static-lib | Build the static library of your application.
make all | Same as "make app".

## Libraries used in MakeLoader
Libraries | Link
------------ | -------------
JSON for modern C++ | https://github.com/nlohmann/json

## TODO
* Documentations
* Dynamic libraries creation in the makefile
