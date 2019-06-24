#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <dlfcn.h>

#include "../complex/complex.h"

#define STRLEN 20

enum Command {
	ADD,
	SUB,
	DIV,
	MUL,
	QUIT,
	HELP,
	UNKNOWN,
};

enum Command Parse_Command(char *CommandStr);

int Get_Input(const char *Type, const char *Name);

char *strlwr(char *str);

void Print_Help();

void Add_Func ();

void Sub_Func();

void Div_Func();

void Mul_Func ();
