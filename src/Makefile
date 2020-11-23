

PROJECT=timer

CC=gcc
CXX=g++


# I wanna play around with C and C++ for GUIs
# I will probobly write the back end in C.
# But GTK uses ojects to describe the UI.
# If that's how it is I would guess that C++ would represent it better?
# But GTK is written in C. So I'm like 50/50 on witch way it will turn out.

# GTK for C
GTKLIB=`pkg-config --cflags --libs gtk+-3.0`
# GTK for C++
GTKMM=`pkg-config --cflags --libs gtkmm-3.0`


CFLAGS=-Wall -g  $(GTKLIB) -rdynamic

LIBS=

DEPS=
OBJ=main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

all: $(OBJ)
	$(CC) -o $(PROJECT) $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o $(PROJECT)
