#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int findMedian(int arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    if (n % 2 != 0)
        return (int)arr[n / 2];
    return 0;
}


int main() {
    int arr; cin >>arr;
    int n = arr.size();
    cout << "Median = " << findMedian(arr) << endl;
    return 0;
}












/*
int findMedian(int a[], int n){
    sort(a, a + n);
    if (n % 2 != 0)
        return (int)a[n / 2];
    return 0;
}


int main(){
    int n; cin >> n;
    int a[10];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Median = " << findMedian(a, n) << endl;
    return 0;
}
*/