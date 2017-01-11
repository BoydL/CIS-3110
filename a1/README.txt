Lucas Boyd             0795339
CIS 3110             Assignment One

***************
Program summary:
***************
The provided parse was provided from the TA posted on moodle. It works by grabbing every possible character delimitation for a command as a seperate argument and creates an array of string to be used for proccessing the command.

The program works by first getting the user's input. once the input has been grabbed the program checks if the users command is any of the following inputs: art, exit, add, or arg. If it is not any of those commands, and is not a null value, the shell then forks a new child process.

once a new child process has been created, it checks the user's input for any file redirection. if there is file redirection then the program executes the command. once the command executes the program either waits for it to end or if there was an ampersand it runs in the background. 

*************
compiling the program
*************
Got to appropriate directroy.
type make

*************
running the program
*************
./msh


*********
known limitations
*********
No piping is supported.

art function:
you must enter a file.

