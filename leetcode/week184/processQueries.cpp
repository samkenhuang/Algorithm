#include "../util/stl.h"

using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> query;
        vector<int> target(m);
        for (int i = 0; i < m; i ++) target[i] = m - i;
        for (int i = 0; i < queries.size(); i ++) {
            vector<int>::iterator iter = target.begin();
            while (iter != target.end()) {
                if (*iter == queries[i]) {
                    query.push_back(target.end() - iter - 1);
                    int x = *iter;
                    target.erase(iter);
                    target.push_back(x);
                    break;
                }
                ++ iter;
            }
        }
        return query;
    }
};

int main() {
    Solution s;
    vector<int> v({3,1,2,1});
    s.processQueries(v, 5); // [2,1,2,1]
    cout << 1 << endl;
    return 0;
}