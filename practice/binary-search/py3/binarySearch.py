def binarySearch(nums, target):
    l = 0
    r = len(nums)-1

    while l <= r:
        mid = int((l+r)/2) # always rounds down
        if (nums[mid] == target):
            return mid
        elif (nums[mid] < target):
            l = mid + 1
        else: #nums[mid] > target
            r = mid - 1

    return -1

if __name__ == "__main__":
    arr = [-1,0,3,5,9,12]
    target = -1
    print("arr: %s, target: %s, result: %s" % (arr,target,binarySearch(arr,
                                                                  target)))
