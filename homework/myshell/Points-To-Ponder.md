##Points To Ponder

Q(1): Why did the cd command get special mention in this assignment? 

	 the cd command gets special mention because cd does't have an executable file, and it's rather a shell builtin. However, other commands and exec() tend to look for an executable file to run under the name of the command passed in.

> JD: Nope, the lack of an executable file is incidental (e.g., OS X has a `/usr/bin/cd`—go check).
>     The fact that it is a shell built-in is *precisely* why this question is being asked—why does
>     it *have* to be a shell built-in?  The real answer to this is not given here.

Q(2): Can your shell run scripts? Why or why not?

	 No, my shell doesn't run scripts. Because, it can only run specific commands, and their corresponding arguments. So, it only knows how to pass things to execvp(), or call a system call. This shell can't handle regular languages.

> JD: Yes, your shell can't handle regular languages...but there's nothing that says a script
>     *has* to be in a regular language.  Give your shell a little credit ;-)

Q(3): Does Ctrl-D exit your shell? Why or why not?

 	 Yes Ctrl-D exits the shell because the while loop keeps going until it finds an End of File character.

> JD: Yes, this one you got totally right.
