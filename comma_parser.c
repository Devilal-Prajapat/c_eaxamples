#include <stdio.h>
#include <stdint.h>
#include <string.h>


void ProcessGPRMC(char *pData);

int main(void)
{
    char data[] = "GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A";
    ProcessGPRMC(&data[0]);
	return 0;
}


char rmcmessage[50];
char date[6];
char time1[9];
char lat[10];
char lng[11];
void ProcessGPRMC(char *pData)
{
	char *pchar;
	char *str;
	int CommaCount;
	int len;
	strcpy(rmcmessage, pData);
	len= strlen(rmcmessage);
	str = pData;
	pchar = str;
	while(len)
	{
		len--;
		if(*str == ',')
		{
			CommaCount++;
			*str = '\0';
			if(pchar == str)
			{
				pchar = str + 1;
				printf("here");
				 continue;
			}
			switch(CommaCount)
			{
				case 2:
				strcpy(time1, pchar);
				time1[6] = '\0';
				printf("\n%s",time1);
				break;
				case 4:
				strcpy(lat,pchar);
				printf("\n%s",lat);
				break;
				
				case 6:
				strcpy(lng,pchar);
				printf("\n%s",lng);
				break;
				
				case 10:
				strcpy(date,pchar);
				printf("\n%s",date);
				break;
				
				default:
				break;
			}
			pchar = str + 1;
		}
		str++;
	}
}
