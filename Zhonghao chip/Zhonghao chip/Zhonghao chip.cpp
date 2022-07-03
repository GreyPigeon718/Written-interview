#include <iostream>
#include <vector>
using namespace std;
// ʱ�临�Ӷȣ�O(N^2)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ��ȶ�
void BubbleSort(vector<int> &array, int size)
{
	// ����ð�ݵ�����
	for (int i = 0; i < size - 1; ++i)  // -1��Ŀ���ǿ�����ðһ�ˣ���Ϊ���һ��ð��������ֻʣ��һ��Ԫ��
	{
		// j����ʾ��һ��Ԫ�ص��±꣬jҪȡ�����һ��Ԫ��
		for (int j = 1; j < size - i; ++j)  // -1Ŀ�ģ�j���ֻ��ȡ��ð������ĵ����ڶ���Ԫ��
		{
			if (array[j - 1] > array[j])
				swap(array[j], array[j - 1]);
		}
	}
}



// hore���������˼��Ĵ��������
int Partion1(vector<int>& array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key;
	key = array[right - 1];

	while (begin < end)
	{
		// ��begin��ǰ�����ң��ұȻ�׼ֵ���Ԫ�أ��ҵ��˾�ͣ����
		while (begin < end && array[begin] <= key)
			begin++;


		// ��end�Ӻ���ǰ�ң��ұȻ�׼ֵС��Ԫ�أ��ҵ��˾�ͣ����
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
		// endλ���γ���һ���µĿ�
		// ��begin��ǰ�����ұȻ�׼ֵ���Ԫ��
		while (begin < end && array[begin] <= key)
			begin++;

		// ��beginλ�ô��Ԫ����endλ�õĿ�
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}


		// beginλ���γ���һ���µĿ�
		// ��end�Ӻ���ǰ�ұȻ�׼ֵС��Ԫ�أ���beginλ�õĿ�
		// ��end�Ӻ���ǰ�ң��ұȻ�׼ֵС��Ԫ�أ��ҵ��˾�ͣ����
		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}

	// �û�׼ֵ������һ����
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


// [left, right)��ʾ������Ԫ�ص�����
void QuickSort(vector<int>& array, int left, int right)
{
	// Partion���ջ�׼ֵ(���������е�ĳ��Ԫ��)��������л��ֳ������֣�������Ԫ�رȻ�׼ֵС���Ҳಿ�ֱȻ�׼ֵ��
		// �ú������ػ�׼ֵ�������е�λ��
		// [left, right) �����еĻ�׼ֵλ���Ѿ���ź��ˣ���׼ֵ���ͻ�׼ֵ�Ҳ಻һ������
	int div = Partion1(array, left, right);

	// ��׼ֵ����ࣺ[left, div)
	QuickSort(array, left, div);

	// ��׼ֵ���Ҳࣺ[div+1, right)
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
	//����max+1��Ͱ
	//int *bucket = new int[max + 1];
	//��ÿ��Ͱ����ֵΪ0��
	//memset(bucket, 0, (max + 1) * sizeof(int));
	vector<int>bucket(max + 1, 0);

	//����ԭ���飬����Ӧ�����ŵ���Ӧ��Ͱ��
	for (int i = 0; i < n; i++)
	{
		bucket[array[i]]++;
	}
	int index = 0;
	//��Ͱ�����ȡ����, i�������ֵ��ӦͰ�±꣬ bucket[i]������Ǹ���
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