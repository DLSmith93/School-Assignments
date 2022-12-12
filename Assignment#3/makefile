CC = g++
CPPFLAGS = -Wall -g -std=c++11
 
app:	app.o hashtable.o
 
hashtable.o:	hashtable.h

.PHONY: clean
clean:      # clean the directory
			$(info -- cleaning the directory -- )
			rm -f *.o
			rm -f app

