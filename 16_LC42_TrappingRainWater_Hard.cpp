class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        if (height.size() < 3) {
            return total;
        }
        for (int i = 0; i < height.size()-1; i ++) {
            int pos = 0;
            bool flag = false; 
            int minus = 0;
            if (height[i] > height[i+1]) {
                int max = height[i+1];
                for (int x = i+1; x < height.size(); x ++) {
                    if (height[x] >= height[i]) { //For when there is a barrior larger than i
                        for (int y = i+1; y < x; y++) {
                            minus += height[y];
                        }
                        total += (((x-i-1) * height[i]) - minus);
                        i = x;
                        i--;
                        flag = true;
                        break;
                    }
                    if (height[x] >= max) { //Find max, keep latest largest max
                        pos = x;
                        max = height[x];
                    }
                }
                // If not found what is larger then use the largest to compute
                if (flag == false && pos != 0) {
                    for (int y = i+1; y < pos; y++) {
                        minus += height[y];
                    }
                    total += (((pos - i - 1) * height[pos]) - minus);
                    i = pos;
                    i--;
                }
            }
        }
        return total;
    }
};
