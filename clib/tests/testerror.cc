
#include <cstdlib> // for EXIT_SUCCESS...

#include <iostream>
#include <string>
#include <sstream>
#include "src/util.h"
#include "src/GFError.h"

int main(int argc, char **argv)
{

    try {
        GF::Fatal("This is a string parameter: '%s'. This is a float parameter: '%f'. This is an int parameter: '%i'. This is a char parameter: '%c'. ",
            "strParam",3.1415, 7, '\a');
    }
    catch (GFError gfe) {
        std::cerr << gfe.get_message();
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;

}
