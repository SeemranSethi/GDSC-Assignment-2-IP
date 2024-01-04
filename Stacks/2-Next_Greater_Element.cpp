class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ump;
        int val=-1;
        for(int i=0;i<nums2.size();i++)
        {
            for(int j=i+1;j<nums2.size();j++)
            {
                if(nums2[j]>nums2[i])
                {
                    val=nums2[j];
                    break;
                }
            }
            ump[nums2[i]]=val;
            val=-1;
        }

        vector<int> ans(nums1.size());
        for(int k=0;k<nums1.size();k++)
        {
            ans[k]=ump[nums1[k]];
        }

        return ans;
    }
};
