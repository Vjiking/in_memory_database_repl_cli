## How to Run

You'll need a C compiler (`gcc`) and a terminal. No IDE is required.

Clone the repository and go into the folder:
```
git clone https://github.com/Vjiking/in_memory_database_repl_cli.git
cd in_memory_database_repl_cli
```

Open a terminal in the project folder (the one containing `main.c`) and run:
```
gcc main.c -o main.exe
```
This compiles the source code into a standalone executable named `main.exe`.
Now run:
```
./main.exe
```
You'll see a `>` prompt — type commands after it.

## Example Usage

```
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
```
