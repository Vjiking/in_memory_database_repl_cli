# In-Memory Key-Value Database (CLI / REPL)

A command-line, in-memory key-value store built in C. 

## Features

- `SET <key> <value>` — store a key-value pair (updates it if the key already exists)
- `GET <key>` — retrieve the value for a key, or `(nil)` if it doesn't exist
- `DEL <key>` — delete a key, or report an error if it isn't found
- `EXISTS <key>` — returns `1` if the key exists, `0` otherwise
- `SAVE <filename>` — writes the current in-memory data to a file on disk
- `LOAD <filename>` — restores data from a previously saved file
- `EXIT` — quits the program

## How to Run

You'll need a C compiler (`gcc`) and a terminal. No IDE is required.

Clone the repository and go into the folder:
git clone <https://github.com/Vjiking/in_memory_database_repl_cli.git>
cd in_memory_database_repl_cli


Open a terminal in the project folder (the one containing `main.c`) and run:
gcc main.c -o main.exe
This compiles the source code into a standalone executable named `main.exe`. 
now run:
./main.exe
now you can type commands(you will se a > after which u can write commands)
## Example Usage

SET name vj
OK
GET name
vj
EXISTS name
1
DEL name
OK
GET name
(nil)
SET age 20
OK
SAVE data.txt
OK
EXIT

Reopening the program and running `LOAD data.txt` will restore any previously 
saved data from that file.