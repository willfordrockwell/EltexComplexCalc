CFLAGS = -ldl
CC = gcc
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = main

LIB_COMPLEX_DIR = complex/
LIB_COMPLEX = complex
LIB_MENU_DIR = menu/
LIB_MENU = menu

app: libcomplex libmenu $(EXECUTABLE)
	$(CC) $(OBJECTS) -o $(EXECUTABLE).elf $(CFLAGS)

libcomplex:
	make -C $(LIB_COMPLEX_DIR)

libmenu:
	make -C $(LIB_MENU_DIR)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(SOURCES) -c

all: app

.PHONY: clean
clean:
	rm *.elf *.o $(LIB_COMPLEX_DIR)*.o $(LIB_COMPLEX_DIR)*.so $(LIB_MENU_DIR)*.o $(LIB_MENU_DIR)*.so
