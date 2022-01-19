def solution(number, k):
    answer = ''
    nums = [int(i) for i in number]
    ans = nums
    t = 0
    
    while True:
        if k == 0:
            break
        m = nums[t:k + t].index(max(nums[t:k + t]))
        if m == 0:
            t = t + 1
            continue
        else :
            nums = nums[m:]
        k = k - m + 1
        
    return ",".join(nums)

n = input()
k = int(input())
print(solution(n, k))