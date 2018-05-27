

def quickSort(array) :
	if len(array) < 2 :
		return array
	else :
 		pivot = array[-1]
		smaller = [x for x in array[:-1] if x <= pivot]
		greater = [x for x in array[:-1] if x > pivot]
		return quickSort(smaller) + [pivot] + quickSort(greater)


arr = [5,9,8,4,1,99,132,77,43,12]

print quickSort(arr)
