#include "menu.h"

enum Command Parse_Command(char *CommandStr)
{
	const char AddStr[4] = "add";
	const char DelStr[4] = "del";
	const char ListStr[5] = "list";
	const char SearchStr[6] = "search";

	CommandStr = strlwr(CommandStr);
	if (strncmp(CommandStr, AddStr, strlen(AddStr)) == 0) {
		return ADD;
	}
	else if (strncmp(CommandStr, DelStr, strlen(DelStr)) == 0) {
		return DEL;
	}
	else if (strncmp(CommandStr, ListStr, strlen(ListStr)) == 0) {
		return LIST;
	}
	else if (strncmp(CommandStr, SearchStr, strlen(SearchStr)) == 0) {
		return SEARCH;
	}
	else if (strncmp(CommandStr, "quit", strlen("quit")) == 0) {
		return QUIT;
	}
	else if (strncmp(CommandStr, "help", strlen("help")) == 0) {
		return HELP;
	}
	else {
		return UNKNOWN;
	}
}
