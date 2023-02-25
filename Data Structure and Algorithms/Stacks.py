from ArrayStack import ArrayStack

def print_in_reverse(str):
    S = ArrayStack()

    for ch in str:
        S.push(ch)

    while (S.is_empty() == False):
        ch = S.pop()
        print(ch, end='')
    print()



def eval_postfix_exp(exp_str):
    operators = "+-*/"
    exp_lst = exp_str.split()
    args_stack = ArrayStack()
    for token in exp_lst:
        if(token not in operators):
            args_stack.push(int(token))
        else:
            arg2 = args_stack.pop()
            arg1 = args_stack.pop()
            if(token == '+'):
                res = arg1 + arg2
            elif (token == '-'):
                res = arg1 - arg2
            elif(token == '*'):
                res = arg1 * arg2
            elif(token == '/'):
                if(arg2 == 0):
                    raise ZeroDivisionError
                else:
                    res = arg1 / arg2
            args_stack.push(res)

    return args_stack.pop()

