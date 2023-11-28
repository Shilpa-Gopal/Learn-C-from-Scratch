/**

// File Name: PartOne.cpp
// Purpose: Count the occurrences of characters in a given text file, clear.txt, and generate a
// corresponding output file, freq.txt, containing the character frequencies.
// Author(s): Shilpa Gopal
// Creation Date: 2023-11-21
**/

#include "utility.h"

/**
 * Writes the frequencies of characters to the output file.
 * Represents line feed character as 'LF'.
 *
 * @param outputFileName The name of the file where frequencies will be written.
 * @param freqMap A map containing the frequencies of characters.
 */
void countCharacters(const string& inputFileName, map<int, int>& freqMap) {
    ifstream inputFile(inputFileName, ios::in);

    if (!inputFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        freqMap[static_cast<int>(ch)]++;
    }

    inputFile.close();
}

/**
 * Writes the frequencies of characters to the output file.
 * Represents line feed character as 'LF'.
 *
 * @param outputFileName The name of the file where frequencies will be written.
 * @param freqMap A map containing the frequencies of characters.
 */
void writeFrequencies(const string& outputFileName, const map<int, int>& freqMap) {
    ofstream outputFile(outputFileName, ios::out);

    if (!outputFile.is_open()) {
        cerr << "Error opening output file!" << endl;
        return;
    }

    for (const auto& pair : freqMap) {
    if (pair.first == 10) { // Handle line feed character
        outputFile << "LF " << pair.second << endl;
    }  else if (pair.first == 13) {
        outputFile << "CR " << pair.second << endl;
    } else if (pair.first == 32) {
        outputFile << "SPACE " << pair.second << endl;
    } else {
        outputFile << static_cast<char>(pair.first) << " " << pair.second << endl;
      }
  }

    outputFile.close();
}

int main() {
    map<int, int> freqMap;

    // Count character frequencies in clear.txt
    countCharacters("clear.txt", freqMap);

    // Write frequencies to freq.txt
    writeFrequencies("freq.txt", freqMap);

    return 0;
}
