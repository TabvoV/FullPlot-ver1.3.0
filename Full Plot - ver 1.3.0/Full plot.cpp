/* 
     FULL PLOT -   GRAFICADOR 
     DESARROLLADO POR:
     GUSTAVO VILLANUEVA Y SEBASTIAN LUGO
     13/05/2019
*/

#include<iostream>
#include<conio.h>
#include<math.h>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<graphics.h>
#include"Texto.h"
#define ValorBarra  9

using namespace std;
int NumeroBarra = 0, a0[ValorBarra],coef1,coef2,potencia;
char var ='y=cos(x)';


//Seccion: Barra de propiedades
void tituloBar(int x,int y, char *n="  "){
	
	setcolor(BLACK);
	outtextxy(x,y,n);
}
int botonBar(int x, int y){
	setcolor(WHITE);
	rectangle(x,y,x+60, y+15);
	if(mousex()>x&&mousex()<x+60&&mousey()>y&&mousey()<y+15&&ismouseclick(WM_LBUTTONDOWN)){
	clearmouseclick(WM_LBUTTONDOWN); return 1;	}
	else { clearmouseclick(WM_LBUTTONDOWN); return 0;}
}
void estadoBar(int x, int y, int c1, int c2){
	if(mousex()>x&&mousex()<x+60&&mousey()>y&&mousey()<y+15){
	setcolor(c1);}
	else {setcolor(c2);}
}
void Acerca(){
	initwindow(500,560,"Full plot",280,60);
	setbkcolor(WHITE);cleardevice();
	readimagefile("Medios/info.jpg",0,0,500,550);
}

int Bar(){
	
	setbkcolor(WHITE);
	setcolor(BLACK);
	bar(0,0,getmaxx(), 16);	
	
	while(true){
	tituloBar(0,0," Archivo");
	estadoBar(0,0,14,0);
	if(botonBar(0,0)){
		while(true){
		bar(0,15,200,100);
		
		tituloBar(0,16,"Abrir");
		estadoBar(0,16,15,0);
		if(botonBar(0,16)){
		ifstream fe("Save-Plot.txt");
		break;
		}
		tituloBar(0,40,"Guardar");
		estadoBar(0,40,15,0);
		if(botonBar(0,40)){
		ofstream fs("Save-Plot.txt");
		fs<<var<<endl;
		fs.close();
		ifstream fe("Save-Plot.txt");
		Texto(375,290,"GUARDADO");
		delay(1000);
		break;
		}
		tituloBar(0,64,"Menu Principal");
		estadoBar(0,64,15,0);
		if(botonBar(0,64)){
			closegraph();
			getch();
			return menuPrincipal;
			
			
		}	
		tituloBar(0,86,"Salir");
		estadoBar(0,86,15,0);
		if(botonBar(0,86)){
			closegraph();
			getch;
			return 0; cout<<"\a";	
		}	
		}
	
	}
	
	tituloBar(60,00," Edicion");
	estadoBar(53,0,14,0);
	if(botonBar(53,00)){
	}
	
	tituloBar(120,00,"Acerca de");
	estadoBar(120,0,14,0);
	if(botonBar(120,00)){
	closegraph();
	Acerca();}
	}
}
void FakeBar(){
	
	setbkcolor(WHITE);
	setcolor(BLACK);
	bar(0,0,getmaxx(), 16);	
	outtextxy(0,0," Archivo");
	outtextxy(60,0," Edicion");
	outtextxy(120,0,"Acerca de");
	
}

