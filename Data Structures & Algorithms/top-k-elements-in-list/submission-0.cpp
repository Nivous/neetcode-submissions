class Solution {
public:
    struct mapComp {
        bool operator() (const pair<int, int>& l, const pair<int, int>& r) const {
            if (l.second == r.second)
                return l.first < r.first;
            return l.second > r.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> occurnces;
        set<pair<int,int>, mapComp> occurnces_sorted;

        for (int num : nums) {
            int count = 0;
            if (occurnces.find(num) != occurnces.end()) {
                count = occurnces.at(num);
            }
            if (count != 0) {
                pair<int,int> p = {num, count};
                occurnces_sorted.erase(occurnces_sorted.find(p));
            }
            
            occurnces[num] = count+1;
            occurnces_sorted.insert(make_pair(num, count+1));

        }

        vector<int> res;
        set<pair<int,int>, mapComp>::iterator it = occurnces_sorted.begin();
        while(k>0) {
            //cout << it->first;
            res.push_back(it->first);
            it++;
            k--;
        }

        return res;

    }

    
};
