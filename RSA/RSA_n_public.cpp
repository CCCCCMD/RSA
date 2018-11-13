#include<iostream>
using namespace std;

//分解质因子（蛮力）
long getFactors(long long n) {
	int i = 2;
	for (i = 2; i <= n; i++)
		if (n%i == 0)
			break;
	return i;
}

//欧拉函数
long long Euler(long long p, long long q)
{
	return (p - 1)*(q - 1);
}

//求私钥（蛮力）
long privatKey(long long n, long long public_key)
{
	long long p = getFactors(n);
	long long eu = Euler(p, n / p);
	for (int k = 0;; k++) {
		if ((k*eu + 1) % public_key == 0)
			return (k*eu + 1) / public_key;
	}

}

long long trans(long long message, long long key, long long n) {
	long long r = 1;
	key = key + 1;
	while (key != 1) {
		r = r * message;
		r = r % n;
		key--;
	}
	return r;
}

int main()
{
	long long n = 4294967297;
	long public_key = 6473669;
	long private_key = privatKey(n, public_key);
	long long m1 = 5;
	long long c2 = 2;
	cout << "m = " << m1 << "的密文为" << trans(m1, public_key, n) << "\n";
	cout << "c = " << c2 << "的明文为" << trans(c2, private_key, n) << "\n";
	system("pause");
	return 0;
}