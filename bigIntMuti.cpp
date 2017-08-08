#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <typeinfo>
using namespace std;

struct bigdatacom
{
  private:
    char dataa[100];
    char datab[100];

  public:
    void init(const char *str1, const char *str2)
    {
        strcpy(this->dataa, str1);
        strcpy(this->datab, str2);
    }
    char *getbigdata()
    {

        int lengtha = strlen(dataa);
        int lengthb = strlen(datab);
        int *pres = (int *)malloc(sizeof(int) * (lengtha + lengthb));
        memset(pres, 0, sizeof(int) * (lengtha + lengthb)); //初始化
        //累乘
        for (int i = 0; i < lengtha; i++)
        {
            for (int j = 0; j < lengthb; j++)
            {
                pres[i + j + 1] += (dataa[i] - '0') * (datab[j] - '0');
            }
        }
        //进位
        for (int i = lengtha + lengthb - 1; i >= 0; i--)
        {
            if (pres[i] >= 10) //进位
            {
                pres[i - 1] += pres[i] / 10; //进位
                pres[i] %= 10;//取出个位数
            }
        }
        int i = 0;
        while (pres[i] == 0)
        {
            i++; //恰好不为0的位置
        }
        char *lastres = (char *)malloc(sizeof(char) * (lengtha + lengthb));
        int j;
        for (j = 0; j < lengtha + lengthb; j++, i++)
        {
            lastres[j] = pres[i] + '0';
        }
        lastres[j] = '\0';
        printf("结果=%s",lastres);

        return lastres;
    }
};

int main()
{
    bigdatacom big1; //C语言中结构体定义必须带struct,C++中不必
    big1.init("234546869966543", "45663453223323423423");
    string s = big1.getbigdata();
    return 0;
}