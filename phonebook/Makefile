#phonebook
CC = gcc
CCFLAGS = -fPIC

LIBRARY = phonebook
LIBRARY_SOURCES = Add.c
LIBRARY_OBJECTS = $(LIBRARY_SOURCES:.c=.o)

#Library Complex library from objects
libphonebook: $(LIBRARY_OBJECTS)
	gcc -shared $(LIBRARY_OBJECTS) -o libcustphonebook.so

#Library Complex objects from sources
$(LIBRARY_OBJECTS): $(LIBRARY_SOURCES)
	$(CC) $(LIBRARY_SOURCES) -c $(CCFLAGS)
