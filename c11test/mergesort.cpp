#include <vector>

int merge_sort(std::vector<int> &nums, int left, int right)
{
    if(right-left < 1){
        return 0;
    }
    int mid = left + (right-left)>>1;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid+1, right);

    int p1 = left;
    int p2 = mid+1;
    std::vector<int> tmp;

    int i=0;
    for(i=0; i<(right-left+1); ++i){
        if(nums[p1] <= nums[p2]){
            tmp[i] = nums[p1++];
        }
        else{
            tmp[i] = nums[p2++];
        }
        if(p1 > mid || p2 > right){
            break;
        }
    }
    while(p1<= mid){
        tmp[i++] = nums[p1++];
    }
    while(p2<= right){
        tmp[i++] = nums[p2++];
    }
    for(int i=left; i<=right; ++i){
        nums[i] = tmp[i-left];
    }
    return 0;
}

