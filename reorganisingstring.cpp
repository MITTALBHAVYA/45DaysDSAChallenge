class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for(auto c: s)
        {
          mp[c]++;
        }

        priority_queue<pair <int, char>> pq;

        for(auto entry: mp)
        {
          pq.push({entry.second, entry.first});
        }

        string res = "";
        while(pq.size() > 1)
        {
            auto one = pq.top();
            pq.pop();
            auto two = pq.top();
            pq.pop();
            res += one.second;
            res += two.second;
            one.first -= 1;
            two.first -= 1;

            if(one.first > 0)
              pq.push(one);
            if(two.first > 0)
              pq.push(two);

        }
        if(!pq.empty())
        {
          if(pq.top().first > 1)
          {
            return "";
          }
          else
          {
            res += pq.top().second;
          }
          
        }


        return res;
    }
};