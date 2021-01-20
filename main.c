#include <stdio.h>
#include <string.h>
#if 1

//NMT(1,12)
void getPars(char* pStr){
	int p1,p2,bitWidth = 0,i,sum,count = 0;
	unsigned char endFlag = 0;
	float temp1 = 0.1;
	
	char* pStr1 = strchr(pStr,'(' );
	char* pStr2;
	char* pStr3;
	if(pStr1 == 0){
		printf("Fail\n");
		return;
	}
	pStr2 = pStr1;
	
	while(1){
		//  pStr1 = "NMT(123,56)"
		pStr2 = strchr(pStr2,',');
		
		if(pStr2 == 0){
			pStr2 = strchr(pStr2,')');
			endFlag = 1;
		}
		printf("pStr2 is:%s\n",pStr2);
		pStr3 = pStr2;
		bitWidth = pStr2 - pStr1 - bitWidth - 1;// , - (
		for(i=0;i<bitWidth;i++){
			pStr3--;
			sum = *pStr3;
			sum -= 48;//
			temp1 = temp1*10; //123    1*100 + 2*10 + 3*1
			p1 += sum* temp1 ;
		}
		
		printf("p1 is: %d\n",p1);
		pStr2++;// ( + bitWidth + ,
		if(count++ > 10 || endFlag == 1){
			printf("结束\n");
			break;
		}
		//bitWidth = 0;
		//break;
	}
	
	
	

}
#endif
int main(){
	//printf("%d",strstr("NMT(1,12)","NMT"));
	char* str = "NMT(123,56)";
	int* p;
	printf("%p\n",str);
	getPars(str);
	
	return 0;
} 
