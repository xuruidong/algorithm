#include <iostream>
#include <memory>
#include <windows.h>
#include <vector>
#include <random>
#include <algorithm>
#include <queue>

#include "utils.h"
#include "heap.h"
#include "merge_sort.h"

using namespace std;

struct demo{
    int a;
    int b;
};


int bubble_sort(std::vector<int> &nums)
{
    int first=0, second=0;
    int last = nums.size()-1;
    if(last <= 0){
        return 0;
    }
    while(last>0){
        first = 0;
        second = 1;
        for(first=0; first<last; ++first){
            second = first+1;
            if(nums[first]>nums[second]){
                std::swap(nums[first], nums[second]);
            }
        }
        --last;
    }
    return 0;
}

int select_sort(std::vector<int> &nums)
{
    int i = 0, tmp=0, tmp_i = 0;;
    int last = nums.size() -1;
    while(last>0){
        tmp_i = 0;
        tmp = nums[0];
        for(i=1; i<=last; ++i){
            if(nums[i] > tmp){
                tmp_i=i;
                tmp = nums[i];
            }
        }
        std::swap(nums[tmp_i], nums[last]);
        --last;
    }
    return 0;
}

int select_sort2(std::vector<int> &nums)
{
    if(nums.size() <=1){
        return 0;
    }
    for(int i=0; i<nums.size()-1; ++i){
        int tmp = nums[i];
        int index_min = i;
        for(int j=i+1;j<nums.size(); ++j){
            if(tmp > nums[j]){
                tmp = nums[j];
                index_min = j;
            }
        }
        std::swap(nums[i], nums[index_min]);
    }
    return 0;
}

int insert_sort(std::vector<int> &nums)
{
    if(nums.size() <= 1){
        return 0;
    }

    for(int i=1; i<nums.size(); ++i){
        if(nums[i]<nums[i-1]){
            int ind_tmp = i;
            while(ind_tmp>0){
                if(nums[ind_tmp]<nums[ind_tmp-1]){
                    std::swap(nums[ind_tmp], nums[ind_tmp-1]);
                }
                else{
                    break;
                }
                --ind_tmp;
            }
        }
    }
    return 0;
}

int priority_queue_test()
{
    std::priority_queue<int, vector<int>, greater<int>> a;
    std::priority_queue<int> b;

    for(int i=0; i<5; ++i){
        //a.push(i);
        b.push(i);
    }

    cout<<a.top()<<endl;
    while (!a.empty()){
        cout<<a.top()<<endl;
        a.pop();
        cout<<b.top()<<endl;
        b.pop();
        //cout<<a.pop()<<endl;
    }
    return 0;
}

/*
 给定一个数组arr，和一个数num，请把小于等于num的数放在数
组的左边，大于num的数放在数组的右边。
要求额外空间复杂度O(1)，时间复杂度O(N)
 */
 int testfunc(std::vector<int> &nums, int num)
 {
     int left=0, right = 0;
     if(nums.size() < 2){
        return 0;
     }
     left = 0;
     right = nums.size()-1;
     while(left<right){
        //left++;
        if(nums[left]>num){
            std::swap(nums[left], nums[right--]);
        }
        else{
            ++left;
        }
     }
     return 0;
 }

 /*
  给定一个数组arr，和一个数num，请把小于num的数放在数组的
左边，等于num的数放在数组的中间，大于num的数放在数组的
右边。
要求额外空间复杂度O(1)，时间复杂度O(N)
 */
int NetherlandsFlag(std::vector<int> &nums, int num)
{
    if(nums.size() < 2){
        return 0;
    }
    int left = -1;
    int mid = 0;
    int right = nums.size()-1;
    while(mid <= right){      // mid < right
        if(nums[mid] < num){
            std::swap(nums[mid++], nums[++left]);
        }
        else if(nums[mid] > num){
            std::swap(nums[mid], nums[right--]);
        }
        else{
            mid++;
        }
    }
    return 0;
}

int test(int a[]){
    std::cout<<sizeof(a)<<std::endl;
    return 0;
}

int main()
{
    srand(time(NULL));
    std::cout << "Hello world!" << endl;
    //priority_queue_test();

    int a[100];
    test(a);
    return 0;

#if 1
    std::vector<int> vtmp = {29,45,9,46,9,21,6,4,21,21,21};
    //heap_sort(vtmp, vtmp.size());
    //testfunc(vtmp, 44);
    NetherlandsFlag(vtmp, 21);
    vector_print(vtmp);
#else
    int test_num = 500000;

    while(test_num-- >0){
        std::vector<int> *nums = generateRandomArray(20, 150);
        std::vector<int> n1(*nums);
        std::vector<int> n2(*nums);

        std::sort(n1.begin(), n1.end());
        //bubble_sort(n2);
        //select_sort2(n2);
        //insert_sort(n2);
        //heap_sort(n2, n2.size());
        merge_sort(n2, 0, n2.size()-1);
        for(std::vector<int>::size_type i=0; i<n1.size(); ++i){
            if(n1[i] != n2[i]){
                vector_print(*nums);
                vector_print(n1);
                vector_print(n2);
                std::cout<<"========= "<<test_num<<std::endl;
                return -1;
                break;
            }
        }
        delete nums;
        //std::cout<<"-";
    }
#endif

    //Sleep(1000);

    return 0;
}


