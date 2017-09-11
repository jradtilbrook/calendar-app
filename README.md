# Calendar Application [![Build Status](https://travis-ci.org/jradtilbrook/calendar-app.svg?branch=master)](https://travis-ci.org/jradtilbrook/calendar-app)
A simple calendar application GUI written in `C` using the **GTK+ 3** library. This was originally an assignment from a
unit I took as part of my B.Eng. degree and this repository is effectively a re-mastering of that work to exhibit on
GitHub. The original assignment specification is paraphrased in this README.

Note: The original spec required the use of GTK+ 2 and conformity to C89 however these have been relaxed since it is no
longer an assessed piece of work.


## To-Do
- [ ] Check and document build/package requirements
- [ ] Convert makefile to use a *build* directory
- [ ] Update makefile to handle linkedlist library in separate directory
- [ ] Find where memory leaks are occurring (within gtk) and fix them
- [ ] ...


## Program Outline
The program works with one calendar at a time, where the calendar consists of a set of events. Each event has a date, a
start time, a title and an duration (in minutes). For simplicity, repeated events are not considered, and the output is
purely textual - no day-by-day or week-by-week (etc) listings.

The program does the following:
- Read an optional command-line parameter. This represents a calendar file, and is loaded and displayed to the user. See
[Calendar Files](#calendar-files) for file format.
- The events in the file must be stored in a linked list. If no parameter is specified, the list will be initially
empty.
- Display the calendar in the text area of the GUI, in a different format to that in the calendar file, and in date
order. The format is described in [Calendar Display](#calendar-display).
- Through the use of GUI buttons, allow the user to:
  * *Load a calendar from file* - An existing calendar to replace the one currently loaded
  * *Save the current calendar to file* - In the format described [here](#calendar-files).
  * *Add a calendar event*
  * *Edit a calendar event*
  * *Delete a calendar event*
  * *Remove the current calendar*
- Where appropriate, validate the contents of calendar files and events to ensure contains a valid date, time and
duration, and that it conforms to the file format.


## Calendar Files
Calendar files can contain several events. The file does not state the number of events - this can only be known by
reading the file to the end (hence the linked list).

Each event consists of *one* or *two* lines, with each event separated by empty lines. For each event:
- The first line contains the date, time, duration and title, in that order, separated by spaces.
  * Date format is `YYYY-MM-DD`.
  * Time is 24-hour `HH:MM`.
  * Duration is a single non-negative integer in minutes.
  * The title takes up the rest of the line and may contain any valid string characters except for a new-line.
- If the next line is not empty it contains the location. The format for the location is the same as for the title.

Here is an example calendar file:
```
2013-11-08 10:00 75 Veg out
Home

2013-11-08 11:15 45 Work on assignment
Uni

2013-12-03 12:30 5 Make Huge Foreign Currency

2014-06-30 23:59 25920 Armageddon -- Contact Bruce Willis
Earth
```


## Calendar Display
The application must update the displayed events whenever a calendar is loaded or modified. It would be optimal if
events are displayed in sorted order with the soonest event at the top. The format to display events differs from that
of the calendar file.

Here is an example display:
```
Veg out @ Home (1 hour, 15 minutes)
8 November 2013, 10am
---

Work on assignment @ Uni (45 minutes)
8 November 2013, 11:15am
---

Make Huge Foreign Currency Transactions (5 minutes)
12 December 2013, 12:30pm
---

Armageddon -- Contact Bruce Willis @ Earth (432 hours)
30 June 2014, 11:59pm
---
```

Some points to note about the display:
- The event title comes first.
- If the event contains a location it follows the title, preceded by an *@* character.
- The duration come next. If greater than 60 minutes, it is displayed in hours and minutes.
- The date follows on the next line. It is shown in an *expanded* format including the name of the month (as opposed to
the number).
- Next, the time is shown in 12-hour format succeeded by either "am" or "pm" as appropriate. If the minutes field is
zero, omit them.
- The event display ends with a new line and "---".


## Graphical User Interface
A wrapper around the GTK library was supplied as part of the original assignment. Note that this is not my work. This
wrapper is found in the [gui.h](./gui.h) and [gui.c](./gui.c) files.

The wrapper library provides easy to use functions to setup the window and text area for event display and provide a
method to attach callbacks to buttons to perform the required functionality (eg. edit an event).

For usage details see [gui.h](./gui.h).


## Compiling
This application requires the **GTK 3.0** package. It also makes use of `pkg-config` package.

To build the application, simply run `make` from the base git directory. This compiles the application and produces an
binary called `calendar-app`.
