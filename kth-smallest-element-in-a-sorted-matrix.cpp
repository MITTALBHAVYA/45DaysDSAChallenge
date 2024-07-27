class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        bool check=false;
        int m=0;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(m<k)
                {
                    pq.push(matrix[i][j]);
                }
                
                m++;
                if(m>k)
                {
                    if(matrix[i][j]<pq.top())
                    {
                     pq.pop();
                       pq.push(matrix[i][j]);
                    }
                    
                    
                }
            }
          
        }
        return pq.top();
    }
};