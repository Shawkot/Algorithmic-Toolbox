// "Greedy" approach

#include <iostream>
#include <vector>
using namespace std;

int compute_min_refills(size_t dist, int tank, vector<int> &stops) {
    int n = stops.size();
    stops.insert(stops.begin(), 0); // Inserting at the beginning of the vector
    stops.push_back(dist); // Inserting at the end of the vector
    int numRefills = 0;
    int currentRefills = 0;

    while(currentRefills <= n){
        int lastRefills = currentRefills;
        while(currentRefills <= n && stops[currentRefills+1] - stops[lastRefills] <= tank){
            currentRefills = currentRefills + 1;
        }
        if(currentRefills == lastRefills){
            return -1;
        }
        else if(currentRefills <= n){
            numRefills = numRefills + 1;
        }
    }
    return numRefills;
}

int main() {
    int d;
    cin >> d;
    int m;
    cin >> m;
    int n;
    cin >> n;
    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    cout << compute_min_refills(d, m, stops) << "\n";
    return 0;
}



