#include <Arduino.h>
class movs{
  private:
    //pines del motor
    int da1;
    int da2;
    int da3;
    int da4;
  public:
    movs(int _da1,int _da2,int _da3,int _da4){
      da1=_da1;
      da2=_da2;
      da3=_da3;
      da4=_da4;
    }
    void c1(){
          digitalWrite(da1,HIGH);
          digitalWrite(da2,LOW);
          digitalWrite(da3,LOW);
          digitalWrite(da4,LOW);
    }
    void c2(){
          digitalWrite(da1,LOW);
          digitalWrite(da2,HIGH);
          digitalWrite(da3,LOW);
          digitalWrite(da4,LOW);
    }
    void c3(){
          digitalWrite(da1,LOW);
          digitalWrite(da2,LOW);
          digitalWrite(da3,HIGH);
          digitalWrite(da4,LOW);
    }
    void c4(){
          digitalWrite(da1,LOW);
          digitalWrite(da2,LOW);
          digitalWrite(da3,LOW);
          digitalWrite(da4,HIGH);
    }
};
class mov_motor{
  private:
    //primer motor
    int lida1;
    int lida2;
    int lida3;
    int lida4;
    //segundo motor
    int lida5;
    int lida6;
    int lida7;
    int lida8;
    int del;
    int e;
    int cont=1;
  public:
    mov_motor(int _lida1,int _lida2,int _lida3,int _lida4,int _lida5,int _lida6,int _lida7,int _lida8,int _e,int _del){
      lida1=_lida1;
      lida2=_lida2;
      lida3=_lida3;
      lida4=_lida4;
      lida5=_lida5;
      lida6=_lida6;
      lida7=_lida7;
      lida8=_lida8;
      e=_e;
      del=_del;
    }
    
    void left(){//izquierda es arriba
      movs u1(lida1,lida2,lida3,lida4);
      movs u2(lida5,lida6,lida7,lida8);
      while(digitalRead(e)==1){
      switch(cont){
        case 1:
          delay(del);
          u1.c4();
          u2.c4();
          cont=2;
        case 2:
          delay(del);
          u1.c3();
          u2.c3();
          cont=3;
        case 3:          
          delay(del);
          u1.c2();
          u2.c2();
          cont=4;
        case 4:          
          delay(del);
          u1.c1();
          u2.c1();              
          cont=1;
      }
      }
    }
    void rigth(){
      movs u1(lida1,lida2,lida3,lida4);
      movs u2(lida5,lida6,lida7,lida8);
      while (digitalRead(e)==1){
      switch(cont){
        case 1:
          delay(del);
          u1.c1();
          u2.c1();
          cont=2;
        case 2:
          delay(del);
          u1.c2();
          u2.c2();
          cont=3;
        case 3:
          delay(del);
          u1.c3();
          u2.c3();
          cont=4;
        case 4:
          delay(del);
          u1.c4();
          u2.c4();
          cont=1;
      }
      }
    }
    void down(){
       movs u1(lida1,lida2,lida3,lida4);
       movs u2(lida5,lida6,lida7,lida8);
       while(digitalRead(e)==1){
       switch(cont){
         case 1:
           delay(del);
           u1.c1();
           u2.c4();
           cont=2;
         case 2:
          delay(del);
           u1.c2();
           u2.c3();
           cont=3;
         case 3:
          delay(del);
           u1.c3();
           u2.c2();
           cont=4;
         case 4:
          delay(del);
           u1.c4();
           u2.c1();
           cont=1;
      }
      }
    }
    void up(){//arriba es izquierda
      movs u1(lida1,lida2,lida3,lida4);
      movs u2(lida5,lida6,lida7,lida8);
      while (digitalRead(e)==1){
      switch(cont){
        case 1:
          delay(del);
          u1.c4();
          u2.c1();
          cont=2;
        case 2:
          delay(del);
          u1.c3();
          u2.c2();
          cont=3;
        case 3:
          delay(del);
          u1.c2();
          u2.c3();
          cont=4;
        case 4:
          delay(del);
          u1.c1();
          u2.c4();
          cont=1;
      }
      }
    }
};
class decision{
  private:
    //pines de salida
    int lida1;
    int lida2;
    int lida3;
    int lida4;
    int lida5;
    int lida6;
    int lida7;
    int lida8;
    //pines de entrada
    int ent1;
    int ent2;
    int ent3;
    int ent4;
    //delay
    int del;
  public:
    decision(int _lida1,int _lida2,int _lida3,int _lida4,int _lida5,int _lida6,int _lida7,int _lida8,int _ent1,int _ent2,int _ent3,int _ent4,int _del){
      lida1=_lida1;
      lida2=_lida2;
      lida3=_lida3;
      lida4=_lida4;
      lida5=_lida5;
      lida6=_lida6;
      lida7=_lida7;
      lida8=_lida8;
      ent1=_ent1;
      ent2=_ent2;
      ent3=_ent3;
      ent4=_ent4;
      del=_del;
    }
    void modo(){
      pinMode(lida1,OUTPUT);
      pinMode(lida2,OUTPUT);
      pinMode(lida3,OUTPUT);
      pinMode(lida4,OUTPUT);
      pinMode(lida5,OUTPUT);
      pinMode(lida6,OUTPUT);
      pinMode(lida7,OUTPUT);
      pinMode(lida8,OUTPUT);
      pinMode(ent1,INPUT);
      pinMode(ent2,INPUT);
      pinMode(ent3,INPUT);
      pinMode(ent4,INPUT);
      digitalWrite(lida1,LOW);
      digitalWrite(lida2,LOW);
      digitalWrite(lida3,LOW);
      digitalWrite(lida4,LOW);
      digitalWrite(lida5,LOW);
      digitalWrite(lida6,LOW);
      digitalWrite(lida7,LOW);
      digitalWrite(lida8,LOW);
    }
    void ifs(){
      if(digitalRead(ent1)==0 && digitalRead(ent2)==0 && digitalRead(ent3)==0 && digitalRead(ent4)==0){
        digitalWrite(lida1,LOW);
        digitalWrite(lida2,LOW);
        digitalWrite(lida3,LOW);
        digitalWrite(lida4,LOW);
        digitalWrite(lida5,LOW);
        digitalWrite(lida6,LOW);
        digitalWrite(lida7,LOW);
        digitalWrite(lida8,LOW);
      }
      if (digitalRead(ent1)==1){
          mov_motor e(lida1,lida2,lida3,lida4,lida5,lida6,lida7,lida8,ent1,del);
          e.rigth(); 
      }
      if (digitalRead(ent2)==1){
          mov_motor e(lida1,lida2,lida3,lida4,lida5,lida6,lida7,lida8,ent2,del);
          e.down();
      }
      if (digitalRead(ent3)==1){
          mov_motor e(lida1,lida2,lida3,lida4,lida5,lida6,lida7,lida8,ent3,del);
          e.up();
      }
      if(digitalRead(ent4)==1){
          mov_motor e(lida1,lida2,lida3,lida4,lida5,lida6,lida7,lida8,ent4,del);
          e.left();
      }
}
};
