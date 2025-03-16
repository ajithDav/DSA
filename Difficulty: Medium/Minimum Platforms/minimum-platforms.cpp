//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to find the minimum number of platforms required at the station
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();

        // Sort arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int ans = 1; // To store the maximum platforms needed
        int count = 1; // Current platforms needed
        int i = 1, j = 0;

        // Traverse through arrival and departure times
        while (i < n && j < n) {
            // If next train arrives before the current one departs, increase platform count
            if (arr[i] <= dep[j]) {
                count++;
                i++;
            }
            // Otherwise, free up a platform
            else {
                count--;
                j++;
            }
            // Update maximum platforms needed
            ans = max(ans, count);
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends