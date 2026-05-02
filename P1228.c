//
// Created by renahsacme on 2026/4/11.
//
#include <stdio.h>
#include <stdlib.h>

void dp(int x, int y, int unit, int px, int py) {
    if (unit == 1) return;
    int half = unit / 2, cx = x + half, cy = y + half;
    if (px < cx && py < cy) {
        printf("%d %d 1\n", cx, cy);
        dp(x, y, half, px, py), dp(x, cy, half, cx - 1, cy);
        dp(cx, y, half, cx, cy - 1), dp(cx, cy, half, cx, cy);
    } else if (px < cx && py >= cy) {
        printf("%d %d 2\n", cx, cy - 1);
        dp(x, y, half, cx - 1, cy - 1), dp(x, cy, half, px, py);
        dp(cx, y, half, cx, cy - 1), dp(cx, cy, half, cx, cy);
    } else if (px >= cx && py < cy) {
        printf("%d %d 3\n", cx - 1, cy);
        dp(x, y, half, cx - 1, cy - 1), dp(x, cy, half, cx - 1, cy);
        dp(cx, y, half, px, py), dp(cx, cy, half, cx, cy);
    } else {
        printf("%d %d 4\n", cx - 1, cy - 1);
        dp(x, y, half, cx - 1, cy - 1), dp(x, cy, half, cx - 1, cy);
        dp(cx, y, half, cx, cy - 1), dp(cx, cy, half, px, py);
    }
}

int main() {
    char buffer[1000] = {}, *next = NULL, *endptr = NULL;
    int k = 0, princess_x = 0, princess_y = 0, unit = 1;
    if (fgets(buffer, sizeof(buffer), stdin)) k = (int) strtol(buffer, NULL, 10);
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer, princess_x = (int) strtol(next, &endptr, 10);
        next = endptr, princess_y = (int) strtol(next, NULL, 10);
    }
    for (int i = 0; i < k; i++) unit *= 2;
    dp(1, 1, unit, princess_x, princess_y);
    return 0;
}
