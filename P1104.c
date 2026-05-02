//
// Created by renahsacme on 2026/4/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[1000];
    int No, year, month, day;
};

// 进阶写法：多关键字约束下的排序 ===========================================================================================
int cmp(struct student a, struct student b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    if (a.day != b.day) return a.day < b.day;
    return a.No > b.No;
}

void quick_sort(struct student a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    struct student pivot = a[(l + r) / 2];
    while (i <= j) {
        while (cmp(a[i], pivot)) i++;
        while (cmp(pivot, a[j])) j--;
        if (i <= j) {
            struct student tmp = a[i];
            a[i] = a[j], a[j] = tmp, i++, j--;
        }
    }
    quick_sort(a, l, j), quick_sort(a, i, r);
}
// =====================================================================================================================

int main() {
    char buffer[2000] = {}, *next = NULL, *endptr = NULL;
    int stu_num = 0;
    if (fgets(buffer, sizeof(buffer), stdin))
        stu_num = (int) strtol(buffer, NULL, 10);
    struct student *Student = calloc(stu_num, sizeof(struct student));
    for (int i = 0; i < stu_num; i++)
        if (fgets(buffer, sizeof(buffer), stdin)) {
            char tmp[1000] = {};
            next = buffer, strcpy(tmp, buffer);
            int j = 0;
            for (j = 0; j < 1000; j++)
                if (tmp[j] == ' ') {
                    tmp[j] = '\0';
                    break;
                }
            strcpy(Student[i].name, tmp), next += j;
            Student[i].year = (int) strtol(next, &endptr, 10), next = endptr;
            Student[i].month = (int) strtol(next, &endptr, 10), next = endptr;
            Student[i].day = (int) strtol(next, &endptr, 10), Student[i].No = i;
        }
    quick_sort(Student, 0, stu_num - 1);
    for (int i = 0; i < stu_num; i++)
        printf("%s\n", Student[i].name);
    free(Student);
    return 0;
}
