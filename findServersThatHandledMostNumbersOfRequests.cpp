class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> available;

        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finish time, server ID}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> busy;

        vector<int> count(k, 0);

        for(int i = 0; i < arrival.size(); i++) {

            // Release servers whose requests are completed
            while(!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            // If all servers are busy
            if(available.empty()) {
                continue;
            }

            // Find the first available server >= i % k
            int server = i % k;

            auto it = available.lower_bound(server);

            // Wrap around if necessary
            if(it == available.end()) {
                it = available.begin();
            }

            server = *it;

            // Assign request
            available.erase(it);

            count[server]++;

            // Add server to busy heap
            busy.push({arrival[i] + load[i], server});
        }

        // Find maximum requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};