#include <iostream>
#include "Editor.h"

int main(int argc, char** argv)
{
    Editor::Init();
    std::cout << "Argument count: " << argc << std::endl;
    for(int i = 0; i < argc; i++)
        std::cout << "Arguments: " << argv[i] << std::endl;
}