# Test Harness
This directory contains files for use with testing the calendar application.
Each file and it's expected output is explained below.

Valid test files are named *valid_input#*, where *#* is the number of the test input,
and the corresponding expected output (would be shown in the text area in app)
is named *valid_output1*. Invalid test files follow the same format. Note that
most invalid test files should still produce some sort of output that is
testable.

**Invalid test files follow the same format, however error messages are expected**

------

## To-Do
1. Figure out how best to test
2. Find good C89 unit test library

------

## Running the Tests
To aid in the testing and hopefully produce more reliable tests, ...
use mixture of python, bash, diff, valgrind, testing library ... are used.

------
## Test file descriptions

###### [valid_input1](./valid_input1)
- this is the example file taken from the [README](../README.md#calendar-files).
- the file structure is valid.
- contains four events, one without a location.

###### [valid_input2](./valid_input2)
- similar to valid_input1 but contains more events.
- some event names are longer and should be displayed correctly
