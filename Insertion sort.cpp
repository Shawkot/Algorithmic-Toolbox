#include <iostream>
#include <vector>
using namespace std;

void insertionsort(vector<int> &a, int n)
{
    int value, key;
    for(int i=1; i <= n-1; i++){
      value = a[i];
      key = i;
      while(key > 0 && a[key - 1] > value){
        a[key] = a[key - 1]; // First, push the greater value to the right
        key = key - 1;       // because key index is greater than key-1
      }                      //then reducing the key index by 1
      a[key] = value;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(size_t i=0; i<n; i++){
        cin >> a[i];
    }
    insertionsort(a, n);
    cout << "Sorted Array: ";
    for(size_t i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    return 0;

}
