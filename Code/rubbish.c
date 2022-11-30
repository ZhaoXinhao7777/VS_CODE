// void MergeSortNor(int array[], int size)
// {
// 	int* temp = (int*)malloc(size*sizeof(array[0]));
// 	if (NULL == temp)
// 	{
// 		assert(0);
// 		return;
// 	}

// 	int gap = 1;
// 	while (gap < size)
// 	{
// 		for (int i = 0; i < size; i += 2*gap)
// 		{
// 			int left = i;
// 			int mid = left + gap;
// 			int right = mid + gap;

// 			if (mid > size)
// 				mid = size;
// 			if (right > size)
// 				right = size;

// 			MergeDate(array, left, mid, right, temp);
// 		}

// 		memcpy(array, temp, size*sizeof(array[0]));
// 		gap *= 2;
// 	}
	
// 	free(temp);
// }
