//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();

        // Pair each meeting's start and end times
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        // Sort meetings by end time
        sort(meetings.begin(), meetings.end());

        int count = 0;
        int lastEndTime = -1;

        // Select meetings greedily
        for (auto& meeting : meetings) {
            int meetingEnd = meeting.first;
            int meetingStart = meeting.second;

            // If this meeting starts after the last selected one ends
            if (meetingStart > lastEndTime) {
                count++;
                lastEndTime = meetingEnd;  // Update the end time to this meeting's end
            }
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends