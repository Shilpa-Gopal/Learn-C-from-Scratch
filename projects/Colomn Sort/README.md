# Column Sort Algorithm

## Introduction

Why another sorting algorithm, when we already know that mergesort is the provably most efficient sorting complexity we can achieve?

Column Sort makes use of the multiprocessing/multithreading feature of computers, aiming to overcome the challenges faced by normal sorting algorithms in scenarios with high cache misses and large datasets. Real-world implementations can be found in places where datasets are tremendously huge, especially in applications like sorting vectors in Genetic Algorithms or serving as an underlying sorting algorithm for databases.

## Steps of Column Sort Algorithm

The steps of the Column Sort Algorithm are as follows:

1. **Sort Each Column Individually**
2. **Transpose**
3. **Sort Each Column Individually**
4. **Untranspose**
5. **Sort Each Column Individually**
6. **Shift**
7. **Sort Each Column Individually**
8. **Unshift**

## Task Division for Simplified Coding and Testing

Let's simplify the coding and testing process by dividing the task into three parts:

### Part 1

1. Write the `filer.cpp` file.
2. Develop the application file.
3. Use the application file to create three different files, each containing 100,000 random integers with a maximum numeric value of 32,000.

### Part 2

Write a program that reads a data file of integer data (one number per line) and sorts that file using one of the general sort techniques discussed earlier (insertion sort, selection sort, mergesort, heapsort, quicksort).

### Main Part 3 - Column Sort

After coding Column Sort and testing, the following results were obtained:

```plaintext
Dimensions for the input(4000x25)	R(row) = 4000,	S(column) = 25
General sort used	Merge Sort for comparing

	         General Sort time	     Column Sort time
Trial 1	           0.554	             0.246
Trail 2	           0.441	             0.307
Trail 3	           0.390	             0.255
```

## Evaluation

Is Column Sort worth the effort?

Yes, from the experiment, Column Sort takes less runtime compared to mergesort (with time complexity O(nlogn)). However, it comes at the cost of increased space complexity. The time complexity of Column Sort is O(R log R / S), where R is the number of rows and S is the number of columns. The constant factor grows exponentially as R decreases. While Column Sort might require more memory space due to its specific operations and intermediate steps, it can be faster in certain scenarios when the number of rows is relatively larger compared to the number of columns.

## Advantage in a Parallel Computing Environment

- **Independence of Columns**: Each column in Column Sort can be sorted independently of the others. This is advantageous in parallel computing, allowing different processors or threads to simultaneously work on sorting different columns without extensive coordination.
- **Parallel Scaling**: Column Sort aligns well with parallel computing paradigms, enabling efficient scaling in large-scale parallel systems.
- **Reduced Dependencies**: Independent sorting of each column reduces the need for extensive communication and synchronization between processing units.

## Practical Considerations

- **Complexity in Practical Use**: The actual advantages of Column Sort in a parallel environment may vary based on system architecture, data size, and the overhead of parallelization.
- **System Size and Processor Count**: The efficiency of Column Sort depends on the balance between coordination overhead and parallel benefits. For instance, with 10 processors, reasonable performance requires N (number of elements) to be greater than 1620.

In summary, Column Sort's ability to handle independent column sorting aligns well with parallel computing paradigms, but its practical advantages depend on system specifics, data size, and the overhead involved in parallelization.
