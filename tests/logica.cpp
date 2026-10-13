
#include "../laboratorios/Logica.h"
#include "../laboratorios/Trama.h"
#include <iostream>
#include <cstdlib>
#include <limits>
int casos=0;
void comprobar(bool ok,const char* nombre){if(!ok){std::cerr<<"FALLO: "<<nombre<<"\n";std::exit(1);}casos++;std::cout<<"OK: "<<nombre<<"\n";}
int main(){
 comprobar(Curso::pwmDesdeAdc(0)==0,"PWM extremo inferior");
 comprobar(Curso::pwmDesdeAdc(1023)==255,"PWM extremo superior");
 comprobar(Curso::pwmDesdeAdc(512)==127,"PWM truncamiento y producto 32 bits");
 comprobar(Curso::pwmDesdeAdc(65535)==255,"ADC fuera de escala acotado");
 comprobar(!Curso::transcurrido(29,0,30)&&Curso::transcurrido(30,0,30),"Periodo en borde exacto");
 comprobar(Curso::transcurrido(10,UINT32_MAX-19,30),"Reloj atraviesa desbordamiento 32 bits");
 float t=0;
 comprobar(Curso::temperaturaTmp36(154,5,t)&&fabs(t-25.43945f)<0.02f,"TMP36 offset y escala nominal");
 comprobar(!Curso::temperaturaTmp36(1023,5,t),"TMP36 fuera de rango fisico");
 comprobar(!Curso::temperaturaTmp36(1024,5,t),"ADC fuera de 10 bits");
 comprobar(!Curso::temperaturaTmp36(154,0,t)&&!Curso::temperaturaTmp36(154,-1,t),"Referencia invalida");
 comprobar(!Curso::temperaturaTmp36(154,std::numeric_limits<float>::quiet_NaN(),t),"Referencia no finita");
 float cm=0;
 comprobar(!Curso::distanciaCm(0,cm),"Timeout no representa distancia cero");
 comprobar(Curso::distanciaCm(1000,cm)&&fabs(cm-17.15f)<0.01f,"Tiempo vuelo ida y vuelta con unidades");
 comprobar(!Curso::distanciaCm(100,cm)&&!Curso::distanciaCm(25000,cm),"Distancia fuera de rango");
 bool a=false;a=Curso::histeresisAlta(29,a,30,28);comprobar(!a,"Histeresis no inicia bajo umbral alto");
 a=Curso::histeresisAlta(30,a,30,28);comprobar(a,"Histeresis activa en umbral alto");
 a=Curso::histeresisAlta(29,a,30,28);comprobar(a,"Histeresis conserva dentro de banda");
 a=Curso::histeresisAlta(28,a,30,28);comprobar(!a,"Histeresis libera en umbral bajo");
 Curso::Boton b;
 comprobar(!b.actualizar(false,0)&&!b.actualizar(true,10)&&!b.actualizar(false,20)&&!b.actualizar(false,49),"Rebote no produce pulsacion prematura");
 comprobar(b.actualizar(false,50),"Evento al estabilizar 30 ms");
 comprobar(!b.actualizar(false,1000),"Pulsacion sostenida no repite evento");
 comprobar(!b.actualizar(true,1010)&&!b.actualizar(true,1040)&&!b.actualizar(false,1100)&&b.actualizar(false,1130),"Liberacion y nueva pulsacion");
 int valor=-1;
 comprobar(Curso::leerTrama("VAL 0",valor)&&valor==0&&Curso::leerTrama("VAL 1023",valor)&&valor==1023,"Tramas en ambos limites");
 comprobar(!Curso::leerTrama("VAL 1024",valor)&&!Curso::leerTrama("VAL -1",valor)&&!Curso::leerTrama("VAL +1",valor),"Trama fuera de rango o signo no permitido");
 comprobar(!Curso::leerTrama("VAL 12x",valor)&&!Curso::leerTrama("VAL ",valor)&&!Curso::leerTrama("ACK 12",valor),"Trama malformada sin conversion silenciosa");
 comprobar(!Curso::leerTrama("VAL 00001",valor)&&!Curso::leerTrama("VAL 999999999999999999999",valor),"Limite de texto antes de strtol");
 std::cout<<"Total "<<casos<<" casos aprobados; no simulan hardware\n";
}
