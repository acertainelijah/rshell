# rshell
cs100 assignment


## Description
This program is a replica of a command shell. It executes commands located in /bin in addition
to our programmed "exit" command.

### Features
- connects commands together using connectors &&, ||, and ;
    * && - next command is executed only if the first one succeeds
    * || - next command is executed only if the first one fails
    * \ - next command is always executed
    * Example:
    ~~~
    $ echo a; ls -a && git status || clear
    ~~~
- special built-in command of exit that terminates rshell
~~~
$ exit
~~~
- handles comments. Any input after # is considered a comment
~~~
$ ls -a #this is a comment
~~~
- error message is displayed for invalid/failed input
~~~
$ tacos #this fails and outputs error
~~~
- Can use the test command for checking the validity of a file or directory
    * Example: (if we have a.out)
    ~~~
    dwhel001@hammer.cs.ucr.edu$ test -e a.out
    (True)
    dwhel001@hammer.cs.ucr.edu$ test -f a.out
    (True)
    It's a file.
    dwhel001@hammer.cs.ucr.edu$ test -d a.out
    (False)
    dwhel001@hammer.cs.ucr.edu$ [ -e a.out ]
    (True)
    dwhel001@hammer.cs.ucr.edu$ [ -f a.out ]
    (True)
    It's a file.
    dwhel001@hammer.cs.ucr.edu$ [ -d a.out ]
    (False)
    ~~~
- Can use parenthesis to instantiate precedence
  * Example:
  ~~~
  dwhel001@hammer.cs.ucr.edu$ (echo a && (echo b && (echo c)))
  a
  b
  c
  dwhel001@hammer.cs.ucr.edu$ exit
  ~~~

## BUGS
### Object bugs
- expected type-specifier before ‘Semicolon’

### Command bugs:
- ls wont work after mkdir
- bad address error after a command fails
- exit will sometimes not execute properly if many commands have been inputted.
    * Example: We dont know why...
    ~~~
    $ ./a.out
    $ ls
    $ mkdir a
    $
    $ ls
    $ rm -r a
    $ ls
    $ mkdir a
    $ ls
    $ rm -r a
    $ exit
    $ exit
    Shell terminates on the second input of exit here.
    ~~~


### Prompt bugs:
- the commands would stack on top of each other inside the vector, causing no commands to work. (FIXED)

###Comment bugs
- .find() not working to find "#" (Fixed using string::npos)

### Parenthesis bugs:
- Examples such as (ls) && (echo a) will not work. We do not know why.
    * Example:
    ~~~
    dwhel001@hammer.cs.ucr.edu$(echo a) && (echo b)
    a
    dwhel001@hammer.cs.ucr.edu$
    ~~~
