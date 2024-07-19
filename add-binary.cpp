/*
https://leetcode.com/problems/add-binary/solutions/5503186/easy-solution-detailed-solution/
*/
class Solution {
public:
    string addBinary(string a, string b) {
        if(b.size()>a.size()){
            swap(a,b);
        }
        while(a.size()>b.size()){b="0"+b;}
        int carry=0;
        string ans="";
        for(int i = b.size()-1;i>=0;i--){
            if(a[i]=='0' && b[i]=='0'){
                if(carry){
                    ans="1"+ans;
                    carry=0;
                }
                else{
                    ans="0"+ans;
                }
            }
            else if((a[i]=='0' && b[i]=='1')||(a[i]=='1' && b[i]=='0')){
                if(carry){
                    ans="0"+ans;
                }
                else{
                    ans="1"+ans;
                }
            }
            else{
                if(carry){
                    ans="1"+ans;
                }
                else{
                    ans="0"+ans;
                    carry=1;
                }
            }
        }
        if(carry){
            ans="1"+ans;
        }
        return ans;
    }
};