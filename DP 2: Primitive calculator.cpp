#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

void primitive_calculator(int number)
{
    vector<int> min_steps(number + 1);
    vector<int> predecessor(number + 1);

    for (int i = 2; i <= number; i++) {
        min_steps[i] = min_steps[i-1] + 1;
        predecessor[i] = i - 1;
        if (i % 3 == 0) {
            if (min_steps[i/3] < min_steps[i]) {
                min_steps[i] = min_steps[i/3] + 1;
                predecessor[i] = i/3;
            }
        }
        if (i % 2 == 0) {
            if (min_steps[i/2] < min_steps[i]) {
                min_steps[i] = min_steps[i/2] + 1;
                predecessor[i] = i/2;
            }
        }
    }

    cout << min_steps[number] << "\n";

    vector<int> sequence;
    for (int i = number; i != 0; ) {
        sequence.push_back(i);
        i = predecessor[i];
    }
    reverse(sequence.begin(), sequence.end());
    for (int i=0; i < sequence.size(); i++) {
        cout << sequence[i] << " ";
    }
}

int main()
{
    int number;
    cin>>number;
    primitive_calculator(number);
    return 0;
}
