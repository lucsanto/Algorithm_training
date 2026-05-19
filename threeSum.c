#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int x;
    int y;

    x = *(int *)a;
    y = *(int *)b;
    if (x < y)
        return (-1);
    if (x > y)
        return (1);
    return (0);
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int **result;
    int capacity;
    int i;
    int left;
    int right;
    int sum;

    *returnSize = 0;

    if (numsSize < 3)
    {
        *returnColumnSizes = NULL;
        return (NULL);
    }

    qsort(nums, numsSize, sizeof(int), compare);

    capacity = 16;
    result = malloc(sizeof(int *) * capacity);
    *returnColumnSizes = malloc(sizeof(int) * capacity);

    if (!result || !*returnColumnSizes)
        return (NULL);

    i = 0;
    while (i < numsSize - 2)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            i++;
            continue;
        }

        left = i + 1;
        right = numsSize - 1;

        while (left < right)
        {
            sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                if (*returnSize == capacity)
                {
                    capacity *= 2;
                    result = realloc(result, sizeof(int *) * capacity);
                    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * capacity);
                }

                result[*returnSize] = malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < 0)
                left++;
            else
                right--;
        }

        i++;
    }

    return (result);
}
