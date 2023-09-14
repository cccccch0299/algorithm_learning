#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[9] = {0,8,4,5,7,1,3,6,2};
int temp[9];
int ans = 0;//逆序对
//合并
void merg(int l, int r, int mid)
{
	int i = l, p = l, j = mid;
	while (i < mid && j <= r)//注意i是小于mid因为merg_sort函数已经加过1
	{
		if (a[i] > a[j])
		{
			temp[p++] = a[j++];
			//逆序对只需注意右侧比左侧大
			ans += mid - i;//左侧比a[i]大的都会比a[j]大
		}
		else temp[p++] = a[i++];
	}
	//剩下的
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
//分
void merg_sort(int l,int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		merg_sort(l, mid);
		merg_sort(mid + 1, r);
		merg(l, r, mid + 1);//加1代表右半元素的角标
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
