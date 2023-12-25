#include<iostream>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int n;
ll a[N], tmp[N]; 

void mergesort(ll a[], int l, int r)
{
	if(l >= r) return;
	int mid = l + r >> 1;
	mergesort(a, l, mid);
	mergesort(a, mid+1, r);
	int i = l, j = mid+1, k = 0;
	while(i <= mid && j <= r) a[i] > a[j] ? tmp[k++] = a[j++] : tmp[k++] = a[i++];
	while(i <= mid ) tmp[k++] = a[i++];
	while(j <= r) tmp[k++] = a[j++];
	for(i = l,j = 0; i <= r; i++,j++) a[i] = tmp[j];
}


int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	mergesort(a, 0, n-1);
	for(int i = 0; i < n; i++) printf("%d", a[i]);
	return 0;
 } 