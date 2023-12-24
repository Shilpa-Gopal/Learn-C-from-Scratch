# Huffman Coding Project

## Overview

Huffman coding is a lossless data compression algorithm that assigns variable-length codes to input characters based on their frequencies. The project aims to simplify and code the Huffman algorithm for better understanding and ease of implementation.

## Part One: Character Count

### Description
Create a program (PartOne.cpp) to read a text file (input.txt) and generate an output file (freq.txt) containing the frequency counts of each character.

### Steps
1. Use get(x) function for reading characters.
2. Implement character counting and write to freq.txt.
3. Order results in freq.txt by ASCII integer.
4. Include a prologue comment in the code with team details.

### Hints
- Use utility.h file.
- Avoid reading the entire file into memory.
- Utilize static_cast <int>( ) and static_cast <char>( ) typecasts.

## Part Two: Huffman Codes

### Description
Build on Part One. Create a program (PartTwo.cpp) to generate Huffman codes for characters and save them in codetable.txt.

### Steps
1. Set up a binary node struct.
2. Use STL list class or priority queue for frequency sorting.
3. Save codes in codetable.txt ordered by ASCII value.
4. Include a prologue comment in the code with team details.

### Hints
- Create a binary node struct.
- Utilize STL list or priority queue class.

## Part Three: Encoding and Decoding

### Part Three A (Encoding):

#### Description
Create PartThreeA.cpp to read clear.txt and generate coded.txt using Huffman codes from codetable.txt.

#### Steps
1. Read clear.txt character by character.
2. Find the corresponding binary code.
3. Write binary code to coded.txt.

#### Hint
- Do not bring the entire clear.txt into memory.

### Part Three B (Decoding):

#### Description
Create PartThreeB.cpp to read coded.txt and decode it back to characters, saving results in decoded.txt.

#### Steps
1. Read coded.txt.
2. Decode binary codes.
3. Write results to decoded.txt.

## Part Four: Optimized Encoding

### Part Four A (Bit-Level Encoding):

#### Description
Modify encoding to represent Huffman codes as actual strings of bits. Save in codedalt.txt.

#### Steps
1. Work at the bit level.
2. Use C++ bitset class.
3. Write bytes to codedalt.txt.

### Part Four B (Bit-Level Decoding):

#### Description
Create PartFourB.cpp to read codedalt.txt and decode it back into characters, saving results in decodedalt.txt.

#### Steps
1. Read codedalt.txt as bytes.
2. Decode bits back into characters.
3. Write results to decodedalt.txt.


