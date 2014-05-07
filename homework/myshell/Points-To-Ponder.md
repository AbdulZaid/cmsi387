##Points To Ponder

Q(1): Why did the cd command get special mention in this assignment? 

First, I know that the command cd is a shell built-in, but why does it have to be built in? 
Well, the reason why the cd command got special mention because exec() tend to look for an executable file to run under the name of the command passed in. However, cd is different from most of the other commands because it doesn't have an executable file. It is just the fact that the pointer to which directory the shell is in,changes or gets updated to the first argument passsed in after cd. Therefor, the exec() will not be able to handle the cd command because it doesn't fit the qualities necessary for exec() to run it.

Q(2): Can your shell run scripts? Why or why not?

Well, Yes my shell can run scripts, as long as those scripts are not regular languages. Also, the shell deals ok with commands such as, (ls, ls -l, pwd, cd .., pwd, ps aux), and that's to say if the script is consisting of commands then yes the shell will run the script. Finally, the shell knows how to pass things to execvp(), or call a system call.

Q(3): Does Ctrl-D exit your shell? Why or why not?

 Yes Ctrl-D exits the shell because the while loop keeps going until it finds an End of File character.
