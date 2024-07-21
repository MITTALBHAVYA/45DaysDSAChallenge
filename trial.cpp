class Solution {
public:
    long long call=0;
    bool solve(vector<bool>&path,long long lastjump,long long index){
        cout<<++call<<endl;
        if(index==path.size()-1){
            return true;
        }
        if(index>=path.size() || index<0 ||path[index]!=true || lastjump<=0){
            return false;
        }
        bool a=false,b=false,c=false;
        a = solve(path,lastjump-1,index+(lastjump-1));
        b = solve(path,lastjump,index+lastjump);
        c = solve(path,lastjump+1,index+(lastjump+1));
        return a||b||c;
    }
    bool canCross(vector<int>& stones) {
        long long n = stones.size();
        long long last = stones[n-1];
        vector<bool>path(last+1,false);
        for(auto stone : stones){
            path[stone]=true;
        }
        return solve(path,1,1);
    }
};