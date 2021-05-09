# Coding-Challenge---Array-Queries

Task:

Given an array A, with N elements:

Answer Q queries of the type:

- L R : Find the minimum value of abs(A[i]-A[k]) with L <= i, j <= R and i != j

Input format:
- First line contain an integer N
- Next line contains N space separated integers, denoting elements of A
- Next line contain an integer Q
- Next Q lines contains two space separated integers L R

Constraints:
- 1 <= A[i] <= 300
- 1 <= N, Q <= 10^5
- 1 <= L < R <= N

Example:
Input:
- `6`
- `5 2 6 72 2 8`
- `2`
- `1 6`
- `2 4`

Output:
- `0` 
- `4`
