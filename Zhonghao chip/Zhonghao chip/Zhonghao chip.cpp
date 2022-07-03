#include <iostream>
#include <vector>
using namespace std;
// 时间复杂度：O(N^2)
// 空间复杂度：O(1)
// 稳定性：稳定
void BubbleSort(vector<int> &array, int size)
{
	// 控制冒泡的趟数
	for (int i = 0; i < size - 1; ++i)  // -1的目的是可以少冒一趟，因为最后一次冒泡区间中只剩余一个元素
	{
		// j：表示后一个元素的下标，j要取到最后一个元素
		for (int j = 1; j < size - i; ++j)  // -1目的：j最多只能取到冒泡区间的倒数第二个元素
		{
			if (array[j - 1] > array[j])
				swap(array[j], array[j - 1]);
		}
	}
}



// hore：提出快排思想的大佬提出的
int Partion1(vector<int>& array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key;
	key = array[right - 1];

	while (begin < end)
	{
		// 让begin从前往后找，找比基准值大的元素，找到了就停下来
		while (begin < end && array[begin] <= key)
			begin++;


		// 让end从后往前找，找比基准值小的元素，找到了就停下来
		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
			swap(array[begin], array[end]);
	}

	if (begin != right - 1)
		swap(array[begin], array[right - 1]);

	return begin;
}

int Partion2(vector<int>& array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int keyofindex = left;
	int key;
	if (keyofindex != right - 1)
		swap(array[keyofindex], array[right - 1]);

	key = array[right - 1];

	while (begin < end)
	{
		// end位置形成了一个新的坑
		// 让begin从前往后找比基准值大的元素
		while (begin < end && array[begin] <= key)
			begin++;

		// 让begin位置大的元素填end位置的坑
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}


		// begin位置形成了一个新的坑
		// 让end从后往前找比基准值小的元素，填begin位置的坑
		// 让end从后往前找，找比基准值小的元素，找到了就停下来
		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}

	// 用基准值填最后的一个坑
	array[begin] = key;
	return begin;
}

int Partion3(vector<int>& array, int left, int right)
{
	int cur = left;
	int prev = cur - 1;

	int keyofindex = left;
	int key;
	if (keyofindex != right - 1)
		swap(array[keyofindex], array[right - 1]);

	key = array[right - 1];

	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
			swap(array[cur], array[prev]);

		++cur;
	}

	if (++prev != right - 1)
		swap(array[right - 1], array[prev]);

	return prev;
}


// [left, right)表示待排序元素的区间
void QuickSort(vector<int>& array, int left, int right)
{
	// Partion按照基准值(就是区间中的某个元素)对区间进行划分成两部分，作部分元素比基准值小，右侧部分比基准值大
		// 该函数返回基准值在区间中的位置
		// [left, right) 区间中的基准值位置已经存放好了，基准值左侧和基准值右侧不一定有序
	int div = Partion1(array, left, right);

	// 基准值的左侧：[left, div)
	QuickSort(array, left, div);

	// 基准值的右侧：[div+1, right)
	QuickSort(array, div + 1, right);
}


void bucketSort(vector<int>& array, int n)
{
	int max = array[0];
	for (int i = 0; i < n; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	//申请max+1个桶
	//int *bucket = new int[max + 1];
	//给每个桶赋初值为0；
	//memset(bucket, 0, (max + 1) * sizeof(int));
	vector<int>bucket(max + 1, 0);

	//遍历原数组，把相应的数放到相应的桶里
	for (int i = 0; i < n; i++)
	{
		bucket[array[i]]++;
	}
	int index = 0;
	//从桶里把数取出来, i代表的数值对应桶下标， bucket[i]代表的是个数
	for (int i = 0; i < bucket.size(); i++)
	{
		while (bucket[i] > 0)
		{
			array[index++] = i;
			bucket[i]--;
		}
	}
}

void PrintArray(vector<int>& array, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

int main()
{
	vector<int>array = { 2,3,5,8,9,7,4,6,1 };
	//QuickSort(array, 0, sizeof(array) / sizeof(array[0]));
	BubbleSort(array, array.size());
	//bucketSort(array, array.size());
	PrintArray(array, array.size());
	return 0;
}