class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
       
        vector<int>ans(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                ans[c]=nums[i];
                c++;
            }
        }
        for(int i=0;i<n;i++){
            nums[i]=ans[i];
        }
        
    }
};
