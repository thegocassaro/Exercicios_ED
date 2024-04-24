#include <stdio.h>
#include "deque.h"

int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char command[15];
        int data;

        scanf(" %s", command);

        if(!strcmp(command, "PUSH_FRONT")){
            scanf(" %d", &data);
            
        }

        else if(!strcmp(command, "PUSH_BACK")){
            scanf(" %d", &data);

        }

        else if(!strcmp(command, "POP_FRONT")){
            
        }

        else if(!strcmp(command, "POP_BACK")){
            
        }
    }


    return 0;
}