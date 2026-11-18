class Solution {
public:
    int kthElement(const vector<int>& nums1,
                   const vector<int>& nums2, int k) {

        int n = nums1.size();
        int m = nums2.size();

        int i = 0, j = 0;

        while (k > 0) {

            // If nums1 is exhausted
            if (i >= n) {
                return nums2[j + k - 1];
            }

            // If nums2 is exhausted
            if (j >= m) {
                return nums1[i + k - 1];
            }

            // Find the smallest remaining element
            if (k == 1) {
                return min(nums1[i], nums2[j]);
            }

            int half = k / 2;

            // Calculate the indices safely
            int idx1 = min(i + half - 1, n - 1);
            int idx2 = min(j + half - 1, m - 1);

            // Eliminate the smaller prefix
            if (nums1[idx1] <= nums2[idx2]) {

                int removed = idx1 - i + 1;

                i = idx1 + 1;
                k -= removed;

            } else {

                int removed = idx2 - j + 1;

                j = idx2 + 1;
                k -= removed;
            }
        }

        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        int total = n + m;

        if (total % 2 == 1) {

            return kthElement(nums1, nums2, total / 2 + 1);

        } else {

            int left = kthElement(nums1, nums2, total / 2);
            int right = kthElement(nums1, nums2, total / 2 + 1);

            return (static_cast<double>(left) + right) / 2.0;
        }
    }
};
