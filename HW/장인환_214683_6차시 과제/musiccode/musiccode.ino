int mynote[]={784,659,784,659,784,880,659};
int mydu[]={250,250,250,250,250,250,500};
void setup(){
  for(int i=0; i<7; i++){
    tone(5, mynote[i], mydu[i]);
    delay(mydu[i]*1.3);
    noTone(3);
  }
}
void loop(){

}