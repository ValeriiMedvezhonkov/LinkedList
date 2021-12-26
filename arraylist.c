#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "arraylist.h"

struct list* create_list(){
    struct list* lst = (struct list*)malloc(sizeof(struct list));
    if(!lst){
        return NULL;
    }
    lst->element=NULL;
    lst->size=0;
    return lst;
}

struct element* create_element(char* text){
    struct element* element = (struct element*)malloc(sizeof(struct element));
    if (!element) {
        return NULL;
    }
    element->text=text ;
    element->next=NULL;
    return element;
}

struct element* append_begin(struct list* list, struct element* element){
    element->next = list->element;
    list->element = element;
    list->size++;
    return element;
}



struct element* append(struct list* list, struct element* element){
    struct element* current = NULL;

    if(list->element==NULL){
        list->element = element;
    }
    else{
        current = list->element;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = element;
    }

    list->size++;
    return element;
}



void insert(struct list* list, int index, struct element* element){
    struct element* curent = NULL;
    if(index==0){
        append_begin(list,element);
        return;
    }

    curent = list->element;
    while(index-1 > 0 && curent->next!=NULL){
        curent = curent->next;
        index--;
    }
    if(curent->next){
        element->next = curent->next;
    } else {
        element->next = NULL;
    }
    curent->next = element;

    list->size++;
}

struct element* get(struct list* list, int index){
    struct element* curent = NULL;
    if(index>list->size) return NULL;
    curent = list->element;
    while(index>0 && curent->next!=NULL){
        curent = curent->next;
        index--;
    }

    return curent;
}

int get_index_of(struct list* list, const char* text){
    struct element* curent = NULL;
    curent = list->element;
    if(list->element == NULL){
        return -1;
    }
    int i=0;
    while(curent->next != NULL){
        if(strcmp(curent->text,text) == 0){
            return i;
        }
        i++;
        curent = curent->next;
    }
    if(curent->next==NULL){
        return -1;
    }
    return 0;
}

int size(struct list* list){
    return list->size;
}

bool is_empty(struct list* list){
    if(list->element == NULL){
        return true;
    }
    else return false;
}

struct element* remove_at(struct list* list, int index){
    struct element* curent = NULL;
    curent = list->element;
    if(list->element == NULL) return NULL;
    if(index<0 || index > list->size) return NULL;
    if(index==0){
        list->element = curent->next;
    }
    if(index>list->size) return NULL;
    while(index>1 && curent->next!=NULL){
        curent = curent->next;
        index--;
    }
    if(curent==NULL || curent->next==NULL) return NULL;
    struct element* next = curent->next->next;
    free(curent->next);
    curent->next = next;
    list->size--;
    return curent;
}


struct element* remove_element(struct list* list, char* text){
    struct element* curent = NULL;
    curent = list->element;
    int lol = get_index_of(list,text);
    if(lol==-1) return NULL;

    while(lol>1 && curent->next!=NULL){
        curent = curent->next;
        lol--;
    }
    if(curent==NULL || curent->next==NULL) return NULL;
    struct element* next = curent->next->next;
    free(curent->next);
    curent->next=next;
    list->size--;
    return curent;
}


void free_list(struct list* list){
    struct element* curent = list->element;
    struct element* next = curent;
    while(curent->next!=NULL){
        next = curent->next;
        free(curent);
        curent = next;
    }
    free(list);
}

void free_element(struct element* element){
    if(element){
        if(element->text){
            free(element->text);
        }
        free(element);
    }
}

void print_get(struct element* element,int index){
    if(element->next != NULL){
        printf("INDEX: %d GET: %s '<->' %s\n",index, element->text, element->next->text);
    }
    else if(element->next == NULL){
        printf("GET: %s '<->' 'NULL' \n",element->text);
    }

}

void reverse(struct list* list)
{
    struct element* prev = NULL;
    struct element* current = list->element;
    struct element* next = NULL;
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->element = prev;
}

void linked_list_print(struct list* list)
{
    struct element* n = list->element;
    if(list->element==NULL){
        printf("List is Empty!\n");
        sleep(2);
        return;
    }

    printf("Size: %d\n[", list->size);

    while (1) {
        printf("'%s'", n->text);
        if (n->next == NULL) break;
        else printf(" <-> ");
        n = n->next;
    }

    printf("]\n");
}



struct list* cutAndSwap(struct list* list,int position){
    struct element* create_ellement = NULL;
    struct element* n = list->element;
    struct element* nn = list->element;
    struct list* newlist1 = create_list();
    int fullSize = size(list);

    int i=0;

    while(i<position){
        n=n->next;
        i++;
    }
    while(i<fullSize){
        char* lol=n->text;
        create_ellement = create_element(lol);
        append(newlist1,create_ellement);
        n=n->next;
        i++;
    }
    int k =0;
    while (k < position) {
        char* lol = nn->text;
        create_ellement = create_element(lol);
        append(newlist1,create_ellement);
        nn = nn->next;
        k++;
    }
    return newlist1;
}
