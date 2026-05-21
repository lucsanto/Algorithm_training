#include <stdlib.h>
#include <string.h>

static const char *get_letters(char digit)
{
    if (digit == '2')
        return "abc";
    if (digit == '3')
        return "def";
    if (digit == '4')
        return "ghi";
    if (digit == '5')
        return "jkl";
    if (digit == '6')
        return "mno";
    if (digit == '7')
        return "pqrs";
    if (digit == '8')
        return "tuv";
    if (digit == '9')
        return "wxyz";
    return "";
}

static char *copy_combination(char *current, int len)
{
    char *copy;
    int i;

    copy = malloc(sizeof(char) * (len + 1));
    if (!copy)
        return NULL;

    i = 0;
    while (i < len)
    {
        copy[i] = current[i];
        i++;
    }
    copy[i] = '\0';

    return copy;
}

static void backtrack(
    char *digits,
    int index,
    int len,
    char *current,
    char **result,
    int *result_index
)
{
    const char *letters;
    int i;

    if (index == len)
    {
        result[*result_index] = copy_combination(current, len);
        (*result_index)++;
        return;
    }

    letters = get_letters(digits[index]);

    i = 0;
    while (letters[i])
    {
        current[index] = letters[i];
        backtrack(digits, index + 1, len, current, result, result_index);
        i++;
    }
}

char** letterCombinations(char* digits, int* returnSize)
{
    int len;
    int total;
    int i;
    char **result;
    char *current;
    int result_index;

    len = strlen(digits);

    if (len == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    total = 1;
    i = 0;
    while (i < len)
    {
        total *= strlen(get_letters(digits[i]));
        i++;
    }

    result = malloc(sizeof(char *) * total);
    if (!result)
    {
        *returnSize = 0;
        return NULL;
    }

    current = malloc(sizeof(char) * (len + 1));
    if (!current)
    {
        free(result);
        *returnSize = 0;
        return NULL;
    }

    current[len] = '\0';
    result_index = 0;

    backtrack(digits, 0, len, current, result, &result_index);

    free(current);

    *returnSize = result_index;
    return result;
}
