#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[9] = {0,8,4,5,7,1,3,6,2};
int temp[9];
int ans = 0;//�����
//�ϲ�
void merg(int l, int r, int mid)
{
	int i = l, p = l, j = mid;
	while (i < mid && j <= r)//ע��i��С��mid��Ϊmerg_sort�����Ѿ��ӹ�1
	{
		if (a[i] > a[j])
		{
			temp[p++] = a[j++];
			//�����ֻ��ע���Ҳ������
			ans += mid - i;//����a[i]��Ķ����a[j]��
		}
		else temp[p++] = a[i++];
	}
	//ʣ�µ�
	while (i < mid)
	{
		temp[p++] = a[i++];
	}
	while (j <= r)
	{
		temp[p++] = a[j++];
	}
	i = l, p = l;
	while (p <= r)
	{
		a[i++] = temp[p++];
	}
}
//��
void merg_sort(int l,int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		merg_sort(l, mid);
		merg_sort(mid + 1, r);
		merg(l, r, mid + 1);//��1�����Ұ�Ԫ�صĽǱ�
	}
}



int main()
{
	merg_sort(0, 8);
	for (int i = 0; i <= 8; i++)
		cout << a[i] << ' ';
	cout << endl;
	cout << ans;
}
