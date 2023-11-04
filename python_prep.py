import heapq
from collections import deque,defaultdict
import bisect
## sets in python

curr_set = {2,3,1}
curr_set.add(4)
listi = [1,2,5]
curr_set.update(listi)
curr_set.remove(5)
curr_set.clear()
a = 5
curr_set.add(5)
curr_set.add(2)
if a in curr_set:
	print("Yes")
else:
	print("No")
print("set is ")
print(curr_set)


## dictionaries in python
## if you declare something like curr_set = {} then it would be considered as a dictionary and not a set
## for set u can declare like set() and for dictionary you can declare like {}

dicti = {1:2,2:4,3:6}
key_list = dicti.keys()
a = 2
if a in dicti:
	print("YES")
else:
	print("NO")
dicti[4] = 8
dicti[6] = 12
print(dicti.get(6))
dicti.pop(6)
print(list(key_list))

## priority quueue in python
# Create an empty priority queue (min-heap)
pq = []

# Push elements onto the priority queue
heapq.heappush(pq, 3)
heapq.heappush(pq, 1)
heapq.heappush(pq, 2)

# Pop the smallest element
min_element = heapq.heappop(pq)
print(min_element)

##using maxheap

# Sort a list of tuples based on the second element
data = [(1, 3), (2, 1), (3, 2)]
sorted_data = sorted(data, key=lambda x: x[1])
print(sorted_data)

#sorting based on the first and second element mixture



# Initialize a queue
queue = deque()

# Enqueue elements
queue.append(1)
queue.append(2)
queue.append(3)

# Dequeue elements
element = queue.popleft()
print(element)
print(queue)
element2 = queue.pop()
print("Length of q is ",len(queue))
print(queue)


# Initialize a 2D DP table with all zeros
rows, cols = 3, 4
dp = [[0] * cols for _ in range(rows)]

# Update a cell
dp[1][2] = 5
print(dp)

arr = [1, 2, 2, 2, 3, 4, 4, 6]

# Find lower bound of 2 (the index of the first occurrence of 2)
lower_bound = bisect.bisect_left(arr, 2)
print(lower_bound)

# Find upper bound of 4 (the index where 4 should be inserted to maintain sorted order)
upper_bound = bisect.bisect_right(arr, 4)
print(upper_bound)

## ascii value positioning
print(ord('a'))
print(ord('b')-ord('A'))

## use of default dict
class Solution:
    def maxTaxiEarnings(self, n, rides) -> int:
        pas = len(rides)
        # we are travelling from 1 to n and we need to pick up passengers
        # we need to ensure no overlap
        # we need to find max earning
        rs = defaultdict(list)
        for s,e,t in rides:
            rs[s].append([e,e-s+t])
        dp = [0]*(n+1)
        for i in range(n-1,0,-1):
            for e,d in rs[i]:
                dp[i] = max(dp[i],dp[e]+d)
            dp[i] = max(dp[i],dp[i+1])
        return dp[1]

