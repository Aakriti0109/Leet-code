class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> freeServers;

        priority_queue<tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>> busyServers;

        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);

        for(int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        long long time = 0;

        for(int j = 0; j < m; j++) {

            time = max(time, (long long)j);

            // If no server is free, jump to the earliest
            // server availability time.
            if(freeServers.empty()) {
                time = max(time, get<0>(busyServers.top()));
            }

            // Release all servers that are free by current time.
            while(!busyServers.empty() &&
                  get<0>(busyServers.top()) <= time) {

                auto [available, weight, index] = busyServers.top();
                busyServers.pop();

                freeServers.push({weight, index});
            }

            // Choose the server with minimum weight,
            // then minimum index.
            auto [weight, index] = freeServers.top();
            freeServers.pop();

            ans[j] = index;

            // Server becomes free after processing this task.
            busyServers.push({
                time + tasks[j],
                weight,
                index
            });
        }

        return ans;
    }
};