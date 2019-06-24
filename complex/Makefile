#complex
CC = gcc
CCFLAGS = -fPIC

LIBRARY_COMPLEX = complex
LIBRARY_COMPLEX_SOURCES = Add.c Sub.c Mul.c Div.c
LIBRARY_COMPLEX_OBJECTS = $(LIBRARY_COMPLEX_SOURCES:.c=.o)

#Library Complex library from objects
all: $(LIBRARY_COMPLEX_OBJECTS)
	gcc -shared Add.o -o libcustcomplexadd.so
	gcc -shared Sub.o -o libcustcomplexsub.so
	gcc -shared Mul.o -o libcustcomplexmul.so
	gcc -shared Div.o -o libcustcomplexdiv.so

#	gcc -shared $(LIBRARY_COMPLEX_OBJECTS) -o $(LIBRARY_COMPLEX_OBJECTS)

#Library Complex objects from sources
$(LIBRARY_COMPLEX_OBJECTS): $(LIBRARY_COMPLEX_SOURCES)
	$(CC) $(LIBRARY_COMPLEX_SOURCES) -c $(CCFLAGS)
