import time


# Q2，上限题数是5
def Q2():
    if a[2] == 1 and a[5] == 3 or \
            a[2] == 2 and a[5] == 4 or \
            a[2] == 3 and a[5] == 1 or \
            a[2] == 4 and a[5] == 2:
        return True
    return False


# Q3，上限题数是6
def Q3():
    if a[3] == 1 and a[6] != a[3] and a[6] == a[2] and a[2] == a[4] or \
            a[3] == 2 and a[6] != a[3] and a[3] == a[2] and a[2] == a[4] or \
            a[3] == 3 and a[2] != a[3] and a[3] == a[6] and a[6] == a[4] or \
            a[3] == 4 and a[4] != a[3] and a[3] == a[2] and a[2] == a[6]:
        return True
    return False


# Q4，上限题数是10
def Q4():
    if a[4] == 1 and a[1] == a[5] or \
            a[4] == 2 and a[2] == a[7] or \
            a[4] == 3 and a[1] == a[9] or \
            a[4] == 4 and a[6] == a[10]:
        return True
    return False


# Q5，上限题数是9
def Q5():
    if a[5] == 1 and a[5] == a[8] or \
            a[5] == 2 and a[5] == a[4] or \
            a[5] == 3 and a[5] == a[9] or \
            a[5] == 4 and a[5] == a[7]:
        return True
    return False


# Q6，上限题数是10
def Q6():
    if a[6] == 1 and a[8] == a[2] and a[8] == a[4] or \
            a[6] == 2 and a[8] == a[1] and a[8] == a[6] or \
            a[6] == 3 and a[8] == a[3] and a[8] == a[10] or \
            a[6] == 4 and a[8] == a[5] and a[8] == a[9]:
        return True
    return False


# Q7，上限题数是10
def Q7():
    count = [0, 0, 0, 0]
    for i in range(1, 11):
        count[a[i] - 1] += 1
    min_count = min(count)
    min_index = count.index(min_count) + 1
    if a[7] == 1 and min_index == 3 or \
            a[7] == 2 and min_index == 2 or \
            a[7] == 3 and min_index == 1 or \
            a[7] == 4 and min_index == 4:
        return True
    return False


# Q8，上限题数是10
def Q8():
    if a[8] == 1 and (a[7] != a[1] + 1 or a[7] != a[1] - 1) or \
            a[8] == 2 and (a[5] != a[1] + 1 or a[5] != a[1] - 1) or \
            a[8] == 3 and (a[2] != a[1] + 1 or a[2] != a[1] - 1) or \
            a[8] == 4 and (a[10] != a[1] + 1 or a[10] != a[1] - 1):
        return True
    return False


# Q9，上限题数是10
def Q9():
    if a[9] == 1 and ((a[1] == a[6]) ^ (a[6] == a[5])) or \
            a[9] == 2 and ((a[1] == a[6]) ^ (a[10] == a[5])) or \
            a[9] == 3 and ((a[1] == a[6]) ^ (a[2] == a[5])) or \
            a[9] == 4 and ((a[1] == a[6]) ^ (a[9] == a[5])):
        return True
    return False


# Q10，上限题数是10
def Q10():
    count = [0, 0, 0, 0]
    for i in range(1, 11):
        count[a[i] - 1] += 1
    min_count = min(count)
    max_count = max(count)
    dif = max_count - min_count
    if a[10] == 1 and dif == 3 or \
            a[10] == 2 and dif == 2 or \
            a[10] == 3 and dif == 4 or \
            a[10] == 4 and dif == 1:
        return True
    return False


def print_answer():
    option = ["A", "B", "C", "D"]
    global all_status
    all_status += 1
    print(all_status, end=" : ")
    for i in range(1, 11):
        print("%s" % option[a[i] - 1], end=" ")
    print()


def violence(h):
    if h > 10:
        return
    # 极致的优化，极致的享受
    if h == 3:
        if a[3] == 2 and a[3] != a[2] or \
                a[3] == 4 and a[3] != a[2]:
            return
    if h == 4:
        if a[3] == 1 and a[2] != a[4] or \
                a[3] == 2 and not (a[3] == a[2] and a[2] == a[4]) or \
                a[3] == 4 and a[3] != a[2]:
            return
    # 正常优化
    if h == 5 and not Q2():
        return
    if h == 6 and not Q3():
        return
    if h == 9 and not Q5():
        return
    if h == 10:
        if Q4() and Q6() and Q8() and Q9() and Q7() and Q10():
            print_answer()
            pass
        return
    # 极致的优化，极致的难受
    for j in range(1, 5):
        a[h + 1] = j
        violence(h + 1)
        a[h + 1] = 0


if __name__ == '__main__':
    time_start = time.time()
    a = [0 for i in range(11)]
    all_status = 0
    violence(0)
    time_end = time.time()
    print("%d条结果，用时%s秒" % (all_status, time_end - time_start))
