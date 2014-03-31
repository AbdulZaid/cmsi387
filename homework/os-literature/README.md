#All of Time and Space

Continue our journey through seminal operating systems literature by using library resources (digital or otherwise) to find at least three additional publications (also digital or otherwise) that are related to and/or build upon the work given out in class. For each found publication:

• State its connection to the other work in our small collection—the connection must be explicit (i.e., cited and overtly discussed in the text). Connections may be to the other work that you find, but at least one must point to something given out in class.
  
• State what it does new or differently from the prior cited works.
  
• Give a brief assessment of the quality of the work. Consider the authors, the publication venue, the level of detail, references cited, etc.

####The First Article: "A new solution to the critical section problem" By Howard P. Katseff"

(1)  This article by Howard P. Katseff is directly related to our subject of Process Synchronization, and mainly on Critical Section Structure.  It is related because it's based on expanding the solutions of Djiksta's, Knuth's, and Eisenberg and McGuire's solution. Moreover, as stated in the introduction "The solution presented here improves on previous solutions by allowing processes to enter their critical sections on a first-come first-served basis."

(2)  Howard's solution for first-come first-serve processes is very efficient. The reason is because it manages to solve  the problem where certain processes that might die (more than once) and emerge again may prevent other processes from entering their critical sections. Moreover, what makes Howard's solution more interesting, is that his way does not require variables which assume arbitrarily large values.
Further more in Howard's paper, he mentions how he expands the solution done by Eisenberg and McGuire's by considering a certain example that shows that "each process will be in the other's behind-of list." 
This example resulted in Howard solving this problem by adding or using additional variables to determine which process has last begun its protocol. For example, When a certain process `i` is dead or not contending for its critical section, its `n` variables are set to be all zeros. But, when a certain process `i` is in its protocol, these `n` variables are set to values from 1 and 3. Finally, A `for` loop is used to make sure that any process that has entered its protocol after the process `i` does not belong on `i`'s behind-of list.
          

(3)  The author Howard Paul Katseff has 12 articles published on the ACM's Digital Library which shows how successful and committed this person is to the academic research and discussion of computer science. He did graduate work in program size complexity at the University of California, Berkeley and received his Ph.D. in 1978. More, in 1978, he became a Member of Technical Staff at Bell Telephone Laboratories in Holmdel, New Jersey. This of course adds some weight to the paper.  He also as stated in the AT&T Researchers website, created sdb, the first debugger that allowed the use of source-language variable names, and he also developed algorithms for two-dimensional bin packing, and  pioneered work in multiprocessor computer systems, and now he's on top of the AT&T research team. Finally, as seen in his article, he does an amazing job of choosing the right test cases to show the problems with previous solutions.


####The Second Article: "Efficient semaphore management using read/modify/write memory cycles" By Richard M. Weatherly and James F. Leathrum.

(1)  This article by Richard M. Weatherly, and Jr. James F is directly related to the problem introduced by Dijkstra because it deals with the issue of wasting the processor time.  Furthermore, as they have mentioned in their article that when an operation is attempted to be passed on a blocked semaphore, two things can happen "1) The blocked process remains active in a 'busy wait' condition continually testing the semaphore or 2) the process is deactivated freeing the processor to do other useful work." This can make unnecessary memory accesses by wasting the processor time and limiting the availability of the semaphore, and also, as discussed this 'busy wait' solution is undesirable.


(2)  The authors Richard M. Weatherly, and Jr. James F introduced their system for managing semaphore signals so that any process being on wait knows a more detailed status of the process that's in the processor and therefore the processor can determine whether or not a process has a good chance of being successful or not, which means "no busy waits". Therefore, this method is new in relation to Dijkstra's paper because it changes the way a process taking up processor time while it's not doing any computing.

Finally I want to share what they have concluded their article with, as it summarizes the idea that's been introduced, and discussed. They stated that "there are wait loops in this scheme. There are no busy waits, however. A process requesting access to a semaphore during Queue Pointer update knows it is waiting on a definite operation, taking a known length of time. Therefore, a wait period, in which other useful work may be done, can be calculated to give a good probability of success on the retry."

(3)  The authors Richard M. Weatherly, and Jr. James F. Leathrum has a sum of 37 publications, the later is 17. However, this make the quality of this work good because the authors are published in the ACM which is a widely read Article Database. Both authors are have done their work at Clemson University. Finally, one more good thing I noticed, is that they take the time to set up the background explaining Dijkstra's problem, which makes you understand the underlying problem clearly and then introducing their new idea, and solutions.
