/**
 *
 */
#include <stdio.h>
#include "gui.h"

typedef struct {
	Window *window;
} Calendar;

int main(int argc, char **argv)
{
	Calendar calendar;

	/* create the window */
	calendar.window = createWindow("Personal Calendar");

	/* set a default message */
	setText(calendar.window, "No calendar loaded");

	/* add the buttons and callbacks */
	addButton(calendar.window, "Load calendar", NULL, &calendar);
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

	/* retun an appropriate status code */
	return 0;
}
