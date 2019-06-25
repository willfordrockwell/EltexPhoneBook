#include "menu.h"

void Preparation(char *Search_Field, char *Value)
{
	const char *First = "first";
	const char *Last = "last";
	const char *Tel = "tel";

	fputs("Type what field you need to search (first/last/tel): ", stdout);
	fgets((Value), STRLEN, stdin);
	strcpy((Value), strlwr((Value)));

	if (strncmp((Value), First, strlen(First)) == 0) {
		fputs("Searching in First_Name\n", stdout);
		(*Search_Field) = 0;
	}
	else if (strncmp((Value), Last, strlen(Last)) == 0) {
		fputs("Searching in Last_Name\n", stdout);
		(*Search_Field) = 1;
	}
	else if (strncmp((Value), Tel, strlen(Tel)) == 0) {
		fputs("Searching in Tel\n", stdout);
		(*Search_Field) = 2;
	}
	else {
		return;
	}

	fputs("Type value to search: ", stdout);
	fgets((Value), STRLEN, stdin);

	return;
}
