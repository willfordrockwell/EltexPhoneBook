#menu
CC = gcc
CCFLAGS = -fPIC

LIBRARY = menu
LIBRARY_SOURCES = Preparation.c Parse_Command.c Print_Help.c Add_Func.c Del_Func.c List_Func.c Search_Func.c strlwr.c
LIBRARY_OBJECTS = $(LIBRARY_SOURCES:.c=.o)

#Library Menu library from objects
libmenu: $(LIBRARY_OBJECTS)
	gcc -shared $(LIBRARY_OBJECTS) -o libcustmenu.so

#Library Menu objects from sources
$(LIBRARY_OBJECTS): $(LIBRARY_SOURCES)
	$(CC) $(LIBRARY_SOURCES) -c $(CCFLAGS)
