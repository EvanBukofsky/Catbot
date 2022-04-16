#include "Motor.h"

  Motor::Motor (int motorPin, int encoderPinA, int encoderPinB)
  : motorPin(motorPin), encoderPinA(encoderPinA), encoderPinB(encoderPinB){
      attach(motorPin);
      arm();
      pinMode(encoderPinA, input);
      pinMode(encoderPinB, input);

  } //construct motor object

  void Motor::Run(int speedPcnt, int timeSec){
      if(speedPcnt <= 100 && speedPcnt >= -100){
        this.setSpeed(speedPcnt);
        }
      delay(timeSec * 1000);
  }//Run motor
  
  void Motor::Run(int dir, int deg, int speedPcnt){
    int speed;
    int time;
    if(dir == 0){
        speed = -1 * abs(speedPcnt);
    }
    else{
        speed = abs(speedPcnt);
    }
    //Implement conversion from desired degrees to speed+time given a certain speed*************
    //***************************

  }//Run motor based on pos

  void Motor::tuneESC(double low, double high){
      //High forward
      int angle = map(99, -100, 100, low, high); //Sets servo positions to different speeds
      this.write(angle);
      delay(7000);

      //High reverse
      int angle = map(-99, -100, 100, mapLow, mapHigh); //Sets servo positions to different speeds
      this.write(angle);
      delay(10000);
  }//Setup ESC range
  
  int Motor::getDir(){

  }//Get directional feedback from encoder
  
  int Motor::getVel(){

  }//Get velocity feedback from encoder
  
  void Motor::setSpeed(int speed){
    int angle = map(speed, -100, 100, mapLow, mapHigh); //Sets servo positions to different speeds ESC1.write(angle);
    //With full mapping [[map(speed, -100, 100, 0, 180)]], the max servo speeds are -88%->88%.

    this.write(angle);
  }//Set motor speed and map

  void Motor::arm(){
      setSpeed(0);
  }


 
