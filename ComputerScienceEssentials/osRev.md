Below is a **concise but interview-oriented Operating Systems revision sheet**. It focuses on **conceptual clarity + mental models + small examples**, which are commonly expected in **systems engineer / infrastructure interviews**.

---

# Operating Systems – Revision Sheet

---

# 1. What is a Process?

A **process** is a **program in execution**.

It includes:

```text
Program code
Current CPU state
Memory
Open files
OS resources
```

A process is **not just the program file**, but the **running instance** of it.

---

### Process Components

Each process contains:

| Component       | Description                     |
| --------------- | ------------------------------- |
| Program Counter | address of next instruction     |
| Registers       | CPU execution state             |
| Stack           | function calls, local variables |
| Heap            | dynamic memory                  |
| Data segment    | global variables                |
| Text segment    | program instructions            |

---

### Process Control Block (PCB)

The OS tracks processes using a **PCB**.

Contents include:

```text
Process ID
Program counter
CPU registers
Scheduling info
Memory info
Open files
```

The **PCB is stored in kernel memory**.

---

# 2. System Calls

System calls are the **interface between user programs and the OS kernel**.

User programs cannot access hardware directly. They must request services from the kernel.

---

### Flow of a System Call

```text
User Program
   ↓
System Call Interface
   ↓
Kernel Mode Execution
   ↓
Return to User Mode
```

---

### Common System Calls

File operations:

```c
open()
read()
write()
close()
```

Process control:

```c
fork()
exec()
wait()
exit()
```

Memory management:

```c
mmap()
brk()
```

IPC:

```c
pipe()
socket()
```

---

### Example

```c
write(1, "hello", 5);
```

Meaning:

```text
write to file descriptor 1 (stdout)
```

---

# 3. Example Implementation of a Shell

A shell repeatedly:

```text
read command
create process
execute program
wait for completion
```

---

### Simplified Shell Example

```c
while (1) {

    printf("shell> ");

    char command[100];
    scanf("%s", command);

    pid_t pid = fork();

    if (pid == 0) {
        execlp(command, command, NULL);
    } else {
        wait(NULL);
    }
}
```

---

### Key System Calls Used

```text
fork()  → create process
exec()  → run new program
wait()  → wait for child
```

---

# 4. File Descriptor Tables

Every process maintains a **file descriptor table**.

A file descriptor is a **small integer representing an open file**.

---

### Default File Descriptors

| FD | Meaning |
| -- | ------- |
| 0  | stdin   |
| 1  | stdout  |
| 2  | stderr  |

---

### Structure

```
Process
  ↓
File Descriptor Table
  ↓
Open File Table (kernel)
  ↓
Actual File
```

Multiple processes can **share the same open file entry**.

---

### Example

```c
int fd = open("data.txt", O_RDONLY);
read(fd, buffer, 100);
```

---

# 5. Interprocess Communication (IPC)

Processes often need to **communicate or synchronize**.

IPC mechanisms include:

```text
Pipes
Shared memory
Message queues
Sockets
Signals
```

---

### IPC Types

| Type          | Speed   |
| ------------- | ------- |
| Shared Memory | fastest |
| Pipes         | medium  |
| Sockets       | slower  |

---

# 6. IPC Using Pipe

A **pipe** provides **unidirectional communication** between processes.

---

### Creating a Pipe

```c
int fd[2];
pipe(fd);
```

Meaning:

```text
fd[0] → read end
fd[1] → write end
```

---

### Example

```c
pipe(fd);

if (fork() == 0) {
    write(fd[1], "hello", 5);
}
else {
    char buf[10];
    read(fd[0], buf, 5);
}
```

Parent reads what child writes.

---

# 7. Address Space of a Process

Each process has its **own virtual address space**.

Typical layout:

```
High Address
----------------
Stack
----------------
Heap
----------------
BSS
----------------
Data
----------------
Text (Code)
----------------
Low Address
```

---

### Meaning

* processes cannot access each other's memory
* OS provides **memory isolation**

---

# 8. Signals and Signal Handlers

Signals are **software interrupts** sent to processes.

Example events:

```text
Ctrl+C
segmentation fault
timer expiration
```

---

### Common Signals

