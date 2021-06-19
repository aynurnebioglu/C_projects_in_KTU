/* Aynur Nebioğlu
358673
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void polynomialDecomposition(char *argv[]);

int main(int argc,char *argv[])
{
polynomialDecomposition(argv);//Polinomu polinom_parcalama() fonksiyonuna yolladım.
}

 void polynomialDecomposition(char *argv[])
 {
    char integralVariant=argv[5][0];
    int sizeOfExpression=0,i=1,j,polynomialCounter=0,constant=0;
    double minValueOfIntegral,maxValueOfIntegral;
    int shredValue=atoi(argv[4]);
    int arrayCoefficients[sizeOfExpression];
    int arrayUpperValues[sizeOfExpression];

    while(argv[1][sizeOfExpression]!=0)//Polinomun karakter uzunluğunu belirledim.
    {sizeOfExpression++;}


   if(argv[1][0]=='x')//Polinomun ilk hanesine x geldiği durumda dizi_katsayilari dizisine 1 değerini atadım.
   {
            polynomialCounter++;
            arrayCoefficients[polynomialCounter]=1;
            if(argv[1][1]=='+'||argv[1][1]=='-')
            {
                arrayUpperValues[polynomialCounter]=1;
                /*X hanesinden sonraki hanesinde + veya - gelmesini durumunda üs degeri 1 olarak
                dizi_usdegerleri dizisine aktardım.*/
            }
   }
   for(i=1;i<sizeOfExpression;i++)
   {
            if(argv[1][i]=='x')
            {
                polynomialCounter++;
                if(argv[1][i+1]=='+'||argv[1][i+1]=='-'){arrayUpperValues[polynomialCounter]=1;}
                /*X hanesinden sonraki hanesinde + veya - gelmesini durumunda üs degeri 1 olarak
                dizi_usdegerleri dizisine aktardım.*/
                if(argv[1][i-1]=='+'){arrayCoefficients[polynomialCounter]=1;}/*X hanesinden önceki
                haneye ne geldiğini kontrol ettirdim.+ gelmesi durumunda 1 değerini dizi_usdegerleri
                dizisine aktardım.*/
                else if(argv[1][i-1]=='-'){arrayCoefficients[polynomialCounter]=-1;}/*X hanesinden önceki
                haneye ne geldiğini kontrol ettirdim.- gelmesi durumunda -1 değerini dizi_usdegerleri
                dizisine aktardım.*/
                else{arrayCoefficients[polynomialCounter]=((int)argv[1][i-1])-48;}/*X hanesinden önceki
                haneye ne geldiğini kontrol ettirdim.+ veya - gelmediğinden sayı gelecektir.
                Bu durumunda değerini dizi_katsayilari dizisine aktardım.*/

                if(argv[1][i-2]=='-'){arrayCoefficients[polynomialCounter]*=-1;}/*X hanesinden 2 önceki
                değerinin - gelmesi durumunda değeri -1 ile çarparak dizi_katsayilari dizisine attım.
                + gelmesi durumunda ise birşey aktarmadım.*/
                if(argv[1][i]=='x' && argv[1][i-1]=='-'){arrayCoefficients[polynomialCounter]=-1;}
                //Girilen ilk x ifadesinin ön hanesinde - işaretini kontrol ettirdim.
            }
            if(argv[1][i]=='^')
            /*^ karakterinden sonra gelen haneyi direk dizi_usdegerleri dizisine aktardım.*/
            {arrayUpperValues[polynomialCounter]=((int)argv[1][i+1])-48;}

        }



    if(argv[1][sizeOfExpression-2]=='-'){constant=(((int)argv[1][sizeOfExpression-1])-48)*-1;}
    //Sabit değer - geldiği durumda -1 ile çarptırıp sabit değişkenine aktardım.
    else{constant=((int)argv[1][sizeOfExpression-1])-48;}
    //Sabit değer + geldiği durumda sabit değişkenine aktardım.


    minValueOfIntegral=((double)argv[2][0])-48;
    maxValueOfIntegral=((double)argv[3][0])-48;
    printf("Entered polynomial expression\t:%s\n",argv[1]);
    printf("Start value\t:%.2f \n",minValueOfIntegral);
    printf("Finish value\t\t:%.2f\n",maxValueOfIntegral);
    printf("Amount of shredding\t:%d\n",shredValue);
    printf("operation type\t:");
    if(integralVariant=='0'){printf("Rectangle Rule\n");}
    if(integralVariant=='1'){printf("Midpoint Rule\n");}
    if(integralVariant=='2'){printf("Trapezoid Rule\n");}
    if(integralVariant=='3'){printf("Simpson's Rule\n");}


    if(polynomialCounter<=0)/*İfadenin polinom olup olmadığını polinom_sayaci değişkenin aldığı değeri
        kontrol ettirerek baktırdım.*/
    {
    printf("Invalid polynomial expression:%s",argv[1]);
    return -1;
    }
    for(i=1;i<=polynomialCounter;i++)//Polinom ifadesindeki üsleri,katsayıları ve sabitleri yazdırdım.
    {
        printf("%d.coefficient value of the term:%d \n",i,arrayCoefficients[i]);
        printf("%d.upper value of the term \t:%d \n",i,arrayUpperValues[i]);
    }
    printf("constant number value\t:%d\n",constant);


    double theoremResult=0;
    double temporaryResult=0;
    double incrementAmount=(maxValueOfIntegral-minValueOfIntegral)/shredValue;
    /*Komut ekranından girilen büyük sayı ile küçük sayı arasındaki farkı bulup istenilen parcalama_degeri
     değişkenine böldürterek her adımdaki artış miktarını buldurdum.*/
    double temporaryMaxValueOfIntegral=minValueOfIntegral+incrementAmount;/*Üst sınır her adımda değişeceği
    için integralin_gecici_buyuk_degeri adlı bir değişkene ihtiyaç duydum.*/
     switch(integralVariant)
     {
        case '0'://Rectangle Rule için hesaplama yaptırdım.
            for(i=0;i<shredValue;i++)
            {
                    for(j=1;j<=polynomialCounter;j++)
                    {temporaryResult+=(double)arrayCoefficients[j]*pow(minValueOfIntegral,(double)arrayUpperValues[j]);}/*Gerekli
                    olan formülün uygulamasını yaptım.*/
            temporaryResult+=constant;//Oluşan geçici sonuca sabit sayısını ekledim.
            theoremResult+=temporaryResult*(temporaryMaxValueOfIntegral-minValueOfIntegral);
            minValueOfIntegral=temporaryMaxValueOfIntegral;/*Sonraki adımda integralin_gecici_buyuk_degeri integralin_kucuk_degeri
            olacağı için değer aktarma işlemi yaptım.*/
            temporaryMaxValueOfIntegral+=incrementAmount;/*Sonraki adımda integralin_gecici_buyuk_degeri artış miktarı kadar artması
            gerekeceği için değer artırma işlemi yaptım.*/
            temporaryResult=0;//gecici_sonuc değişkenini sıfırlayarak bir sonraki aralıktaki değerleri adım adım almayı sağlıyoruz.
            }
        break;
        case '1'://Midpoint Rule için hesaplama yaptırdım.
            for(i=0;i<shredValue;i++)
            {
                    for(j=1;j<=polynomialCounter;j++)
                    {temporaryResult+=(double)arrayCoefficients[j]*pow((minValueOfIntegral+temporaryMaxValueOfIntegral)/2,(double)arrayUpperValues[j]);}
                    //Gerekli olan formülün uygulamasını yaptım.
            temporaryResult+=constant;//Oluşan geçici sonuca sabit sayısını ekledim.
            theoremResult+=temporaryResult*(temporaryMaxValueOfIntegral-minValueOfIntegral);
            minValueOfIntegral=temporaryMaxValueOfIntegral;/*Sonraki adımda integralin_gecici_buyuk_degeri integralin_kucuk_degeri
            olacağı için değer aktarma işlemi yaptım.*/
            temporaryMaxValueOfIntegral+=incrementAmount;/*Sonraki adımda integralin_gecici_buyuk_degeri artış miktarı kadar artması
            gerekeceği için değer artırma işlemi yaptım.*/
            temporaryResult=0;//gecici_sonuc değişkenini sıfırlayarak bir sonraki aralıktaki değerleri adım adım almayı sağlıyoruz.
            }
        break;
        case '2'://Trapezoid Rule için hesaplama yaptırdım.
            for(i=0;i<shredValue;i++)
            {
                    for(j=1;j<=polynomialCounter;j++)
                    {temporaryResult+=(double)arrayCoefficients[j]*pow(minValueOfIntegral,(double)arrayUpperValues[j]);}
                    //Gerekli olan formülün uygulamasını yaptım.
                    temporaryResult+=constant;//Oluşan sonuca sabit sayısını ekledim.
                    for(j=1;j<=polynomialCounter;j++)
                    {temporaryResult+=(double)arrayCoefficients[j]*pow(minValueOfIntegral,(double)arrayUpperValues[j]);}
                    //Gerekli olan formülün uygulamasını yaptım.
            temporaryResult+=constant;//Oluşan geçici sonuca sabit sayısını ekledim.
            theoremResult+=(temporaryResult/2)*(temporaryMaxValueOfIntegral-minValueOfIntegral);
            minValueOfIntegral=temporaryMaxValueOfIntegral;/*Sonraki adımda integralin_gecici_buyuk_degeri integralin_kucuk_degeri
            olacağı için değer aktarma işlemi yaptım.*/
            temporaryMaxValueOfIntegral+=incrementAmount;/*Sonraki adımda integralin_gecici_buyuk_degeri artış miktarı kadar artması
            gerekeceği için değer artırma işlemi yaptım.*/
            temporaryResult=0;//gecici_sonuc değişkenini sıfırlayarak bir sonraki aralıktaki değerleri adım adım almayı sağlıyoruz.
            }
        break;
        case '3'://Simpson’s Rule için hesaplama yaptırdım.
            for(i=0;i<shredValue;i++)
            {
                    for(j=1;j<=polynomialCounter;j++)
                    {temporaryResult+=(double)arrayCoefficients[j]*pow((minValueOfIntegral+temporaryMaxValueOfIntegral)/2,(double)arrayUpperValues[j]);}
                    //Gerekli olan formülün uygulamasını yaptım.
            temporaryResult+=constant;//Oluşan geçici sonuca sabit sayısını ekledim.
            temporaryResult*=4;//Gerekli olan formülün uygulamasını yaptım.
                    for(j=1;j<=polynomialCounter;j++)
                    {temporaryResult+=(double)arrayCoefficients[j]*pow(temporaryMaxValueOfIntegral,(double)arrayUpperValues[j]);}
                    //Gerekli olan formülün uygulamasını yaptım.
            temporaryResult+=constant;//Oluşan geçici sonuca sabit sayısını ekledim.
                    for(j=1;j<=polynomialCounter;j++)
                    {temporaryResult+=(double)arrayCoefficients[j]*pow(minValueOfIntegral,(double)arrayUpperValues[j]);}
                    //Gerekli olan formülün uygulamasını yaptım.
            temporaryResult+=constant;//Oluşan geçici sonuca sabit sayısını ekledim.
            theoremResult+=temporaryResult*((temporaryMaxValueOfIntegral-minValueOfIntegral)/6);//Gerekli olan formülün uygulamasını yaptım.
            minValueOfIntegral=temporaryMaxValueOfIntegral;/*Sonraki adımda integralin_gecici_buyuk_degeri integralin_kucuk_degeri
            olacağı için değer aktarma işlemi yaptım.*/
            temporaryMaxValueOfIntegral+=incrementAmount;/*Sonraki adımda integralin_gecici_buyuk_degeri artış miktarı kadar artması
            gerekeceği için değer artırma işlemi yaptım.*/
            temporaryResult=0;//gecici_sonuc değişkenini sıfırlayarak bir sonraki aralıktaki değerleri adım adım almayı sağlıyoruz.
         }break;
        }
    printf("Result of the integral\t:%.2f",theoremResult);
}


