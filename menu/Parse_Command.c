#include "menu.h"

enum Command Parse_Command(char *CommandStr)
{
	const char AddStr[4] = "add";
	const char SubStr[4] = "sub";
	const char DivStr[4] = "div";
	const char MulStr[4] = "mul";

	void *Ext_Library;
	char* (*strlwr)(char*);

	Ext_Library = dlopen("./menu/libcustmenustrlwr.so", RTLD_LAZY);

	if (!Ext_Library) {
		fprintf(stderr, "dlopen error:%s\n", dlerror());
		return UNKNOWN;
	}

	strlwr = dlsym(Ext_Library, "strlwr");

	if (!strlwr) {
		fprintf(stderr, "dlwym error: %s\n", dlerror());
		return UNKNOWN;
	}

	CommandStr = strlwr(CommandStr);
	if (strncmp(CommandStr, AddStr, strlen(AddStr)) == 0) {
		return ADD;
	}
	else if (strncmp(CommandStr, SubStr, strlen(SubStr)) == 0) {
		return SUB;
	}
	else if (strncmp(CommandStr, DivStr, strlen(DivStr)) == 0) {
		return DIV;
	}
	else if (strncmp(CommandStr, MulStr, strlen(MulStr)) == 0) {
		return MUL;
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
