#include <stdio.h>
#include <stdlib.h>
/*What is the maximum value of the integer at index k
in such an array?
For example, let's say n = 3, maxSum = 6, and k = 1.
So, the goal is to find the maximum value of the
element at index 1 in an array of 3 positive integers,
where the sum of elements is at most 6, and the
absolute difference between every two consecutive
elements is at most 1.
The maximum such value is 2, and it can be
achieved, for example, by the array [1, 2, 2]. This
array has 3 elements, each of them a positive
integer. The sum of the elements does not exceed 6,
and the absolute difference between any two
consecutive elements is at most 1. There is no other
such array that has a larger value at index k = 1.
Therefore, the answer is 2 because that is the
maximum value of the integer at index k.
*/

/*
int maxElement(int n, int maxSum, int k)
{
    int left = 1;
    int right = maxSum;
    int ans = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        // Check if there exists an array with middle element = mid
        int sum = mid;
        int cnt = 1;
        for (int i = k - 1; i >= 0; i--)
        {
            int x = mid - (k - i);
            if (x > 0)
            {
                sum += x;
                if (sum > maxSum)
                {
                    break;
                }
                cnt++;
            }
        }
        for (int i = k + 1; i < n; i++)
        {
            int x = mid - (i - k);
            if (x > 0)
            {
                sum += x;
                if (sum > maxSum)
                {
                    break;
                }
                cnt++;
            }
        }
        if (cnt == n)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}
*/
int maxElement(int n, int maxSum, int k)
{
    int left = 1;
    int right = maxSum;
    int ans = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        // Check if there exists an array with middle element = mid
        int sum = mid;
        int cnt = 1;
        for (int i = k - 1; i >= 0; i--)
        {
            int x = mid - (k - i);
            if (x > 0)
            {
                sum += x;
                if (sum > maxSum)
                {
                    break;
                }
                cnt++;
            }
        }
        for (int i = k + 1; i < n; i++)
        {
            int x = mid - (i - k);
            if (x > 0)
            {
                sum += x;
                if (sum > maxSum)
                {
                    break;
                }
                cnt++;
            }
        }
        if (cnt == n)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return ans;
}
// for input(4,6,2)
// the output should be 2
int maxElement2(int n, int maxSum, int k)
{
    int left = 1;
    int right = maxSum;
    int ans = -1; // Set initial answer to -1 instead of 0

    while (left <= right)
    {
        int mid = (left + right) / 2;
        // Check if there exists an array with middle element = mid
        int sum = mid;
        int cnt = 1;
        for (int i = k - 1; i >= 0; i--)
        {
            int x = mid - (k - i);
            if (x > 0)
            {
                sum += x;
                if (sum > maxSum)
                {
                    break;
                }
                cnt++;
            }
        }
        for (int i = k + 1; i < n; i++)
        {
            int x = mid - (i - k);
            if (x > 0)
            {
                sum += x;
                if (sum > maxSum)
                {
                    break;
                }
                cnt++;
            }
        }
        if (cnt == n)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (ans == -1)
    { // If no valid array exists, return 0
        return 0;
    }
    return ans;
}
int maxElement3(int n, int maxSum, int k)
{
    int left = 1;
    int right = maxSum;
    int ans = -1; // Set initial answer to -1 instead of 0

    while (left <= right)
    {
        int mid = (left + right) / 2;
        // Check if there exists an array with middle element = mid
        int sum = mid;
        int cnt = 1;
        for (int i = k - 1; i >= 0; i--)
        {
            int x = mid - (k - i);
            if (x > 0)
            {
                sum += x;
                if (sum > maxSum)
                {
                    break;
                }
                cnt++;
            }
        }
        for (int i = k + 1; i < n; i++)
        {
            int x = mid - (i - k);
            if (x > 0)
            {
                sum += x;
                if (sum > maxSum)
                {
                    break;
                }
                cnt++;
            }
        }
        if (cnt == n)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (ans == -1)
    { // If no valid array exists, return 0
        return 0;
    }
    return ans;
}

int main()
{
    int n, maxSum, k;
    scanf("%d %d %d", &n, &maxSum, &k);
    printf("%d", maxElement3(n, maxSum, k));
    return 0;
}