#include <stdio.h>
#include <string.h>

char gga[] = "$GPGGA,181908.00,3404.7041778,N,07044.3966270,W,4,13,1.00,495.144,M,29.200,M,0.10,0000*40";
char rmc[] = "$GPRMC,144326.00,A,5107.0017737,N,11402.3291611,W,0.080,323.3,210307,0.0,E,A*20";
char time1[9];
char date[6];
char lat[10];
char lng[11];
char lat_dir = 'N';
char lng_dir = 'W';
char gps_fix = 0;
char satellite[2];
char altitude[6];
char gps_valid;
char speed[5];

void parse_gga(char *ptr)
{    
    char *pchar;
    char *str;//(char *)ptr;
    strcpy(str,ptr); // if ptr where it originally declared is pointer than use this
   // str = ptr;   // use this if ptr is array
    pchar = str;
    int len  = strlen(str);
    printf("%d\n",len);
    int comma_count= 0;
    while(len)
    {
        len--;
        if(*str == ',')
        {
            comma_count++;
            *str = '\0';
            if(pchar == str)
			{
				pchar = str + 1;
				//printf("here");
				continue;
			}
           
            switch(comma_count)
            {
                case 1:// gpgga
                printf("gpgga %s\n",pchar);
                break;
                case 2:// time
                    strcpy(time1, pchar);
                    time1[6] = '\0';
                    printf("time %s\n",time1);
                break;// lat
                case 3:
                    strcpy(lat, pchar);
                    printf("lat %s",lat);
                break;
                case 4: // lat dir
                    lat_dir = pchar[0];
                    printf("%c\n",lat_dir);
                break;
                case 5:// lng
                    strcpy(lng, pchar);
                    printf("lng %s",lng);
                break;
                case 6: // lng dir
                    lng_dir = pchar[0];
                    printf("%c\n",lng_dir);
                break;
                case 7: // fix
                    gps_fix = pchar[0];
                    printf("gps fix %c\n",gps_fix);
                break;
                case 8: // num of satellite
                strcpy(satellite, pchar);
                printf("sat %s\n",satellite);
                break;
                case 10: //altitude
                strcpy(altitude, pchar);
                printf("alt %s\n",altitude);
                break;
                default:
                break;
            }
            pchar = str+1;
            }
        str++;
    }
}

void parse_rmc(char *ptr)
{
    char *pchar;
    char *str;//(char *)ptr;
    strcpy(str,ptr); // if ptr where it originally declared is pointer than use this
   // str = ptr;   // use this if ptr is array
    pchar = str;
    int len  = strlen(str);
    printf("%d\n",len);
    int comma_count= 0;
    while(len)
    {
        len--;
        if(*str == ',')
        {
            comma_count++;
            *str = '\0';
          if(pchar == str)
			{
				pchar = str + 1;
				//printf("here");
				continue;
			}
           
            switch(comma_count)
            {
                case 1:// gprmc
                printf("gprmc %s\n",pchar);
                break;
                
                case 2:// time
                strcpy(time1, pchar);
                    time1[6] = '\0';
                    printf("time %s\n",time1);
                break;// gps valid
                case 3:
                    gps_valid = pchar[0];
                    printf("gps_valid %c\n",gps_valid);
                break;
                
                case 4:// lat
                    strcpy(lat, pchar);
                    printf("lat %s",lat);
                break;
                
                case 5: // lat  dir
                    lat_dir = pchar[0];
                    printf("%c\n",lat_dir);
                break;
                
                case 6:// lng
                    strncpy(lng, pchar,11);
                    printf("lng %s",lng);
                break;
                
                case 7: // lng dir
                    lng_dir = pchar[0];
                    printf("%c\n",lng_dir);
                break;
                
                case 8: // speed
                    strcpy(speed, pchar);
                    printf("speed %s\n",speed);
                break;
                case 9: //track true
                //strcpy(satellite, pchar);
                printf("track %s\n",pchar);
                break;
                case 10: //date
                strcpy(date, pchar);
                printf("date %s\n",date);
                break;
                default:
                break;
            }
            pchar = str+1;
            }
        str++;
    }
}

int main()
{
    printf("Hello World\n");
    parse_gga(gga);
    parse_rmc(rmc);
    return 0;
}
