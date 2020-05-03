#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getMajorityElement(vector<int> &a) {

        if (a.size() == 1) {
            return 0;
        }

        // Step 1: Find max element
        int candidate = 0;
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (count == 0) {
                candidate = a[i];
                count = 1;
                continue;
            } else {
                if (candidate == a[i]) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        if (count == 0) {
            return 0;
        }

        // Step 2: Check if candidate is majority element
        count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (candidate == a[i]) {
                count++;
            }
        }
        return (count > a.size() / 2) ? 1 : 0;
    }

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  cout << getMajorityElement(a) << '\n';
}

