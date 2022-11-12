#pragma once
#include "helper.h"
void RobotLine::radionica() {
  static int broj = 0;
  static bool uzzid = false;

  char simbol[10 + sizeof(char)];

  if (setup()) {
    armOpen();
    go(50, 50);
    delayMs(200);
  }

  if(lineAny()){
    if (line(0) && line(8) && broj < 2){
      go(60, 60);
      delayMs(500);
    } else if (line(0) && line(8) && broj < 4){
      go(60, 60);
      delayMs(1000);
      broj = 5;
    } else if (line(0) && line(8)){
      stop();
      end();
    } else {
      lineFollow();
    }
    if(uzzid){
      uzzid = false;
      broj++;
    }
  } else if (broj == 0 && rightFront()<120){
    if (rightFront() < 120) {
      if (rightFront() > 80)
        go(80, 20);
      else
        go(20, 80);
    }
    uzzid = true;
  } else if (broj == 1 && rightFront()<120){
    go(70,70);
    delayMs(1400);
    go(-90,90);
    delayMs(45
    0);
    broj = 2;
  } else if (broj == 2 && front()>100){
    go(80, 80);     
  } else if (broj == 2){
    go(-80, -80);
    delayMs(1000);
    go(100,-80);
    delayMs(700);
    go(80, 60);
    delayMs(500);
    broj = 3;
  } 
  sprintf(simbol, "%d", broj);
  display(simbol);
}
