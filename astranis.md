## How many bits are set (high) in 0xfeedc0ffee? (How did you calculate it?)

29.
Converted from hex to int, then calculated using C++ and the __popcnt() function in a simple c++ shell on cpp.sh. (Also confirmed by a straight conversion into binary, and counted the ones.) 


## You try to use a serial USB adapter, but your command fails with: "FATAL: cannot open /dev/ttyUSB0: Permission denied". How do you fix this issue?

Looks like a linux command, and we literally do not have permission to access whatever's at the location.  Happens all the time; I'd first just try "sudo" in front of the command, and enter login credentials when prompted.  


## What will this pseudo-code print, and why? https://i.imgur.com/6n6aEzm.png

//IF deadlock protection is enabled  

"Foo!" // thread F1 fires on its own thread, prints and locks m1/m2.  
"Baz!" // thread F2 fires second on its own thread and prints.  
"Bar!" // F2 checks for m1/m2, they're locked!  F2 waits. F1 completes.  
"Qux!" // F2 wakes and completes.  

//IF deadlock protection is not enabled  

"Foo!" // thread F1 fires on its own thread, prints and locks m1.  
"Baz!" // thread F2 fires second on its own thread and prints and locks m2.  
//output ends, F2 and F1 are in deadlock, each holding one resource and requiring the other.  

## This state machine ( https://i.imgur.com/5srBQsG.png ) reads input character by character and accepts strings if it is in state S6. Its goal is to accept a string if it contains a certain substring. What strings will it accept? Will it always achieve its goal? If not, how would you improve it?

Accept any string with the substring "ninja" in it.  
It will not always achieve its goal, for example, the input string "nninja" would fail.  This is not the state machines fault, it's doing what we told it too.  A state machine can only read, move, and accept in one atomic unit.  So on the string "nninja" (from s1) it would read 'n', move to s2.  Then it would read 'n' and move back to s1, from this point never completing its true goal of accepting ninja as it is now on the character 'i'. 
I would improve it by adding a line at s2, if its an 'n', come back to s2.


## Our satellite records telemetry such as battery status, temperatures, and reboot count once per second. How would you store this data on the spacecraft for periodic downlink? How would you handle limited storage space and/or downlink bandwidth?

If we logged only three variables once a second, assuming downlink every hour we would have 10,800 variables to transmit and store (3 * 60 * 60).   That's a lot, looking at the limitations of deep space communication; we would be transmitting our data over Radio Frequency to a deep space network, and be limited to packet sizes in the kilobyte range. 
So access and seek time take a back seat to space complexity.
For reboot count, an unsigned short int to store values up to 65,535 (because we want something large enough to log if we are rebooting every second, repeatedly, constrained by our downlink broadcast time, but we don't need negative numbers).  
For battery status we only want a number capable of storing a positive integer between 0-100; so a char is perfect, clocking in at 8 bits.  Each number translates to a different status code, which we keep in a table or hashmap either locally or locally and remotely to identify each code meaning.  
Temperature is more variable, and it would be nice to have both negative and positive numbers as well, because we're in space, but we don't need to record values past the temperature at which metal turns to liquid, so a signed short int is fine (-32,767, +32,767) assuming we don't need decimals and floats.

Then we store this data in a hashmap indexed by timestamp (insertion O(1) and space O(n)).

Downlink bandwidth is an even harder problem!  Sure, we've taken some values and put them in small containers, great.  But how can we squeeze the size down smaller for transfer?  I would use a bitset to translate these stored variables into binary strings of data, indexed by timestamp -- we don't need to keep them human readable in transmission, and we're broadcasting empty data for every char and int data structure; why send "0000 0000 0000 0010" when we could send "10"?

## Our satellite telemetry log files contain timestamped battery status, temperatures, and reboot count. What other parameters would you want in a log file? What tools would you use to examine this data?

Fault detection, Any correction routines that have been run, antenna direction, signal strength, noise and signal degradation.  An immediate tool I would want is a full database, to look at potentially multiple years of data in a more cohesive format, with a shell where I could create full queries.  Is the battery losing power more quickly this month, versus last month?  How many faults of a particular type have been detected, since the last software update? 


## We leverage https://github.com/EnterpriseQualityCoding/FizzBuzzEnterpriseEdition as a core part of our internal infrastructure. How would you enhance this project to make it web-scale?

FizzBuzz, the enterprise edition holds quite a few lines of code.   It uses a gradle wrapper and is coded in Java, which are interesting choices.  It imports quite a few libraries and enforces it's Main.java with final's and uses pointers that reference to factories, which eventually get to the actual business of solving what is inherently an incredibly simple problem.  
The trouble with making things web-scale is that they need to be fast, efficient, and not overbuilt past the scope of the problem they are trying to solve.  If we wanted to enhance this project to make it web-scale, we would need to strip it down to it's roots, perhaps even changing the language that its written in from Java to Python or C.  Java is a powerful and excellent framework for serious problems  (and this isn't one of those).  Reduce or eliminate the libraries to decrease compiling time, rip out most of the extraneous code and decide in advance, what do *our* users need most out of the implementation?  
There are many different solutions to fizzbuzz, but which one is right, for our usage requirements?  Streamlining is impossible for all scenarios, and fortunately we don't have to do that.  We only have to decide what we need in our company's web-scaled implementation.   
I would choose the solution that optimized for our usage, and then add more documentation to ensure that future coders could understand, follow, and change the codebase as our needs changed over time.