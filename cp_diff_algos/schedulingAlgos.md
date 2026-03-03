## Job Scheduling — Mental Model

The single most important question to ask first:

```
Do I need to SELECT a subset of jobs?  →  Greedy or DP
Do I need to PROCESS all jobs?         →  Line Sweep or Sorting
```

---

## Classification by Problem Type

### 1. "Select jobs to maximize count" → **Sort by End Time + Greedy**

**When:** Pick maximum number of non-overlapping intervals.
**Why end time?** Finishing early leaves maximum room for future jobs.

**Algorithm:**
```
1. Sort jobs by end time
2. Greedily pick job if start >= last_end
3. Update last_end
```

**Problems:** Activity Selection, Meeting Rooms (max meetings), Non-overlapping Intervals (min removals = N - max_selected)

---

### 2. "Select jobs to maximize profit/weight" → **Sort by End Time + DP**

**When:** Each job has a value/profit, maximize total value of non-overlapping jobs.
**Why DP over greedy?** Greedy breaks when jobs have different weights — a high-value longer job might beat two short low-value jobs.

**Algorithm:**
```
1. Sort jobs by end time
2. For each job i:
   dp[i] = max(
       dp[i-1],                          ← skip job i
       profit[i] + dp[last_non_overlap]  ← take job i
   )
3. Binary search to find last_non_overlap (latest job ending ≤ start[i])
```

**Problems:** Weighted Job Scheduling, Maximum Profit Job Scheduling (LC 1235)

---

### 3. "Minimum resources needed (rooms/machines)" → **Sort by Start Time + Min-Heap**

**When:** How many parallel resources (meeting rooms, CPUs) are needed simultaneously?
**Why start time?** You assign a resource when a job *arrives*, not when it leaves.
**Why min-heap?** Always check if the earliest-finishing resource is free.

**Algorithm:**
```
1. Sort jobs by start time
2. Min-heap stores end times of active jobs
3. For each job:
   if heap.top() <= job.start → reuse that resource (pop)
   push job.end onto heap
4. Answer = max heap size seen
```

**Problems:** Meeting Rooms II, Task Scheduler (machines), Minimum Platforms (trains)

---

### 4. "Find overlaps / coverage / gaps" → **Line Sweep**

**When:** You need to know *how many* jobs are active at any point, or merge/count intervals.
**Why line sweep?** You care about events (start/end) at specific time points, not which jobs to pick.

**Algorithm:**
```
1. Create events: (time, +1) for start, (time, -1) for end
2. Sort events by time (ties: process ends before starts, or vice versa — problem-specific)
3. Sweep through, maintain running count
4. Track max count / detect overlaps / find gaps
```

**Tie-breaking rule:**
```
"Do [a,b] and [b,c] overlap?"  → ends before starts (count drops first)
"Do [a,b] and [b,c] share point b?" → starts before ends (count rises first)
```

**Problems:** Maximum concurrent meetings, Employee Free Time, Skyline Problem, Count of points covered by intervals

---

### 5. "Assign jobs to minimize makespan / completion time" → **Sort by Start Time or Ratio**

**When:** All jobs must run, minimize total time or weighted completion.

**Algorithm variants:**
```
Minimize makespan (no overlap allowed):
  → Sort by start time, simulate greedily

Minimize weighted completion time (single machine):
  → Sort by processing_time/weight ratio (WSPT rule — Smith's theorem)

Minimize lateness (deadline-based):
  → Sort by deadline (Earliest Deadline First)
```

**Problems:** Task scheduling with cooldown (LC 621 — use math/greedy), Course Schedule with deadlines, CPU scheduling

---

### 6. "Can I attend / complete all?" → **Sort by End Time or Deadline + Greedy Check**

**When:** Binary yes/no — can all jobs fit without conflict?

**Algorithm:**
```
1. Sort by end time (or deadline)
2. Simulate greedily — if any job can't be scheduled, return false
```

**Problems:** Can attend all meetings (LC 252), Course Schedule feasibility

---

## Decision Tree

```
Is it an interval/scheduling problem?
│
├── Must SELECT a subset?
│   ├── All jobs equal value?
│   │   └── → Sort by END TIME + GREEDY (Activity Selection)
│   └── Jobs have different profits?
│       └── → Sort by END TIME + DP (Weighted Job Scheduling)
│
├── Must use ALL jobs?
│   ├── Count parallel resources needed?
│   │   └── → Sort by START TIME + MIN-HEAP (Meeting Rooms II)
│   ├── Find overlaps / coverage / density?
│   │   └── → LINE SWEEP with events
│   └── Minimize completion time?
│       └── → Sort by DEADLINE or RATIO (EDF / WSPT)
│
└── Feasibility check (yes/no)?
    └── → Sort by END TIME or DEADLINE + simulate
```

---

## Sort Key Cheat Sheet

| Sort By | Why | Problems |
|---|---|---|
| **End time** | Greedy: finish early, leave room | Activity selection, weighted job DP |
| **Start time** | Process arrivals in order | Meeting rooms, merge intervals |
| **Deadline** | Meet earliest deadlines first | Scheduling with deadlines |
| **Duration/Weight ratio** | Minimize weighted completion | WSPT, CPU burst |
| **Events (+1/-1)** | Track point-in-time occupancy | Line sweep, coverage |

---

## Greedy vs DP Decision

```
Greedy works when:
  ✓ Greedy choice property holds (local optimum = global optimum)
  ✓ All jobs have equal weight/profit
  ✓ You can prove no better choice exists after sorting

DP needed when:
  ✗ Jobs have different weights — greedy can leave profit on the table
  ✗ "Should I take this job or save slot for a better future job?"
  ✗ Optimal substructure exists but greedy choice property fails

Quick test:
  Counter-example exists for greedy? → Use DP
  Can't construct counter-example?  → Greedy probably works
```

---

## Common Pitfalls

```
1. Heap vs sorting for rooms:
   Sorting tells you ORDER of events.
   Heap tells you the MINIMUM end time among active jobs.
   You need BOTH — sort by start, heap for active jobs.

2. Line sweep tie-breaking:
   [1,3] and [3,5] — do they overlap?
   Depends on open/closed intervals. Always clarify with interviewer.

3. Weighted DP binary search:
   After sorting by end time, finding last_non_overlap requires
   binary search on end times → O(N log N) not O(N²).

4. "Minimum removals" = N - "Maximum non-overlapping"
   Don't re-solve — reuse Activity Selection answer.
```