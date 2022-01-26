from audioop import reverse


def solution(people, limit):
    people.sort(reverse=True)
    
    answer = 0
    lp = 0
    rp = len(people) - 1
    print(people)
    
    while True:
        if lp >= rp:
            return answer
        s = people[lp]
        while True:
            print("lp : ", lp, "rp : ", rp)
            s = s + people[rp]
            if s > limit or lp == rp:
                break
            rp = rp - 1
        lp = lp + 1
        answer = answer + 1


p = [40, 40, 40]
l = 120

print(solution(p, l))