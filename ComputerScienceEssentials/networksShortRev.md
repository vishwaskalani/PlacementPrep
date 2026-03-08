Below is a **structured revision sheet** designed for **systems engineer / low-latency / infrastructure interviews**. It focuses on **key concepts, definitions, diagrams in words, and common interview insights**.

---

# Computer Networks – Systems Engineer Revision Notes

---

# 1. Packet Switching vs Circuit Switching

### Circuit Switching

A **dedicated communication path** is established between two devices before data transmission begins.

Example: Traditional telephone networks.

### Characteristics

* Resources reserved before transmission
* Constant bandwidth
* Low latency after setup
* No packet loss due to congestion

### Process

1. Circuit establishment
2. Data transmission
3. Circuit teardown

### Example

A phone call between two people.

Bandwidth is **reserved even when no data is sent**.

---

### Packet Switching

Data is **broken into packets**, each sent independently through the network.

Example: Internet.

### Characteristics

* No dedicated path
* Packets may take **different routes**
* Efficient resource usage
* Possible packet loss and delay

### Process

1. Message split into packets
2. Packets routed independently
3. Reassembled at destination

---

### Comparison

| Feature             | Circuit Switching | Packet Switching |
| ------------------- | ----------------- | ---------------- |
| Resource allocation | Reserved          | Shared           |
| Setup time          | Required          | Not required     |
| Efficiency          | Low               | High             |
| Delay               | Predictable       | Variable         |
| Failure tolerance   | Low               | High             |

---

# 2. Transmission Time vs Propagation Time

### Transmission Time

Time required to **push all bits of a packet onto the wire**.

Formula:

[
Transmission \ Time = \frac{Packet\ Size}{Transmission\ Rate}
]

Example

Packet size = 1000 bits
Bandwidth = 1 Mbps

[
T_t = 1000 / 10^6 = 1ms
]

---

### Propagation Time

Time taken for **signal to travel from sender to receiver**.

Formula:

[
Propagation\ Time = \frac{Distance}{Propagation\ Speed}
]

Propagation speed in fiber ≈ **2 × 10⁸ m/s**

---

### Key Insight

Transmission depends on **packet size + bandwidth**

Propagation depends on **distance**

---

# 3. Internet Protocol Stack

The Internet uses a **5-layer architecture**.

```
Application
Transport
Network
Data Link
Physical
```

---

### Application Layer

Provides services to applications.

Examples:

* HTTP
* DNS
* FTP
* SMTP

---

### Transport Layer

Provides **end-to-end communication**.

Protocols:

* TCP
* UDP

Responsibilities:

* segmentation
* flow control
* reliability

---

### Network Layer

Handles **routing of packets across networks**.

Protocol:

* IP

---

### Data Link Layer

Handles **node-to-node communication** on same network.

Examples:

* Ethernet
* WiFi

---

### Physical Layer

Transmits **raw bits over medium**.

Examples:

* Fiber
* Copper
* Radio waves

---

# 4. Layer Identifiers

Each layer uses **different identifiers**.

| Layer       | Identifier   | Example        |
| ----------- | ------------ | -------------- |
| Application | URL / Domain | google.com     |
| Transport   | Port number  | 80             |
| Network     | IP Address   | 192.168.1.1    |
| Data Link   | MAC Address  | 00:1A:2B:3C:4D |
| Physical    | Bits         | 010101         |

---

# 5. Socket vs Port

### Port

A **port is a logical endpoint** used to identify a process on a host.

Example

HTTP → port 80

---

### Socket

A **socket uniquely identifies a network connection**.

Socket =

```
(IP Address, Port)
```

Example

```
Server: 192.168.1.10:80
Client: 10.0.0.5:50000
```

TCP connection identified by:

```
(Client IP, Client Port, Server IP, Server Port)
```

This allows **multiple clients to connect to same server port**.

---

# 6. TCP vs UDP

| Feature            | TCP                 | UDP            |
| ------------------ | ------------------- | -------------- |
| Reliability        | Reliable            | Unreliable     |
| Ordering           | Guaranteed          | Not guaranteed |
| Connection         | Connection-oriented | Connectionless |
| Congestion control | Yes                 | No             |
| Speed              | Slower              | Faster         |

