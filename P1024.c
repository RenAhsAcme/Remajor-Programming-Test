//
// Created by renahsacme on 2026/4/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double equation_check(int a, int b, int c, int d, double x, int is_answer) {
    if (is_answer) return fabs(a * x * x * x + b * x * x + c * x + d) < 1e-6;
    return a * x * x * x + b * x * x + c * x + d;
}

void dichotomous(int a, int b, int c, int d, double l, double r, double *result) {
    if (r - l < 1e-4) {
        *result = (l + r) / 2;
        return;
    }
    double mid = (double) (l + r) / 2;
    if (equation_check(a, b, c, d, l, 0) * equation_check(a, b, c, d, mid, 0) <= 0) {
        dichotomous(a, b, c, d, l, mid, result);
    } else {
        dichotomous(a, b, c, d, mid, r, result);
    }
}

// void dichotomous(int a, int b, int c, int d, double l, double r, double *result) {
//     while (r - l > 1e-4) {
//         double mid = (l + r) / 2;
//         double fl = equation_check(a,b,c,d,l,0);
//         double fm = equation_check(a,b,c,d,mid,0);
//
//         if (fl * fm <= 0)
//             r = mid;
//         else
//             l = mid;
//     }
//     *result = (l + r) / 2;
// }

int main() {
    char buffer[100000] = {}, *next = NULL, *endptr = NULL;
    int a = 0, b = 0, c = 0, d = 0;
    if (fgets(buffer, sizeof(buffer), stdin)) {
        next = buffer, a = (int) strtol(next, &endptr, 10);
        next = endptr, b = (int) strtol(next, &endptr, 10);
        next = endptr, c = (int) strtol(next, &endptr, 10);
        next = endptr, d = (int) strtol(next, &endptr, 10);
    }
    double result[3] = {};
    int j = 0;

    for (int i = -100; i < 100; i++) {
        double fi = equation_check(a,b,c,d,i,0);
        double fi1 = equation_check(a,b,c,d,i+1,0);
        if (fabs(fi) < 1e-6) {
            double x = i;
            if (j == 0 || fabs(result[j-1] - x) > 1e-3)
                result[j++] = x;
        }
        else if (fi * fi1 < 0) {
            double x;
            dichotomous(a,b,c,d,i,i+1,&x);
            if (j == 0 || fabs(result[j-1] - x) > 1e-3)
                result[j++] = x;
        }
        if (j == 3)
            break;
    }
    for (int i = 0; i < 3; i++)
        printf("%.2f ", result[i]);
    return 0;
}
