// "Divide and Conquer" approach
#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

void partition2(vector<int> &a, int left, int right, int &i, int &j) {
   if (right - left <= 1) {
      if (a[right] < a[left])
         swap(a[right], a[left]);
      i = left;
      j = right;
      return;
}
int mid = left;
int pivot = a[right];
while (mid <= right) {
   if (a[mid]<pivot)
      swap(a[left++], a[mid++]);
      else if (a[mid]==pivot)
         mid++;
      else if (a[mid] > pivot)
         swap(a[mid], a[right--]);
   }
   i = left-1;
   j = mid;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int i, j;
  partition2(a, l, r, i, j);

  randomized_quick_sort(a, l, i);
  randomized_quick_sort(a, j, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}

