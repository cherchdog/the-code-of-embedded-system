float BASE_SPEED=20;  // 基础速度
TURN_SPEED = 30  // 转弯速度

float Left_Forword=1;      //基本参数
float Left_Back=1;
float Right_Forword=1.05;
float Right_Back=1.15;     

int no=0;
int Light[8];
void Turn_initial_coefficient(){  //返回基本参数
  Left_Forword=1;
  Left_Back=1;
  Right_Forword=1.05;
  Right_Backrword=1.15;
}

void setup() {
  // put your setup code here, to run once:
  DDRJ |= 0x0f;
  DDRL |= (1<<PL2)|(1<<PL5)|(1<<PL6);
  DDRG |=(1<<PG3);
  Turn_initial_coefficient();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  proxLEDon();
  for(int i=0;i<4;i++
  ){
    readProximitySensors(i+8);
  }


  if (Light[1]>960){
    TurnLeft(TURN_SPEED);
    PORTG  &= ~(1<<PG3);
    
  }else if (Light[2]>800){
    TurnRight(TURN_SPEED);
    PORTL &= ~(1<<PL5);
    
  }
  else{
    PORTL |= 0xfe;
    TurnOn(BASE_SPEED);
  }
  delay(50);
  
}

void leftMotorForward(float SPEED){
  analogWrite(7,0);
  analogWrite(6,Left_Forword*SPEED);
}

void leftMotorBackward(float SPEED){
  analogWrite(6,0);
  analogWrite(7,Left_Back*SPEED);
}

void leftMotorStop(){
  analogWrite(6,0);
  analogWrite(7,0);
}

void rightMotorForward(float SPEED){
  analogWrite(2,0);
  analogWrite(5,Right_Forword*SPEED);
}

void rightMotorBackward(float SPEED){
  analogWrite(5,0);
  analogWrite(2, Right_Back*SPEED);
}

void rightMotorStop(){
  analogWrite(2,0);
  analogWrite(5,0);
}
void TurnLeft(char SPEED){
  Left_Back=1;
  Right_Forword=1.05;
  leftMotorBackward(SPEED);
  rightMotorForward(SPEED);
}
void TurnRight(char SPEED){
  Right_Backrword=1.15;
  Left_Forword=1;
  leftMotorForward(SPEED);
  rightMotorBackward(SPEED);
  
}
void TurnOn(char SPEED){
    Turn_initial_coefficient();
    leftMotorForward(SPEED);
    rightMotorForward(SPEED);
}
void proxLEDoff(){
  PORTJ |= 0xff;
}
void proxLEDon(){
  PORTJ &= 0x00;
}

void readProximitySensors(char no){
  
  Light[no]=analogRead(no+8);
  
}
