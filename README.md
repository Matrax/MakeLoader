# MakeLoader 1.0 (WORK IN PROGRESS)

## Description
MakeLoader is a program that generate all your C/C++ project folders and your makefile 
using all the sources files of your project that use GCC or G++.
<br/><br/>
MakeLoader will generate with the "create" command the makeloader.txt file that contains all variables 
and commands used by Make to generate the makefile.
<br/><br/>
Configure your compiler and other options in the makeloader.txt,
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
Sources |  Folder that contains all your sources files (.c, .cpp ...).

## Available commands
Commands | Uses
------------ | -------------
create | Generate all the folders of your project and the makeloader.txt.
build | Generate a makefile for your project using all the sources in the Sources folder and add the content of the makeloader.txt file in this new makefile.
make | Call the "make" program to compile your project.
info |  Give informations about MakeLoader.

## TODO
* Documentations