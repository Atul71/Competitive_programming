class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> m;
        vector <int> res;
        stack <int> s;
        int i;
        for(i=0;i<nums2.size();i++){
            m[nums2[i]] = -1;
            while(!s.empty() && nums2[i]>s.top()){
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        
        for(i=0;i<nums1.size();i++){
            res.push_back(m[nums1[i]]);
        }
        
        return res;
        
    }
};