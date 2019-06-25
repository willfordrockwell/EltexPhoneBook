#include "menu.h"

void Print_Help() 
{
	fputs("All commands are not case sensitive\n", stdout);
	fputs("Parameters must be integer values\n", stdout);
	fputs("Add to add a member in phone book:\n", stdout);
	fputs("ADD\n", stdout);
	fputs("Del to delete member from existing phone book. Prototype:\n", stdout);
	fputs("DEL\n", stdout);
	fputs("List to list all members in existing phone book. Prototype:\n", stdout);
	fputs("LIST\n", stdout);
	fputs("Search to search a mebmer in existing phone book. Prototype:\n", stdout);
	fputs("SEARCH\n", stdout);
	fputs("Quit to quit program. Prototype:\n", stdout);
	fputs("QUIT\n", stdout);
}
