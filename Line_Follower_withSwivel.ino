//THIS ROBOT USES 2 SENSORS, PLACED SIDE BY SIDE TO DETECT BEING ON TOP OF BLACK THE LINE

int M_L_F = 11; 
int M_L_R = 10; 
int M_R_F = 6; 
int M_R_R = 5; 

int state = 1;
void swivel(int state);


void setup() {
  pinMode(M_L_F, OUTPUT);
  pinMode(M_L_R, OUTPUT);
  pinMode(M_R_F, OUTPUT);
  pinMode(M_R_R, OUTPUT);

  digitalWrite(M_L_F, LOW);
  digitalWrite(M_L_R, LOW);
  digitalWrite(M_R_F, LOW);
  digitalWrite(M_R_R, LOW);

  Serial.begin(9600);
  
}

void loop() {
  //if both sensors are looking at the black line,
  //which means it's on top of the line, then it
  //should go forward 
  if ((analogRead(A0)>200)&&(analogRead(A1)>200)){
    forward();
  }
  
  //if only the right sensor is seeing the black 
  //line, make it turn right 
  else if (analogRead(A1)>200){
    turnRight();
    state = 1;
  }

  //if only the left sensor is seeing the black 
  //line, make it turn left 
  else if (analogRead(A0)>200){
    turnLeft();   
    state = 2;
  }

  //if none of the sensors are seeing the black
  //line, make it swivel
  else
  {
    swivel(state);
  }
   
}

void swivel(int state) {
  if (state == 2){
    hardLeftTurn();
  }
  else if (state == 1){
    hardRightTurn();
  }
  return; 
}

//forward function whic h simply make the car drive forward
void forward() {
    digitalWrite(M_R_R, LOW);
    digitalWrite(M_L_R, LOW);
    digitalWrite(M_L_F, HIGH);
    digitalWrite(M_R_F, HIGH);
}

//a smooth left turn where we just slow the left wheel a bit
void turnLeft(){
    digitalWrite(M_R_R, LOW);
    digitalWrite(M_L_R, LOW);
    analogWrite(M_L_F, 100);
    analogWrite(M_R_F, 175);
}

//a smooth right turn where we just slow the right wheel a bit
void turnRight() {
    digitalWrite(M_R_R, LOW);
    digitalWrite(M_L_R, LOW);
    analogWrite(M_L_F, 150);
    analogWrite(M_R_F, 125);
}

//a hard left turn where we actually moving the left wheel backwards 
void hardLeftTurn(){
    digitalWrite(M_R_R, LOW);
    digitalWrite(M_L_F, LOW);
    analogWrite(M_L_R, 150);
    analogWrite(M_R_F, 75);
}

//a hard right turn where we actually move the right wheel backwards
void hardRightTurn(){
    digitalWrite(M_R_F, LOW);
    digitalWrite(M_L_R, LOW);
    analogWrite(M_L_F, 50);
    analogWrite(M_R_R, 175);
}


