#include "cppmain.h"

int main(int argc, char *argv[])
{
    int i;

    std::cout << "argc = " << argc << "\n";

    for( i = 0; i < argc; i++)
    {
        std::cout << argv[i] << "\n";
    }
    
    std::cout << "end\n";
}
