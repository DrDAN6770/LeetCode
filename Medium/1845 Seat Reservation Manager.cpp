#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
void print_res(const T& input) {
    if constexpr (is_same_v<T, int> || is_same_v<T, long> || is_same_v<T, long long> ||
                  is_same_v<T, bool> || is_same_v<T, float> || is_same_v<T, double> || is_same_v<T, string>)
        cout << input << endl;

    else if constexpr (is_same_v<T, vector<int>>) {
        for (auto x : input)
            cout << x << " ";
        cout << endl;
    }
}

// minheap O(mlogn) O(n)
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> seat;
    int seatnumber = 1;

    SeatManager(int n) {      
    }

    int reserve() {
        if (!seat.empty()) {
            int x = seat.top();
            seat.pop();
            return x;
        }
        return seatnumber++;
    }
    
    void unreserve(int seatNumber) {
        seat.push(seatNumber);
    }
};

// minheap O((m+n) * logn) O(n)
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> seat;

    SeatManager(int n) {
        for (int i = 1; i <= n; i++)
            seat.push(i);
    }

    int reserve() {
        int x = seat.top();
        seat.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
        seat.push(seatNumber);
    }
};

int main() {
        
    return 0;
}