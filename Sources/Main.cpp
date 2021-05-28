#include "../Headers/Application.h"

int main(int argc, char * argv[])
{
	MakeLoader::Application application;
	application.start(argc, argv);
	return 0;
}