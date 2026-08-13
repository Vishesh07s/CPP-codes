class Solution {
public:

    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;

        int i = l;
        int j = mid + 1;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= r) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }
    }

    int countPairs(vector<int>& arr, int l, int mid, int r) {
        int cnt = 0;
        int right = mid + 1;

        for (int i = l; i <= mid; i++) {
            while (right <= r && arr[i] > 2LL * arr[right]) {
                right++;
            }

            cnt += right - (mid + 1);
        }

        return cnt;
    }

    void mergeSort(vector<int>& arr, int l, int r, int& cnt) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid, cnt);
        mergeSort(arr, mid + 1, r, cnt);

        cnt += countPairs(arr, l, mid, r);

        merge(arr, l, mid, r);
    }

    int reversePairs(vector<int>& nums) {
        int cnt = 0;

        mergeSort(nums, 0, nums.size() - 1, cnt);

        return cnt;
    }
};