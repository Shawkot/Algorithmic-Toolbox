// "Greedy" approach
#include <iostream>
#include <vector>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int i = 0;
  int a;
  int n = values.size();
  while(i<n){
        if(capacity == 0)
            return value;
        double temp = 0.0;
        int temp3 = 0;
        for(int j=0; j<n; j++){
            if(weights[j] > 0){
                double temp2 = (values[j]/(double)weights[j]);
                if(temp < temp2){
                    temp = temp2;
                    temp3 = j;
                }
            }
        }
        int a = min(weights[temp3], capacity);

        value = value + (double)a * (values[temp3]/(double)weights[temp3]);
        weights[temp3] = weights[temp3] - a;
        capacity = capacity - a;
        i++;
    }
    return value;
}


int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
