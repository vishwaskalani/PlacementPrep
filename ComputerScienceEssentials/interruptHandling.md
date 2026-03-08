Great question — this is *core OS + computer architecture* knowledge and very important for interviews (especially systems / trading systems roles).

Let’s walk through **exactly what happens when an interrupt occurs**, step by step, including:

* Program Counter (PC) changes
* Register saving
* Stack usage
* Address space switch
* Mode switch (user → kernel)
* Context switching (if it happens)

We’ll assume a typical modern CPU (like x86-64) and a Unix-like OS (e.g., Linux).

---

# 0️⃣ First: What Is an Interrupt?

An **interrupt** is a signal to the CPU that something needs immediate attention.

Types:

1. **Hardware interrupt** – keyboard, network card, timer
2. **Software interrupt / trap** – system call
3. **Exception** – divide by zero, page fault

---

# 1️⃣ Initial State (Before Interrupt)

Assume:

* A **user process** is running
* CPU is in **user mode**
* Using:

  * User virtual address space
  * User stack
* Registers contain:

  * `PC` → next user instruction
  * `SP` → user stack pointer
  * General-purpose registers (RAX, RBX, etc.)

Example state:

```
Mode = User
PC = 0x400540
SP = 0x7fffabcd
CR3 = user page table base
```

---

# 2️⃣ Interrupt Occurs (Hardware Signals CPU)

Let’s say:

* Timer interrupt fires.

The CPU does NOT ask the OS first.
It reacts in hardware.

---

# 3️⃣ CPU Hardware Automatically Performs These Steps

This part is done **entirely by hardware**.

### Step 3.1: Finish Current Instruction

CPU completes the current instruction (interrupts are precise).

---

### Step 3.2: Switch to Kernel Mode

CPU flips:

```
CPL (Current Privilege Level)
User (3) → Kernel (0)
```

This is critical:

* User code cannot execute privileged instructions.
* Interrupt handler must run in kernel mode.

---

### Step 3.3: Switch Stack (Very Important)

Each process has:

* User stack
* Kernel stack

When interrupt happens from user mode:

CPU switches:

```
Old: user stack
New: kernel stack of current process
```

How?

* OS stores kernel stack pointer in a per-process structure.
* CPU loads kernel stack pointer automatically.

Now:

```
SP = top of kernel stack
```

---

### Step 3.4: Save Minimal Context (Automatically)

CPU pushes onto **kernel stack**:

```
Old SS (stack segment)
Old SP
RFLAGS
CS (code segment)
Old PC
```

So kernel stack now contains:

```
| Old SS |
| Old SP |
| RFLAGS |
| CS     |
| Old PC |
```

This is the minimum needed to return later.

⚠️ Important:
The old PC is saved so we can resume user program exactly.

---

# 4️⃣ CPU Looks Up Interrupt Handler

CPU uses:

```
Interrupt Descriptor Table (IDT)
```

* Each interrupt number has an entry
* Entry contains:

  * Address of handler
  * Privilege level
  * Segment selector

CPU does:

```
PC = address_of_interrupt_handler
```

So now execution jumps to:

```
kernel_interrupt_handler()
```

We are now executing in:

* Kernel mode
* Kernel address space
* On kernel stack

---

# 5️⃣ Kernel Prologue: Save Remaining Registers

The hardware only saved minimal state.

Now the OS must save:

```
RAX, RBX, RCX, RDX, RSI, RDI...
```

This is done by assembly at the beginning of handler:

```asm
push rax
push rbx
push rcx
...
```

Now full CPU context is saved on kernel stack.

This saved structure is often called:

```
trap frame
```

---

# 6️⃣ Now Kernel Executes Interrupt Handler

Example: Timer interrupt.

Kernel might:

* Increment system tick
* Update scheduler
* Decide to preempt current process

---

# 7️⃣ Address Space Situation

Very important concept.

### Are we using user address space?

Yes — but in a special way.

Modern OSes:

* Kernel is mapped into every process's address space.
* But user cannot access it (protected via page permissions).

So:

```
CR3 = still user page table
```

But:

* Kernel pages are mapped at high memory
* User pages mapped at low memory

So when interrupt handler runs:

* Same page table
* But executing kernel-only pages

No page table switch yet.

---

# 8️⃣ Scheduler May Run (Preemption Case)

If this interrupt triggers scheduling:

Kernel does:

```
schedule()
```

Now things get interesting.

---

# 9️⃣ Context Switch Happens (If Needed)

Suppose scheduler decides:

```
Switch from Process A → Process B
```

Steps:

---

## Step 9.1: Save Current Process State

Kernel stores:

* Saved registers
* Saved kernel stack pointer
* Saved PC

Into:

```
Process Control Block (PCB)
```

---

## Step 9.2: Switch Address Space

Now:

```
CR3 = page table base of Process B
```

This changes:

* Virtual → physical mapping
* TLB flushed (usually)

Now entire memory view changes.

---

## Step 9.3: Switch Kernel Stack

Kernel loads:

```
SP = Process B’s kernel stack pointer
```

---

## Step 9.4: Restore Registers of Process B

Pop registers from B's saved trap frame.

---

## Step 9.5: Return From Interrupt

CPU executes:

```
iret (or iretq)
```

This instruction:

* Pops PC
* Pops CS
* Pops RFLAGS
* Pops SP
* Pops SS
* Switches back to user mode

Now:

```
PC = Process B’s user instruction
Mode = User
Address space = Process B
```

Process B is now running.

---

# 🔁 If No Context Switch Happens

Then:

* Kernel restores registers
* Executes `iret`
* Returns to same process

Execution continues from exact saved PC.

---

# 🔎 Complete Timeline Summary

Let’s compress everything:

```
User process running
        ↓
Interrupt signal
        ↓
Finish instruction
        ↓
Switch to kernel mode
        ↓
Switch to kernel stack
        ↓
Push minimal context (PC, flags, etc.)
        ↓
Jump to interrupt handler
        ↓
Kernel saves remaining registers
        ↓
Run handler
        ↓
(Optional) Run scheduler
        ↓
(Optional) Switch address space (CR3)
        ↓
Restore registers
        ↓
iret
        ↓
Back to user mode
```

---

# 🧠 Critical Concepts to Remember

### 1️⃣ Interrupt does NOT automatically switch process

Only scheduler does.

---

### 2️⃣ Mode switch ≠ Context switch

| Mode Switch   | Context Switch |
| ------------- | -------------- |
| User → Kernel | Process A → B  |
| Cheap         | Expensive      |

---

### 3️⃣ Address Space Change Happens Only During Context Switch

Not during every interrupt.

---

### 4️⃣ Stack Behavior

| Before     | After interrupt |
| ---------- | --------------- |
| User stack | Kernel stack    |

Each process has its own:

* User stack
* Kernel stack

---

# ⚡ Performance Insight (Important for trading systems)

Interrupt cost includes:

* Pipeline flush
* Register save
* Possible TLB flush (if context switch)
* Cache pollution

That’s why:

* High-frequency systems minimize interrupts
* Use polling sometimes

---

# 🎯 Interview-Grade Explanation (Short Version)

When an interrupt occurs:

1. CPU completes current instruction.
2. Hardware switches to kernel mode.
3. CPU switches to process’s kernel stack.
4. Minimal state (PC, flags, etc.) is pushed.
5. CPU jumps to interrupt handler via IDT.
6. OS saves remaining registers.
7. Handler runs.
8. If scheduler decides:

   * Save PCB
   * Switch CR3
   * Switch kernel stack
   * Restore new process context
9. `iret` restores user state and resumes execution.

---