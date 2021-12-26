#include <string.h>
#include "arraylist.h"
#include <stdio.h>
int main(){
    struct list* list = create_list();

    struct element* create_ellement = NULL;

    create_ellement = create_element("1");
    append(list, create_ellement);

    create_ellement = create_element("10");
    append(list, create_ellement);

    create_ellement = create_element("7");
    append(list, create_ellement);

    create_ellement = create_element("6");
    append(list, create_ellement);

    create_ellement = create_element("12");
    append(list, create_ellement);

    create_ellement = create_element("8");
    append(list, create_ellement);

    create_ellement = create_element("5");
    append(list, create_ellement);

    create_ellement = create_element("4");
    append(list, create_ellement);

    linked_list_print(list);

    int position;
    printf("Enter position: ");
    scanf("%d",&position);
    if(position>=size(list) || position <= 0){
        printf("VIAC");
        return 0;
    }

    list = cutAndSwap(list,position);

    linked_list_print(list);
    reverse(list);
    linked_list_print(list);

    return 0;
}
