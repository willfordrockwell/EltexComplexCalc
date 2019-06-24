#include "menu.h"

void Print_Help() 
{
	fputs("All commands are not case sensitive\n", stdout);
	fputs("Parameters must be integer values\n", stdout);
	fputs("Add to addictive two complex numbers. Prototype:\n", stdout);
	fputs("ADD\n", stdout);
	fputs("Sub to substract two complex numbers. Prototype:\n", stdout);
	fputs("SUB\n", stdout);
	fputs("Mul to multiply two complex numbers. Prototype:\n", stdout);
	fputs("MUL\n", stdout);
	fputs("Div to divide two complex numbers. Prototype:\n", stdout);
	fputs("DIV\n", stdout);
	fputs("Quit to quit program. Prototype:\n", stdout);
	fputs("QUIT\n", stdout);
}