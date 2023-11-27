#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "timer.h"

// WARNING: Update the inputPath and outputPath with the appropriate file paths in main function before running/executing

void merge(std::vector<short>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<short> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<short>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

bool isSorted(const std::vector<short>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false; // Array is not sorted
        }
    }
    return true; // Array is sorted
}

int main() {
    Timer timer;
    std::vector<short> numbers;
    
    for (int run = 1; run <= 3; ++run) {
        // Change this to the actual input file path
        std::ifstream inputFile("C:/Users/shlpg/source/repos/Program3/x64/Debug/RandomNumebrs/rn_" + std::to_string(run) + ".txt");
        if (!inputFile) {
            std::cerr << "Error opening the file." << std::endl;
            return 1;
        }

        short num;
        while (inputFile >> num) {
            numbers.push_back(num);
        }
        inputFile.close();

        timer.reset();
        mergeSort(numbers, 0, numbers.size() - 1);
        double elapsed = timer.elapsed_time();

        bool sorted = isSorted(numbers); // Check if the array is sorted
        if (sorted) {
            // Change this to the actual output file path
            // The array is sorted, proceed to write to the output file
            std::ofstream outputFile("C:/Users/shlpg/source/repos/Program3/x64/Debug/Output_sorted/output" + std::to_string(run) + ".txt");
            if (outputFile.is_open()) {
                for (const auto& number : numbers) {
                    outputFile << number << "\n";
                }
                outputFile.close();
            }
            else {
                std::cerr << "Error opening the output file." << std::endl;
                return 1; // Return error code if failed to open output file
            }
        }
        else {
            std::cerr << "Array is not sorted." << std::endl;
            // Handle the case where the array is not sorted as required
        }

        std::ofstream outputFile("C:/Users/shlpg/source/repos/Program3/x64/Debug/Output_sorted/output" + std::to_string(run) + ".txt");
        if (!outputFile) {
            std::cerr << "Error creating the output file." << std::endl;
            return 1;
        }

        for (const auto& number : numbers) {
            outputFile << number << "\n";
        }
        outputFile.close();

        std::cout.setf(std::ios::fixed);
        std::cout.setf(std::ios::showpoint);
        std::cout.precision(3);
        std::cout << "Run " << run << " elapsed time: " << elapsed << " seconds" << std::endl;

        numbers.clear(); // Clear vector for next run
    }

    return 0;
}
