/**
// File Name: PartThree.cpp
// Purpose :
// Part(A): Encode the characters in a given text file, clear.txt, and generate a
// corresponding output file, coded.txt, containing the a sequence of bits representing Huffman codes using codetable.txt
// Part(B): Decode the sequence of bits representing Huffman codes in a given text file, coded.txt, and generate a
// corresponding output file, decoded.txt using codetable.txt
// Author(s): Shilpa Gopal
// Creation Date: 2023-11-23
**/


#include "utility.h"
#include <unordered_map>



/**
 * @brief Encodes a file using the provided code table and writes the result to output file.
 *
 * @param inputFileName The name of the input file to be encoded.
 * @param outputFileName The name of the output file to write the encoded result.
 * @param codeTable A Map containing char and corresponing Huffman codes.
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


/**
 * @brief Decodes a file that has been encoded using a codeTable and writes the result to output file.
 *
 * @param inputFileName The name of the input file to be decoded.
 * @param outputFileName The name of the output file to write the decoded result.
 * @param codeTable A Map containing char and corresponing Huffman codes.
 */

void decode(const string& inputFileName, const string& outputFileName, const unordered_map<string, string>& codeTable) {
    
    ifstream inputFile(inputFileName, ios::in);
    ofstream outputFile(outputFileName, ios::out);
       

    // Check if files are successfully opened
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
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
    ifstream codeTableFile("C:/Users/shlpg/source/repos/Pro5_3/codetable.txt");

    string line;


    while (getline(codeTableFile, line)) {
        string ch;

        // Find position of ' ' using find()
        int pos = line.find(" ");

        ch = line.substr(0, pos);
        codeTable[ch] = line.substr(pos + 1);

      
    }
    codeTableFile.close();


    encode("C:/Users/shlpg/source/repos/Pro5_3/clear.txt", "C:/Users/shlpg/source/repos/Pro5_3/coded.txt", codeTable);
  
    decode("C:/Users/shlpg/source/repos/Pro5_3/coded.txt", "C:/Users/shlpg/source/repos/Pro5_3/decoded.txt", codeTable);


    return 0;
}
