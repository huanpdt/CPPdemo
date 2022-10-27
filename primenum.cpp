//Chương trình phân tích 1 số nguyên dương ra thừa số nguyên tố
//20221026 - huanpdt
#include "stdio.h"

int main()
{
    unsigned int n = 91;
    unsigned int pnum = 2;
    unsigned int divcount = 0;
    unsigned int numofprime = 0;
    //nhập số nguyên dương n
    printf("Nhap so nguyen duong n = ");
    scanf("%u",&n);
    printf("Danh sach thua so nguyen to cua %d: ",n);
    numofprime = 0;
    while(pnum<=n)
    {
        divcount = 0;
        while(n%pnum==0)
        {
            n = n/pnum;
            divcount ++;
            if(divcount == 1)
                printf("%d ^ ",pnum);
        }
        if(divcount !=0) 
        {
            numofprime++;
            if(pnum<n)
               printf("%d x ",divcount);     
            else
                printf("%d", divcount);      
        }
        pnum++;
    }
    printf("\nCo %d thua so nguyen to", numofprime);
    return 1;
}