#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MaxSize 1000
using namespace std;

// 输入样例：

// 123456789050987654321 7

// 输出样例：

// 17636684150141093474 3
void main()
{
  char a[MaxSize];
  int b[MaxSize];
  int c[MaxSize];
  int i;
  int n;
  int x=0;
  int lena=0;
  int lenc=1;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));
  scanf("%s",a);
  scanf("%d",&n);
  for(i=0;i<strlen(a);i++)
  {
    b[i+1]=a[i]-'0';
  }

  lena=strlen(a);

  for(i=1;i<=lena;i++)
  {
    c[i]=(x*10+b[i])/n;
    x=(x*10+b[i])%n;
  }

  while (c[lenc]==0&&lenc<lena)
  {
    lenc++;
  }

  c[0]=lena-lenc+1;
  for(i=1;i<=c[0];i++)
  {
    c[i]=c[lenc];
    lenc++;
  }
  for(i=1;i<=c[0];i++)
  {
    printf("%d",c[i]);
  }
  printf(" %d",x);
  system("pause");

}
