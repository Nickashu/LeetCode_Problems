int searchInsert(int* nums, int numsSize, int target) {
    return binarySearch(nums, numsSize, 0, numsSize-1, target);
}

int binarySearch(int *nums, int numsSize, int begin, int end, int target){
    int guess = (begin + end) / 2;
    if(nums[guess] == target)
        return guess;
    if(end == begin){
        if(nums[end] > target)
            return end;
        return end+1;
    }

    if(nums[guess] > target)
        return binarySearch(nums, numsSize, begin, guess, target);
    else{
        guess++;
        return binarySearch(nums, numsSize, guess, end, target);
    }
}