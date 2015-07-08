//Robotistan.com L298 motor sürücü kartı örnek kodu.


int ENA = 10;   //MotorA çıkışı için pwm kontrol pini
int ENB = 11;  //MotorB çıkışı için pwm kontrol pini
int INA = 12;  //MotorA çıkışı için yön kontrol pini
int INC = 13;  //MotorB çıkışı için yön kontrol pini
int hiz = 0;   //hız değeri

void setup()
{
  pinMode(ENA, OUTPUT);  //Kontrol pinleri çıkış olarak ayarlanır
  pinMode(ENB, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(INC, OUTPUT);

  analogWrite(ENA, 0);  //İki motor da durur
  analogWrite(ENB, 0);

}

void loop()
{ 
  ileri();           //İki motor da ileri. Bu fonksiyonda hız tanımlanmamıştır. Hız ayarı hızlan() ve yavasla() fonksiyonları ile yapılır.  
  hizlan();          //Motor pwm değerleri 0'dan 255'e çıkarılır.
  delay(1000);       //1 saniye bekle.
  tam_hiz_ileri();   //Tam hız dönmeye devam eder.
  delay(1000);    
  yavasla();         //Motor pwm değerleri 255'den 0'a düşürülür.
  delay(1000);    

  dur();             //2 saniye dur.
  delay(2000);    


  geri();           //İki motor da geri. Bu fonksiyonda hız tanımlanmamıştır. Hız ayarı hızlan() ve yavasla() fonksiyonları ile yapılır.
  hizlan();         //Motor pwm değerleri 0'dan 255'e çıkarılır.
  delay(1000);  
  tam_hiz_geri();   //Tam hız dönmeye devam eder.
  delay(1000);
  yavasla();        //Motor pwm değerleri 255'den 0'a düşürülür.
  delay(1000);
}


/* ileri() ve geri() fonksiyonları motorların pwm sinyali alınca hangi yöne döneceğini belirler.
 Yani sadece ileri() ve geri() fonksiyonlarını çağırmak motorları hareket ettirmez. 
 Aynı şekilde sadece hızlan() ve yavasla() fonksiyonlarını çağırmakta motorları hareket ettirmez.
 Bu fonksiyonlardan önce ileri() ve geri() fonksiyonlarının çağırılması gerekir.
 Ancak motorların hareket etmesi için tam_hız_ileri() veya tam_hız_geri() fonksiyonlarını çağırmak yeterlidir.
 Çünkü bu fonksiyonlar hem yön bilgisini hemde hız bilgisini içinde barındırır. Eğer motorlar hız kontrolü
 yapılmak istenmiyorsa ENA ve ENB pinlerinin arduino ile bağlantıları sökülerek bu pinlerin 5V ile arasındaki
 jumperlar geri takılarak motorların istenilen yönde sürekli tam hızda dönmesi sağlanabilir. 
 */

void ileri()
{ 
  digitalWrite(INA, HIGH);  
  digitalWrite(INC, HIGH); 
}

void geri() 
{
  digitalWrite(INA, LOW);   
  digitalWrite(INC, LOW); 
}

void tam_hiz_ileri() 
{ 
  digitalWrite(INA, HIGH);  
  digitalWrite(INC, HIGH);  
  analogWrite(ENA, 255);    
  analogWrite(ENB, 255);
}

void tam_hiz_geri()
{
  digitalWrite(INA, LOW);  
  digitalWrite(INC, LOW); 
  analogWrite(ENA, 255);   
  analogWrite(ENB, 255);
}

void dur() 
{ 
  digitalWrite(INA, LOW);   
  digitalWrite(INC, LOW); 
  analogWrite(ENA, 0);    
  analogWrite(ENB, 0); 
}

void hizlan()
{ 

  for(int hiz_degeri = 0 ; hiz_degeri <= 255; hiz_degeri +=5) 
  { 
    analogWrite(ENA, hiz_degeri);   
    analogWrite(ENB, hiz_degeri);       
    delay(30);                            
  } 
}

void yavasla()
{ 
  for(int hiz_degeri = 255 ; hiz_degeri >= 0; hiz_degeri -=5) 
  { 
    analogWrite(ENA, hiz_degeri);
    analogWrite(ENB, hiz_degeri);  
    delay(30);  
  }
}






