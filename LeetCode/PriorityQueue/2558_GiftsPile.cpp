class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long sum = 0;
        for (auto it : gifts) {
            pq.push(it);
        }
        int cnt = 0;
       //PQ maintain
        while (!pq.empty()) {
            auto big = pq.top();
            pq.pop();
            cnt++;
            long long sQrt = floor(sqrt(big));
            pq.push(sQrt);

            if (cnt == k) {
                break;
            }
        }
       //Sum
        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            sum += ele;
        }
        return sum;
    }
};


class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long sum = 0;
        for (auto it : gifts) {
            pq.push(it);
        }
        int cnt = 0;

        while (k--) {
            auto sQrt = sqrt(pq.top());

            pq.pop();
            cnt++;
            pq.push(sQrt);

        }

        while (!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            sum += ele;
        }
        return sum;
    }
};
