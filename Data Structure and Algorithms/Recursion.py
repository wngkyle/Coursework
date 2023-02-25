### 1 ###
def count_up1(start, end):
    if (start == end):
        print(end)
    else:
        print(start)
        count_up1(start + 1, end)

def count_up2(start, end):
    if (start == end):
        print(end)
    else:
        count_up2(start, end - 1)
        print(end)

def count_up3(start, end):
    if (start == end):
        print(end)
    else:
        mid = (start + end) // 2
        count_up3(start, mid)
        count_up3(mid+1, end)


def count_down(start, end):
    if (start == end):
        print(end)
    else:
        print(end)
        count_down(start + 1, end)


def count_up_and_down(start, end):
    if (start == end):
        print(end)
    else:
        print(start)
        count_up_and_down(start + 1, end)
        print(start)


### 2 ###
def factorial(n):
    if(n == 1):
        return 1
    else:
        rest_fact = factorial(n-1)
        return rest_fact * n


### 3 ###
def count_appearances1(lst, val):
    if(len(lst) == 0):
        return 0
    else:
        count_rest = count_appearances1(lst[1: ], val)
        if(lst[0] == val):
            return count_rest + 1
        else:
            return count_rest


def count_appearances2(lst, val):
    def count_appearances_helper(lst, low, high, val):
        if (low == high):
            if (lst[low] == val):
                return 1
            else:
                return 0
        else:
            count_rest = count_appearances_helper(lst, low + 1, high, val)
            if (lst[low] == val):
                return count_rest + 1
            else:
                return count_rest

    if(len(lst) == 0):
        return 0
    else:
        return count_appearances_helper(lst, 0, len(lst) - 1, val)




### 4 ###
def power1(a, n):
    if(n == 1):
        return x
    else:
        rest = power1(a, n-1)
        return a*rest

def power2(a, n): 
    if (n == 1):
        return x
    else:
        part1 = power2(a, n//2)
        part2 = power2(a, n//2)
        if (n % 2 == 0):
            return part1 * part2
        else: # n is odd
            return a * part1 * part2

def power3(a, n):
    if (n == 1):
        return x
    else:
        part = power3(a, n//2)
        if (n % 2 == 0):
            return part * part
        else: # n is odd
            return a * part * part


### 5 ###
def pos_ints_list(n):
    if(n == 1):
        return [1]
    else:
        res_list = pos_ints_list(n-1)
        res_list.append(n)
        return res_list

