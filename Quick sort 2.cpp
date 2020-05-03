#include <iostream>
#include <vector>
#include <cstdlib>

using std::swap;
using namespace std;

void quicksort(vector<int> &a, int low, int high);
int partitionfunc(vector<int> &a, int low, int high);

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(size_t i=0; i < n; i++){
        cin >> a[i];
    }
    cout << "Given Array: ";
    for(size_t i=0; i < n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    quicksort(a, 0, n-1);
    cout << "Sorted Array: " ;
    for(size_t i=0; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}

void quicksort(vector<int> &a, int low, int high)
{
    if(high - low <= 0)
        return;
    int pi = partitionfunc(a, low, high);

    quicksort(a, low, pi-1);
    quicksort(a, pi+1, high);
}

int partitionfunc(vector<int> &a, int low, int high)
{
    int pivot = a[high]; // Taking the last element of the array as pivot
    int i = low - 1;
    for(int j = low; j <= high-1; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return (i+1);
}

