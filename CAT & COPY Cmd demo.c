/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int  main(int argc,char *argv[])
{
        int n;
        char name[10];
        FILE *fp,*fq;
        char ch;
        printf("1.enter for cat\n");
        printf("2.enter for copy\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:


                fp=fopen(argv[1],"r");
                while((ch=getc(fp))!=EOF)
                {
                        printf("%c",ch);
                }
                fclose(fp);
                break;
        case 2:
                printf("enter the destination file name\n");
                scanf("%s",name);
                fp=fopen(argv[1],"r");
                fq=fopen(name,"w");
                while((ch=getc(fp))!=EOF)
                {
                        putc(ch,fq);
                }
                fclose(fp);
                fclose(fq);
                break;
        }

        return 0;
}
