#include <iostream>
#include <vector>
using namespace std;

void merging(vector<int> &a, int left, int mid, int right)
{
    int firstarrcnt, secondarrcond, i;
    firstarrcnt = left;
    secondarrcond = mid+1; int temp[a.size()];
    for(i=firstarrcnt; firstarrcnt <= mid && secondarrcond <= right; i++){
        if(a[firstarrcnt] < a[secondarrcond]){
            temp[i] = a[firstarrcnt++];
        }
        else{
            temp[i] = a[secondarrcond++];
        }
    }
    while(firstarrcnt <= mid){
        temp[i++] = a[firstarrcnt++];
    }
    while(secondarrcond <= right){
        temp[i++] = a[secondarrcond++];
    }
    for(i=left; i<=right; i++){
        a[i] = temp[i];
    }

}

void mergesort(vector <int> &a, int left, int right)
{
    if(left >= right)
        return;
    int mid = (right + left)/2;
    mergesort(a, left, mid);
    mergesort(a, mid+1, right);
    merging(a, left, mid, right);

}

int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for(size_t i=0; i<n; i++){
        cin >> a[i];
    }
    mergesort(a, 0, n-1);
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}
