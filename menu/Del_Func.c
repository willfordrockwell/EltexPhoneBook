#include "menu.h"

struct Phone_Book *Del_Func (
	struct Phone_Book *Book,
	int *Size_Of_Book
)
{
	void *Ext_Library;
	void (*Add)(struct Phone_Book*, char *, char *,char *);

	char First_Name = '\0', Last_Name = '\0', Tel = '\0';
	char Search_Field;
	char *Value = (char*) malloc(sizeof(char) * STRLEN);
	int Search_Result;

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

	Preparation(&Search_Field, Value);

	Search_Result = Search_Func(Book, (*Size_Of_Book), (Value), Search_Field);

	for (int i = 0; i < (*Size_Of_Book); i++) {
		if (i >= Search_Result && i < ((*Size_Of_Book) - 1)) {
			Book[i] = Book[i + 1];
		}
	}
	Book = (struct Phone_Book*) realloc(Book, (--(*Size_Of_Book)) * sizeof(struct Phone_Book));
	dlclose(Ext_Library);
	free(Value);
	return Book;
}
