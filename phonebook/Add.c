#include "phonebook.h"

void Add(
	struct Phone_Book *Book,
	char *First_Name,
	char *Last_Name,
	char *Tel
)
{
	strcpy(Book->First_Name, First_Name);
	strcpy(Book->Last_Name, Last_Name);
	strcpy(Book->Tel, Tel);
	return;
}
