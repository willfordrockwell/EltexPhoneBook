#include "menu.h"

struct Phone_Book *Add_Func (
	struct Phone_Book *Book,
	int *Size_Of_Book
)
{
	void *Ext_Library;
	void (*Add)(struct Phone_Book*, char *, char *, char *);

	char First_Name[STRLEN], Last_Name[STRLEN], Tel[STRLEN];

	Ext_Library = dlopen("./phonebook/libcustphonebook.so", RTLD_LAZY);

	if (!Ext_Library) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return Book;
	}

	Add = dlsym(Ext_Library, "Add");

	if (!Add) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return Book;
	}

	if ((*Size_Of_Book)) {
		Book = (struct Phone_Book*)realloc(Book,(++(*Size_Of_Book)) * sizeof(struct Phone_Book));
		fputs("Type first name of member: ", stdout);
		fgets(First_Name, STRLEN, stdin);
		fputs("Type last name of member: ", stdout);
		fgets(Last_Name, STRLEN, stdin);
		fputs("Type Telephone of member: ", stdout);
		fgets(Tel, STRLEN, stdin);
		Add(&(Book[(*Size_Of_Book) - 1]), First_Name, Last_Name, Tel);
	}
	else {
		Book = (struct Phone_Book*)realloc(NULL, (++(*Size_Of_Book)) * (sizeof(struct Phone_Book)));
		fputs("Type first name of member: ", stdout);
		fgets(First_Name, STRLEN, stdin);
		fputs("Type last name of member: ", stdout);
		fgets(Last_Name, STRLEN, stdin);
		fputs("Type Telephone of member: ", stdout);
		fgets(Tel, STRLEN, stdin);
		Add(&(Book[(*Size_Of_Book) - 1]), First_Name, Last_Name, Tel);
	}

	dlclose(Ext_Library);
	return Book;
}
