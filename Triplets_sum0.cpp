#include <iostream>;
#include <algorithm>;
using namespace std;

bool findTriplets(int a[], int n) {
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++) {
        int l = a[i + 1];
        int r = a[n - 1];
        int x = a[i];

        while (l < r) {
            if (x + l + r == 0) return true;
            else if (x + l + r < 0) l++;
            else r--;
        }
    }
    return false;
}

int main() {
    int n; cin >> n;
    int a[7];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (findTriplets(a, n))
        cout << "1" << endl;
    else
        cout << "0" << endl;
}