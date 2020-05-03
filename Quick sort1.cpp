// "Divide and Conquer" approach
#include <iostream>
#include <vector>
using namespace std;

void swapfunc(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partitionfunc(vector <int> &a, int left, int right, int pivot)
{
    int leftpointer = left - 1;
    int rightpointer = right;

    while(true){

        while(a[++leftpointer] < pivot){

        }
        while(rightpointer > 0 && a[--rightpointer] > pivot){

        }
        if(leftpointer >= rightpointer){
            break;
        }
        else{
        swapfunc(&a[leftpointer], &a[rightpointer]);
        }
    }
    swapfunc(&a[leftpointer], &a[right]);

    return leftpointer;
}

void quicksort(vector<int> &a, int left, int right)
{
    if(right - left <= 0)
        return;
    else{
        int pivot = a[right];
        int pi = partitionfunc(a, left, right, pivot);

        quicksort(a, left, pi - 1);
        quicksort(a, pi + 1, right);
    }
}

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
    quicksort(a, 0, n-1);
    cout << endl;
    cout << "Sorted Array: " ;
    for(size_t i=0; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}
