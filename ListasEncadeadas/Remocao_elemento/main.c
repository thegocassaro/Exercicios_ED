
#include <stdio.h>

#include "forward_list.h"

void print_int(int data)
{
    printf("%d", data);
}

int main()
{
    int n=0, m=0, read=0;

    scanf(" %d", &n);
    
    ForwardList* l = forward_list_construct();

    for(int i=0; i<n; i++){
        
        scanf(" %d", &read);
        forward_list_push_front(l, read);
    }

    scanf(" %d", &m);

    for(int i=0; i<m; i++){
        
        scanf(" %d", &read);
        forward_list_remove(l, read);
    }

    forward_list_print(l, print_int);

    forward_list_destroy(l);

    return 0;
}