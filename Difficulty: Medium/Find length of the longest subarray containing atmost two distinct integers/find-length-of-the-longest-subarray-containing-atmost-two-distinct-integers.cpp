//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int,int> freq;
        int l=0,maxlength=0;
        for(int r=0;r<arr.size();++r){
            freq[arr[r]]++;
            while(freq.size()>2){
                freq[arr[l]]--;
                if(freq[arr[l]]==0){
                    freq.erase(arr[l]);
                }
                l++;
            }
            maxlength=max(maxlength,r-l+1);
        }
        return maxlength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends