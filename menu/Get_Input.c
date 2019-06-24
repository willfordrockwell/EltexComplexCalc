#include "menu.h"

int Get_Input(const char *Type, const char *Name)
{
	int result = 0;
	int ErrorCount = 0;
	char Input[STRLEN], *IsInputValid;
	do {
		if (ErrorCount > 0) {
			fputs("Error found!\n", stdout);
		}
		fputs("Type ", stdout); 
		fputs(Type, stdout); 
		fputs(" part of ", stdout);
		fputs(Name, stdout);
		fputc(' ', stdout);
		fgets(Input, STRLEN, stdin);
		result = strtol(Input, &IsInputValid, 10);
		if (IsInputValid == NULL) {
			ErrorCount++;
		}
		else {
			ErrorCount = 0;
		}
	} while (ErrorCount > 0);
	return result;
}
