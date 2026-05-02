//
// Created by renahsacme on 2026/4/10.
//
#include <stdio.h>
#include <stdlib.h>

struct student {
    int No, Chinese, Math, English, summary;
};

void quick_sort(struct student a[], int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    int pivot = a[(l + r) / 2].summary;
    while (i <= j) {
        while (a[i].summary > pivot) i++;
        while (a[j].summary < pivot) j--;
        if (i <= j) {
            struct student tmp = a[i];
            a[i] = a[j], a[j] = tmp, i++, j--;
        }
    }
    quick_sort(a, l, j), quick_sort(a, i, r);
}

int main() {
    char buffer[1000] = {}, *next = NULL, *endptr = NULL;
    int stu_num = 0;
    if (fgets(buffer, sizeof(buffer), stdin))
        stu_num = (int) strtol(buffer, NULL, 10);
    struct student *Student = calloc(stu_num, sizeof(struct student));
    for (int i = 0; i < stu_num; i++) {
        if (fgets(buffer, sizeof(buffer), stdin)) {
            next = buffer, Student[i].Chinese = (int) strtol(next, &endptr, 10);
            next = endptr, Student[i].Math = (int) strtol(next, &endptr, 10);
            next = endptr, Student[i].English = (int) strtol(next, &endptr, 10);
        }
        Student[i].No = i + 1, Student[i].summary = Student[i].Chinese + Student[i].Math + Student[i].English;
    }
    quick_sort(Student, 0, stu_num - 1);
    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < stu_num; j++)
            if (Student[i].summary == Student[j].summary) {
                if (Student[i].Chinese < Student[j].Chinese) {
                    struct student tmp = Student[j];
                    Student[j] = Student[i], Student[i] = tmp;
                }
                if (Student[i].Chinese == Student[j].Chinese)
                    if (Student[i].No > Student[j].No) {
                        struct student tmp = Student[j];
                        Student[j] = Student[i], Student[i] = tmp;
                    }
            }
    for (int i = 0; i < 5; i++)
        printf("%d %d\n", Student[i].No, Student[i].summary);
    free(Student);
    return 0;
}
