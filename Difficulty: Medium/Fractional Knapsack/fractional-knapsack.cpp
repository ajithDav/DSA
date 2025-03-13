//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
      struct Item {
        int value;
        int weight;
    };
 static bool comp(const Item& a, const Item& b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }

    // Fractional Knapsack function
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> arr(n);

        // Create an array of items (value-weight pairs)
        for (int i = 0; i < n; i++) {
            arr[i] = {val[i], wt[i]};
        }

        // Sort items by value/weight ratio
        sort(arr.begin(), arr.end(), comp);

        double finalValue = 0.0;
        int curWeight = 0;

        // Process items one by one
        for (int i = 0; i < n; i++) {
            // Take full item if it fits
            if (curWeight + arr[i].weight <= capacity) {
                curWeight += arr[i].weight;
                finalValue += arr[i].value;
            } 
            // Take fraction of the item if remaining capacity is smaller
            else {
                int remain = capacity - curWeight;
                finalValue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                break;  // No more room, exit
            }
        }

        return finalValue;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends