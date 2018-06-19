#!/usr/bin/python
# INSERTION-SORT(A)
# for j = 2 to A.length
#    key = A[j]
#    // Insert A[j] into the sorted sequence A[1..j - 1].
#    i = j - 1
#    while i > 0 and A[i] > key
#       A[i+1] = A[i]
#       i = i - 1
#    A[i + 1] = key


def insert_sort_asce(array):
    for j in range(1, len(array), 1):
        key = array[j]
        i = j - 1
        while i > -1 and array[i] > key:
            array[i + 1] = array[i]
            i -= 1
        array[i + 1] = key

    return array


def insert_sort_desc(array):
    for j in range(1, len(array), 1):
        key = array[j]
        i = j - 1
        while i > -1 and array[i] < key:
            array[i + 1] = array[i]
            i -= 1
        array[i + 1] = key

    return array


def main():
    print(range(9, -1, -1))
    print("{}{}").format("insert_sort_asce: \n", insert_sort_asce(range(9, -1, -1)))
    print(range(0, 10, 1))
    print(("{}{}").format("insert_sort_desc: \n", insert_sort_desc(range(0, 10, 1))))


if __name__ == '__main__':
    main()
