#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

bool check[100000];

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) return true;
    else return false;
}

int main() {
    int n; cin >> n;

    vector<int> km(n - 1);
    vector<pair<int, int> > price(n - 1);

    for (int i = 0; i < n - 1; i++) cin >> km[i];
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            int temp; cin >> temp;
        }
        else {
            cin >> price[i].first;
            price[i].second = i;
        }
    }

    vector<pair<int, int> > sortPrice = price;
    sort(sortPrice.begin(), sortPrice.end(), compare);

    ll total = 0;
    for (int i = 0; i < n - 1; i++) {
        int index = sortPrice[i].second;
        if (check[index] == false) {
            int cost = price[index].first;
            for (int j = index; j < n - 1; j++) {
                if (check[j] == true) break;
                check[j] = true;
                total += 1L * cost * km[j];
            }
        }
    }

    cout << total;
}