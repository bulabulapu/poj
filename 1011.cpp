#include <iostream>

using namespace std;

int *sticks;		// 存储木条
bool *status;		// 木条使用状态
int countStick = 0; // 木条数目

/**
 * 归并排序,降序
 *
 * @param l 排序起位置
 * @param r 排序结束位置
 * */
void sort(int l, int r)
{
	if (l == r)
		return;
	int mid = (l + r) / 2;
	sort(l, mid);
	sort(mid + 1, r); // 排序左右两部分
	int i = l, j = mid + 1;
	int *temp = new int[r - l + 1];
	int k = 0;
	while (k <= r - l) // 合并
	{
		if (i <= mid && j <= r)
		{
			if (sticks[i] > sticks[j])
			{
				temp[k++] = sticks[i++];
			}
			else
			{
				temp[k++] = sticks[j++];
			}
		}
		else if (i <= mid)
		{
			temp[k++] = sticks[i++];
		}
		else
		{
			temp[k++] = sticks[j++];
		}
	}
	k = 0;
	while (k < r - l + 1)
	{
		sticks[l + k] = temp[k];
		k++;
	}
	delete[] temp;
}

/**
 * 深度搜索是否存在长度为length的结果
 *
 * @param length 目标长度
 * @param subLength 当前需要凑齐的木条余下长度
 * @param position 上层用到的木条位置(当前搜索起点),保证下层用到的木条是后面的(更短的),以此进行剪枝
 * */
bool dfs(int length, int subLength, int position)
{
	int i = position;
	while (i < countStick)
	{
		while (i < countStick && (status[i] || subLength < sticks[i])) // 选择下一根可选择的木条
		{
			i++;
		}
		if (i == countStick)
			break;
		status[i] = true;
		subLength -= sticks[i];
		int nextPosition = i; // 剪枝:下一个可选木条必须不长于当前
		if (subLength == 0)	  // 匹配出了一个木棍
		{
			subLength = length;
			nextPosition = 0;
		}
		if (dfs(length, subLength, nextPosition))
		{
			status[i] = false;
			return true;
		}
		else // 当前木条匹配失败
		{
			status[i] = false;
			if (subLength == length)
				subLength = 0;
			subLength += sticks[i];
			if (subLength == length)
				return false; // 剪枝:剩余中最长的木条匹配失败,直接结束
			// 在组合新棍子时，如果添加的第一根棍子stick[i]和剩余的所有棍子都无法组合，则不用继续往下搜索，直接返回（如果继续搜索，到最后stick[i]会被剩下）
			int currentLength = sticks[i]; // 当前选择的木条长度
			while (sticks[++i] == currentLength)
				; // 剪枝:跳过和当前长度相同的木条
		}
	}
	// 没有可选木条
	bool flag = true;
	for (int j = 0; j < countStick; j++)
	{
		flag = flag && status[j];
	}
	if (flag) // 木条已经用完
		return true;
	else
		return false;
}

int main()
{
	cin >> countStick;
	int sum = 0;
	while (countStick != 0)
	{
		sticks = new int[countStick];
		status = new bool[countStick];
		sum = 0;
		for (int i = 0; i < countStick;)
		{
			cin >> sticks[i++];
			sum += sticks[i - 1];
			status[i - 1] = false;
		}
		sort(0, countStick - 1);
		int length = sticks[0];
		while (length < sum)
		{
			while (sum % length != 0) // 剪枝:length为sum的因数
			{
				length++;
			}
			if (dfs(length, length, 0))
			{
				cout << length << endl;
				break;
			}
			else
			{
				length++;
			}
		}
		if (countStick == 1) // 输入一根木条
			cout << length << endl;
		delete[] sticks;
		cin >> countStick;
	}
	return 0;
}