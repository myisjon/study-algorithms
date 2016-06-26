#!/usr/bin/python
# exercise 2.1-4


def big_int_add(array1, array2):
    while True:
        if array1.startswith('0'):
            array1 = array1[1:]
        if array2.startswith('0'):
            array2 = array2[1:]
        if not array2.startswith('0') and not array1.startswith('0'):
            break
    max_list = array1[::-1] if len(array1) > len(array2) else array2[::-1]
    min_list = array1[::-1] if len(array1) < len(array2) else array2[::-1]

    sum_list = [r * 0 for r in range(len(max_list) + 1)]
    for k, v in enumerate(max_list):
        if k < len(min_list):
            sum_list[k] = int(v) + int(min_list[k])
            if sum_list[k] > 9:
                sum_list[k] = sum_list[k] - 9
                sum_list[k + 1] += 1
        else:
            sum_list[k] += int(v)
            if sum_list[k] > 9:
                sum_list[k] = sum_list[k] - 9
                sum_list[k + 1] += 1

    sum_list = sum_list[::-1]
    sum_list = sum_list if sum_list[0] != 0 else sum_list[1:]
    sum_str = ''
    for r in sum_list:
        sum_str += str(r)
    return sum_str


def main():
    array1 = '123456789'
    array2 = '123456789'
    print("b", eval(array1) + eval(array2))
    print('a:', big_int_add(array1, array2))


if __name__ == '__main__':
    main()