---

### TCP Usage

* HTTP
* HTTPS
* Email
* File transfer

---

### UDP Usage

* Video streaming
* Gaming
* DNS
* VoIP

Reason: **lower latency**

---

# 7. Basics of HTTP

HTTP = **HyperText Transfer Protocol**

Application layer protocol used for **web communication**.

---

### HTTP Characteristics

* Stateless
* Request/Response protocol
* Runs over TCP

---

### HTTP Request Example

```
GET /index.html HTTP/1.1
Host: example.com
```

---

### HTTP Response Example

```
HTTP/1.1 200 OK
Content-Type: text/html
```

---

### Common Methods

| Method | Purpose           |
| ------ | ----------------- |
| GET    | Retrieve resource |
| POST   | Send data         |
| PUT    | Update resource   |
| DELETE | Remove resource   |

---

# 8. Domain Name System (DNS)

DNS translates **domain names → IP addresses**.

Example

```
google.com → 142.250.183.14
```

---

### DNS Hierarchy

```
Root Server
   ↓
TLD Server (.com)
   ↓
Authoritative Server
```

---

### DNS in Protocol Stack

DNS belongs to:

Application Layer

Transport used:

* **UDP port 53** (mostly)
* TCP for large responses

---

# 9. TCP Connection Setup and Termination

### TCP 3-Way Handshake

Used to establish connection.

Steps:

1️⃣ Client → SYN
2️⃣ Server → SYN-ACK
3️⃣ Client → ACK

Connection established.

---

### TCP Termination (4-way)

1️⃣ Client → FIN
2️⃣ Server → ACK
3️⃣ Server → FIN
4️⃣ Client → ACK

Connection closed.

---

### TCP Socket Identification

Each connection identified by:

```
(Client IP,
 Client Port,
 Server IP,
 Server Port)
```

---

# 10. TCP Flow Control vs Congestion Control

### Flow Control

Ensures **receiver is not overwhelmed**.

Mechanism:

**Receiver Window (rwnd)**

Receiver advertises how much data it can handle.

---

### Congestion Control

Prevents **network congestion**.

Mechanisms:

* Slow Start
* Congestion Avoidance
* Fast Retransmit
* Fast Recovery

---

### Key Difference

| Feature       | Flow Control | Congestion Control |
| ------------- | ------------ | ------------------ |
| Protects      | Receiver     | Network            |
| Controlled by | Receiver     | Sender             |

---

# 11. Internet Protocol (IP)

IP provides **best effort packet delivery**.

Characteristics:

* Connectionless
* No reliability
* No ordering guarantee

---

### Responsibilities

* Addressing
* Packet forwarding
* Routing

---

### IP Packet Structure

Key fields:

* Source IP
* Destination IP
* TTL
* Protocol
* Header checksum

---

### TTL (Time to Live)

Prevents infinite loops.

Each router decrements TTL.

If TTL = 0 → packet dropped.

---

# 12. IP Addressing, Subnets, DHCP

---

## IP Address

32 bit identifier in IPv4.

Example

```
192.168.1.10
```

Split into:

```
Network ID | Host ID
```

Example

```
192.168.1.0 /24
```

* 24 bits network
* 8 bits host

---

## Subnetting

Divides a network into smaller networks.

Example

```
192.168.1.0/24
```

Split into:

```
192.168.1.0/26
192.168.1.64/26
192.168.1.128/26
192.168.1.192/26
```

---

## DHCP (Dynamic Host Configuration Protocol)

Automatically assigns IP addresses.

Uses **UDP ports 67 and 68**.

---

### DHCP Process (DORA)

When mobile joins network:

1️⃣ Discover
Device broadcasts

```
DHCPDISCOVER
```

2️⃣ Offer
Server offers IP

```
DHCPOFFER
```

3️⃣ Request
Client requests specific IP

```
DHCPREQUEST
```

4️⃣ Acknowledge

```
DHCPACK
```

Now device has:

* IP address
* Default gateway
* DNS server

---

# 13. Network Address Translation (NAT)

NAT allows **multiple private devices to share one public IP**.

Example

Home router.

---

Private IP:

```
192.168.1.10
192.168.1.11
192.168.1.12
```

