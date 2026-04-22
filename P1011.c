//
// Created by renahsacme on 2026/4/8.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct station {
        int e_com_up, e_com_down, a_com_up, a_com_down, a_com_current, e_com_current;
    };
    int a = 0, n = 0, m = 0, x = 0, e = 0;
    char buffer[14], *next = NULL, *endptr = NULL;
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer, a = (int) strtol(next, &endptr, 10);
        next = endptr, n = (int) strtol(next, &endptr, 10);
        next = endptr, m = (int) strtol(next, &endptr, 10);
        next = endptr, x = (int) strtol(next, &endptr, 10);
    }
    struct station Station[n + 1] = {};
    Station[1].a_com_up = 1, Station[1].a_com_current = 1;
    Station[2].e_com_up = 1, Station[2].e_com_down = 1, Station[2].a_com_current = 1;
    for (int i = 3; i <= n - 1; i++) {
        Station[i].a_com_up = Station[i - 2].a_com_up + Station[i - 1].a_com_up;
        Station[i].e_com_up = Station[i - 2].e_com_up + Station[i - 1].e_com_up;
        Station[i].a_com_down = Station[i - 1].a_com_up, Station[i].e_com_down = Station[i - 1].e_com_up;
        Station[i].a_com_current = Station[i - 1].a_com_current + Station[i].a_com_up - Station[i].a_com_down;
        Station[i].e_com_current = Station[i - 1].e_com_current + Station[i].e_com_up - Station[i].e_com_down;
    }
    if (Station[n - 1].e_com_current != 0)
        e = (m - a * Station[n - 1].a_com_current) / Station[n - 1].e_com_current;
    printf("%d", Station[x].a_com_current * a + Station[x].e_com_current * e);
    return 0;
}
