#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int lonelyinteger(vector<int> a) {
    int ans = 0;
    for (int i = 0; i < (int)a.size(); i++)
        ans ^= a[i];
    return ans;
}
int main() {

    int a_size; cin >> a_size;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<int> a;
    int a_item;
    for (int i = 0; i < a_size; i++) {
        cin >> a_item;
        a.push_back(a_item);
    }
    
    cout << lonelyinteger(a);

    return 0;
}