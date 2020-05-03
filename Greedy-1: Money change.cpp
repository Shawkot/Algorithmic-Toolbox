#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int result = n/10;
    int remainder = n % 10;
    int result2 = remainder/5;
    int remainder2 = remainder % 5;
    int result3 = remainder2/1;
    cout << (result + result2 + result3) << endl;
}
