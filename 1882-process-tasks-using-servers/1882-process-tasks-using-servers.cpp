class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // {weight, index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > available;

        // {freeTime, weight, index}
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > busy;

        int n = servers.size();

        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;

        for(int i = 0; i < tasks.size(); i++) {

            // Release servers that have finished
            while(!busy.empty() &&
                  get<0>(busy.top()) <= i) {

                auto [time, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            long long startTime = i;

            // No server available: wait
            if(available.empty()) {

                auto [freeTime, weight, index] = busy.top();
                busy.pop();

                startTime = freeTime;

                ans.push_back(index);

                busy.push({
                    startTime + tasks[i],
                    weight,
                    index
                });

            }
            else {

                auto [weight, index] = available.top();
                available.pop();

                ans.push_back(index);

                busy.push({
                    startTime + tasks[i],
                    weight,
                    index
                });
            }
        }

        return ans;
    }
};