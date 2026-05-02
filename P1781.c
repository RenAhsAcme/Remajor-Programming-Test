//
// Created by renahsacme on 2026/4/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct president {
    int No;
    char votes[200];
};

int cmp(struct president a, struct president b) {
    if (strlen(a.votes) != strlen(b.votes)) return strlen(a.votes) > strlen(b.votes);
    for (int i = 0; i < strlen(a.votes); i++) if (a.votes[i] != b.votes[i]) return a.votes[i] > b.votes[i];
    return 0;
}

void quick_sort(struct president a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    struct president pivot = a[(l + r) / 2];
    while (i <= j) {
        while (cmp(a[i], pivot)) i++;
        while (cmp(pivot, a[j])) j--;
        if (i <= j) {
            struct president tmp = a[i];
            a[i] = a[j], a[j] = tmp, i++, j--;
        }
    }
    quick_sort(a, l, j), quick_sort(a, i, r);
}

int main() {
    char buffer[1000] = {};
    int n = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) n = (int) strtol(buffer, NULL, 10);
    struct president *President = calloc(n, sizeof(struct president));
    for (int i = 0; i < n; i++) {
        if (fgets(buffer, sizeof(buffer), stdin)) {
            strcpy(President[i].votes, buffer);
            for (int j = 0; j < 200; j++)
                if (President[i].votes[j] == '\n') {
                    President[i].votes[j] = '\0';
                    break;
                }
        }
        President[i].No = i + 1;
    }
    quick_sort(President, 0, n - 1);
    printf("%d\n%s", President[0].No, President[0].votes);
    free(President);
    return 0;
}
