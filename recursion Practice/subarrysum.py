def subarray(N,K,A):
    subarrays = []
    sum = 0
    for i in range (0, len(A)):
        sum = 0
        for j in range (i, len(A)):
            sum = sum + A[j]
            subarrays.append(sum)
    subarrays.sort()
    subarrays.reverse()
    return subarrays[K-1]


A = [5]
print(subarray(1, 1, A))