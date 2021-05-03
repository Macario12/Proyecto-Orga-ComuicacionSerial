void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,INPUT);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    //Lectura de bytes
    char data[5];
    Serial.readBytes(data,5);
    //Verficaci�n de modo
    bool configurar = true;
    if(data[0] == '1'){
      configurar = false;
    }
    //Acciones
    if(data[1] == '1'){
      digitalWrite(13,HIGH);
    }else{
      digitalWrite(13,LOW);
    }
    if(data[2] == '1'){
      digitalWrite(12,HIGH);
    }else{
      digitalWrite(12,LOW);
    }
    if(data[3] == '1'){
      digitalWrite(11,HIGH);
    }else{
      digitalWrite(11,LOW);
    }
    if(data[4] == '1'){
      digitalWrite(10,HIGH);
    }else{
      digitalWrite(10,LOW);
    }
    if(configurar == true){
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
    }else{
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
    }
    delay(500);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    delay(500);
    if(digitalRead(7) == HIGH){
      Serial.write("00000");
    }else{
      Serial.write("11111");
    }
  }
}
