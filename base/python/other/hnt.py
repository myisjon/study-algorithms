TOTAL = 0

def hanoi_towers(n, a='A', b='B', c='C'):
    global TOTAL
    TOTAL += 1
    if n < 2:
        print('{} ===> {}'.format(a, b))
    else:
        hanoi_towers(n - 1, a, c, b)
        print('{} ===> {}'.format(a, c))
        hanoi_towers(n - 1, b, a, c)



def main():
    hanoi_towers(8)
    print('total: {}'.format(TOTAL))

    return 0


if __name__ == '__main__':
    main()