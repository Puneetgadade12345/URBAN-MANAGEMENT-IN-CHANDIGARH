
QuickSort(arr, low, high):
    if low < high:
        // Partition the array and get the pivot index
        pivot_index = Partition(arr, low, high)
        
        // Recursively apply QuickSort to the left and right sub-arrays
        QuickSort(arr, low, pivot_index - 1)  // Left sub-array
        QuickSort(arr, pivot_index + 1, high) // Right sub-array

Partition(arr, low, high):
    pivot = arr[high]  // Choosing the pivot (can be any element, here it's the last element)
    i = low - 1
    
    for j = low to high - 1:
        if arr[j] < pivot:
            i = i + 1
            swap arr[i] and arr[j]
    
    swap arr[i + 1] and arr[high]  // Place the pivot at its correct position
    return i + 1  // Return the pivot index
