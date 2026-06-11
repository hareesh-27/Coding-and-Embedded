#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;

    // input size
    cin >> n;

    // dynamic array
    int *arr = new int[n];

    // initialize 1 → n
    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // input k
    cin >> k;

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // first k elements
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // process remaining
    for(int i = k; i < n; i++) {
        if(arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // result
    cout << pq.top() << endl;

    delete[] arr;
    return 0;
}
