Lucas Boyd             0795339
CIS 3110             Assignment Three Question 2

***************
Program summary:
***************
This code will simulate four memory management strategies. The four memory management stratagies that htis program simulates are, Best fit, Next fit, Worst fit, and
first fit. At the end of each simulation you can scroll through the steps to see how each stratagy differs and what is happening when each processes is being loaded, 
and swapped.

*************
Description of Algorithm
*************
In this program I used a linked list data structure for simulating memory use. I use Queue linked list for the ready queue, and the in memory list. two operations are
primearily used, add to back and remove from front. a bit table, (table of 0 or 1's size of 128) where each spot in the table is a megabyte. This bit table is used to
keep track of holes aswell as give a visual representation of what is happening in memory for each simulation. At the start all processes are in the ready Queue. Once a
simulaltion starts it is load from the ready Queue into the memory list, and the bit table is update accordingly. Processes are loaded into memory until there is not 
enough room for the process currently being loaded. Once this occurs the process at the top of the memory queue is poped off and added back to the ready queue if it has
not been swapped 3 times. If not the process is removed from both lists. once a process has been removed a loop starting at the address in memory of the process switch 
all spots taken up (indicated by a 1) and switchs them to a zero depending on the size of the process. this repeats and may vary pending on each type of Memory
Management strategy.


*************
compiling the program
*************
Go to directory where programfiles are.
type make, to compile

*************
running the program
*************
./holes "inputfile.txt" in the proper directory after compiling.
once the program has compiled, each of the four memory management
strategies will run one by one. After a simulation runs, the user will be prompted 
to hit any key to contiue which will run the next simulation until there are no more
to run.



*********
known limitations
*********
The program is able to run the simulations using he example input on the moodle.

**********
Example input file:
**********
see test.txt in q2 folder for input file which ran on my program.

A 13
B 99
C 2
D 2
E 44
F 32
G 2
H 9


**********
Example output:
**********

First Fit:
******************************************

Attempting to load process:A size:13

1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 1, #holes = 1, memusage = 10.16, cumulative mem = 13.00

Attempting to load process:B size:99

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 2, #holes = 1, memusage = 87.50, cumulative mem = 62.00

Attempting to load process:C size:2

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 3, #holes = 1, memusage = 89.06, cumulative mem = 79.00

Attempting to load process:D size:2

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 4, #holes = 1, memusage = 90.62, cumulative mem = 88.00

Attempting to load process:E size:44
Swapping process:A starting Address:0 Ending Address:13

Attempting to load process:E size:44
Swapping process:B starting Address:13 Ending Address:112

Attempting to load process:E size:44

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 3, #holes = 2, memusage = 37.50, cumulative mem = 80.00

Attempting to load process:F size:32

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 4, #holes = 2, memusage = 62.50, cumulative mem = 80.00

Attempting to load process:G size:2

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 5, #holes = 2, memusage = 64.06, cumulative mem = 80.00

Attempting to load process:H size:9

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 6, #holes = 2, memusage = 71.09, cumulative mem = 82.00

Attempting to load process:A size:13

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 
0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 7, #holes = 2, memusage = 81.25, cumulative mem = 84.00

Attempting to load process:B size:99
Swapping process:C starting Address:112 Ending Address:114

Attempting to load process:B size:99
Swapping process:D starting Address:114 Ending Address:116

Attempting to load process:B size:99
Swapping process:E starting Address:0 Ending Address:44

Attempting to load process:B size:99
Swapping process:F starting Address:44 Ending Address:76

Attempting to load process:B size:99
Swapping process:G starting Address:76 Ending Address:78

Attempting to load process:B size:99
Swapping process:H starting Address:78 Ending Address:87

Attempting to load process:B size:99
Swapping process:A starting Address:87 Ending Address:100

Attempting to load process:B size:99

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 1, #holes = 1, memusage = 77.34, cumulative mem = 85.00

Attempting to load process:C size:2

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 2, #holes = 1, memusage = 78.91, cumulative mem = 87.00

Attempting to load process:D size:2

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 3, #holes = 1, memusage = 80.47, cumulative mem = 88.00

Attempting to load process:E size:44
Swapping process:B starting Address:0 Ending Address:99

Attempting to load process:E size:44

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 3, #holes = 2, memusage = 37.50, cumulative mem = 85.00

Attempting to load process:F size:32

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 4, #holes = 2, memusage = 62.50, cumulative mem = 85.00

Attempting to load process:G size:2

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 5, #holes = 2, memusage = 64.06, cumulative mem = 84.00

Attempting to load process:H size:9

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 
0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 6, #holes = 2, memusage = 71.09, cumulative mem = 85.00

Attempting to load process:A size:13

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 
0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 7, #holes = 2, memusage = 81.25, cumulative mem = 86.00

Attempting to load process:B size:99
Swapping process:C starting Address:99 Ending Address:101

Attempting to load process:B size:99
Swapping process:D starting Address:101 Ending Address:103

Attempting to load process:B size:99
Swapping process:E starting Address:0 Ending Address:44

Attempting to load process:B size:99
Swapping process:F starting Address:44 Ending Address:76

Attempting to load process:B size:99
Swapping process:G starting Address:76 Ending Address:78

Attempting to load process:B size:99
Swapping process:H starting Address:78 Ending Address:87

Attempting to load process:B size:99

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 0 0 0 0 1 1 
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 2, #holes = 2, memusage = 87.50, cumulative mem = 87.00

Attempting to load process:C size:2

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 0 0 1 1 
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 3, #holes = 2, memusage = 89.06, cumulative mem = 89.00

Attempting to load process:D size:2

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 4, #holes = 2, memusage = 90.62, cumulative mem = 90.00

Attempting to load process:E size:44
Swapping process:A starting Address:103 Ending Address:116

Attempting to load process:E size:44
Swapping process:B starting Address:0 Ending Address:99

Attempting to load process:E size:44

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 3, #holes = 2, memusage = 37.50, cumulative mem = 88.00

Attempting to load process:F size:32

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 4, #holes = 2, memusage = 62.50, cumulative mem = 88.00

Attempting to load process:G size:2

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 5, #holes = 2, memusage = 64.06, cumulative mem = 87.00

Attempting to load process:H size:9

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 
0 0 0 0 0 0 0 0 0 1 1 1 1 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
pid loaded, #processes = 6, #holes = 2, memusage = 71.09, cumulative mem = 87.00

******************************************
First Fit ended:
Total loads = 24, average #processes = 3.00, average #holes = 1.00, cumulative mem = 87.00



Press enter when ready for next simulation...


