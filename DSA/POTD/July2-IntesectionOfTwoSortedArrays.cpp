#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count; // to store count of nums1 elements
        for(int n : nums1) {
            count[n]++;
        }
        vector<int> ans;
        for(int n : nums2) {
            if(count[n] > 0) {
                ans.push_back(n);
                count[n]--;
            }
        }
        return ans;
    }
};

int main() {
    // Input vectors
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    // Create an instance of Solution
    Solution solution;
    
    // Call intersect method
    vector<int> result = solution.intersect(nums1, nums2);
    
    // Output the result
    cout << "Intersection of the two arrays is: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

        // Another Approach could be
        // vector <int> ans;
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        // int i=0;
        // int j=0;
        // while(i<nums1.size() and j<nums2.size()){
        //     if(nums1[i]==nums2[j]){
        //         ans.push_back(nums1[i]);
        //         i++;
        //         j++;
        //     }
        //     else if(nums1[i]<nums2[j]){
        //         i++;
        //     }
        //     else{
        //         j++;
        //     }
        // }
        // return ans;

        /*
        this is the 1st one I did
        unordered_map<int,int>arr;
        vector<int>ans;
        int i=0;int j=0;
        while(i<nums1.size() && j<nums2.size()){
            if( arr[i]==0  && nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                arr[i]=1;
            }
            i++;j++;
        }
        return ans;
        */
//     }
// };