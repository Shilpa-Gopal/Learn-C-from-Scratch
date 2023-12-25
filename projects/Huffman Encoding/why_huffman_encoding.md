# Part Three Analysis

## Overview
The table below presents a comparison of file sizes between the original text (`clear.txt`) and its corresponding Huffman-encoded file (`coded.txt`) for three different input files. The first row in Data Collection table represents the file sizes for the clear Mary.txt (“clear.txt”) provided along with assignment and generated coded.txt. The analysis focuses on understanding the efficiency of Huffman encoding in terms of compression ratios and highlights variations based on the characteristics of the input data.

## Data Collection
Comparison of file sizes between clear.txt and coded.txt (the version which represents each bit as an ASCII character)

Clear.txt (input file) in Bytes    | Coded.txt (output file) in Bytes
-----------------------------------|-----------------------------------
484                                | 3000
4022                               | 2570
3793                               | 21411

- Yes, Huffman's coding algorithm takes more bit than the original size (for coded.txt)
- When a text is too short and the probability distribution function looks uniform, the frequencies of occurrence are (more or less) the same, the input string gets very close to random noise. It is impossible to compress random noise in a general way, compression will most likely be longer than the input sequence, because one also needs to add some metadata, like an encoding table.
- If one tries to encode a longer general English text, one would notice at some point, the encoded string size will start to get dramatically shorter than the original text. This is because the encoded sequence frequencies will start to make a much higher impact - the most frequent character will be encoded with the shortest possible code and because it is repeated a lot, its shorter size will dominate the size of the original character.
- When using Huffman encoding each character is assigned a code with code lengths dependent on the frequency of characters in the text. However in cases where the file size is relatively small like in clear.txt the overhead involved in this method may outweigh the advantages of compression. This is especially true for texts that have a range of characters. If we store the codes as ASCII text characters ('0s and '1s) in coded.txt each binary digit takes up a byte. In contrast the original file stores each character (including spaces and punctuation) in one byte. This difference can significantly increase the size of the coded.txt file.
- In fact, since each code is at least one bit long and decodes to a byte, representing each coded bit as a byte guarantees that coded.txt will be at least as big as clear.txt. Huffman encoding is generally more effective at compressing files that have patterns of characters. However when dealing with files like clear.txt (484 bytes) where there is diversity in character usage, significant compression benefits may not be achievable and could potentially result in adding more bytes to the file. Additionally encoded files such as coded.txt may include metadata like headers or mappings between characters and their corresponding codes, which cause an increase in file size. In addition extra bits can be added to ensure that the encoded data is properly aligned which can result in a file size.

# Part Four Analysis

## codedalt analysis
codedalt.txt is roughly 57% of the size of the uncompressed text. Since clear.txt is an excerpt of English text, it has a very uneven frequency distribution of bytes (characters). Some values (such as the ASCII value for ‘e’) are used very frequently, while others (such as ASCII value 7, which is a command to ring a bell) are not used at all. This makes it a good candidate for Huffman encoding.
However, since the code table takes up 367 bytes, we have not truly reduced the size of the file. If clear.txt were long enough, the number of bytes saved by encoding would probably be bigger than the size of the table.
One drawback of codedalt.txt is that it contains a junk character at the end. This is because most (all?) operating systems only allow users to make files with lengths specified in numbers of bytes. In other words, the number of bits must be divisible by 8, regardless of the number of bits in the compressed file.
One way to fix this problem would be to have a header that contains the number of bits in the file. Alternatively, you could have a header containing the number of symbols. I asked Fabian Giesen (who works on huffman encoding professionally) what mechanism his software uses, and he told me they have a header with the size of the stream (stream here refers to “bit stream”.)
