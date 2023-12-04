/**
// File Name: PartThree.cpp
// Purpose :
// Part(A): Encode the characters in a given text file, clear.txt, and generate a
// corresponding output file, coded.txt, containing the sequence of bits representing Huffman codes using codetable.txt
// Part(B): Decode the sequence of bits representing Huffman codes in a given text file, coded.txt, and generate a
// corresponding output file, decoded.txt using codetable.txt
// Author(s): Shilpa Gopal
// Creation Date: 2023-11-23
**/

#include "utility.h"

/*
 * It takes a file and encodes it using a special set of Huffman codes.
 * translating each character in the file into a secret code according to a code book (the codeTable).
 * It reads the file you give it (inputFileName), goes through it character by character, and replaces each
 * character with its code. These codes are then written into another file (outputFileName) - encoded file.
 *
 * Parameters:
 * - inputFileName: original file to encode
 * - outputFileName: save encoded file
 * - codeTable: character-to-code mappings.
 */


void encode(const string& inputFileName, const string& outputFileName, const unordered_map<string, string>& codeTable) {
    ifstream inputFile(inputFileName, ios::in);
    ofstream outputFile(outputFileName, ios::out);

    // Check if files are successfully opened
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return;
    }

    unsigned char ch;
    string seperator = "X";
    while (inputFile.get(reinterpret_cast<char&>(ch))) {

        // Encoding newline character
        if (ch == '\n') {
            auto it = codeTable.find("LF");
            outputFile << it->second << seperator;
        }

        // Encoding space character
        else if (isspace(ch)) {
            auto it = codeTable.find("SPACE");
            outputFile << it->second << seperator;
        }

        // Encoding other characters
        else {
            string key;
            key = ch;
            if (codeTable.find(key) != codeTable.end()) {

                auto it = codeTable.find(key);
                outputFile << it->second << seperator;
            }

            else {
                cerr << "Character not found in the code table: " << ch << endl;
            }

        }

    }

    inputFile.close();
    outputFile.close();
}


/*
 * the reverse of the encode function. It takes the file
 * filled with codes (inputFileName), reads these codes, and then uses the codeTable to figure out what each code
 * originally meant. Basically, it's turning the secret codes back into the original text. Once it does that, it
 * writes this decoded text into a new file (outputFileName).
 *
 * Parameters:
 * - inputFileName: file with all the codes.
 * - outputFileName: decoded output file
 * - codeTable:  character to code mapping, used for decoding
 */
void decode(const string& inputFileName, const string& outputFileName, const unordered_map<string, string>& codeTable) {

    ifstream inputFile(inputFileName, ios::in);
    ofstream outputFile(outputFileName, ios::out);


    // Check if files are successfully opened
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Oops! There's an error opening your file! Try again!" << endl;
        return;
    }

    unordered_map<string, string> inverseCodeTable;
    for (auto& pair : codeTable)
    {
        string code = pair.second;
        inverseCodeTable[code] = pair.first;
    }

    string bits;
    char bit;
    while (inputFile.get(bit)) {

        if (bit != 'X') {
            bits += bit;
        }

        else {
            if (inverseCodeTable.find(bits) != inverseCodeTable.end()) {

                auto it = inverseCodeTable.find(bits);
                string decode_char = it->second;

                if (decode_char == "LF") {

                    outputFile << endl;
                }
                else if (decode_char == "SPACE") {

                    outputFile << ' ';
                }
                else {
                    outputFile << it->second;
                }
            }

            else {
                cerr << "Character not found in the code table for decoding: " << bits << endl;
            }

            bits.clear();
        }


    }


    inputFile.close();
    outputFile.close();

}



int main() {

    // Assuming you have a codetable.txt in the format: character code
    unordered_map<string, string> codeTable;

    // Populate codeTable from codetable.txt
    ifstream codeTableFile("codetable.txt");

    string line;


    while (getline(codeTableFile, line)) {
        string ch;

        // Find position of ' ' using find()
        int pos = line.find(" ");

        ch = line.substr(0, pos);
        codeTable[ch] = line.substr(pos + 1);


    }
    codeTableFile.close();


    encode("clear.txt", "coded.txt", codeTable);

    decode("coded.txt", "decoded.txt", codeTable);

    return 0;
}
