“CSI: Process"
=============
**TASK 1**

**BOTH SYSTEM IMAGES ARE UNDER THE FOLDER  "first-part"**

***The process was used during the compilation of the Sum program was "ping localhost."***

*Linux*

    second-screenshot.png

*Mac OS X*

    first-screenshot.png

**TASK 2**

**BOTH SYSTEM IMAGES ARE UNDER THE FOLDER  "second-part"**

*Linux*

    Linux1.png
         .
         .
         .
         .
         
    linux5.png
    
*Mac OS X*

    Activity-mac.png
    
    
**comparison**

***The major difference between Mac and Linux is that the display in general is
different, also they are different in displaying the threads.

***Mac displays the threads all under the % CPU tab, or it can display "sort" the threads under any tab the user prefers. Such as, CPU Time, threads, or pids. The total number of threads is displayed in the window, "bottom right" which make it easy for the user to know. 

***Linux displays all the threads as separate lines. Also, gives the threads the same process ID. In Linux, it doesn't show the total number of threads as in Mac.

> JD: Ah, it doesn't do that only *by default*.  There *is* a way to expose the
>     threads in Linux, and that was what I was hoping you would find.  Read the
>     `man` page for Linux `ps` more closely, and you'll see that it is there.

***A similarity between the two systems, is that the number of threads is updated as the process is being run.  That means the individual threads are deleted as necessary, when the arguments are being added to Sum.java.

***Both operating systems doesn't allow the threads to exist if they are no longer needed. Finally, on Mac the display is a live display whereas on Linux the command has to be run over again to see the update in the number of threads.

> JD: Meanwhile, yes, the rest of your observations work out nicely.
