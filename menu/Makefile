#menu
CC = gcc
CCFLAGS = -fPIC

LIBRARY_MENU = menu
LIBRARY_MENU_SOURCES = Parse_Command.c Print_Help.c Add_Func.c Sub_Func.c Mul_Func.c Div_Func.c Get_Input.c strlwr.c
LIBRARY_MENU_OBJECTS = $(LIBRARY_MENU_SOURCES:.c=.o)

#Library Menu library from objects
all: $(LIBRARY_MENU_OBJECTS)
	gcc -shared Parse_Command.o -o libcustmenuparse_command.so
	gcc -shared Print_Help.o -o libcustmenuprint_help.so
	gcc -shared Get_Input.o -o libcustmenuget_input.so
	gcc -shared Add_Func.o -o libcustmenuadd_func.so
	gcc -shared Sub_Func.o -o libcustmenusub_func.so
	gcc -shared Mul_Func.o -o libcustmenumul_func.so
	gcc -shared Div_Func.o -o libcustmenudiv_func.so
	gcc -shared strlwr.o -o libcustmenustrlwr.so

#Library Menu objects from sources
$(LIBRARY_MENU_OBJECTS): $(LIBRARY_MENU_SOURCES)
	$(CC) $(LIBRARY_MENU_SOURCES) -c $(CCFLAGS)
