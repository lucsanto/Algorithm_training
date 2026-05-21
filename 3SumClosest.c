#include <stdlib.h>

static int compare_ints(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

static long long absolute_diff(long long a, long long b)
{
    if (a > b)
        return a - b;
    return b - a;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    int i;
    int left;
    int right;
    long long sum;
    long long closest;

    qsort(nums, numsSize, sizeof(int), compare_ints);

    closest = (long long)nums[0] + nums[1] + nums[2];

    i = 0;
    while (i < numsSize - 2)
    {
        left = i + 1;
        right = numsSize - 1;

        while (left < right)
        {
            sum = (long long)nums[i] + nums[left] + nums[right];

            if (absolute_diff(sum, target) < absolute_diff(closest, target))
                closest = sum;

            if (sum == target)
                return target;
            else if (sum < target)
                left++;
            else
                right--;
        }

        i++;
    }

    return (int)closest;
}