//seccion: graficador 2d
int Sen(){
	outtextxy(20,120, "  y=sen(x) ");
	int x,y;
	line(0,300,getmaxx(),300);
	line(400,50,400,getmaxy());
	float pi = 3.1415;
	
	for(int i =-360; i<=360; i++){
		x=(int)400+i;
		y=(int)300-sin(i*pi/100)*25;
		putpixel(x,y,GREEN);
	}
}
int Cos(){
	outtextxy(20,120, "  y=cos(x)");
	int x,y;
	line(0,300,getmaxx(),300);
	line(400,50,400,getmaxy());
	float pi = 3.1415;
	
	for(int i =-360; i<=360; i++){
		x=(int)400+i;
		y=(int)300-cos(i*pi/100)*25;
		putpixel(x,y,BLUE);
	}
}
int Tg(){
	outtextxy(20,120, "  y=tan(x)");
	int x,y;
	line(0,300,getmaxx(),300);
	line(400,50,400,getmaxy());
	
	float pi = 3.1415;
	
	for(int i =-360; i<=360; i++){
		x=(int)400+i;
		y=(int)300-tan(i*pi/90);
		putpixel(x,y,WHITE);
	}
}
int x(){
	outtextxy(20,120, "  y=x²");
	int x,y;
	line(0,300,getmaxx(),300);
	line(400,50,400,getmaxy());
	float pi = 3.1415;
	
	for(int i =-360; i<=360; i++){
		x=(int)400+i;
		y=(int)300-i;
		putpixel(x,y,RED);
	}
}
int x2(){
	outtextxy(20,120, "  y=x²");
	int x,y;
	line(0,300,getmaxx(),300);
	line(400,50,400,getmaxy());
	float pi = 3.1415;
	
	for(int i =-360; i<=360; i++){
		x=(int)400+i;
		y=(int)300-pow(i*.02,2);
		putpixel(x,y,RED);
	}
}
int x3(){
	outtextxy(20,120, "  y=x³");
	int x,y;
	line(0,300,getmaxx(),300);
	line(400,50,400,getmaxy());
	float pi = 3.1415;
	
	for(int i =-360; i<=360; i++){
		x=(int)400+i;
		y=(int)300-pow(i*.05,3);
		putpixel(x,y,	WHITE);
	}
}int xMod(){
	outtextxy(20,120, "  y=a(x^n)+b");
	int x,y;
	line(0,300,getmaxx(),300);
	line(400,50,400,getmaxy());
	float pi = 3.1415;
	
	for(int i =-360; i<=360; i++){
		x=(int)400+i;
		y=(int)300-*coef1*pow(i*.05,potencia)-coef2;
		putpixel(x,y,WHITE);
	}
}

int Graficador(int OpcionFuncion){
	initwindow(800,600,"Full Plot",280,60);
	setbkcolor(BLACK);cleardevice();
	outtextxy(350,35, "GRAFICADOR 2D");
	outtextxy(15,80, "Función: ");
	
	if(OpcionFuncion ==0){
	x();	
	}else if(OpcionFuncion ==1){
		x2();
	}else if(OpcionFuncion ==2){
		x3();
	}else if(OpcionFuncion ==3){
		Sen();
	}else if(OpcionFuncion ==4){
		Cos();
	}else if(OpcionFuncion ==5){
	Tg();
	}else if(OpcionFuncion==6){
	xMod();
	}else{
	}
	Bar();

}

