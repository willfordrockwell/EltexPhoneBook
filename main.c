#include "main.h"

int main (int argc, char **argv)
{
	int Size_Of_Book = 0;
	int Num_Of_Empty = 0;
	int First_Empty = 0;
	char CommandStr[STRLEN];
	enum Command Cmd = ADD;

	void *Ext_Library;

	struct Phone_Book* (*Add_Func)(struct Phone_Book*, int*);

	struct Phone_Book* (*Del_Func)(struct Phone_Book*, int*);

	void (*Print_Help)();
	void (*List_Func)(struct Phone_Book*,int);
	void (*Preparation)(char*, char*);

	int (*Search_Func)(struct Phone_Book*, int, char*, char);

	enum Command (*Parse_Command)(char*);

	struct Phone_Book *Book = NULL;

	char Search_Field;
	char *Value = (char*) malloc(sizeof(char) * STRLEN);

	Ext_Library = dlopen("./menu/libcustmenu.so", RTLD_LAZY);

	if (!Ext_Library) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return 1;
	}

	Parse_Command = dlsym(Ext_Library, "Parse_Command");

	if (!Parse_Command) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return 1;
	}

	Add_Func = dlsym(Ext_Library, "Add_Func");

	if (!Add_Func) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return 1;
	}

	List_Func = dlsym(Ext_Library, "List_Func");

	if (!List_Func) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return 1;
	}

	Del_Func = dlsym(Ext_Library, "Del_Func");

	if (!Del_Func) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return 1;
	}

	Search_Func = dlsym(Ext_Library, "Search_Func");

	if (!Search_Func) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return 1;
	}

	Preparation = dlsym(Ext_Library, "Preparation");

	if (!Preparation) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return 1;
	}


	Print_Help = dlsym(Ext_Library, "Print_Help");

	if (!Print_Help) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return 1;
	}

	//Loop for commands
	fputs("Type help for help\n", stdout);
	do {
		if (Cmd == UNKNOWN) {
			fputs("Unknown command, type help for help\n", stdout);
		}
		fputs(">", stdout);
		fgets(CommandStr, STRLEN, stdin);
		Cmd = Parse_Command(CommandStr);
		switch (Cmd)
		{
		case ADD:
			Book = Add_Func(Book, &Size_Of_Book);
			if (Num_Of_Empty > 0) {
				//update First_Empty
			}
			break;
		case DEL:
			Book = Del_Func(Book, &Size_Of_Book);
			break;
		case LIST:
			List_Func(Book, Size_Of_Book);
			break;
		case SEARCH:
			Preparation(&Search_Field, Value);
			fprintf(stdout, "Position of Searching element is: %d\n",
			Search_Func(Book, Size_Of_Book, Value, Search_Field + 1));
			break;
		case HELP:
			Print_Help();
			break;
		default:
			break;
		}
	} while (Cmd != QUIT);
	dlclose(Ext_Library);
	free(Book);
	fputs("Quiting...\n", stdout);
	return 0;
}
