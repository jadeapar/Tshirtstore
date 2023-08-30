// Jadea Parchment this program will find tshirts for student organizations at USF
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tshirt.h"
void help() {
    printf("List of operation codes:\n");
    printf("\t'a' for adding a t-shirt to the inventory;\n");
    printf("\t'h' for help;\n");
    printf("\t'o' for searching t-shirts by organization;\n");
    printf("\t's' for searching t-shirts by size;\n");
    printf("\t'p' for printing the inventory;\n");
    printf("\t'q' for quit.\n");
}

struct tshirt * add_to_inventory(struct tshirt *inventory) {
    struct tshirt *g= NULL, *now = inventory, *replace;

    g = malloc(sizeof(struct tshirt));
    if (g == NULL) {
    printf("Memory can not be allocated.");
    return inventory;
    }

    printf("Enter the organization's name: ");
    read_line(g->org_name, ORG_NAME_LEN);
    printf("Enter your tshirt size ");
    read_line(g->size, SIZE_LEN);
    printf("Enter the tshirt price: ");
    scanf("%lf", &g->price);
    printf("Enter the tshirt quantity: ");
    scanf("%d", &g->quantity);

    while (now != NULL && now->next != NULL) {
    if (strcmp(now->org_name, g->org_name) == 0&& strcmp(now->size, g->size) == 0) {
        
    printf("This Tshirt already exists.");
    free(g);
    return inventory;
    }
    now = now->next;
    }

    if (inventory == NULL) {
    inventory = g;
    return inventory;
    }

    for (now = inventory, replace = NULL; now != NULL && strcmp(now->org_name, g->org_name) < 0; replace = now, now = now->next);

    if (now != NULL) {
    if (strcmp(now->org_name, g->org_name) == 0) {
    while (now != NULL && strcmp(now->org_name, g->org_name) == 0 && strcmp(now->size, g->size) <= 0) {
    replace = now;
    now = now->next;
    }
    }
    }

    g->next = now;

    if (replace == NULL)
    return g;
    else
    replace->next = g;

    return inventory;
    }
    

void search_by_organization(struct tshirt *inventory) {
 
    struct tshirt *f;
       int prob = 0;
       char user_org_name[ORG_NAME_LEN + 1];
       printf("Enter the organization's name: ");
       read_line(user_org_name, ORG_NAME_LEN);
       printf("\n");
       f = inventory;
       while(f != NULL)
       {
               if (strcmp(f -> org_name, user_org_name) == 0)
               {
                       if (prob == 0)
                       {
                               printf("|----------------------------------------------------|-----|-------|------|\n");
                               printf("| Student organization                               | Sz. | Price | Qty. |\n");
                               printf("|----------------------------------------------------|-----|-------|------|\n");
                               prob = 1;
                       }
                       printf("| %-50s | %-3s | %5.2f | %4d |\n", f-> org_name, f -> size, f -> price, f -> quantity);
               }
               f = f -> next;
       }
       if (prob != 0)
       {
               printf("|----------------------------------------------------|-----|-------|------|\n");
       }
       else
       {
               printf("No t-shirt found! \n");
       }
}




void search_by_size(struct tshirt *inventory) {
    struct tshirt *f;
    int prob = 0;
    char usr_size[SIZE_LEN + 1];
    printf("Enter the tshirt size: ");
    scanf("%s", usr_size);
    printf("\n");
    f = inventory;
    while(f != NULL)
    {
            if(strcmp(f -> size, usr_size) == 0)
            {
                    if (prob == 0)
                    {
                            printf("|----------------------------------------------------|-----|-------|------|\n");
                            printf("| Student organization                               | Sz. | Price | Qty. |\n");
                            printf("|----------------------------------------------------|-----|-------|------|\n");
                            prob = 1;
                    }
                    printf("| %-50s | %-3s | %5.2f | %4d |\n", f -> org_name, f -> size, f -> price, f -> quantity);
            }
            f = f -> next;
    }
    if(prob != 0)
    {
            printf("|----------------------------------------------------|-----|-------|------|\n");
    }
    else
    {
            printf("No t-shirt found! \n");
    }
}



void print_inventory(struct tshirt *inventory) {
    struct tshirt *f;
    int prob = 0;
    f = inventory;
    while (f != NULL)
    {
            if(prob == 0)
            {
            printf("\n");
            printf("|----------------------------------------------------|-----|-------|------|\n");
            printf("| Student organization                               | Sz. | Price | Qty. |\n");
            printf("|----------------------------------------------------|-----|-------|------|\n");
            }
            printf("| %-50s | %-3s | %5.2f | %4d |\n", f-> org_name, f -> size, f -> price, f -> quantity);
            f= f -> next;
            prob = 1;
    }
    if(prob != 0)
    {
            printf("|----------------------------------------------------|-----|-------|------|\n");
    }
    else
    {
            printf("No t-shirt found! \n");
    }
}

void clear_inventory(struct tshirt *inventory) {

    struct tshirt *f;
          while(inventory != NULL)
          {
                  f = inventory;
                  inventory = inventory -> next;
                  free(f);

          }
}

