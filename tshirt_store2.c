// Jadea Parchment this program will find tshirts for student organizations at USF
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readline.h"
#include "tshirt.h"



int main() {
    char code;

    struct tshirt *inventory = NULL;

    help();
    printf("\n");

    for (;;) {
        // read operation code
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n') /* skips to end of line */
            ;

        // run operation
        switch (code) {
            case 'a':
                inventory = add_to_inventory(inventory);
                break;
            case 'h':
                help();
                break;
            case 'o':
                search_by_organization(inventory);
                break;
            case 's':
                search_by_size(inventory);
                break;
            case 'p':
                print_inventory(inventory);
                break;
            case 'q':
                clear_inventory(inventory);
                return 0;
            default:
                printf("Illegal operation code!\n");
        }
        printf("\n");
    }
}

