def solution(participant, completion):
    d = {}
    for key in participant:
        d[key] = d.get(key, 0) + 1
    for k in completion:
        d[k] -= 1
    
    for i in d:
        if d[i] > 0:
            return i
