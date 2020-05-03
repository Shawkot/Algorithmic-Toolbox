// Divide and Conquer approach
#include <iostream>
#include <vector>
using namespace std;

void merging(vector<int> &arr, int left, int m, int r)
{
	int i, j, k;
	int n1 = m - left + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; j = 0;
	k = left; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int> &arr, int left, int r)
{
	if (left >= r)
        return;

    // Same as l+(r-l)/2, but overflow can be happened for
    // large l and h
    int m = (r+left)/2;
    // Sort first and second halves
    mergeSort(arr, left, m);
    mergeSort(arr, m+1, r);
    merging(arr, left, m, r);

}

int main()
{
	int n;
	cin >> n;
	vector <int> arr(n);
	for(size_t i=0; i<n; i++){
        cin >> arr[i];
	}
	cout << "Given array: ";
	for(size_t i=0; i<n; i++){
        cout << arr[i] << ' ';
	}
	cout << endl;
	mergeSort(arr, 0, n-1);
	cout << "Sorted Array: ";
	for(size_t i=0; i<n; i++){
        cout << arr[i] << ' ';
	}
	return 0;
}
