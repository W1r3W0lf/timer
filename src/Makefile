
PROJECT=timer

CC=gcc
CXX=g++


# GTK for C
GTKLIB=`pkg-config --cflags --libs gtk+-3.0`
# GTK for C++
GTKMM=`pkg-config --cflags --libs gtkmm-3.0`


CFLAGS=-Wall -g  $(GTKLIB) -rdynamic

LIBS=

DEPS=
OBJ=main.o timer.o alarm.o clock.o stopWatch.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

all: $(OBJ)
	$(CC) -o $(PROJECT) $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o $(PROJECT)
