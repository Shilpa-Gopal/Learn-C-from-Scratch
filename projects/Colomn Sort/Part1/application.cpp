#include <iostream>
#include <string>
#include "utility.h"
#include "filer.h"

int main() {
    filer fileCreator;

    int totalIntegers, maxLimit, totalFiles;
    std::string fileDirectory = "C:/Users/shlpg/source/repos/Program3/x64/Debug/RandomNumebrs";  // Define your directory path here
    std::string filePrefix;

    std::cout << "Enter the number of files to create: ";
    std::cin >> totalFiles;

    std::cout << "Enter the total number of integers: ";
    std::cin >> totalIntegers;

    std::cout << "Enter the maximum limit for the numbers: ";
    std::cin >> maxLimit;

    std::cout << "Enter the file name prefix: ";
    std::cin >> filePrefix;

    for (int fileIndex = 1; fileIndex <= totalFiles; ++fileIndex) {
        std::string fileName = fileDirectory + "/" + filePrefix + "_" + std::to_string(fileIndex) + ".txt";
        fileCreator.makefile(totalIntegers, maxLimit, fileName);
    }

    return 0;
}
