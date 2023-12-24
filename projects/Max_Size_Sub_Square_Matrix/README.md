# Maximum Size Square Sub-Matrix with All 1s

This algorithm is designed to find the maximum size square sub-matrix with all elements as 1 in a given binary matrix. The idea is to construct an auxiliary matrix `S[][]`, where each entry `S[i][j]` represents the size of the square sub-matrix with all 1s, including the cell `M[i][j]`, which is the rightmost and bottom-most entry in the sub-matrix.

## Example

Consider the following binary matrix `M`:

```
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
```

The algorithm will output a square sub-matrix of size 3x3 with all 1s:

```
1 1 1
1 1 1
1 1 1
```
