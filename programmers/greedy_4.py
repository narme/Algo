def solution(people, limit):
    people.sort(reverse=True)
    people.append(0)

    print(people)
    '''
    while True:
        if people[-1] == 0:
            break
        
       '''     
    answer = 0
    return answer


p = [70, 50, 80, 50]
l = 100

print(solution(p, l))