//subseccion: Menu de funciones
void tituloMenuFuncion(int x,int y, char *n="  "){
	setcolor(BLACK);
	outtextxy(x,y,n);
}
int botonMenuFuncion(int x, int y){
	rectangle(x,y,x+50, y+20);
	if(mousex()>x&&mousex()<x+50&&mousey()>y&&mousey()<y+20&&ismouseclick(WM_LBUTTONDOWN)){
	clearmouseclick(WM_LBUTTONDOWN); return 1;	}
	else { clearmouseclick(WM_LBUTTONDOWN); return 0;}
}
void estadoMenuFuncion(int x, int y, int c1, int c2){
	if(mousex()>x&&mousex()<x+50&&mousey()>y&&mousey()<y+20){
	setcolor(c1);}
	else {setcolor(c2);}
}
int GraficMain(){
	int Funcion;
	initwindow(600,400, "Full Plot",270,70);
	setbkcolor(WHITE);cleardevice();
	setcolor(BLACK);
	outtextxy(50,38, "INGRESA UNA FUNCION: ");
	setcolor(RED);
	bar(120,125,480,125);
	
	while(true){
		int OpcionMenuFuncion=40;
		char operacion =' ', varTrigo=' ';
	//botones inferiores
		
	tituloMenuFuncion(70,205,"     x");
	estadoMenuFuncion(70,200,15,0);
	if(botonMenuFuncion(70,200)){
	var='y=x' ;
	Texto(130,125,"x ");
	Funcion = 0;
	}
	
	tituloMenuFuncion(152,205,"     x²");
	estadoMenuFuncion(152,200,15,0);
	if(botonMenuFuncion(152,200)){
	var='y=x² ';
	Texto(130,125,"x² ");
	Funcion = 1;
	}

	tituloMenuFuncion(234,205,"     x³");
	estadoMenuFuncion(234,200,15,0);
	if(botonMenuFuncion(234,200)){ 
	var='y=x³ ';
	Texto(130,125,"x³ ");
	Funcion = 2;
	}
	
	tituloMenuFuncion(316,205,"   Sen");
	estadoMenuFuncion(316,200,15,0);
	if(botonMenuFuncion(316,200)){
	var='y=Sen(x) ';
		Texto(130,125,"Sen(x) ");
		Funcion = 3;}
	
	tituloMenuFuncion(398,205,"   Cos");
	estadoMenuFuncion(398,200,15,0);
	if(botonMenuFuncion(398,200)){
	var='y=Cos(x) ';
	Texto(130,125,"Cos(x) ");
	Funcion = 4;}
	
	tituloMenuFuncion(480,205,"   Tan");
	estadoMenuFuncion(480,200,15,0);
	if(botonMenuFuncion(480,200)){
	var = 'y=Tan(x) ';
	Texto(130,125,"Tan(x) ");
	Funcion = 5;}
	
	//botones superiores
			
	tituloMenuFuncion(70,245,"     +");
	estadoMenuFuncion(70,245,15,0);
	if(botonMenuFuncion(70,245)){
	operacion='+ ';
	setcolor(BLACK);
	moveto(130,130);
	outtext("+ ");
	}
	
	tituloMenuFuncion(152,245,"     -");
	estadoMenuFuncion(152,245,15,0);
	if(botonMenuFuncion(152,245)){
	operacion='- ';
	setcolor(BLACK);
	moveto(130,130);
	outtext("- ");
	}

	tituloMenuFuncion(234,245,"     /");
	estadoMenuFuncion(234,245,15,0);
	if(botonMenuFuncion(234,245)){ 
	var=' / ';
	}
	
	tituloMenuFuncion(306,245,"  Mod");
	estadoMenuFuncion(306,245,15,0);
	if(botonMenuFuncion(306,245)){
	Texto(130,125,"Modificar funcion: a(x^n)+b");
	Texto(130,150," ingresa valores en segunda pantalla ");
	system ("cls");
	cout<<"  GRAFICADOR 2D\n"<<endl;
	cout<<"  Modificar funcion: a(x^n)+b"<<endl;
	cout<<"a: ";cin>>coef1;
	cout<<"b: ";cin>>coef2;
	cout<<"n: ";cin>> potencia;
	delay(500);
	system ("cls");
	cout<<"\nregresa a la interfaz grafica"<<endl;
	outtext(" ");
	Funcion = 6;
	}
	
	//graficar
	tituloMenuFuncion(275,315,"  PLOT");
	estadoMenuFuncion(275,315,15,0);
	if(botonMenuFuncion(275,315)){
	closegraph();
	Graficador(Funcion);
	break;
	}
	
	
	}
	
	
}

