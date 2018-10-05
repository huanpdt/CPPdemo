#include "stdio.h"
#include "conio.h"
char hexbin[16][5]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
char hexdigit[17]="0123456789ABCDEF";
void printchar2bit(unsigned char c)
{
	int i=0;
	for(;i<8;i++)
	{
		printf("%u",(c&0x80)==0x80);
		c = c<<1;
	}	
	printf(" "); 	
}	
void printchar2hex(unsigned char c)
{
	unsigned char left = (c & 0xF0)>>4;
	unsigned char right = c & 0x0F;
	printf("%c%c ",hexdigit[left],hexdigit[right]);
}
void printbit(unsigned char*p, int size)
{
	int i=0;
	for(;i<size;i++)
		printchar2bit(*(p+i));
}
void printhex(unsigned char *p, int size)
{
	int i=0;
	for(;i<size;i++)
		printchar2hex(*(p+i));

}
void printbit_rev(unsigned char*p, int size)
{
	int i=size-1;
	for(;i>=0;i--)
		printchar2bit(*(p+i));
}
void printhex_rev(unsigned char*p, int size)
{
	int i=size-1;
	for(;i>=0;i--)
		printchar2hex(*(p+i));
}
void dumpbyte(unsigned char *p)
{
	printf("%12p:",p);
	printchar2hex((unsigned char)(*p));
	printchar2bit((unsigned char)(*p));
	printf("\n");
}
int main()
{
	int x;
	float f;
	unsigned char *p;
	printf("Chuong trinh xem day bit cua so nguyen/so thuc\n");
	printf("\n---------INT 2 BIT---------------");
	printf("\nNhap vao so nguyen x= ");
	scanf("%d",&x);
	printf("\nSize of %d = %d",x,sizeof(x));
	printf("\nDay bit: %8d = ",x);
	p=(unsigned char*)&x;
	printf("\n");printhex(p,4);
	printf("\n");printbit(p,4);
	printf("\nDay bit dung (reverse little endian):");
	printf("\n");printhex_rev(p,4);
	printf("\n");printbit_rev(p,4);
	printf("\nBytes dumped:\n");
	dumpbyte(p);dumpbyte(p+1);dumpbyte(p+2);dumpbyte(p+3);
	printf("\n");
	//----------------------
	printf("\n---------Float 2 BIT---------------");
	printf("\nNhap vao so thuc f= ");
	scanf("%f",&f);
	printf("\nSize of %f = %d",f,sizeof(f));
	printf("\nDay bit: %8f = ",f);
	p=(unsigned char*)&f;
	printf("\n");printhex(p,4);
	printf("\n");printbit(p,4);
	printf("\nDay bit dung (reverse little endian):");
	printf("\n");printhex_rev(p,4);
	printf("\n");printbit_rev(p,4);
	printf("\nBytes dumped:\n");
	dumpbyte(p);dumpbyte(p+1);dumpbyte(p+2);dumpbyte(p+3);
	printf("\n");
	//----------------
	printf("\n---------OVERFLOW SAMPLE---------------");
	char a = 100, b= 50, c;
	c = a+b;
	printf("\na= %d, b= %d, c= a+b = %d",a,b,c);
	printf("\nday bit %4d:",a);
	printchar2bit((unsigned char)(a));
	printf("\nday bit %4d:",b);
	printchar2bit((unsigned char)(b));
	printf("\nday bit %4d:",c);
	printchar2bit((unsigned char)(c));
	printf("\n");
	getch();
	return 0;
}
