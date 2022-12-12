CC = g++
CPPFLAGS = -Wall -g -std=c++11

app:        app.o songs.o list.o

songs.o:    list.h songs.h

list.o:     list.h songs.h

.PHONY: clean
clean:      # clean the directory
	        $(info -- cleaning the directory -- )
	        rm -f *.o
	        rm -f app

