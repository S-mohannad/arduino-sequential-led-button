int s=0;
int d=200;
void setup() {
pinMode(0,INPUT_PULLUP);
for(int i=1;i<11;i++)
{pinMode(i, OUTPUT);}
}
void loop() {
s=digitalRead(0);
if(s==0){
 for(int j=1;j<11;j++){
  digitalWrite(j,HIGH);
  delay(d);}
}
else{
 for(int j=1;j<11;j++){
  digitalWrite(j,LOW);
  delay(d);}
}
}