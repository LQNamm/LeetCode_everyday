/**
 * Problem 1. Two Sum
 *
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * Author: Lê Quốc Nam
 * Date: 2025-05-24
 */
 
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 0;
    for(int i = 0; i < numsSize; i++){
        int findnum = target - nums[i];
        for(int j = i + 1; j < numsSize; j++){
            if(findnum == nums[j]){
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return result;
}