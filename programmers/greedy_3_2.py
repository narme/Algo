def solution(number, k):
    answer = ''
    t = 0
    while True:
        if int(number[0]) == 9:
            answer = answer + str(9)
            number = number[1:]
            continue
            
        if number[0+t] < number[1+t]:
            number = number[:t] + number[1+t:]
            k = k - 1
            t = 0
            
        else :
            t = t + 1
            if t == len(number) - 1:
                number = number[:t] 
                k = k - 1
            
        if k == 0:
            return answer + number
        
        
        


n = input()
k = int(input())
print(solution(n, k))