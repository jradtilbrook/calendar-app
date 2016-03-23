/**
 * deals with all things calendar related
 */

#include "gui.h"
#include "linkedlist/linkedlist.h"

typedef struct {
	Window *window;
	LinkedList *events;
} Calendar;
