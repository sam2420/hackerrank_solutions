#include <stdio.h>
#include <stdlib.h>
int maxCost(int cost_count, int *cost, int label_count, char **labels, int dailyCount)
{
    int ans = 0;
    int cur_cnt = 0;
    int cur_cost = 0;
    for (int i = 0; i < cost_count; i++)
    {
        cur_cost += cost[i];
        if (labels[i][0] == 'i')
        {
            continue;
        }
        cur_cnt++;
        if (cur_cnt == dailyCount)
        {
            ans = ans > cur_cost ? ans : cur_cost;
            cur_cnt = 0;
            cur_cost = 0;
        }
    }
    return ans;
}
int main()
{
    int cost_count;
    scanf("%d", &cost_count);
    int *cost = malloc(cost_count * sizeof(int));
    for (int i = 0; i < cost_count; i++)
    {
        scanf("%d", &cost[i]);
    }
    int label_count;
    scanf("%d", &label_count);
    char **labels = malloc(label_count * sizeof(char *));
    for (int i = 0; i < label_count; i++)
    {
        labels[i] = malloc(10 * sizeof(char));
        scanf("%s", labels[i]);
    }
    int dailyCount;
    scanf("%d", &dailyCount);
    int ans = maxCost(cost_count, cost, label_count, labels, dailyCount);
    printf("%d\n", ans);
    return 0;
}