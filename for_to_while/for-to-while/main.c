/*Aynur Nebioğlu
358673
*/

#include <stdio.h>
#include <stdlib.h>
FILE *input;
FILE *output;

char *loopShred(int forStartCounter,int forFinishCounter,char forArray[],char array[])
{
    char a[50],b[50],c[50],d[5000],enter[5000],forSpace[5000];
    int a_finishValue=0,b_startValue=0,b_finishValue=0,c_startValue=0,c_finishValue=0;
    int d_startValue=0,shredCounter=0,valueCounter=0,a_startValue=0,startFinishCounter=0;
    int startBracketCounter=0,forCountCounter=0;
    //For kısmının a b c ve d kısımlarının olduğu yer
    for(int j=0;j<forFinishCounter;j++)
    {
        if(forArray[j]=='f' && forArray[j+1]=='o' &&forArray[j+2]=='r')
        {
            forCountCounter++;
                for(int i=j;i<forFinishCounter;i++)
                  {
                        startFinishCounter=j-1;
                        if(forArray[i]==';' && shredCounter==0)
                        {
                            for(int k=j+3;k<=forFinishCounter;k++)
                            {
                                if(forArray[k]==' '){}
                                else if (forArray[k]=='(')
                                {
                                    startBracketCounter=k;
                                    break;
                                }
                            }
                            for(int k=startBracketCounter+1;k<=forFinishCounter;k++)
                            {
                                if(forArray[k]==' '){}
                                else
                                {
                                    a_startValue=k;
                                    break;
                                }
                            }

                            a_finishValue=i;
                            shredCounter++;
                        }
                        else if(forArray[i]==';' && shredCounter==1)
                        {
                            for(int k=a_finishValue+1;k<=forFinishCounter;k++)
                            {
                                if(forArray[k]==' '){}
                                else
                                {
                                    b_startValue=k;
                                    break;
                                }
                            }
                            b_finishValue=i-1;
                            shredCounter++;
                        }
                        else if(forArray[i]==')' && shredCounter==2)
                        {
                            for(int k=b_finishValue+2;k<=forFinishCounter;k++)
                            {
                                if(forArray[k]==' '){}
                                else
                                {
                                    c_startValue=k;
                                    break;
                                }
                            }
                            c_finishValue=i;
                            for(int k=c_finishValue+1;k<=forFinishCounter;k++)
                            {
                                if(forArray[k]==' '){}
                                if(forArray[k]=='{')
                                {
                                    d_startValue=k+2;
                                    break;
                                }
                        }

                        shredCounter++;
                        }

                        if(shredCounter==3)
                        {
                            shredCounter=0;
                            //Boşluk Hesaplama Kısmı
                            for(int j=0;j<=forCountCounter-2;j++)
                            {
                                forSpace[valueCounter]='\t';
                                valueCounter++;
                            }
                            forSpace[valueCounter]='\0';
                            valueCounter=0;
                            //Giriş Bölümü Hesaplaması
                            for(int j=0;j<=startFinishCounter;j++)
                            {
                                enter[valueCounter]=forArray[j];
                                valueCounter++;
                            }
                            enter[valueCounter]='\0';
                            valueCounter=0;
                            //A Bölümü Hesaplaması
                            for(int j=a_startValue;j<=a_finishValue;j++)
                            {
                                a[valueCounter]=forArray[j];
                                valueCounter++;
                            }
                            a[valueCounter]='\0';
                            valueCounter=0;
                            //B Bölümü Hesaplaması
                            for(int j=b_startValue;j<=b_finishValue;j++)
                            {
                                b[valueCounter]=forArray[j];
                                valueCounter++;
                            }
                            b[valueCounter]='\0';
                            valueCounter=0;
                            //C Bölümü Hesaplaması
                            for(int j=c_startValue;j<=c_finishValue-1;j++)
                            {
                                c[valueCounter]=forArray[j];
                                valueCounter++;
                            }
                            c[valueCounter]='\0';
                            valueCounter=0;
                            //D Bölümü Hesaplaması
                            for(int j=d_startValue;j<forFinishCounter;j++)
                            {
                                d[valueCounter]=forArray[j];
                                valueCounter++;
                            }
                            d[valueCounter]='\0';
                            valueCounter=0;
                            sprintf(forArray,"%s%s\nwhile(%s)\n{\n%s;\n%s",enter,a,b,c,d);
                            break;
                        }
                }
        }
}
    return forArray;
}

int main(int argc,char *argv[])
{
char forArray[5000],inputArray[5000],outputArray[5000],forArray[5000];
int forStartCounter=0,forFinishCounter=0,characterCounter=0,c=0;
int control=-1,temporaryShredCounter=0,i=0,forCounter=0,temporaryCounter=0,decision=1;
input= fopen(argv[1],"r");
output= fopen(argv[2],"w");
//Dosyanın boş olup olmadığının kontrolü ve değerlerin diziye aktarılması
if (input != NULL)
{
    while (!(feof(input)))
    {
                forArray[i] = getc(input);
                characterCounter++;
                i++;
    }
}
else if(input==NULL)
{
    printf("File not found!");
    return 1;
}
characterCounter-=1;
if(characterCounter>0)
{
forArray[characterCounter-1]='\0';
}
else if(characterCounter==0)
{
    printf("The content of the file is empty");
    return -1;
}

for(int i=0;i<characterCounter;i++)
{
    if(forArray[i]=='f' && forArray[i+1]=='o' &&forArray[i+2]=='r')
    {
        forCounter++;
        if(forCounter==1){forStartCounter=i;}
    }
}
//For kısmının başlangıç ve bitiş değerlerinin bulunduğu kısım
for(int j=forStartCounter;j<characterCounter;j++)
{
    if(forArray[j]=='f' && forArray[j+1]=='o' &&forArray[j+2]=='r' )
    {
        temporaryCounter++;
        if(forCounter==temporaryCounter)
        {
            for(int i=forStartCounter;i<characterCounter;i++)
            {
                if(forArray[i]=='{')
                {
                    if(control==-1){control=0;}
                    control++;
                }
                else if(forArray[i]=='}'){control--;}
                if(control==0)
                {
                forFinishCounter=i+1;
                }
            }
        }
    }
}
//For ifadesine kadar olan giriş kısmının tutulduðu dizi
    for(int i=0;i<forStartCounter;i++)
    {
        inputArray[i]=forArray[i];
    }
    inputArray[i+1]='\0';
//For ifadesinin tutulduğu dizi
    for(int i=forStartCounter;i<=forFinishCounter+1;i++)
    {
        forArray[temporaryShredCounter]=forArray[i];
        temporaryShredCounter++;
    }
    forArray[temporaryShredCounter]='\0';
    temporaryShredCounter=0;
//For ifadesinden sonra olan kısmınn tutulduğu dizi
    for(int i=forFinishCounter;i<characterCounter-2;i++)
    {
        outputArray[temporaryShredCounter]=forArray[i];
        temporaryShredCounter++;
    }
    outputArray[temporaryShredCounter]='\0';
    for(i=0;i<=forCounter;i++)
    {
        sprintf(forArray,"%s",loopShred(forStartCounter,forFinishCounter,forArray,forArray));
    }
    printf("\nThe value of the result:\n");
    printf("%s",inputArray);
    printf("%s",forArray);
    printf("%s",outputArray);
    fputs(inputArray,output);
    fputs(forArray,output);
    fputs(outputArray,output);
    fclose(input);
    fclose(output);
    return 0;
}