Public IP:

```
203.0.113.5
```

---

### NAT Table

| Private IP   | Private Port | Public Port |
| ------------ | ------------ | ----------- |
| 192.168.1.10 | 5000         | 40001       |

Router translates:

```
192.168.1.10:5000 → 203.0.113.5:40001
```

---

### Benefits

* IP conservation
* Security

---

# 14. IPv6 Tunneling over IPv4

IPv6 deployment is gradual.

Some networks support only IPv4.

Solution: **tunneling**

---

### Idea

Encapsulate IPv6 packet inside IPv4 packet.

```
[ IPv4 Header ][ IPv6 Packet ]
```

---

### Process

1. IPv6 packet generated
2. Wrapped inside IPv4 packet
3. Sent through IPv4 network
4. Unwrapped at IPv6 gateway

---

### Used Technologies

* 6to4
* Teredo
* ISATAP

---

# Quick Interview Summary

Must remember:

* **Transmission time vs propagation time**
* **TCP 3-way handshake**
* **DORA DHCP process**
* **Socket = (IP, Port)**
* **TCP connection = 4-tuple**
* **Flow control vs congestion control**
* **DNS hierarchy**
* **NAT translation table**

---
Both of these are **important systems/network interview topics**, especially for **systems engineering / low latency roles**. I’ll explain them in a **conceptual + practical way** so you can reason about real packet flow.

---

# 1. MAC Address – Where It Belongs and How It Is Used

## What is a MAC Address?

A **MAC (Media Access Control) address** is a **48-bit hardware identifier** assigned to a **network interface card (NIC)**.

Example:

```
00:1A:2B:3C:4D:5E
```

Structure:

```
24 bits → Manufacturer (OUI)
24 bits → Device identifier
```

Example:

```
00:1A:2B  → Intel
3C:4D:5E  → Device number
```

---

# Where MAC Address Exists in the Internet Stack

MAC addresses belong to the **Data Link Layer**.

Internet stack:

```
Application
Transport
Network      → IP Address
Data Link    → MAC Address
Physical
```

So:

| Layer     | Identifier  |
| --------- | ----------- |
| Transport | Port        |
| Network   | IP Address  |
| Data Link | MAC Address |

---

# Key Idea

IP identifies **devices globally**

MAC identifies **devices locally within a LAN**

---

# Example Network

Imagine this network:

```
Laptop → Router → Internet → Google Server
```

Addresses involved:

```
Laptop
IP: 192.168.1.10
MAC: AA:AA:AA:AA:AA:AA

Router
IP: 192.168.1.1
MAC: BB:BB:BB:BB:BB:BB
```

Server:

```
IP: 142.250.183.14
MAC: (unknown to laptop)
```

Important point:

Your laptop **does NOT know Google's MAC address**.

MAC addresses are **only used inside a local network**.

---

# How MAC Is Used When Sending a Packet

Suppose your browser wants to contact:

```
google.com → 142.250.183.14
```

Steps:

### Step 1 — Application creates request

```
GET / HTTP/1.1
```

---

### Step 2 — TCP adds transport header

```
Source Port: 54000
Dest Port: 443
```

---

### Step 3 — IP adds network header

```
Source IP: 192.168.1.10
Dest IP: 142.250.183.14
```

---

### Step 4 — Data Link Layer adds MAC header

But now the system must determine:

```
What MAC address should I send this to?
```

Since Google is **outside the LAN**, the laptop sends the packet to the **default gateway (router)**.

So the MAC destination becomes:

```
Destination MAC = Router MAC
```

---

# How Laptop Learns Router MAC (ARP)

Laptop uses **ARP (Address Resolution Protocol)**.

ARP request:

```
Who has 192.168.1.1 ?
Tell 192.168.1.10
```

Broadcast MAC:

```
FF:FF:FF:FF:FF:FF
```

Router responds:

```
192.168.1.1 → BB:BB:BB:BB:BB:BB
```

Laptop stores this in **ARP cache**.

---

# Actual Packet Sent

Frame on wire:

```
MAC Header
------------------
Source MAC: AA:AA:AA:AA:AA:AA
Dest MAC:   BB:BB:BB:BB:BB:BB

IP Header
------------------
Source IP: 192.168.1.10
Dest IP:   142.250.183.14

TCP Header
------------------
Src Port: 54000
Dst Port: 443
```

