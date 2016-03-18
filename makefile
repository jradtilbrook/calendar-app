# PROJECT:	Calendar Application
# AUTHOR:	Jarryd Tilbrook
# DATE:		18 Mar 2016
# The makefile for the calendar application

CC			= gcc
GTKFLAGS 	= `pkg-config --cflags gtk+-2.0`
GTKLIBS 	= `pkg-config --libs gtk+-2.0`
CFLAGS 		= -Wall -pedantic -ansi
DEBUG		= -g
BIN 		= calendar-app
SOURCE 		= $(wildcard *.c)
OBJECTS 	= $(SOURCE:%.c=%.o)

# Link the objects
$(BIN): $(OBJECTS)
	$(CC) -o $(BIN) $(OBJECTS) $(GTKLIBS)

# Compile the source
%.o: %.c
	$(CC) $(CFLAGS) $(GTKFLAGS) -c $<
	$(CC) $(CFLAGS) -MM -o $*.d $<

# Cleaning rules
cleandeps:
	@echo -n "Cleaning dependency files... "
	@rm -f *.d
	@echo "Done."

cleanobjs:
	@echo -n "Cleaning object files... "
	@rm -f *.o
	@echo "Done."

clean: cleandeps cleanobjs
	@echo -n "Cleaning binary... "
	@rm -f $(BIN)
	@echo "Done."

.PHONY: clean cleandeps cleanobjs

# Include the generated dependencies
-include $(OBJECTS:%.o=%.d)
