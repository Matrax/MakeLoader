#include "../Headers/Application.hpp"

/**
* Main entry of the MakeLoader program.
* This main function initialize and start the Application object that 
* is a representation of the program and manage the command entered by the user.
* check how to use MakeLoader here : https://github.com/Matrax/MakeLoader
* @author Matrax
* @version 1.0
**/
int main(int argc, char * argv[])
{
	Application application;
	application.start(argc, argv);
	return 0;
}