#include "utility.h"
#include "filer.h"


void filer::makefile(int n, int range, std::string file_name) {
    std::ofstream outFile(file_name);
    if (outFile.is_open()) {
        srand(static_cast<unsigned>(time(nullptr)));

        for (int i = 0; i < n; ++i) {
            int randomNum = next_number(range);
            outFile << randomNum << "\n";
        }

        outFile.close();
        std::cout << "File " << file_name << " created with " << n << " random numbers.\n";
    }
    else {
        std::cerr << "Error creating file: " << file_name << std::endl;
    }
}

int filer::next_number(int range) {
    return rand() % (range + 1);
}
