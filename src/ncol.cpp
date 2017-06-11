#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unistd.h>

// arguments
// 1: file name
// s: separator, defaults to ,

int main(int argc, char *argv[])
{
    // variables
    std::string line;       // to hold a line of code
    std::string fileName;   // file name

    // variables for dealing with arguments
    int c;               // argument selection
    extern char *optarg; // value of argument
    extern int optind, opterr, optopt;

    // argument variables and defaults
    char sep = ',';


    // iterarate through the options
    // s provides the separator
    while (optind < argc)
    {
        if ((c = getopt(argc, argv, "s:")) != -1)
        {
            // Option argument
            switch (c)
            {
            case 's':
                sep = *optarg;
                break;
            case '?':
                fprintf(stderr, "Unrecognized option: -%c\n", optopt);
                break;
            default:
                break;
            }
        }
        else
        {
            // Regular argument
            // <code to handle the argument>
            fileName = argv[optind];
            optind++; // Skip to the next argument
        }
    }

    // read the file
    // convert fileName to a C string with fileName.c_str()
    std::ifstream infile(fileName.c_str());

    // if the file can't be opened say so and exit
    if (!infile.is_open())
    {
        std::cout << "Unable to open file: " << fileName << std::endl;

        return 0;
    }

    // get first line and store in line
    getline(infile, line);

    // count number of commas
    unsigned int numChars = std::count(line.begin(), line.end(), sep);

    // add one
    numChars++;

    // print the number of characters to the screen
    std::cout << numChars << std::endl;

    // close the file
    infile.close();

    // return number of characters
    return numChars;
}