/**
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "gui.h"
#include "calendar.h"
#include "linkedlist/linkedlist.h"

void loadCalendar(void *data);

int main(int argc, char **argv)
{
	Calendar calendar;

	/* create the window */
	calendar.window = createWindow("Personal Calendar");

	/* create the linked list */
	calendar.events = createList();

	/* load calendar if specified */
	if (argc >= 2)
	{
		char *text;
		if (argc > 2)
		{
			/* alert user of ignored parameters */
			fprintf(stderr, "More than one calendar is not supported. Only the "
				"first calendar (%s) will be loaded.\n", argv[1]);
		}
		/*text = readCalendar(argv[1], calendar.events);*/
		setText(calendar.window, text);
		free(text);
	}
	else /* otherwise set a default message */
	{
		/* TODO: put this in load calendar if an error occurs? */
		setText(calendar.window, NO_CALENDAR);
	}

	/* add the buttons and callbacks */
	addButton(calendar.window, "Load calendar", loadCalendar, &calendar);
	addButton(calendar.window, "Save calendar", NULL, &calendar);
	addButton(calendar.window, "Add new event", NULL, &calendar);
	addButton(calendar.window, "Edit event", NULL, &calendar);
	addButton(calendar.window, "Delete event", NULL, &calendar);
	addButton(calendar.window, "Close calendar", NULL, &calendar);
	addButton(calendar.window, "Quit", NULL, &calendar);

	/* show the window */
	runGUI(calendar.window);

	/* clean up memory */
	freeWindow(calendar.window);
	deleteList(&calendar.events, NULL);

	/* retun an appropriate status code */
	return 0;
}
/*
void loadCalendar(void *data)
{
	Calendar *calendar = (Calendar *)data;
	messageBox(calendar->window, "Test message box");
}
*/
