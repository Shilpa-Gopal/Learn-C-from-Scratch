#include "utility.h"
#include "timer.h"

// WARNING: Update the input, part1Data and Results paths with the appropriate file paths in main function before running/executing

const int r = 4000; // Defined your r and s values according to the assignment rules
const int s = 25; 

bool SortCheck(const std::vector<std::vector<int>>& matrix) {
    for (size_t col = 0; col < matrix.size(); ++col) {
        for (size_t row = 1; row < matrix[col].size(); ++row) {
            if (matrix[col][row - 1] > matrix[col][row]) {
                return false; // Not sorted
            }
        }
    }
    return true; // Sorted
}


// Function to sort the values in each column
void sortColumns(std::vector<std::vector<int>>& matrix) {
    for (int col = 0; col < s; ++col) {

        int column[r];
        for (int row = 0; row < r; ++row) {
            column[row] = matrix[row][col];
        }

        std::sort(column, column + r);
        for (int row = 0; row < r; ++row) {
            matrix[row][col] = column[row];
        }
    }
}

// Function to sort the values in each column
void sortshift(std::vector<std::vector<int>>& shift) {
    for (int col = 0; col < (s+1); ++col) {

        int column[r];
        for (int row = 0; row < r; ++row) {
            column[row] = shift[row][col];
        }

        std::sort(column, column + r);

        for (int row = 0; row < r; ++row) {
            shift[row][col] = column[row];
        }
    }
}

// Function to transpose the matrix
void transpose(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& transposed) {
    
    std::vector<int> list;
    for (size_t i = 0; i < s; ++i) {
        for (size_t j = 0; j < r; ++j) {
            list.push_back(matrix[j][i]);
        }
    }

    size_t index = 0;
    for (size_t i = 0; i < r; ++i) {
        for (size_t j = 0; j < s; ++j) {
            transposed[i][j] = list[index];
            index++;
        }
    }
}



// Function to retranspose the matrix
void retranspose(std::vector<std::vector<int>>& transposed, std::vector<std::vector<int>>& retransposed) {
    std::vector<int> list;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            list.push_back(transposed[i][j]);
        }
    }
    
    int index = 0;
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < r; ++j) {
            retransposed[j][i] = list[index];
            index++;
        }
    }
}

// Function to shift the matrix
void shift(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& shiftmatrix) {
    const int INFINITY_NEG = -32766;
    const int INFINITY_POS = 32767;
    const int shiftAmount = r / 2;

    std::vector<int> list;

    for (int i = 0; i < shiftAmount; ++i) {
        list.push_back(INFINITY_NEG);
    }

    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < r; ++j) {
            list.push_back(matrix[j][i]);
        }
    }

    for (int i = shiftAmount; i > -1; --i) {
        list.push_back(INFINITY_POS);
    }


    int index = 0;
    for (int i = 0; i < (s + 1); ++i) {
        for (int j = 0; j < r; ++j) {
            shiftmatrix[j][i] = list[index];
            index++;
        }
    }


}

// Function to shift back the matrix
void shiftback(std::vector<std::vector<int>>& shiftmatrix, std::vector<std::vector<int>>& matrix) {

    const int shiftAmount = r / 2;

    std::vector<int> list;

 
    for (int i = 0; i < (s+1); ++i) {
        for (int j = 0; j < r; ++j) {
            list.push_back(shiftmatrix[j][i]);
        }
    }
    list.erase(list.begin(), list.begin() + shiftAmount);


    int index = 0;
    for (int i = 0; i < (s); ++i) {
        for (int j = 0; j < r; ++j) {
            matrix[j][i] = list[index];
            index++;
        }
    }


}


// Function to display the shiftmatrix
void displayshift(const std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < (s + 1); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


// Function to display the matrix
void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}



int main() {
    std::vector<std::vector<int>> matrix(r, std::vector<int>(s));

    std::ifstream inputFile("C:/Users/shlpg/source/repos/Program3/x64/Debug/RandomNumebrs/rn_3.txt");
    if (!inputFile) {
        std::cerr << "Unable to open input file!";
        return 1;
    }

    // Reading the 100,000 integers and creating the matrix
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            if (!(inputFile >> matrix[i][j])) {
                std::cerr << "Error reading input file!";
                return 1;
            }
        }
    }
    inputFile.close();

    // Saving the matrix to Part1Data file path
    std::ofstream outputFile("C:/Users/shlpg/source/repos/Program3_3/Part1Data/Part1data_3.txt");

    if (!outputFile) {
        std::cerr << "Unable to create output file!";
        return 1;
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            outputFile << matrix[i][j] << " ";
        }
        outputFile << "\n";
    }
    outputFile.close();

    // Timer for recording Columnsort time
    Timer timer;

    // Now, you can perform your operations using vectors instead of arrays
    
    sortColumns(matrix);


    std::vector<std::vector<int>> transposedMatrix(r, std::vector<int>(s));
    transpose(matrix, transposedMatrix);

    
    sortColumns(transposedMatrix);
    
    std::vector<std::vector<int>> retransposedMatrix(r, std::vector<int>(s));
    retranspose(transposedMatrix, retransposedMatrix);
    
    sortColumns(retransposedMatrix);
    
    std::vector<std::vector<int>> shiftmatrix(r, std::vector<int>(s + 1));

    shift(retransposedMatrix, shiftmatrix);
    sortshift(shiftmatrix);
    
    shiftback(shiftmatrix, matrix); 

    double sortingTime = timer.elapsed_time(); // Time taken by Columnsort
    std::cout << "Columnsort time: " << sortingTime << " seconds\n";

    // SortCheck checks if the matrix is sorted
    bool isSorted = SortCheck(matrix);
    if (isSorted) {
        std::cout << "The matrix is sorted.\n";
        std::ofstream outputFile("C:/Users/shlpg/source/repos/Program3_3/Results/Result_3.txt");
        if (outputFile.is_open()) {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < s; ++j) {
                    outputFile << matrix[i][j] << " ";
                }
                outputFile << "\n";
            }
            outputFile.close();
        }
        else {
            std::cerr << "Error opening the output file." << std::endl;
            return 1; 
        }
    }
    else {
        std::cerr << "Matrix is not sorted." << std::endl;
    }

    

    

    /*

    // Display the sorted matrix
    for (const auto& row : transposedMatrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    } */

    // displayMatrix(matrix);

    return 0;
}
