list1 = [5, 10, 28, 29, 38, 48, 59, 65]

def binary_search(list, value ):
    low = 0
    high = len(list) - 1
    while low <= high:
            mid = (low + high) //2
            if list[mid] > value:
                high  = mid - 1

            elif list[mid] < value:
                low = mid + 1
            
            else:
               return print("İndex: [{}]".format(mid))
        
binary_search(list1, 29)