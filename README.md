# Arduino random sayı üretimi için farklı bir yaklaşım
arduino random sayı üreteci, zar oyunu, 1-6 arasında sayi üretir. kod myArray dizinisini sürekli karıştırarak random sıralalar üretir ve dizinin son elemanını 7segmente yazarak kullanıcı için random sayı üretir.

kod açıklaması:

```
int myArray[6] = {1, 2, 3, 4, 5, 6};
```

```
// 50 defa çalışır.
for(int i=1; i<50; i++ ) randomize(myArray);
```

```
// myArray dizisini karıştırır
void randomize(int myArray[]) {
  for (int i = 0; i < 6; i++) {
    int j = random(0, 6);
    swap(myArray[i], myArray[j]);
  }
}
```

```
// animasyonlu şekilde 7 segmente'e sayilari yazar, dizideki en son sayi ürettiği sayıdır.
for(int i = 0; i<6; i++) {
  sound(1,30);
  randNumber = myArray[i];
  clear7Segment();
  SayiYaz(randNumber);
  delay(60);
}
```
