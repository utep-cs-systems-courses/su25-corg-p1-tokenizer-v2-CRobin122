#ifndef _HISTORY_
#define _HISTORY_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *list = (List *)malloc(sizeof(List));
  if (list == NULL){
    return NULL;
  }

  list->root = NULL;
  return list;
}
/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  if (list == NULL || str == NULL){
    return;
  }

  Item *new_item = (Item *)malloc(sizeof(Item));
  if (new_item == NULL){
    return;
  }
  strcpy(new_item->str, str);

  new_item->next = NULL;

  //If list is empty, this is the first item
  if (list->root == NULL){
    new_item->id = 1;
    list->root = new_item;
    return;
  }

  //Find the last item and get next ID
  Item *current = list->root;
  while (current-> next != NULL){
    current = current->next;
  }

  //set ID to be one more than the last item
  new_item->id = current->id;

  //add new item to end of list
  current->next = new_item;
  
}
/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  if (list == NULL || list->root == NULL){
    return NULL;
  }

  Item *current = list->root;

  //Search for item with matching ID
  while (current != NULL){
    if (current->id == id){
      return current->str;
    }
    current = current->next;
  }
  //ID not found
  return NULL;
  
}

/*Print the entire contents of the list. */
void print_history(List *list){
  if (list == NULL || root == NULL){
    printf("History is empty.\n");
    return;
  }

  Item *current = list->root;

  printf("History:\n");
  while (current != NULL){
    printf("%d: %s\n", current->id, current->str);
    current = current->next;
  }
  
}
/*Free the history list and the strings it references. */
void free_history(List *list){
  if (list == NULL){
    return;
  }

  Item *current = list->root;
  Item *next;

  while (current != NULL){
    next = current->next;

    if (current->str != NULL){
      free(current->str);
    }

    free(current);

    current = next;
  }

  free(list);
}

#endif
