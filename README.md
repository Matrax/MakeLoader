# MakeLoader 1.0 (BETA)

## Description
MakeLoader is a program that generate all your C/C++ project folders and your makefile using all the sources files of your project that use GCC or G++.
<br/><br/>
MakeLoader will generate with the "create" command the makeloader.json file that contains all options used to generate the makefile.
<br/><br/>
Configure your compiler in the makeloader.json,
program your application using the "Sources" and "Headers" directory, and generate 
the makefile using the "build" command.
<br/><br/>
MakeLoader find recursively your sources files in the "Sources" directory.

## Installation
- Clone the repository.
- Use "make" to generate the executable of MakeLoader in the Builds folder.
- Now you can execute MakeLoader in CLI using the executable.
- Type "makeloader info" to have the list of commands available.

## Project folders
Folders | Uses
------------ | -------------
Objects | Folder that contains all the object file generated by your compiler.
Builds | Folder that contains your executable.
Headers | Folder that contains all your headers files (.h, .hpp ...).
Sources | Folder that contains all your sources files (.c, .cpp ...).
Includes | Folder that contains your includes headers files (.h, .hpp).

## Available commands
Commands | Uses
------------ | -------------
create | Generate all the folders of your project and the makeloader.json.
build | Generate a makefile for your project using all the sources in the "Sources" folder.
make | Call the "make" program to compile your project.
info | Give informations about MakeLoader.

## Compilation of your project
Commands | Uses
------------ | -------------
make app | Build the executable of your application.
make static-lib | Build the static library of your application.
make all | Same as "make app".

## Libraries
Libraries | Link
------------ | -------------
JSON for modern C++ | https://github.com/nlohmann/json

## TODO
* Documentations