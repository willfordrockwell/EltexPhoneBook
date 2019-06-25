#include <string.h>

struct Phone_Book {
	char First_Name[10];
	char Last_Name[10];
	char Tel[10];
};

void Add(struct Phone_Book *Book, char *First_Name, char *Last_Name, char *Tel);
