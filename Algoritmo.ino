//pines 
const int SER =5;
const int reloj_des=3;
const int reloj_salida=4;
// Menu
int opciones;



void setup()
{
  
  Serial.begin(9600);
  pinMode(SER,OUTPUT);
  pinMode(reloj_des,OUTPUT);
  pinMode(reloj_salida,OUTPUT);
  for(int i=3;i ==5;i++)
  {digitalWrite(i,0); }
  //Serial.print("Bienvendio al menu");
  
}

void loop()
{
    //esto para que no pase de este campo sin el dato a ingregar
	Serial.print(F("bienvenido al menu!!!\n"));
    Serial.print(F(" presiona 1. para invocar la funcion verificacion\n presiona 2. para invocar la funcion imagen\n presiona 3. para la funcion  publik \n \n \n"));
  	while(Serial.available()==0){} 
  	opciones=Serial.parseInt();
  	
     switch(opciones)
     {
      case 0:
        break;
      case 1:       
       verificacion();
       Serial.println(F("todos los leds funcion correctamente \n porfavor presione cualquier letra para volver al menu principal \n \n \n"));
       while(Serial.available()==0){}
       apagado();
       break;
  	  case 2:
       int patronn[8][8];
       imagen(patronn);
       
       break;
      
      default:
      Serial.println(F("el dato ingresado no esta en el menu \n \n \n"));
    }
    
}

// funciones auxiliares 

void inicializacion()
{	// funcion para inicializar los relojes 
	digitalWrite(reloj_des,0);
  	digitalWrite(reloj_des,1);
  	digitalWrite(reloj_des,0);
  	
  	digitalWrite(reloj_salida,0);
    digitalWrite(reloj_salida,1);
   	digitalWrite(reloj_salida,0);
}
void apagado()
{	for(byte i=0 ; i<64 ; i++)
	{
  		digitalWrite(SER,0);
    	inicializacion();
	}	
}

void grupo8(int cadena[])
{	//recorrer las filas dejando datos, pide una cadena de enteros 
	for(short int e=0;e<8;e++)
    { 
    	digitalWrite(SER,*(cadena+e));
      	inicializacion();
    }
}  

void patron(int guardado[][8], short int num_arre)
{	
  	long int num, aux;
    short int tamano=0, cifra;
  	Serial.print(F("ingrese el numero que representan los leds de la fila: "));
  	Serial.print(num_arre);
    Serial.print(F("\n")); 
    while(Serial.available()==0){}
  	num=Serial.parseInt();
  	Serial.print(num);
    Serial.print(F("\n"));
    while(num < 0)
    {
    Serial.print(F("ingrese el numero que representan los leds prendidos \n"));
    while(Serial.available()==0){}
  	num=Serial.parseInt(); 
    }
  	aux= num;
  	while(num>0)
    {
      cifra= num % 10;
      if(cifra !=9 and cifra !=0)
      {
        tamano++;
      }
      num=num/10;
    }
  int espacios[tamano],ingresor[8]={0,0,0,0,0,0,0,0};

  	ingreso(espacios,aux,cifra);
  	orden(espacios,tamano,ingresor);
  	guardador(guardado,ingresor,num_arre);
}

void ingreso(int espacios[],long int aux,short int cifra )
{	byte e=0;  
  	while(aux>0)
    {
      cifra = aux % 10;
      if (cifra !=9 and cifra !=0)
      {
        espacios[e]=cifra;
      	e++;
      }
      aux= aux / 10;
    }  
}


void orden(int espacios[],short int tamano,int fin[])
{ 
  int a;
	for(short int i=0; i<tamano ;i++){
      a=espacios[i]-1;
      fin[a]=1;
    }  
}

void guardador(int arreglodarreglos[][8],int ingreso[],short int num_arre)
{
	for(byte i= 0 ; i <8;i++)
    {
      arreglodarreglos[num_arre][i]=*(ingreso+i);
    }	
}

void verificacion()
{//funcion que prende todos los leds para verificar que funcionan 
  for(int i=1;i<=64;i++)
  {
    digitalWrite(SER,1);
    inicializacion();  	 
  } 
}


void imagen(int patronn[][8])
{	
  Serial.print(F("Menu de la funcion imagen\n"));
  Serial.print(F(" presiona 1. para ingresar tu propio patron\n  \n \n"));
  while(Serial.available()==0){} 
  opciones=Serial.parseInt();
  
  switch(opciones)
  {
    case 1:
    	Serial.print(F("ingrese el numero que representan los leds prendidos \n "));
    	Serial.print(F("Ejemplo:si usted ingresa 1468, encenderan los led en posicion 1 4 6 8  \n"));
    	
    	for(int i=0;i<8;i++)
        {
          patron(patronn,i);
          grupo8(patronn[i]);
        }
    	
    break;
    
  }
}
 




         









