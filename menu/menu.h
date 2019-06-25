#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include <dlfcn.h>

#include "../phonebook/phonebook.h"

#define STRLEN 20

enum Command {
	ADD,
	DEL,
	LIST,
	SEARCH,
	QUIT,
	HELP,
	UNKNOWN,
};

enum Command Parse_Command(char *CommandStr);

char *strlwr(char *str);

void Print_Help();

struct Phone_Book *Add_Func (
	struct Phone_Book *Book,
	unsigned int *Size_Of_Book,
	unsigned int *Num_Of_Empty,
	unsigned int First_Empty
);

void Del_Func();

void List_Func(
	struct Phone_Book *Book,
	unsigned int Size_Of_Book
);

void Search_Func ();
