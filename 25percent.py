def my(n):
    i = 0
    t =  n
    while(n > 1):
        i += 1
        n = n*(.75)
        print(i , "  " , n)

k = int(input())

while(k != -1):
    my(k)
    print("enter next")
    k = int(input())