---

# Important Interview Insight

Every **router hop changes the MAC header**.

But **IP addresses remain constant**.

Example:

```
Laptop → Router1 → Router2 → Router3 → Server
```

At every hop:

```
MAC changes
IP stays same
```

---

# Visual Packet Flow

```
Laptop
MAC: A → B
IP : Laptop → Google

Router
MAC: C → D
IP : Laptop → Google

Next Router
MAC: E → F
IP : Laptop → Google
```

MAC works **hop-by-hop**.

IP works **end-to-end**.

---

# 2. TCP Congestion Control Protocols

Congestion control prevents **network overload**.

When too many packets enter a network:

```
Queue overflow
Packet loss
High latency
```

TCP dynamically adjusts **sending rate**.

Key variable:

```
Congestion Window (cwnd)
```

Effective sending window:

```
min(rwnd, cwnd)
```

Where:

```
rwnd → receiver window (flow control)
cwnd → congestion window
```

---

# Major TCP Congestion Control Algorithms

---

# 1. TCP Tahoe

Old but fundamental.

Phases:

```
Slow Start
Congestion Avoidance
```

---

## Slow Start

Start with:

```
cwnd = 1 MSS
```

Each ACK doubles cwnd.

Growth:

```
1
2
4
8
16
32
```

Exponential growth.

---

## Packet Loss

When packet loss occurs:

```
cwnd → 1 MSS
```

Start slow start again.

Very conservative.

---

# 2. TCP Reno

Improvement over Tahoe.

Key idea:

**Fast Recovery**

Detects packet loss using **3 duplicate ACKs**.

---

## Fast Retransmit

If sender receives:

```
3 duplicate ACKs
```

Then packet assumed lost.

Retransmit immediately.

No timeout required.

---

## Fast Recovery

Instead of dropping cwnd to 1:

```
cwnd = cwnd / 2
```

Continue transmission.

More efficient than Tahoe.

---

# 3. TCP New Reno

Improves Reno for **multiple packet losses**.

Key improvement:

Handles **partial ACKs better** during fast recovery.

Used widely before modern algorithms.

---

# 4. TCP Cubic (Modern Linux Default)

Most modern Linux systems use **CUBIC**.

Key idea:

Window growth follows a **cubic function**.

Advantages:

* Works well in **high bandwidth networks**
* Good for **long fat networks (LFN)**

Growth:

```
cwnd = C(t − K)^3 + Wmax
```

Where:

* `Wmax` = previous max window
* `t` = time since last congestion

Result:

```
Fast growth
Stable recovery
```

Used in:

* Linux
* CDN infrastructure
* large-scale systems

---

# 5. TCP BBR (Modern Google Algorithm)

Developed by Google.

Instead of loss-based control, it estimates:

```
Bandwidth
Round Trip Time
```

Goal:

```
Send at bottleneck bandwidth
```

Advantages:

* lower latency
* higher throughput
* fewer queues

Used in:

* Google services
* YouTube
* Google Cloud

---

# Quick Comparison

| Algorithm | Type                 |
| --------- | -------------------- |
| Tahoe     | Loss based           |
| Reno      | Loss based           |
| New Reno  | Loss based           |
| Cubic     | Loss based optimized |
| BBR       | Model based          |

---

# Congestion Window Behavior

Typical graph:

```
cwnd
 ^
 |        /\
 |       /  \   /\
 |      /    \ /  \
 |_____/      V    \____
        time
```

Pattern:

```
Slow start → linear growth → drop → repeat
```

This is called **AIMD**.

---

# AIMD Principle

Additive Increase
Multiplicative Decrease

Meaning:

```
Increase slowly
Decrease rapidly
```

---

# Interview Summary

MAC Address

* Data Link layer identifier
* Used for **local delivery**
* Learned via **ARP**
* Changes at every router hop

TCP Congestion Control

Key algorithms:

```
Tahoe
Reno
New Reno
Cubic
BBR
```

Concepts to remember:

```
cwnd
rwnd
slow start
fast retransmit
fast recovery
AIMD
```

---

