#include<iostream>
using namespace std;

int w[25], bestx[25];
int MaxLoading(int n,int c)
{
	int i = 1;
	int *x = new int[n +1];
	int bestw = 0,cw = 0,r = 0;
	for (int j = 1;j <= n;j++)
		r += w[j];
	int temp = r;//�տ�ʼʱ��rΪ������Ʒ����
	while (true) {
		while (i <= n&&cw + w[i] <= c) {//Լ������
			//����������
			r -= w[i];
			cw += w[i];
			x[i] = 1;
			i++;
		}
		if (i > n) {		//����Ҷ�ڵ�

			//for (int j = 1;j <= n;j++) //<δ�Ż�ʱ>�ڱ����Ĺ�����Ҳ�ڼ�¼���Ž⣬��ʹ���Ӷ�����n��
			//	bestx[j] = x[j];
			bestw = cw;
		}
		else {//����������
			r -= w[i];
			x[i] = 0;
			i++;
		}
		while (cw + r <= bestw) {//�޽�����
			//��֦����
			i--;
			while (i > 0 && !x[i]) {
				//������������
				r += w[i];
				i--;
			}
			if (i == 0) { delete[] x;
				goto breakloop;//<�Ż�>���ҵ�����װ�������˳�ѭ��
			}
			//����������
			x[i] = 0;
			cw -= w[i];
			i++;
		}
	}
	breakloop://��ʼ��������װ�����������Ž�
	cw = 0;r = temp;//��cw��r��Ϊ��ʼֵ
	while (true) {
		while (i <= n&&cw + w[i] <= bestw) {
			r -= w[i];
			cw += w[i];
			bestx[i] = 1;
			i++;
		}
		if (i > n) {//������Ҷ�ڵ㣬���ҵ����Ž�bestw[];
			return bestw;
		}
		else {
			r -= w[i];
			bestx[i] = 0;
			i++;
		}
	}
}
int main()
{
	int n,ct=0;
	while (cin >> n)
	{
		int sum = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> w[i];sum += w[i];
		}
		int c1, c2;//���Ҵ�������
		cin >> c1 >> c2;
		cout << "Case " << ++ct << endl;
		int bestw1 = MaxLoading(n, c1);
		if (sum - bestw1 <= c2)//ȫ����װ�ϴ�������
		{
			cout << bestw1<<" ";
			for (int i = 1;i <= n;i++)
				cout <<bestx[i];
			cout << endl<<endl;
		}
		else cout << "No"<<endl<<endl;
	}
	return 0;
}