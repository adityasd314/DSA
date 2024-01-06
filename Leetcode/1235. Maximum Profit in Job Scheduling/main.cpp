
struct Job {
    short start;
    short end;
    short profit;
};

bool jobComparator(const Job &a, const Job &b) {
    return a.end < b.end;
}
class Solution {
public:
    int jobScheduling(vector<short>& startTime, vector<short>& endTime, vector<short>& profit) {
        short n = startTime.size();
        vector<Job> jobs;
        for (short i = 0; i < n; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), jobComparator);
        vector<int> dp(n, 0);
        dp[0] = jobs[0].profit;

        for (short i = 1; i < n; ++i) {
            short lastCompatibleJob = binarySearch(jobs, i);
            dp[i] = max(dp[i - 1], (lastCompatibleJob != -1) ? jobs[i].profit + dp[lastCompatibleJob] : jobs[i].profit);
        }

        return dp[n - 1];
    }

private:
    short binarySearch(const vector<Job>& jobs, short index) {
        short low = 0;
        short high = index - 1;

        while (low <= high) {
            short mid = low + (high - low) / 2;

            if (jobs[mid].end <= jobs[index].start) {
                if (jobs[mid + 1].end <= jobs[index].start) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};