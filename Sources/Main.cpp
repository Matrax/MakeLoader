#include "../Headers/Core/Application.hpp"

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

	try {
		application.start(argc, argv);
	} catch(const std::runtime_error & exception) {
		std::cerr << "\n[MakeLoader] " << exception.what() << std::endl;
	}

	return 0;
}
