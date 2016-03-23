#include "callbacks.h"
#include "calendar.h"

void loadCalendar(void *data)
{
	Calendar *calendar = (Calendar *)data;
	int open;
	messageBox(calendar->window, "Test message box");
    printf("%s\n", file(calendar->window));
	/*open = dialogBox(calendar->window, "Select calendar file");*/
}
