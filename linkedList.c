//
//  main.c
//  linkedList
//

/*

To declare a pointer in C, you use the "*" symbol. First consider the data type of the data that you want to point to.

For example, if we declare an integer called "x" as follows:

int x;

A pointer to an integer like "x" would be declared like this using "int":

int *pointertox;

If x was a char, the pointer would instead be declared like this, this rule applies to all data types:

char x;
char *pointertox;

If x were a data structure, such as an item in a linked list, you would declare a pointer to the item as you would expect,
by using "struct listItem":

struct listItem *pointertox;

Assuming x is an integer, let's initialise it with a random number:

x = 5;

And now lets make our pointer point to x in memory (Don't use a "*" before the pointer name as we are assigning the address):

pointertox = &x;

Alternatively you can initialise the pointer straight after declaration as follows
(here you keep the "*" otherwise you'd just be declaring a normal integer):

int *pointertox = &x;

Time to explain how to use a pointer, take a look at these "printf" functions to understand how they're used:

printf("Value of 'pointertox' -> %p\n", pointertox); // This will print the memory address of our original variable "x" that the pointer holds (will be a hex address like 0xFFFFFFFF).
printf("Value of number at the memory address pointed to by 'pointertox' -> %d", *pointertox); // This will print the value at the memory address held in 'pointertox', in this case '5'.

As you can see, using a "*" before the pointer name gets the data that the pointer is pointing to.

Pointers to structures are pretty much the same. Usually when we are manipulating data in a structure we use this format:

listItem.data = whatever_we_want;

However if we want to use a pointer to the exact same thing, we use this format instead:

listItemPointer->data = whatever_we_want;

No "*" used here.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listItem { // Setting up the structure of a listItem (This is like an object in Java, Objective C etc.)

    int data; // Data the item will store.
    struct listItem *next; // Pointer to next item (Contains address of next item in the list).

};

void addNewItem (struct listItem *end, struct listItem *toAdd) { // Method for adding a new item.

    toAdd->data = 4; // New item should have data value (4). Since "d" was passed by reference from main function, "toAdd" is a pointer so we use "toAdd->data" rather than "tooAdd.data". (Hope that makes sense...)


    printf("listItem C currently has pointer value %p\n\r", end->next); // Prints the address of the next item in the list, at this point it should be 0x0

    end->next = toAdd; // Need to update item C's pointer so that it points to the next item that we have just initialised, which is "D".
    toAdd->next = NULL; // Need to set D's pointer to Null as it is now at the end of the list.

    printf("listItem C points to %p has value '%d'\n\r", end->next, end->data); // Printing stuff because why not...
     printf("listItem D points to %p has value '%d'\n\r", toAdd->next, toAdd->data);

}

void printItems(struct listItem *first) { // Method for printing all the items.

    int ctr = 0; // Counter variable.

    for (struct listItem *i = first; i != NULL; i = i->next) { // Declaring a for loop, creates a pointer to the address of the first item in the list called "i", parameter "first" is a pointer so we just assign it without a "&" symbol. Loop will iterate until it reaches an item with a NULL pointer, indicating the end of the list has been reached. After each iteration, set i to the address of the next item in the list.

        ctr++; // Add one to ctr.
        printf("Item %d value is %d\n\r", ctr, i->data); // Print the current item data.

    }

}

int main () {

    struct listItem a; // Creating items a, b, c, d.
    struct listItem b;
    struct listItem c;
    struct listItem d;

    a.data = 1; // Assigning data values to each item. a, b, c, d aren't pointers, so we use a.data, b.data etc. instead of a->data, b->data etc.
    b.data = 2;
    c.data = 3;

    a.next = b.next = c.next = d.next = NULL; // Initialising all pointers as NULL to avoid issues.

    a.next = &b; // Setting up pointers to allow linked list to work. a, b, c aren't pointers so we use the symbol "&".
    b.next = &c;

    printItems(&a); // Prints the item order and content.

    addNewItem(&c, &d); // Pass in last item first followed by the item you want to add.

    printItems(&a); // Prints the item order and content (again).

    return 0;

}
