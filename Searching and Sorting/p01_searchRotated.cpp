class Solution {
public:
    int search(vector<int>& nums, int k) {
        int n = nums.size();
        int c=n;
        if (nums[0] > nums[n - 1])
        {
            int l = 0, r = n - 1;
            while (true)
            {
                if (r - l <= 1 && nums[r] <= nums[l])
                {
                    c = r;
                    break;
                }
                int m = (l+r)/2;
                if (nums[m] > nums[r])
                    l = m;
                else if (nums[m] < nums[l])
                    r = m;
            }
        }
        int x = -1;
        int l=0,r=c-1;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]>k)
            r = m-1;
            else if(nums[m]<k)
            l = m+1;
            else{
                x = m;
                break;
            }
        }
        l=c;
        r=n-1;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]>k)
            r = m-1;
            else if(nums[m]<k)
            l = m+1;
            else{
                x = m;
                break;
            }
        }
        return x;
    }
};