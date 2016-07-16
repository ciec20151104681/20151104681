#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int a,i=0,n=0;
	char *str;
	char lat[10];
	char lon[11];
	char date[11];
	char time[10];
	FILE *fp,*fp1;
	fp=fopen("C:\\Users\\jszx\\Desktop\\export.gpx","r");
	fp1=fopen("hello.csv","w");
	if(fp==NULL)
	{
		printf("It is wrong!");
		return -1;
	}
	else
	{
	    fseek(fp,SEEK_SET,SEEK_END);
	    a=ftell(fp);
	    fseek(fp,1,SEEK_SET);
	    str=(char *)malloc(1*a);
	    fread(str,sizeof(char),a,fp);
	}
	fprintf(fp1,"序号,经度,纬度,日期,时间\n");
	while(!(str[i]=='<'&&str[i+1]=='/'&&str[i+2]=='g'&&str[i+3]=='p'&&str[i+4]=='x'&&str[i+5]=='>'))
	{
	if(str[i]==' '&&str[i+1]=='l'&&str[i+2]=='a'&&str[i+3]=='t')
	  {
			strncpy(lat,&str[i+6],9);
			strncpy(lon,&str[i+22],10);
			strncpy(date,&str[i+44],10);
			strncpy(time,&str[i+55],8);
			lat[9]='\0';
			lon[10]='\0';
			date[10]='\0';
			time[9]='\0';
			printf("%s   %s   %s   %s\n",lat,lon,date,time);
			fprintf(fp1,"%d,%s,%s,%s,%s\n",n+1,lat,lon,date,time);
			n++;
	  }
		i++;
	}
	fclose(fp);	
	fclose(fp1);	
	return 0;
}


