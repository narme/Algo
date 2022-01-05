def solution(n, lost, reserve):
    lost_1 = [x for x in lost if x not in set(reserve)]
    reserve = [x for x in reserve if x not in set(lost)]
    lost = lost_1
    lost_1.sort()
    reserve.sort()
    
    for i in reserve :
        for j in lost :
            if abs(j - i) == 1:
                lost.remove(j)
                break
                
    return n - len(lost)