| Signal  | Meaning            |
| ------- | ------------------ |
| SIGINT  | interrupt          |
| SIGKILL | force terminate    |
| SIGSEGV | segmentation fault |
| SIGTERM | termination        |

---

### Signal Handler Example

```c
void handler(int sig) {
    printf("Signal received\n");
}

signal(SIGINT, handler);
```

Now pressing **Ctrl+C** triggers the handler.

---

# 9. Threads

A thread is a **lightweight execution unit inside a process**.

Threads share:

```text
code
heap
global variables
```

Each thread has its own:

```text
stack
registers
program counter
```

---

### Example

Web server:

```text
Thread 1 → client A
Thread 2 → client B
Thread 3 → client C
```

Advantages:

* parallelism
* lower overhead than processes

---

# 10. Kernel Threads vs User Threads

### Kernel Level Threads

Managed by OS kernel.

Example: POSIX threads.

Advantages:

* true parallelism
* OS scheduling

Disadvantages:

* slower creation

---

### User Level Threads

Managed by user library.

Kernel sees only **one process**.

Advantages:

* faster context switch

Disadvantages:

* blocking system call blocks all threads

---

# 11. How a C Program Is Loaded

Compilation pipeline:

```
C Source Code
    ↓
Compiler
    ↓
Assembly
    ↓
Assembler
    ↓
Object File
    ↓
Linker
    ↓
Executable
```

---

### Execution Steps

```
User runs program
      ↓
Kernel loader loads executable
      ↓
Memory segments created
      ↓
Program counter set to main()
```

---

### Program Layout

```
Text segment
Data segment
BSS
Heap
Stack
```

---

# 12. Physical Address Space Division

Physical memory is divided between:

```
Kernel space
User space
```

Example (32-bit Linux):

```
0x00000000 - 0xBFFFFFFF → user
0xC0000000 - 0xFFFFFFFF → kernel
```

Kernel space contains:

```text
kernel code
device drivers
page tables
```

---

# 13. Virtual to Physical Address Translation

Processes use **virtual addresses**.

Actual memory uses **physical addresses**.

Translation is done by **MMU (Memory Management Unit)**.

---

### Address Translation

```
Virtual Address
      ↓
Page Table Lookup
      ↓
Physical Address
```

---

### Example

```
Virtual Address = 0x00401234
Page number = 0x00401
Offset = 0x234
```

Page table maps it to a **physical frame**.

---

# 14. MMU and Segmentation

Segmentation divides memory into **logical segments**.

Examples:

```text
Code
Data
Stack
Heap
```

Each segment has:

```text
base address
limit
```

---

### Address Translation

```
Logical Address = Segment + Offset
```

MMU checks:

```
physical = base + offset
```

---

### Global Descriptor Table (GDT)

Used by x86 CPUs.

Contains descriptors describing:

```text
base
limit
permissions
```

Segments are referenced by **segment selectors**.

---

# 15. Interrupts and Interrupt Handling

Interrupts allow hardware to **notify CPU about events**.

Examples:

```text
keyboard input
network packet
timer interrupt
disk IO
```

---

### Interrupt Handling Flow

```
Interrupt occurs
      ↓
CPU saves current state
      ↓
Switch to kernel mode
      ↓
Execute interrupt handler
      ↓
Restore state
      ↓
Resume process
```

---

### Interrupt Vector Table

Maps interrupt numbers to handlers.

Example:

```
Interrupt 0 → divide by zero
Interrupt 14 → page fault
```

---

# 16. User Mode vs Kernel Mode

CPUs support **two privilege modes**.

---

### User Mode

Used for:

```text
applications
```

Restrictions:

* cannot access hardware
* cannot modify kernel memory

---

### Kernel Mode

Used for:

```text
operating system
device drivers
```

Full hardware access.

---

# Context Switch

When CPU switches between processes:

```
Save current registers
Save program counter
Load new process registers
Resume execution
```

State stored in **PCB**.

---

# Interrupt Handling and Mode Switch

Example:

```
Process running (user mode)
      ↓
System call or interrupt
      ↓
CPU switches to kernel mode
      ↓
Kernel executes handler
      ↓
Return to user mode
```

---

# Where Data Is Stored During Context Switch

Saved in:

```
Process Control Block
Kernel stack
```

Registers saved include:

```
program counter
general registers
stack pointer
flags
```

---
