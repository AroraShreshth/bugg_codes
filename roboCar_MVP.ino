//This Code writes a silly MVP on ground idk why i wote this ;-)
void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);

}

void loop() {
 MZP();
}

void MZP(){
 M(3000,450);
 
 rotate(800, -2);
 translate(500,1);
 rotate(800, 2);
 translate(3000,1);
 rotate(800, -2);
 
 Z(3000,450);
 
 translate(500,1);
 rotate(800,2);
 P(3000,800);
}

void P(int dist, int angle){
  translate(dist,1);
  rotate(angle,-2);
  for(int i=1;i<140;i++){
    forward(dist/150);
    rotate(800/100,-2);
  }
  pause(10000);
}
void Z(int dist, int angle){
  translate(dist,1);
  rotate(angle,2);//Rotate 60 degrees
  translate(dist*1.4,-1);
  rotate(angle,-2);//Rotate -60 degrees
  translate(dist,1);
  delay(1000);
}

void M(int dist, int angle){
  translate(dist,1);
  rotate(angle,2);//Rotate 60 degrees
  translate(dist/2,-1);
  rotate(angle*2,-2);//Rotate -120 degrees
  translate(dist/2,1);
  rotate(angle,2);//Rotate 60 degrees
  translate(dist,-1);
  delay(1000);
}

void triangle(){
  translate(3000,1);
  pause(100); //Forward
  
  rotate(540,-2);//Rotate 60 degrees
  translate(3000,-1);
  
  rotate(300,-2);
  translate(3000,1); //Rotate 60 Degrees

  pause(4000);
  
}

void plus(){

  translate(1500,1);
  pause(100);
  translate(3000,-1);
  pause(100);
  translate(1500,1);
  pause(100);
  rotate(800,2);
  translate(3000,1);
  pause(100);
  translate(1500,-1);
  pause(100);
  rotate(1400,2);
  translate(1500,1);
  pause(100);
  translate(1500,-1);
  rotate(800,-2);
  rotate(2800,2);
  pause(100);
  rotate(2800,2);
  
  pause(2000);
}

void pause(int del){
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    Serial.println("Paused");
    delay(del);
}

void forward(int del){
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(del);
}


void translate(int del, int dir){
  if (dir==1){
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    Serial.println("Forward Direction");
  }//Forward Direcion
  if(dir==-1){
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    Serial.println("Backward Direction");
  }//Backward Direction
  delay(del);
  pause(100);
}

void rotate(int del, int dir){
   if (dir==2){
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    Serial.println("Clockwise Direction");
  }//Clockwise Direction
  if(dir==-2){
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    
    Serial.println("Anticlockwise Direction");
  }//AntiClockwise Direction
  delay(del);

}
