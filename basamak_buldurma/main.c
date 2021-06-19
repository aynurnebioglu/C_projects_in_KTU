/*
Aynur Nebioğlu / 358673
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int k,i,sum = 0,remaining = 0,d1,string_of_numbers_entered[10];
static int stepValue = 10,stepRemainder,enteredNumber;
int main(int argc,char *argv[])
{
  enteredNumber = atoi(argv[1]);/*Burada girilen string sayıyı atoi
  fonksiyonu ile integer girilensayi değişkenine aktardım.*/
  d1 = d1_calculation(enteredNumber);/*d1 sayısını hesaplamak ve girilen
  sayıyı basamaklarına ayırıp integer girilen sayılar dizisine
  aktarmak için d1 hesaplama fonksiyonunu kullandım.Geriye de
  bulunan d1 sayısını döndürdüm.*/
  d1_add(d1,string_of_numbers_entered);/*Elde edilen d1 sayısını  alınan
  sayılarla birlikte ekrana yazdırmak için d1 ekleme
  fonksiyonunu çalıştırdım.*/
  return 0;
}

void d1_add(int d1,int string_of_numbers_entered[])/*d1 sayısını programın
başında  alınan sayıya ekleme işlemi yaptım*/
{
  for(i=8;i>=0;i--)
  {
      printf("%d",string_of_numbers_entered[i]);/*Diziye aktarmış olduğum
      sayıları yazdırdım.*/
  }
  if(d1==10){printf("X\n");}/*Programın başında girilmiş olan sayılara
  ek olarak d1 sayısı 10 ise X simgesini ekledim.*/
  else{printf("%d\n",d1);}/*Programın başında girilmiş olan sayılara
  ek olarak d1 sayısı değerini ekledim.*/
  return 0;
}
int d1_calculation(int enteredNumber)/*Girilen sayıyı bu fonksiyonda
basamaklarına ayırıp dizinin indislerine aktardım ve 11'e bölüne
bilmesi için gereken d1 sayının hesaplama işlemini yaptım.*/
{
  for(k=0;k<9;k++)
  {
  stepRemainder = enteredNumber%stepValue;/*Programın başında girilmiş
  olan integer sayının 10 ve katları şeklinde modunu alarak
  sayının o basamaktaki değerine ulaştım.*/
  stepRemainder/=stepValue/10;/*Burada sayının basamak değerini
  birler onlar yüzler diye artırarak böldürüp bölüm sayısını
  elde ettim.Bu değer aynı zamanda dizide tutacak olduğum değerdir.*/
  string_of_numbers_entered[k]=stepRemainder;/*Burada buldurduğum bölüm
  değerini dizinin indisleri şeklinde aktarma yaptırdım.*/
  enteredNumber-=stepRemainder;/*Burada bir sonraki adımda bulduracağım
  basamak değerinde şu anki bulduğum değeri çıkararak işlemin
  uzamamasını sağladım.*/
  stepValue*=10;/*Burada bir sonraki adımda basamak değeri
  yani birlerse onlar onlarsa binler yapabilmek için çarpma
  işlemi yaptım.*/
  }
  for(i=0;i<=8;i++)
  {
      printf("\n%d .Value:%d",i+2,string_of_numbers_entered[i]);/*Dizideki
       indis değerlerini yazdırdım.*/
      sum += (i+2)*(string_of_numbers_entered[i]);/*Burada dizideki
      basamak değerlerini katsayılarına uygun şekilde toplattım.*/
  }
  printf("\nTotal Value:%d",sum);//Toplam değeri yazdırttım.
  remaining = (sum%11);/*Toplam değerin modunu alarak kalan değeri
  hesapladım.*/
  if(remaining==0)
  {
      d1=0;
      printf("\nValue of d1:%d\n",d1);/*Normalde kalan değeri
      11'den çıkarıyordum.Ancak burada 0 olursa 11'den çıkarldığında
      11 değeri olacaktı d1 değeri bunu engellemek için
      if şartı kullandım.*/
  }
  else if(remaining!=0)
  {
        d1=(11-remaining);/*Burada kalan değerini 11'den çıkarıyorum,
        çünkü eklenecek olan sayı olan d1 sayısı ile 11'e tam
        bölünebilmesi gerekiyor.*/
        printf("\nvalue of d1:%d\n",d1);
  }
  return d1;
}
