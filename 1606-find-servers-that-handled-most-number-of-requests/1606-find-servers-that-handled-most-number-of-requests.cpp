
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> av;

        for(int i = 0; i < k; i++) {
            av.insert(i);
        }

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> busy;

        vector<int> count(k, 0);

        for(int i = 0; i < arrival.size(); i++) {

            // Release completed servers
            while(!busy.empty() && busy.top().first <= arrival[i]) {
                av.insert(busy.top().second);
                busy.pop();
            }

            if(av.empty()) {
                continue;
            }

            int preferred = i % k;

            auto it = av.lower_bound(preferred);

            if(it == av.end())
                it = av.begin();

            int server = *it;

            av.erase(it);

            count[server]++;

            busy.push({arrival[i] + load[i], server});
        }

        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(count[i] == maxi)
                ans.push_back(i);
        }

        return ans;
    }
};
