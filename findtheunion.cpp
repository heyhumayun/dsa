class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {

    int p1 = 0;
    int p2 = 0;
    vector<int> ans;
    int last = INT_MIN;

    while(p1 < nums1.size() && p2 < nums2.size()){
        int value;
        if(nums1[p1] < nums2[p2]){
            value = nums1[p1];
            p1++;
        }
        else if(nums1[p1] > nums2[p2]){
            value = nums2[p2];
            p2++; 
        }
        else{
            value = nums2[p2]; 
            p1++;
            p2++;
        }

        if(last != value){
            ans.push_back(value);
            last = value;
        }
    }

    while(p1 < nums1.size()){
        if(last != nums1[p1]){
            ans.push_back(nums1[p1]);
            last = nums1[p1];
        }
    p1++;
    }
    while(p2 < nums2.size()){
        if(last != nums2[p2]){
            ans.push_back(nums2[p2]);
            last = nums2[p2];
        }
    p2++;
    }
    return ans;
    }
};
