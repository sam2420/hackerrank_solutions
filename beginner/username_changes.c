#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **possibleChanges(int usernamesSize, char **usernames, int *returnSize)
{
    char **ans = (char **)malloc(sizeof(char *) * usernamesSize);
    *returnSize = 0;
    for (int i = 0; i < usernamesSize; i++)
    {
        if (strlen(usernames[i]) <= 1)
        {
            ans[*returnSize] = "NO";
            (*returnSize)++;
            continue;
        }
        for (int j = 0; j < strlen(usernames[i]) - 1; j++)
        {
            if (usernames[i][j] > usernames[i][j + 1])
            {
                ans[*returnSize] = "YES";
                (*returnSize)++;
                break;
            }
            if (j == strlen(usernames[i]) - 2)
            {
                ans[*returnSize] = "NO";
                (*returnSize)++;
            }
        }
    }
    return ans;
}
//! copy just the possibleChanges function to the online judge and not the main function
int main()
{
    int n;
    scanf("%d", &n);
    char **usernames = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        usernames[i] = (char *)malloc(sizeof(char) * 100);
        scanf("%s", usernames[i]);
    }
    int returnSize;
    char **ans = possibleChanges(n, usernames, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", ans[i]);
    }
    return 0;
}