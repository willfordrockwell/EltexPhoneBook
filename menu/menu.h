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
	int *Size_Of_Book
);

struct Phone_Book *Del_Func(
	struct Phone_Book *Book,
	int *Size_Of_Book
);

void List_Func(
	struct Phone_Book *Book,
	int Size_Of_Book
);

int Search_Func (
	struct Phone_Book *Book,
	int Size_Of_Book,
	char *Value,
	char Search_Field
);

void Preparation(
	char *Search_Field,
	char *Value
);
