#include <stdio.h>
#include <stdlib.h>

// Count how many times 'num' appears in nums[lo...hi]
int countInRange(int* nums, int num, int lo, int hi) {
    int count = 0;
    for (int i = lo; i <= hi; i++) {
        if (nums[i] == num)
            count++;
    }
    return count;
}

// Divide and conquer majority element finder
int majorityElementRec(int* nums, int lo, int hi) {
    if (lo == hi) {
        return nums[lo];
    }

    int mid = lo + (hi - lo) / 2;
    int left = majorityElementRec(nums, lo, mid);
    int right = majorityElementRec(nums, mid + 1, hi);

    if (left == right) {
        return left;
    }

    int leftCount = countInRange(nums, left, lo, hi);
    int rightCount = countInRange(nums, right, lo, hi);

    return leftCount > rightCount ? left : right;
}

int majorityElement(int* nums, int numsSize) {
    return majorityElementRec(nums, 0, numsSize - 1);
}

int main() {
    char ch;
    int nums[100005], n = 0;

    // Skip until '['
    while ((ch = getchar()) != '[' && ch != EOF);

    // Read integers from input like: nums = [3, 2, 3]
    int num = 0, sign = 1;
    while ((ch = getchar()) != ']' && ch != EOF) {
        if (ch == '-') {
            sign = -1;
        } else if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
        } else if (ch == ',' || ch == ' ') {
            if (num != 0 || sign == -1) {
                nums[n++] = num * sign;
                num = 0;
                sign = 1;
            }
        }
    }
    // Add the last number
    if (num != 0 || sign == -1) {
        nums[n++] = num * sign;
    }

    int result = majorityElement(nums, n);
    printf("%d\n", result);
    return 0;
}