//Seccion: graficador de barras
void Barra(int ancho, int  alto, int separacion){
	bar(70+separacion,360-alto,70+ancho+separacion,360);
	setcolor(WHITE);
	rectangle(70+separacion,360-alto,70+ancho+separacion,360);
}
void Medidor(){
	setcolor(WHITE);
	line(50,60,50,360);
	for(int i=0; i<=10; i++){
	setcolor(WHITE);
	line(43,60+30*i,50,60+30*i);
	} 
}
int GraficadorBarras(){
	initwindow(600,400,"Full plot",240,80);
	setbkcolor(WHITE);cleardevice();
	setcolor(BLACK);
	FakeBar();
	
	outtextxy(200,35, "GRAFICADOR DE BARRAS");
	outtextxy(140,90, "Ingresa los datos desde la segunda pantalla...");
	system ("cls");
	while(true){
		
		cout<<"\n\nNumero de barras(Max. 10):"; cin>>NumeroBarra;
		if(NumeroBarra>10 ||NumeroBarra<0){
			cout<<"\n-NUMERO INVALIDO DE BARRAS-"<<endl;
		}else{
			break;
		}
	}
	
	cout<<"\n\nIngresa el valor de cada barra\n(valores entre 0 y 100):"<<endl;
	
	for(int ContValorBarras = 0; ContValorBarras<NumeroBarra; ContValorBarras++){
		while(true){
		cout<<"Barra "<<ContValorBarras+1<<": ";	cin>>a0[ContValorBarras];
		if(a0[ContValorBarras]>100 ||a0[ContValorBarras]<0){
			cout<<"\n-VALOR INVALIDO -"<<endl;
		}else{
			break;
		}	
	}	
	}
	delay(500);
	system ("cls");
	cout<<"\nregresa a la interfaz grafica"<<endl;
	cleardevice();
	setcolor(BLACK);
	outtextxy(200,35, "GRAFICADOR DE BARRAS");
	setbkcolor(BLACK);			
	setfillstyle(0, 0);
	bar(30,55,570,367);
	setcolor(RED);
	rectangle(30,55,570,367);
	Medidor();
	for(int ContadorBarras = 0; ContadorBarras<NumeroBarra; ContadorBarras++){
	
		if(ContadorBarras==0){
		setbkcolor(12);			
		setfillstyle(8, 1);
		Barra(40,a0[ContadorBarras]*3,0);
		}else{	
		setbkcolor(ContadorBarras+2);	
		setfillstyle(8, ContadorBarras+1);
		Barra(40,a0[ContadorBarras]*3,50*ContadorBarras);
		}
	} 
	setbkcolor(WHITE);			
	setfillstyle(0, 0);
	Bar();
}

//Seccion: Menu Principal
void tituloMenu(int x,int y, char *n="  "){
	setcolor(BLACK);
	outtextxy(x,y,n);
}
int botonMenu(int x, int y){
	rectangle(x,y,x+75, y+30);
	if(mousex()>x&&mousex()<x+75&&mousey()>y&&mousey()<y+30&&ismouseclick(WM_LBUTTONDOWN)){
	clearmouseclick(WM_LBUTTONDOWN); return 1;	}
	else { clearmouseclick(WM_LBUTTONDOWN); return 0;}
}
void estadoMenu(int x, int y, int c1, int c2){
	if(mousex()>x&&mousex()<x+75&&mousey()>y&&mousey()<y+30){
	setcolor(c1);}
	else {setcolor(c2);}
}
int menuPrincipal(){
	initwindow(800,450, "FULL PLOT - Graficador1.3.0 ",270,70);
	setbkcolor(WHITE);cleardevice();
	readimagefile("Medios/mainfl.jpg",0,0,800,400);
		while(true){
	tituloMenu(170,100,"GRAFICAR");
	estadoMenu(170,100,15,0);
	if(botonMenu(165,98)){
	closegraph();
	GraficMain();
	break;}

	tituloMenu(170,200," BARRAS");
	estadoMenu(170,200,15,0);
	if(botonMenu(165,195)){
	closegraph();
	GraficadorBarras();
	break;
	}
	
	tituloMenu(170,300,"   SALIR");
	estadoMenu(170,300,15,0);
	if(botonMenu(165,295)){
	closegraph();
	getch;
	return 0;
	cout<<"\a";	}
	}
	
}

//Metodo main
int main(){
		menuPrincipal();
	cout<<"\a";	
	getch();	
}
