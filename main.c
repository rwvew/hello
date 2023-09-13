#include <INTRINS.H>
#include <REGX52.H>

void Delay1ms(int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--){
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

int numTable[] = {
	0X3F, 0X06, 0X5B, 0X4F, 0X66,
	0X6D, 0X7D, 0X07, 0X7F, 0X6F
};

void niexie(int LedNo, int Num){
	switch(LedNo){
		case 0:
			P2_4 = 0X01; P2_3 = 0X01; P2_2 = 0X01;
		break;
		case 1:
			P2_4 = 0X01; P2_3 = 0X01; P2_2 = 0X00;
		break;
		case 2:
			P2_4 = 0X01; P2_3 = 0X00; P2_2 = 0X01;
		break;
		case 3:
			P2_4 = 0X01; P2_3 = 0X00; P2_2 = 0X00;
		break;
		case 4:
			P2_4 = 0X00; P2_3 = 0X01; P2_2 = 0X01;
		break;
		case 5:
			P2_4 = 0X00; P2_3 = 0X01; P2_2 = 0X00;
		break;
		case 6:
			P2_4 = 0X00; P2_3 = 0X00; P2_2 = 0X01;
		break;
		case 7:
			P2_4 = 0X00; P2_3 = 0X00; P2_2 = 0X00;
		break;
	}
	P0 = numTable[Num];
	Delay1ms(1);
	P0 = 0X00;
}

void show(unsigned int x){
	unsigned int a = x/1000;
	niexie(0, a);
}

void main(){
	for(;;){
		/*
		niexie(0, 1);
		niexie(1, 2);
		niexie(2, 3);
		niexie(3, 4);
		niexie(4, 5);
		niexie(5, 6);
		niexie(6, 7);
		niexie(7, 8);
		*/
		show(7000);
		
	}
}