'''
max() 를 사용하는 경우 시간초과가 발생했다.
max() 를 사용하지않고 앞뒤 비교를 하는 알고리즘으로 변경
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
