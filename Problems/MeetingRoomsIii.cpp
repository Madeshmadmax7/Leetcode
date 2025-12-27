/*
 * @lc app=leetcode id=1866761725 lang=cpp
 *
 * MeetingRoomsIii
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        priority_queue<vector<long long int>, vector<vector<long long int>>, greater<vector<long long int>>> meetings;
        for(auto& vec : m) {
            meetings.push({(long long)vec[0], (long long)vec[1]});
        }

        vector<vector<long long int>> rooms(n, vector<long long int>(3, 0));

        while(!meetings.empty()) {
            auto meeting = meetings.top();
            meetings.pop();

            long long int startTimeOfMeeting = meeting[0];
            long long int endTimeOfMeeting = meeting[1];

            long long int minEndTime = LLONG_MAX;
            long long int minEndTimeIndex;
            bool roomFound = false;

            for(int i = 0; i < n; i++) {
                if(rooms[i][0] < minEndTime) {
                    minEndTime = rooms[i][0];
                    minEndTimeIndex = i;
                }

                if(rooms[i][0] <= startTimeOfMeeting) {
                    roomFound = true;
                    rooms[i][0] = endTimeOfMeeting;
                    rooms[i][2]++;
                    break;
                }
            }

            if(!roomFound) {
                rooms[minEndTimeIndex][0] += (endTimeOfMeeting - startTimeOfMeeting);
                rooms[minEndTimeIndex][2]++;
            }
        }

        long long int maxCount = LLONG_MIN;
        long long int roomNumber;

        for(int i = 0; i < n; i++) {
            if(rooms[i][2] > maxCount) {
                maxCount = rooms[i][2];
                roomNumber = i;
            }
        }

        return roomNumber;
    }
};