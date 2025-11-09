# Basic gdb commands to debug C++ program

- Compiling the program with debug information:
```bash 
g++ -g -o my_program my_program.cpp
```
- Starting gdb with the compiled program:
```bash
gdb ./my_program
```
- Running the program inside gdb:
```gdb
(gdb) run
```
- Setting a breakpoint at a specific line number:
```gdb
(gdb) break 25
```	
- Setting a breakpoint at a specific function:
```gdb
(gdb) break my_function
```
- Continuing execution until the next breakpoint:
```gdb
(gdb) continue
```
- Stepping through the program line by line:
```gdb
(gdb) step
```
- Stepping over function calls:
```gdb
(gdb) next
```
- Printing the value of a variable:
```gdb
(gdb) print my_variable
```
- Displaying the call stack:
```gdb
(gdb) backtrace
```
- Exiting gdb:
```gdb
(gdb) quit
```
- Additional useful commands:
  - List source code around the current line:
  ```gdb
  (gdb) list
  ```
  - Watch a variable for changes:
  ```gdb
  (gdb) watch my_variable
  ```
  - Inspect memory at a specific address:
  ```gdb
  (gdb) x/10x &my_variable
  ```