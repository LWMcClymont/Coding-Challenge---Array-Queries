#include <iostream>

using namespace std;

void solve(int* A, int& N, int& qSize, int* Q);

unsigned int max_unsigned = ~0 >> 1;

int main()
{
	int N = 0;
	cin >> N;

	int* A = new int[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	int qSize = 0;

	cin >> qSize;

	int* Q = new int[qSize * 2];

	for (int i = 0; i < qSize; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin >> Q[(2 * i) + j];
		}
	}

	cout << "Output: " << endl;

	// Check constraints 
	if (N >= 1 && qSize <= 100000)
	{
		solve(A, N, qSize, Q);
	}
	else
	{
		cout << "Input doesn't meet constraints" << endl;
	}

	delete[] A;
	delete[] Q;

	return 0;
}

void solve(int* A, int& N, int& qSize, int* Q)
{
	int* smallest = new int[qSize];

	bool foundSmallest = false;

	for (int q = 0; q < qSize; ++q)
	{
		int L = Q[2 * q] - 1;
		int R = Q[2 * q + 1] - 1;

		smallest[q] = max_unsigned >> 1;

		for (int i = L; i < R && !foundSmallest; ++i)
		{
			for (int j = (i + 1); j < R && !foundSmallest; ++j)
			{
				int temp = abs(A[i] - A[j]);

				if (temp < smallest[q])
				{
					smallest[q] = temp;
				}

				if (temp == 0)
				{
					foundSmallest = true; // value cant get any smaller than 0, so stop searching for this query
				}
			}
		}

		foundSmallest = false;
	}

	for (int i = 0; i < qSize; ++i)
	{
		cout << smallest[i] << endl;
	}

	delete[] smallest;
}