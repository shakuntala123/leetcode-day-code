//1716: Calculate Money in Leetcode Bank
/*
Problem breakdown
---------------
Hercy starts saving money on a Monday.

On the first Monday, he deposits $1.

Each subsequent day in the same week, he deposits $1 more than the previous day.

On each new Monday, he starts again, but with $1 more than the previous Monday.

----------------
solution
-------


*/

#include <iostream>
using namespace std;

int totalMoney(int n) {
    int weeks = n / 7;
    int days = n % 7;

    return 28 * weeks + 7 * weeks * (weeks - 1) / 2
           + days * (weeks + 1) + days * (days - 1) / 2;
}

int main() {
    cout << totalMoney(4) << endl;   // 10
    cout << totalMoney(10) << endl;  // 37
    cout << totalMoney(20) << endl;  // 96
    return 0;
}
