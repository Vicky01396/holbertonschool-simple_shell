# Simple Shell in C#
Simple command interpreter UNIX.

## Description
This code implements a very basic shell that allows command execution on Unix-based operating systems. The functionality of this shell includes the ability to display the prompt, read and parse user input, and execute commands entered by the user.

## Flowchart
![image](https://user-images.githubusercontent.com/124283901/235261395-c00c5d58-ea75-4337-a7f3-a4b1c5c2fe94.png)

## How it works
If you want to use this basic Unix command interpreter, the first thing you should do is clone the repository:

How to clone the repository?

* In the terminal run the command git clone next to the url of the repository in github.

After that you should compile with:

* gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Placing the previous command in the terminal, the executable hsh will be created, to execute it use:

* ./hsh

Once this is done you will be in the command interpreter, you can use for example the following commands:
* ls
```
$ ls
README.md  _execve.c  _get_path.c  hsh  main.h  simple_shell.c  tkn.c
$
```
* pwd
```
$ pwd
/root/holbertonschool-simple_shell-2
$
```
* clear

Before clear
```
$ ls
README.md  _execve.c  _get_path.c  hsh  main.h  simple_shell.c  tkn.c
$ pwd
/root/holbertonschool-simple_shell-2
$ ls
README.md  _execve.c  _get_path.c  hsh  main.h  simple_shell.c  tkn.c
$ clear
```
After clear
```
$
```
* exit
```
$ ls
README.md  _execve.c  _get_path.c  hsh  main.h  simple_shell.c  tkn.c
$ exit
root@c504d64e290e4ba88c969f38355daadd-2377118072:~/holbertonschool-simple_shell-2#
```
* env (Print all of the environ variables)

Also commands whit arguments:

* touch *filename
* echo *printext
* mkdir *arguments *dirname
* and others

## Bugs
Multiple commands cannot be performed on the same line.

Status values returned in certain cases are erroneous.

## These are some important shell function
* simple_shell()
This main function contains the main shell loop. It reads the user input, parses it and executes the entered commands. If the user enters the command "exit", the program terminates.
* tkn()
This function take the imput and tokenizes whit a delimitator "\n\t ", saves the tokens in a array of tokens and return this array.
* _execve()
This function is called when the shell need execute a command, recognize if the command is valid, create a child proccess, the father procces wait a status, execute the command, kill the child proccess and return the status to the main function.
* _get_path()
This function find the envirion variable called PATH, save and return the PATH variable.
* findexpath()
This function is called in the _execve() function if the command don't have /bin, the function find the command called using the PATH, check the permissions of the file and if success return the command path.
* free_grid()
The function frees the contents of an array of pointers and before terminating it frees the array itself.

## If you need to write to us, here are our contacts
* José Moreno - joseignaciomorenocamargo000@gmail.com
* Victoria Coria - Vicky.c_96@hotmail.com
