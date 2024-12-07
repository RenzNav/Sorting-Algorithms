A = [546, 46734, 435, 44, 3436, 3]
N = len(A)

print('Here is the original order of the array:', A)

i = 0
sorted = False
while (i < N - 1 and sorted == False):
    sorted = True
    j = 0
    while (j < N - i - 1):
        if (A[j] > A[j + 1]):  
            temp = A[j]
            A[j] = A[j + 1]
            A[j + 1] = temp
            sorted = False
        j = j + 1
    i = i + 1

print('Here is your sorted list:', A)

# this is the most optimized version i have made. Use this one.

# O(n^2) - For this loop for example we will be running this O(6^2) times...
# Estimate of how long it will take to run the program in its WORST case.
# Best case in O(N)