const int eye = 3;
const int light0 = 5;
const int light1 = 6;

const int m0 = 9;
const int m1 = 10;
const int m2 = 11;

const int mWait = 200;

int square0Brightness = 0;
int square1Brightness = 100;

void setup() {
  pinMode(light0, OUTPUT);
  pinMode(light1, OUTPUT);
  pinMode(eye, OUTPUT);
  pinMode(m0, OUTPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);

  analogWrite(eye, 255);
  analogWrite(light0, 255);
  analogWrite(light1, 255);
}

void loop() {
  cycleMode();
}

void autoMode(){
  while(true){
    int mode = random(0, 3);
    
    if(mode == 0){
      runEye();
    } else if(mode == 1){
      runLights();
    } else if(mode == 2){
      runMotor();
    }
    
    delay(5000);
  }
}

void cycleMode(){
  runEye();
  runLights();
  runMotor();
  delay(1000);
}

void runLights(){
  for(int i = 0; i < 10; i++){
    analogWrite(light0, 255);
    analogWrite(light1, 0);
    delay(100);
    analogWrite(light0, 0);
    analogWrite(light1, 255);
    delay(100);
  }

  analogWrite(light0, 255);
  analogWrite(light1, 255);
}

void runEye(){
  for(int i = 0; i < 2; i++){
    for(int brightness = 50; brightness < 255; brightness++){
      analogWrite(eye, brightness);
      delay(1);   
    }
  }
}

void runMotor(){
  motorEffect0();
}

void motorEffect0(){
  moveMotor(1, 1, 0);
  moveMotor(1, 0, 0);
  moveMotor(1, 0, 1);
  moveMotor(0, 0, 1);
  moveMotor(0, 1, 1);
  moveMotor(0, 1, 0); 
  
  moveMotor(0, 0, 0);
}

void moveMotor(int x, int y, int z){
  digitalWrite(m0, x);
  digitalWrite(m1, y);
  digitalWrite(m2, z);
  delay(mWait);
}
