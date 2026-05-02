#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct surface {
    int x_node, y_node, x_length, y_length;
} static Surface[10000] = {};

struct node {
    int x_node, y_node;
} Target = {};

int surface_num = 0, node_num = 200000000, node_num_origin = 200000000;

void getInput(int n) {
    char buffer[256] = {}, *next = NULL, *endptr = NULL;
    switch (n) {
        case 1:
            if (fgets(buffer, sizeof(buffer), stdin)) {
                surface_num = (int) strtol(buffer, NULL, 10);
                strcpy(buffer, "");
            }
            break;
        case 2:
            for (int i = 0; i < surface_num; i++) {
                if (fgets(buffer, sizeof(buffer), stdin)) {
                    next = buffer, Surface[i].x_node = (int) strtol(next, &endptr, 10);
                    next = endptr, Surface[i].y_node = (int) strtol(next, &endptr, 10);
                    next = endptr, Surface[i].x_length = (int) strtol(next, &endptr, 10);
                    next = endptr, Surface[i].y_length = (int) strtol(next, &endptr, 10);
                    strcpy(buffer, "");
                }
            }
            break;
        case 3:
            if (fgets(buffer, sizeof(buffer), stdin)) {
                next = buffer, Target.x_node = (int) strtol(next, &endptr, 10);
                next = endptr, Target.y_node = (int) strtol(next, &endptr, 10);
                strcpy(buffer, "");
            }
        default:
            break;
    }
}

void queryRequest() {
    for (int i = surface_num - 1; i >= 0; i--) {
        if (Target.x_node >= Surface[i].x_node && Target.x_node <= Surface[i].x_node + Surface[i].x_length &&
            Target.y_node >= Surface[i].y_node && Target.y_node <= Surface[i].y_node + Surface[i].y_length) {
            printf("%d\n", i + 1);
            return;
        }
    }
    printf("-1");
}

int main() {
    for (int i = 1; i <= 3; i++)
        getInput(i);
    queryRequest();
    return 0;
}
