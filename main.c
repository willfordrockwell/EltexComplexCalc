#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "menu/menu.h"

int main (int argc, char ** argv)
{
	unsigned int ListLength = 0;
	char CommandStr[STRLEN];
	enum Command Cmd = ADD;

	void *Ext_Library_Parse;
	void *Ext_Library_Print;
	void *Ext_Library_Add;
	void *Ext_Library_Sub;
	void *Ext_Library_Mul;
	void *Ext_Library_Div;

	void
	(*Add_Func)(),
	(*Mul_Func)(),
	(*Sub_Func)(),
	(*Div_Func)(),
	(*Print_Help)();
	enum Command (*Parse_Command)(char*);

	Ext_Library_Parse = dlopen("./menu/libcustmenuparse_command.so", RTLD_LAZY);

	if (!Ext_Library_Parse) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return 1;
	}

	Parse_Command = dlsym(Ext_Library_Parse, "Parse_Command");

	if (!Parse_Command) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return 1;
	}

	Ext_Library_Add = dlopen("./menu/libcustmenuadd_func.so", RTLD_LAZY);

	if (!Ext_Library_Add) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return 1;
	}

	Add_Func = dlsym(Ext_Library_Add, "Add_Func");

	if (!Add_Func) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return 1;
	}

	Ext_Library_Mul = dlopen("./menu/libcustmenumul_func.so", RTLD_LAZY);

	if (!Ext_Library_Mul) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return 1;
	}

	Mul_Func = dlsym(Ext_Library_Mul, "Mul_Func");

	if (!Mul_Func) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return 1;
	}

	Ext_Library_Sub = dlopen("./menu/libcustmenusub_func.so", RTLD_LAZY);

	if (!Ext_Library_Sub) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return 1;
	}

	Sub_Func = dlsym(Ext_Library_Sub, "Sub_Func");

	if (!Sub_Func) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return 1;
	}

	Ext_Library_Div = dlopen("./menu/libcustmenudiv_func.so", RTLD_LAZY);

	if (!Ext_Library_Div) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return 1;
	}

	Div_Func = dlsym(Ext_Library_Div, "Div_Func");

	if (!Div_Func) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return 1;
	}

	Ext_Library_Print = dlopen("./menu/libcustmenuprint_help.so", RTLD_LAZY);

	if (!Ext_Library_Print) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return 1;
	}

	Print_Help = dlsym(Ext_Library_Print, "Print_Help");

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
			Add_Func();
			break;
		case SUB:
			Sub_Func();
			break;
		case MUL:
			Mul_Func();
			break;
		case DIV:
			Div_Func();
			break;
		case HELP:
			Print_Help();
			break;
		default:
			break;
		}
	} while (Cmd != QUIT);
	dlclose(Ext_Library_Parse);
	dlclose(Ext_Library_Print);
	dlclose(Ext_Library_Add);
	dlclose(Ext_Library_Sub);
	dlclose(Ext_Library_Mul);
	dlclose(Ext_Library_Div);
	fputs("Quiting...\n", stdout);
	return 0;
}
 
