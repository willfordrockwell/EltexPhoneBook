#include "menu.h"

int Search_Func(
	struct Phone_Book *Book,
	int Size_Of_Book,
	char *Value,
	char Search_Field
)
{
	if (Size_Of_Book == 0) {
		fputs("No phone book found\n", stdout);
		return -1;
	}
	const char *First = "first";
	const char *Last = "last";
	const char *Tel = "tel";

	for (int i = 0; i < Size_Of_Book; i++) {
		switch (Search_Field)
		{
		case 0:
			if (strncmp(Book->First_Name, Value, strlen(Value)) == 0) {
				return i;
			}
			break;
		case 1:
			if (strncmp(Book->Last_Name, Value, strlen(Value)) == 0) {
				return i;
			}
			break;
		case 2:
			if (strncmp(Book->Tel, Value, strlen(Value)) == 0) {
				return i;
			}
			break;
		}
		Book++;
	}
	fputs("No Record found\n", stdout);
	return -2;
}
