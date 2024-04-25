#include <stdio.h>
#include <string.h>
#include "deque.h"

int main()
{
    int n;
    Deque* f = deque_construct();

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char command[15];
        int data;

        scanf(" %s", command);

        if(!strcmp(command, "PUSH_FRONT")){
            scanf(" %d", &data);
            deque_push_front(f, data);
        }

        else if(!strcmp(command, "PUSH_BACK")){
            scanf(" %d", &data);
            deque_push_back(f, data);
        }

        else if(!strcmp(command, "POP_FRONT")){
            printf("%d\n", deque_pop_front(f));
        }

        else if(!strcmp(command, "POP_BACK")){
            printf("%d\n", deque_pop_back(f));
        }
    }

    deque_destroy(f);

    return 0;
}