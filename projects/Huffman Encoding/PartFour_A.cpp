

#include "utility.h"


using namespace std;

// Function to read Huffman codes from "codetable.txt"
unordered_map<char, string> read_code_table(const string& filename) {
    ifstream file(filename);
    unordered_map<char, string> code_table;
    string line, code;
    char ch;

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return {};
    }

    while (getline(file, line)) {
        if (line.empty()) continue;
        if (line.substr(0, 2) == "LF") {
            ch = '\n';
            code = line.substr(3);
        }
        else if (line.substr(0, 5) == "SPACE") {
            ch = ' ';
            code = line.substr(6);
        }
        else {
            ch = line[0];
            code = line.substr(2);
        }
        code_table[ch] = code;
    }
    file.close();
    return code_table;
}

// Function to encode text using Huffman codes and write it in binary format
void encode_to_binary(const string& input_file, const string& output_file) {
    unordered_map<char, string> huffman_codes = read_code_table("codetable.txt");

    ifstream in_file(input_file, ios::binary);
    ofstream out_file(output_file, ios::binary);
    if (!in_file.is_open() || !out_file.is_open()) {
        cerr << "Error opening files!" << endl;
        return;
    }

    char character;
    string str;
    while (in_file.get(character)) {
        // Handle CR character by treating it as LF (if applicable)
        if (character == '\r') {
            auto lf = huffman_codes.find('\n');
            if (lf != huffman_codes.end()) {
                str += lf->second;
                continue;
            }
        }

        auto item = huffman_codes.find(character);
        if (item != huffman_codes.end()) {
            str += item->second;
            while (str.length() >= 8) {
                string byte_str = str.substr(0, 8);
                str = str.substr(8);
                out_file << static_cast<char>(bitset<8>(byte_str).to_ulong());
            }
        }
        else {
            cerr << ">> Unknown Character in Encoding: ASCII Code " << static_cast<int>(character) << endl;
        }
    }

    // Handle the remaining bits (padding with zeros if necessary)
    if (!str.empty()) {
        str += string(8 - str.size(), '0');
        out_file << static_cast<char>(bitset<8>(str).to_ulong());
    }

    in_file.close();
    out_file.close();
    cout << "Encoded data written to " << output_file << endl;
}

int main() {
    encode_to_binary("clear.txt", "codedalt.txt");
    return 0;
}