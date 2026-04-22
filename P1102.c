//
// Created by renahsacme on 2026/4/13.
//
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    long long C;
    scanf("%d %lld", &N, &C);

    long long *a = (long long *)malloc(sizeof(long long) * N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }

    qsort(a, N, sizeof(long long), cmp);

    long long ans = 0;
    int l = 0, r = 0;

    while (r < N) {
        long long diff = a[r] - a[l];

        if (diff < C) {
            r++;
        } else if (diff > C) {
            l++;
        } else {
            // diff == C
            long long cnt_l = 1, cnt_r = 1;

            while (l + 1 < N && a[l] == a[l + 1]) {
                cnt_l++;
                l++;
            }

            while (r + 1 < N && a[r] == a[r + 1]) {
                cnt_r++;
                r++;
            }

            ans += cnt_l * cnt_r;

            l++;
            r++;
        }
    }

    printf("%lld\n", ans);
    free(a);
    return 0;
}