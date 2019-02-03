# linkedList

Demo program which will hopefully provide you with a better understanding of how to implement linked lists in C using pointers.

## Pointers in C

The following information is also available in the .c file but thought I'd paste it here as well:

---

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

---

### Contact

If you have any questions, please don't hesistate to contact me on Twitter: [@jamescarter2001](https://twitter.com/jamescarter2001)
# Linked-List
