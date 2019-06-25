#include "menu.h"

void List_Func (
	struct Phone_Book *Book,
	unsigned int Size_Of_Book
)
{
	fprintf(stdout, "Found %d record%s in phone book\n", 
	Size_Of_Book,
	(Size_Of_Book > 1 ? "s " : " "));
	for (int i = 0; i < Size_Of_Book; i++) {
		if (strcmp(Book->First_Name, "\0") == 0) {
			continue;
		}
		fprintf(stdout, "%2d member \nFirst name: %sLast name: %sTel.: %s\n",
		i + 1, Book->First_Name, Book->Last_Name, Book->Tel);
		Book++;
	}
}
