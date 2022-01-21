'''
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
'''

def solution(number, k):
    answer = ''
    
    while True:
        if k <= 0:
            answer = answer + number
            return answer
        
        if len(number) - 1 == k :
            tmp = number
        else :
            tmp = number[:len(number) - k - 1]
        
        maxinx = tmp.index(max(tmp))
        print("number : ", number)
        print("maxinx : ", maxinx)
        print("tmp : ", tmp)
        
        print("k : ", k)
        k = k - maxinx
        number = number[maxinx+1:]
        answer = answer + tmp[maxinx]
        print("answer : ",answer)

n = input()
k = int(input())
print(solution(n, k))