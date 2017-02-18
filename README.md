# rshell
cs100 assignment

<<<<<<< HEAD

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


## BUGS
### Object bugs
- expected type-specifier before ‘Semicolon’

### Command bugs:
- ls wont work after mkdir
- bad address error after a command fails 

### Prompt bugs: 
- the commands would stack on top of each other inside the vector, causing no commands to work.

### Comment bugs
=======
# BUGS
##Command bugs:
- ls wont work after mkdir
- echo: bad address 

##prompt bugs: 
-the commands would stack on top of each other inside the vector, causing no commands to work.

##comment bugs
>>>>>>> e3987eec9475c95179bf787699d8f9313ce85191
- .find() not working to find "#"