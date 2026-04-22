//
// Created by renahsacme on 2026/4/15.
//
#include <stdio.h>
#include <stdlib.h>

struct item {
    int v, p, q;
};

int main() {
    char buffer[1000] = {}, *next = NULL, *endptr = NULL;
    int n = 0, m = 0;
    int main_v[65] = {0}, main_w[65] = {0};
    int att_v[65][2] = {0}, att_w[65][2] = {0};
    int att_cnt[65] = {0};

    int dp[32010] = {0};
    if (fgets(buffer, sizeof(buffer), stdin))
        n = (int) strtol(buffer, &endptr, 10), next = endptr, m = (int) strtol(next, NULL, 10);
    struct item *Item = calloc(m, sizeof(struct item));
    for (int i = 0; i < m; i++)
        if (fgets(buffer, sizeof(buffer), stdin)) {
            Item[i].v = (int) strtol(buffer, &endptr, 10), next = endptr;
            Item[i].p = (int) strtol(next, &endptr, 10), next = endptr;
            Item[i].q = (int) strtol(next, NULL, 10);
        }
    for (int i = 0; i < m; i++) {
        if (Item[i].q == 0) {
            // 主件
            main_v[i + 1] = Item[i].v;
            main_w[i + 1] = Item[i].v * Item[i].p;
        } else {
            // 附件
            int k = Item[i].q; // 它属于哪个主件
            int idx = att_cnt[k]++;

            att_v[k][idx] = Item[i].v;
            att_w[k][idx] = Item[i].v * Item[i].p;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (main_v[i] == 0) continue; // 不是主件，跳过

        for (int j = n; j >= 0; j--) {

            // 1. 只选主件
            if (j >= main_v[i])
                if (dp[j] < dp[j - main_v[i]] + main_w[i])
                    dp[j] = dp[j - main_v[i]] + main_w[i];

            // 2. 主件 + 附件1
            if (att_cnt[i] >= 1 && j >= main_v[i] + att_v[i][0])
                if (dp[j] < dp[j - main_v[i] - att_v[i][0]] + main_w[i] + att_w[i][0])
                    dp[j] = dp[j - main_v[i] - att_v[i][0]] + main_w[i] + att_w[i][0];

            // 3. 主件 + 附件2
            if (att_cnt[i] >= 2 && j >= main_v[i] + att_v[i][1])
                if (dp[j] < dp[j - main_v[i] - att_v[i][1]] + main_w[i] + att_w[i][1])
                    dp[j] = dp[j - main_v[i] - att_v[i][1]] + main_w[i] + att_w[i][1];

            // 4. 主件 + 两个附件
            if (att_cnt[i] >= 2 && j >= main_v[i] + att_v[i][0] + att_v[i][1])
                if (dp[j] < dp[j - main_v[i] - att_v[i][0] - att_v[i][1]] + main_w[i] + att_w[i][0] + att_w[i][1])
                    dp[j] = dp[j - main_v[i] - att_v[i][0] - att_v[i][1]] + main_w[i] + att_w[i][0] + att_w[i][1];
        }
    }
    printf("%d\n", dp[n]), free(Item);
    return 0;
}