#include <stdio.h>
#include <stdlib.h>
int longestSubarray(int arrSize, int *arr)
{
    int n = arrSize;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int w[2] = {0};
        int cnt = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == w[0] || arr[j] == w[1])
            {
                cnt++;
                continue;
            }
            if (w[0] == 0)
            {
                w[0] = arr[j];
            }
            else if (w[1] == 0)
            {
                if (abs(w[0] - arr[j]) > 1)
                {
                    break;
                }
                else
                {
                    w[1] = arr[j];
                }
            }
            else
            {
                break;
            }
            cnt++;
        }
        ans = ans > cnt ? ans : cnt;
    }
    return ans;
}

//! copy just the longestSubarray function to the online judge and not the main function
int main()
{
    int arrSize;
    scanf("%d", &arrSize);
    int *arr = malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans = longestSubarray(arrSize, arr);
    printf("%d\n", ans);
    return 0;
}