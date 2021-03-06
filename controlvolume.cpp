/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2017  Pablo Alvarado
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file   controlVolume.cpp
 *         Implements a equalizer using filters IIR with central frequencies of 32Hz,64Hz,64Hz,125Hz,250Hz,500Hz,1kHz,2kHz,4kHz,8kHz and 16kHz.
 * \author Jose Miguel Barboza \ Luis Alfredo Piedra Esquivel \ Jose Pablo Delgado Martinez
 * \date   2017.31.05 \ 2017.1.12
 *
 * $Id: controlVolume.cpp $
 */

#include "controlvolume.h"
#include <cmath>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include "ventanasingleton.h"
#include <sndfile.h>
using namespace std;

#define REAL 0
#define IMAG 1
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481
#define e = 2.718281828459045235360287471352
#define N 8192

/*
 * Constructor
 */
controlVolume::controlVolume(){

    //Inicializacion de los punteros de tipo double[2048][2].
    f32 = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    f64 = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    f125 = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)* N);
    f250 = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)* N);
    f500 = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)* N);
    f1k = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    f2k = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    f4k = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    f8k = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    f16k = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)* N);

    hkeverb = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)* N);
    wVentana = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)* N);

    //valor booleano que indica el inicio de una cancion.
    inicio = true;

    // Arreglos donde se almacenan los M-1 valores de la salida que se generan al aplicar el metodo de solapamiento y suma.
    datos32 = new float[N/2];
    datos64 = new float[N/2];
    datos125 = new float[N/2];
    datos250 = new float[N/2];
    datos500 = new float[N/2];
    datos1k = new float[N/2];
    datos2k = new float[N/2];
    datos4k = new float[N/2];
    datos8k = new float[N/2];
    datos16k = new float[N/2];

    datosReverb = new float[N/2];


    //Inicializacion de los valores en los punteros de tipo double[2048][2]
    inicializarH32();
    inicializarH64();
    inicializarH125();
    inicializarH250();
    inicializarH500();
    inicializarH1k();
    inicializarH2k();
    inicializarH4k();
    inicializarH8k();
    inicializarH16k();

    inicializarHReverb(hkeverb);
    inicializarVentana(wVentana);
}
/*
 * Destructor
 */
controlVolume::~controlVolume(){

}

void controlVolume::inicializarHReverb(fftw_complex *salidaHk)
{

    //Alocar espacio para el h(n)
    fftw_complex *h = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

    //Declaramos el archivo
    QFile file("reverbhn");
    if(!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Error reading file" << std::endl;
    }
    //Obtiene el archivo como una lista de caracteres
    QTextStream in(&file);
    //Esta variable contiene cada uno de los valores
    QStringList fields;
    //Hay que iterar el archivo hasta el final línea por línea, aunque solo sea una en este caso
    while(!in.atEnd()) {
        QString line = in.readLine(); //Leer línea
        fields = line.split("\t"); //Separar la línea en valores, el separador son tabs (\t)
    }
    //Rellenar el h(n) con los valores obtenidos hasta 4095 (N/2-1)
    for (int i = 0; i<N/2+1; i++)
    {
        QString str = fields.at(i);
        h[i][REAL] = str.toFloat();
        h[i][IMAG] = 0.0;
    }
    //Se rellena el resto hasta N con ceros
    for (int i = N/2+1; i<N; i++)
    {
        h[i][REAL] = 0.0;
        h[i][IMAG] = 0.0;
    }

    file.close();
    //Se aplica la DFT.
    fftw_plan plan = fftw_plan_dft_1d(N,h,salidaHk,FFTW_FORWARD,FFTW_ESTIMATE);
    fftw_execute(plan);

    //Se libera la memoria.
    fftw_destroy_plan(plan);
    fftw_free(h);
    fftw_cleanup();
}

void controlVolume::inicializarVentana(fftw_complex *salidaW)
{
    //Rellenar el vector w(n) con los valores de la ventana
    //Además, se realiza el cálculo de la constante U
    constanteUVentana = 0.0;
    for (int i = 0; i<N/2; i++)
    {
        salidaW[i][REAL] = (1.0/2.0)*(cos((2*PI*i)/(N/2)));
        salidaW[i][IMAG] = 0.0;
        constanteUVentana += pow((1.0/2.0)*(cos((2*PI*i)/(N/2))),2);
    }
    constanteUVentana = constanteUVentana/(N/2);
}

/**
 * @brief inicializarHK Funcion encargada de generar H(k) utilizando la DFT para un filtro especifico.
 * @param puntero puntero a un arreglo donde se almacenaran los valores de H(k).
 * @param G valor que representa la ganancia total de la ecuacion de diferencias de grado 6.
 * @param a_0 valor decimal que representa coeficiente que multiplica a x(n).
 * @param b_0 valor decimal que representa coeficiente que multiplica a x(n-1).
 * @param c_0 valor decimal que representa coeficiente que multiplica a x(n-2).
 * @param e_0 valor decimal que representa coeficiente que multiplica a x(n-4).
 * @param f_0 valor decimal que representa coeficiente que multiplica a x(n-5).
 * @param g_0 valor decimal que representa coeficiente que multiplica a x(n-6).
 * @param b_1 valor decimal que representa coeficiente que multiplica a y(n-1).
 * @param c_1 valor decimal que representa coeficiente que multiplica a y(n-2).
 * @param d_1 valor decimal que representa coeficiente que multiplica a y(n-3).
 * @param e_1 valor decimal que representa coeficiente que multiplica a y(n-4).
 * @param f_1 valor decimal que representa coeficiente que multiplica a y(n-5).
 * @param g_1 valor decimal que representa coeficiente que multiplica a y(n-6).
 */
void controlVolume::inicializarHK(fftw_complex *puntero, double G, double a_0, double b_0, double c_0, double e_0, double f_0, double g_0, double b_1, double c_1, double d_1, double e_1, double f_1, double g_1){

    //int N = 2048; //Largo del enventanado. Esto hay que cambiarlo porque es el doble del tamaño de la entrada, entonces solapamiento y almacenamiento significaría utilizar toda la entrada anterior
    //aunque creo que igual se puede hacer con la entrada anterior completa, no veo el problema en realidad.

    fftw_complex *h = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

    //Asumiendo que x(n) = d(n) Impulso unitario.
    //calculo de h(0).
    h[0][REAL] = G * a_0;
    //calculo de h(1).
    h[1][REAL] = G * b_0 + b_1 * h[0][REAL];
    //calculo de h(2).
    h[2][REAL] = G * c_0 + h[1][REAL] * b_1 + c_1 * h[0][REAL];
    //calculo de h(3).
    h[3][REAL] = h[2][REAL] * b_1 + c_1 * h[1][REAL] + d_1 * h[0][REAL];
    //calculo de h(4).
    h[4][REAL] = G * e_0 + b_1 * h[3][REAL] + c_1 * h[2][REAL] + d_1 * h[1][REAL] + e_1 * h[0][REAL];
    //calculo de h(5).
    h[5][REAL] = G * f_0 + b_1 * h[4][REAL] + c_1 * h[3][REAL] + d_1 * h[2][REAL] + e_1 * h[1][REAL] + f_1 * h[0][REAL];
    //calculo de h(6).
    h[6][REAL] = G * g_0 + b_1 * h[5][REAL] + c_1 * h[4][REAL] + d_1 * h[3][REAL] + e_1 * h[2][REAL] + f_1 * h[1][REAL] + g_1 * h[0][REAL];

    //De h(7) en adelante solo depende de las salidas anteriores. Por lo que recursivamente se calculan los demas valores.
    for(int i = 7; i<(N/2)+1; i++){


        h[i][REAL] = b_1 * h[i-1][REAL] + c_1 * h[i-2][REAL] + d_1 * h[i-3][REAL] + e_1 * h[i-4][REAL] + f_1 * h[i-5][REAL] + g_1 * h[i-6][REAL];

    }

    //Se agregan ceros hasta que el largo de h(n) sea igual a L+M-1 = 2048.
    for(int i = N/2+1;i<N;i++){

        h[i][REAL] = 0.0;

    }

    //Se inicializan la parte imaginaria en cero debido a que la respuesta al impulso es real.
    for(int i =0;i<N;i++){

        h[i][IMAG] = 0.0;

    }

    //Se aplica la DFT.
    fftw_plan plan = fftw_plan_dft_1d(N,h,puntero,FFTW_FORWARD,FFTW_ESTIMATE);
    fftw_execute(plan);

    //Se libera la memoria.
    fftw_destroy_plan(plan);
    fftw_free(h);
    fftw_cleanup();

}
void controlVolume::inicializarH32(){

    //Coeficientes obtenidos al generar la funcion de transferencia y ecuacion de diferencias de los filtros de orden 6.
    double G = 0.0000051726440015777536390439301;
    double a_0 = 1.0;
    double b_0 = -3.9983645237106202330323867;
    double c_0 = 4.996729047853150973423908;
    double e_0 = -4.996729047853150973423908;
    double f_0 = 3.9983645237106202330323867;
    double g_0 = -1.0;

    double b_1 = 5.9967453132568113716160951;
    double c_1 = -14.983801901853976090706055;
    double d_1 = 19.9677543230578251609586;
    double e_1 = -14.967904692182449011284007;
    double f_1 = 5.9840274563218738279601894;
    double g_1 = -0.99682049860009280806139031;

    //Se almacenan en el arreglo asociado a el filtro de 32Hz los valores de su H(k).
    inicializarHK(f32,G,a_0,b_0,c_0,e_0,f_0,g_0,b_1,c_1,d_1,e_1,f_1,g_1);

}
void controlVolume::inicializarH64(){

    //Coeficientes obtenidos al generar la funcion de transferencia y ecuacion de diferencias de los filtros de orden 6.
    double G = 0.000010341142425214124028623811;
    double a_0 = 1.0;
    double b_0 = -3.9934658733542631736668227;
    double c_0 = 4.9869317536107633515030102;
    double e_0 = -4.9869317536107633515030102;
    double f_0 = 3.9934658733542631736668227;
    double g_0 = -1.0;

    double b_1 = 5.9933505401304589810251855;
    double c_1 = -14.967054483387533636573608;
    double d_1 = 19.934711294803655334817449;
    double e_1 = -14.935312410443541963900316;
    double f_1 = 5.9679561693283540435572831;
    double g_1 = -0.99365111043196252538223234;

    //Se almacenan en el arreglo asociado a el filtro de 64Hz los valores de su H(k).
    inicializarHK(f64,G,a_0,b_0,c_0,e_0,f_0,g_0,b_1,c_1,d_1,e_1,f_1,g_1);
}
void controlVolume::inicializarH125(){

    //Coeficientes obtenidos al generar la funcion de transferencia y ecuacion de diferencias de los filtros de orden 6.
    double G = 0.000019738188870821139823908894;
    double a_0 = 1.0;
    double b_0 = -3.9763100468322947200761064;
    double c_0 = 4.9526201985423163876021135;
    double e_0 = -4.9526201985423163876021135;
    double f_0 = 3.9763100468322947200761064;
    double g_0 = -1.0;

    double b_1 = 5.9867734651203612372682983;
    double c_1 = -14.935035264418475620118443;
    double d_1 = 19.872396905624650997879144;
    double e_1 = -14.874714159791597722914958;
    double f_1 = 5.9385113334062298307003402;
    double g_1 = -0.98793227997522281569331426;

    //Se almacenan en el arreglo asociado a el filtro de 125Hz los valores de su H(k).
    inicializarHK(f125,G,a_0,b_0,c_0,e_0,f_0,g_0,b_1,c_1,d_1,e_1,f_1,g_1);
}
void controlVolume::inicializarH250(){

    //Coeficientes obtenidos al generar la funcion de transferencia y ecuacion de diferencias de los filtros de orden 6.
    double G = 0.000040929054711206818079668318;
    double a_0 = 1.0;
    double b_0 = -3.902501155624368944785374;
    double c_0 = 4.8050038824718228624988114;
    double e_0 = -4.8050038824718228624988114;
    double f_0 = 3.902501155624368944785374;
    double g_0 = -1.0;

    double b_1 = 5.970858033075922222110421;
    double c_1 = -14.858935846164756711118571;
    double d_1 = 19.72708134746538988224529;
    double e_1 = -14.736215153719255610553773;
    double f_1 = 5.8726394387280063114076256;
    double g_1 = -0.97542782140164918658342685;

    //Se almacenan en el arreglo asociado a el filtro de 250Hz los valores de su H(k).
    inicializarHK(f250,G,a_0,b_0,c_0,e_0,f_0,g_0,b_1,c_1,d_1,e_1,f_1,g_1);

}
void controlVolume::inicializarH500(){

    //Coeficientes obtenidos al generar la funcion de transferencia y ecuacion de diferencias de los filtros de orden 6.
    double G = 0.000086593064180069152921057074;
    double a_0 = 1.0;
    double b_0 = -3.6358483439687612204238576;
    double c_0 = 4.2717201469857393192341988;
    double e_0 = -4.2717201469857393192341988;
    double f_0 = 3.6358483439687612204238576;
    double g_0 = -1.0;

    double b_1 = 5.9332745075537252077424455;
    double c_1 = -14.685204622617673564377583;
    double d_1 = 19.407335230768644862564543;
    double e_1 = -14.443617387617392111565096;
    double f_1 = 5.7396734044529704732440223;
    double g_1 = -0.95146125988497265435483996;

    //Se almacenan en el arreglo asociado a el filtro de 500Hz los valores de su H(k).
    inicializarHK(f500,G,a_0,b_0,c_0,e_0,f_0,g_0,b_1,c_1,d_1,e_1,f_1,g_1);
}
void controlVolume::inicializarH1k(){

    //Coeficientes obtenidos al generar la funcion de transferencia y ecuacion de diferencias de los filtros de orden 6.
    double G = 0.000213804126957497;
    double a_0 = 1.0;
    double b_0 = -2.8486080392648727155;
    double c_0 = 2.6975120363417355307;
    double e_0 = -2.6975120363417355307;
    double f_0 = 2.8486080392648727155;
    double g_0 = -1.0;

    double b_1 = 5.8333303089089971749;
    double c_1 = -14.244364370759852179;
    double d_1 = 18.636922806015558507;
    double e_1 = -13.779420871523798908;
    double f_1 = 5.4588165829462678147;
    double g_1 = -0.90529237899539838352;

    //Se almacenan en el arreglo asociado a el filtro de 1kHz los valores de su H(k).
    inicializarHK(f1k,G,a_0,b_0,c_0,e_0,f_0,g_0,b_1,c_1,d_1,e_1,f_1,g_1);
}
void controlVolume::inicializarH2k(){

    //Coeficientes obtenidos al generar la funcion de transferencia y ecuacion de diferencias de los filtros de orden 6.
    double G = 0.00074926873545703097899417511;
    double a_0 = 1.0;
    double b_0 = -1.4947375892812146958021913;
    double c_0 = -0.0079745402897966055633105498;
    double e_0 = 0.0079745402897966055633105498;
    double f_0 = 1.4947375892812146958021913;
    double g_0 = -1.0;

    double b_1 = 5.5387754475048005531334638;
    double c_1 = -13.029374739156493134828452;
    double d_1 = 16.651554296506425600910006;
    double e_1 = -12.191866778059177178761274;
    double f_1 = 4.8500890150686037927130201;
    double g_1 = -0.81965335930735705449734496;

    //Se almacenan en el arreglo asociado a el filtro de 2kHz los valores de su H(k).
    inicializarHK(f2k,G,a_0,b_0,c_0,e_0,f_0,g_0,b_1,c_1,d_1,e_1,f_1,g_1);

}
void controlVolume::inicializarH4k(){

    //Coeficientes obtenidos al generar la funcion de transferencia y ecuacion de diferencias de los filtros de orden 6.
    double G = 0.0038620598365113022187866676;
    double a_0 = 1.0;
    double b_0 = -0.4538632308826702210780013;
    double c_0 = -2.0784018774208239399570175;
    double e_0 = 2.0784018774208239399570175;
    double f_0 = 0.4538632308826702210780013;
    double g_0 = -1.0;

    double b_1 = 4.6144062374193630660101917;
    double c_1 = -9.6764649201924619603687461;
    double d_1 = 11.642260519904482407582691;
    double e_1 = -8.4704561841444778735876753;
    double f_1 = 3.5365447408459269595937258;
    double g_1 = -0.67244749821832905389840107;

    //Se almacenan en el arreglo asociado a el filtro de 4kHz los valores de su H(k).
    inicializarHK(f4k,G,a_0,b_0,c_0,e_0,f_0,g_0,b_1,c_1,d_1,e_1,f_1,g_1);
}
void controlVolume::inicializarH8k(){

    //Coeficientes obtenidos al generar la funcion de transferencia y ecuacion de diferencias de los filtros de orden 6.
    double G = 0.023485908459061365094466822;
    double a_0 = 1.0;
    double b_0 = -0.053294510377427606329092669;
    double c_0 = -2.8410023434563282940246154;
    double e_0 = 2.8410023434563282940246154;
    double f_0 = 0.053294510377427606329092669;
    double g_0 = -1.0;

    double b_1 = 1.8584813304477576512141468;
    double c_1 = -3.0324829142244507096393136;
    double d_1 = 2.8064965808216433273969415;
    double e_1 = -2.3723134094008937466924181;
    double f_1 = 1.0888038141957738780263298;
    double g_1 = -0.4546435756375884484903338;

    //Se almacenan en el arreglo asociado a el filtro de 8kHz los valores de su H(k).
    inicializarHK(f8k,G,a_0,b_0,c_0,e_0,f_0,g_0,b_1,c_1,d_1,e_1,f_1,g_1);

}
void controlVolume::inicializarH16k(){

    //Coeficientes obtenidos al generar la funcion de transferencia y ecuacion de diferencias de los filtros de orden 6.
    double G = 0.10997904749987028050206561;
    double a_0 = 1.0;
    double b_0 = 0.030250891271815127936406498;
    double c_0 = -2.9393565409747353101010958;
    double e_0 = 2.9393565409747353101010958;
    double f_0 = -0.030250891271815127936406498;
    double g_0 = -1.0;

    double b_1 = -3.3343994032731112397982542;
    double c_1 = -4.7727334282323425895810942;
    double d_1 = -4.3522525193891041794813646;
    double e_1 = -2.9690684783118825862402446;
    double f_1 = -1.2885809650908786050393928;
    double g_1 = -0.23414890805816163110719685;

    //Se almacenan en el arreglo asociado a el filtro de 16kHz los valores de su H(k).
    inicializarHK(f16k,G,a_0,b_0,c_0,e_0,f_0,g_0,b_1,c_1,d_1,e_1,f_1,g_1);
}

/**
 * @brief filtroGeneral Funcion encargada aplicar el filtrado por DFT a una arreglo de muestras de tipo float.
 * @param blockSize numero de elementos que contiene la entrada, son valores de tipo float.
 * @param volumeGain numero entero que representa el escalado que se aplica a cada valor de la salida calculada.
 * @param in puntero al arreglo de valores de tipo float que conforman la entrada del sistema.
 * @param out puntero a un arreglo de valores tipo float que conforman la salida del ecualizador y son enviados a la tarjeta de audio a reproducirse.
 * @param hk puntero a un arreglo que contiene los valores complejos de H(k) de un filtro especifico.
 * @param temporal puntero al arreglo donde se almacenan los valores de la salida anterior que no se utilizaron y se guardaran los M-1 datos que sobren al filtrar.
 */
void controlVolume::filtroGeneral(int blockSize, int volumeGain, float *in, float *out, fftw_complex *hk, float *temporal){

    //int dobleBloque = 2 * blockSize;
    int dobleBloque = N;
   //Inicializan los arreglos que almacenaran a x(n), X(k), y(n), Y(k).
    fftw_complex *x = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * dobleBloque);
    fftw_complex *X = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * dobleBloque);
    fftw_complex *Y = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * dobleBloque);
    fftw_complex *y = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * dobleBloque);
/*
    //Se agregan los 1024 datos entrantes y se inicializa la parte imaginaria en cero al se valores reales.
    for(int i = 0; i < blockSize; i++){

        x[i][REAL] = in[i];
        x[i][IMAG] = 0.0;

    }


    //Se agregan M-1 ceros para poder aplicar el metodo de solapamiento y suma. M-1 = 1024.

    for(int i = blockSize; i< dobleBloque; i++){

        x[i][REAL] = 0.0;
        x[i][IMAG] = 0.0;

    }

    //Se aplica la DFT a x(n) para obtener X(k).
    fftw_plan dft = fftw_plan_dft_1d(dobleBloque,x,X,FFTW_FORWARD,FFTW_ESTIMATE);
    fftw_execute(dft);
*/
    /*Se realiza la multiplicacion de los valores complejos de X(k)H(k) = Y(k)
      A ser valores complejos dados en parte real e imaginaria se utiliza:

        Re{Y(k)} = Re{X(k)}*Re{H(k)} - Im{X(k)}*Im{H(k)}
        Im{Y(k)} = Re{X(k)}*Im{H(k)} + Re{H(k)}*Im{X(k)} */
/*
    for(int i = 0;i<dobleBloque;i++){

        Y[i][REAL] = (X[i][REAL]*hk[i][REAL]) - (X[i][IMAG]*hk[i][IMAG]);
        Y[i][IMAG] = (X[i][IMAG]*hk[i][REAL]) + (X[i][REAL]*hk[i][IMAG]);

    }

    //Se aplica la IDFT a Y(k) para obtener y(n).
    fftw_plan idft = fftw_plan_dft_1d(dobleBloque,Y,y,FFTW_BACKWARD,FFTW_ESTIMATE);
    fftw_execute(idft);

    double Div = static_cast<double>(dobleBloque);

    if(inicio){
    cout << "Se agregan 1s a la entrada" << endl;
        //Si es el inicio de la cancion los valores de la salida se guardan directamente
        for(int i=0; i<blockSize;i++){

           out[i] = static_cast<float>(0.02 * (volumeGain)* (y[i][REAL]/Div));

        }

    }else{

        //Si no es el inicio de la cancion la salida es la suma del valor actual obtenida mas el valor L+1+i de la salida anterior.
        for(int i=0; i<blockSize;i++){

           double salida =  y[i][REAL] / Div;
           salida  = salida + temporal[i];
           salida = salida * volumeGain * 0.02;
           out[i] = static_cast<float>(salida);

        }

    }
    //Se almacenan los M-1 valores sobrantes de la salida.
    for(int i=0; i<blockSize;i++){

        temporal[i] = static_cast<float>(y[blockSize+i][REAL]/Div);

    }
*/
//Solapamiento y almacenamiento/////////////////////

    //Se agrega la entrada anterior o ceros si es el inicio
    if(inicio){
        for(int i = 0; i < blockSize; i++){

            x[i][REAL] = 0.0;
            x[i][IMAG] = 0.0;

        }
    }
    else {
        for(int i = 0; i < blockSize; i++){

            x[i][REAL] = temporal[i];
            x[i][IMAG] = 0.0;

        }
    }

    //Hay que agregar los 4096 datos entrantes pero en la parte final del bloque
    for(int i = blockSize; i < dobleBloque; i++){

        x[i][REAL] = in[i-blockSize];
        x[i][IMAG] = 0.0;

    }

    //Se aplica la DFT a x(n) para obtener X(k).
    fftw_plan dft = fftw_plan_dft_1d(dobleBloque,x,X,FFTW_FORWARD,FFTW_ESTIMATE);
    fftw_execute(dft);

    for(int i = 0;i<dobleBloque;i++){

        Y[i][REAL] = (X[i][REAL]*hk[i][REAL]) - (X[i][IMAG]*hk[i][IMAG]);
        Y[i][IMAG] = (X[i][IMAG]*hk[i][REAL]) + (X[i][REAL]*hk[i][IMAG]);

    }

    //Se aplica la IDFT a Y(k) para obtener y(n).
    fftw_plan idft = fftw_plan_dft_1d(dobleBloque,Y,y,FFTW_BACKWARD,FFTW_ESTIMATE);
    fftw_execute(idft);

    double Div = static_cast<double>(dobleBloque);

    //Luego de aplicar la DFT y la IDFT se debe tomar solo la última parte de la salida de esta
    for(int i=0; i<blockSize;i++){
        double salida = y[i+blockSize][REAL] / Div;
        salida = salida * volumeGain * 0.02;
        out[i] = salida;
    }

    //Se agregan los datos de la última entrada
    for(int i = blockSize; i < dobleBloque; i++){

        temporal[i-blockSize] = static_cast<float>(x[i][REAL]);
    }

    //Se libera la memoria.
    fftw_destroy_plan(dft);
    fftw_destroy_plan(idft);
    fftw_free(x);
    fftw_free(X);
    fftw_free(y);
    fftw_free(Y);
    fftw_cleanup();
}

void controlVolume::obtenerEspectroPoder(float* in)
{
    int blocksize = N/2;

    //Contienen el valor máximo para cada barra
    float maximoBin1 = 0.0;
    float maximoBin2 = 0.0;
    float maximoBin3 = 0.0;
    float maximoBin4 = 0.0;
    float maximoBin5 = 0.0;
    float maximoBin6 = 0.0;
    float maximoBin7 = 0.0;
    float maximoBin8 = 0.0;
    float maximoBin9 = 0.0;
    float maximoBin10 = 0.0;

    //Inicializan los arreglos que almacenaran a x(n), X(k), y(n), Y(k).
     fftw_complex *x = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * blocksize);
     fftw_complex *X = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * blocksize);
     float* magnitudX = (float*) malloc(sizeof(float)*blocksize);
/*
     for(int i = 0; i < blocksize; i++){

         x[i][REAL] = in[i];
         x[i][IMAG] = 0.0;

     }

     //Se aplica la DFT a x(n) para obtener X(k).
     fftw_plan dft = fftw_plan_dft_1d(blocksize,x,X,FFTW_FORWARD,FFTW_ESTIMATE);
     fftw_execute(dft);
*/

     //se inicializa el vector de entrada con los datos de audio multiplicados por la ventana
     //Esto se hace según el método de Welch
     for(int i = 0; i < blocksize; i++){

         x[i][REAL] = in[i]*static_cast<float>(wVentana[i][REAL]);
         x[i][IMAG] = 0.0;

     }

     //Se aplica la DFT a x(n).
     fftw_plan dft = fftw_plan_dft_1d(blocksize,x,X,FFTW_FORWARD,FFTW_ESTIMATE);
     fftw_execute(dft);

     for(int i = 0; i < blocksize/2; i++){

         //Aplicando la fórmula de Welch
         float num = (1/(blocksize*constanteUVentana))*(static_cast<float>(X[i][REAL])*static_cast<float>(X[i][REAL]) + static_cast<float>(X[i][IMAG])*static_cast<float>(X[i][IMAG]));
         magnitudX[i] = num;
         //Se calcula la frecuencia de cada muestra
        float frecuenciaAnalogica = (44100.0/(N/2))*i;

        //Dependiendo de la frecuencia obtenida se decide la barra a la que pertenece
        if (frecuenciaAnalogica < 50)
        {
            //Revisa si el valor es el máximo que se ha encontrado
            if (magnitudX[i]>maximoBin1)
                maximoBin1 = magnitudX[i];
        }
        else if (frecuenciaAnalogica < 85)
        {
            if (magnitudX[i]>maximoBin2)
                maximoBin2 = magnitudX[i];
        }
        else if (frecuenciaAnalogica < 180)
        {
            if (magnitudX[i]>maximoBin3)
                maximoBin3 = magnitudX[i];
        }
        else if (frecuenciaAnalogica < 380)
        {
            if (magnitudX[i]>maximoBin4)
                maximoBin4 = magnitudX[i];
        }
        else if (frecuenciaAnalogica < 800)
        {
            if (magnitudX[i]>maximoBin5)
                maximoBin5 = magnitudX[i];
        }
        else if (frecuenciaAnalogica < 1700)
        {
            if (magnitudX[i]>maximoBin6)
                maximoBin6 = magnitudX[i];
        }
        else if (frecuenciaAnalogica < 3500)
        {
            if (magnitudX[i]>maximoBin7)
                maximoBin7 = magnitudX[i];
        }
        else if (frecuenciaAnalogica < 7000)
        {
            if (magnitudX[i]>maximoBin8)
                maximoBin8 = magnitudX[i];
        }
        else if (frecuenciaAnalogica < 14000)
        {
            if (magnitudX[i]>maximoBin9)
                    maximoBin9 = magnitudX[i];
        }
        else
        {
            if (magnitudX[i]>maximoBin10)
                maximoBin10 = magnitudX[i];
        }
     }

     //Se aplica la fórmula exponencial para obtener el tamaño de la barra
     maximoBin1 = 170*(1-exp(-0.01*maximoBin1*300));
     maximoBin2 = 170*(1-exp(-0.01*maximoBin2*300));
     maximoBin3 = 170*(1-exp(-0.01*maximoBin3*300));
     maximoBin4 = 170*(1-exp(-0.01*maximoBin4*300));
     maximoBin5 = 170*(1-exp(-0.01*maximoBin5*300));
     maximoBin6 = 170*(1-exp(-0.01*maximoBin6*300));
     maximoBin7 = 170*(1-exp(-0.01*maximoBin7*300));
     maximoBin8 = 170*(1-exp(-0.01*maximoBin8*300));
     maximoBin9 = 170*(1-exp(-0.01*maximoBin9*300));
     maximoBin10 = 170*(1-exp(-0.01*maximoBin10*300));

     //Se pasan los valores al singleton
     VentanaSingleton::instance()->setBin1(maximoBin1);
     VentanaSingleton::instance()->setBin2(maximoBin2);
     VentanaSingleton::instance()->setBin3(maximoBin3);
     VentanaSingleton::instance()->setBin4(maximoBin4);
     VentanaSingleton::instance()->setBin5(maximoBin5);
     VentanaSingleton::instance()->setBin6(maximoBin6);
     VentanaSingleton::instance()->setBin7(maximoBin7);
     VentanaSingleton::instance()->setBin8(maximoBin8);
     VentanaSingleton::instance()->setBin9(maximoBin9);
     VentanaSingleton::instance()->setBin10(maximoBin10);

    //Se libera la memoria.
    fftw_destroy_plan(dft);
    fftw_free(x);
    fftw_free(X);
    fftw_cleanup();
}

/**
* @brief filter Funcion encargada de filtrar la entrada de datos pasandola por distintos filtros y luego sumando la salida de cada uno.
* @param blockSize cantidad de muestras que contiene la entrada.
* @param volumeGain valor entero que representa la posicion del slider y escala el valor final de la salida controlando asi el volumen.
* @param g32 valor entero que representa la posicion del slider asociado al filtro de 32Hz y escala el valor de la salida especifica de dicho filtro.
* @param g64 valor entero que representa la posicion del slider asociado al filtro de 64Hz y escala el valor de la salida especifica de dicho filtro.
* @param g125 valor entero que representa la posicion del slider asociado al filtro de 125Hz y escala el valor de la salida especifica de dicho filtro.
* @param g250 valor entero que representa la posicion del slider asociado al filtro de 250Hz y escala el valor de la salida especifica de dicho filtro.
* @param g500 valor entero que representa la posicion del slider asociado al filtro de 500Hz y escala el valor de la salida especifica de dicho filtro.
* @param g1k valor entero que representa la posicion del slider asociado al filtro de 1kHz y escala el valor de la salida especifica de dicho filtro.
* @param g2k valor entero que representa la posicion del slider asociado al filtro de 2kHz y escala el valor de la salida especifica de dicho filtro.
* @param g4k valor entero que representa la posicion del slider asociado al filtro de 4kHz y escala el valor de la salida especifica de dicho filtro.
* @param g8k valor entero que representa la posicion del slider asociado al filtro de 8kHz y escala el valor de la salida especifica de dicho filtro.
* @param g16k valor entero que representa la posicion del slider asociado al filtro de 16kHz y escala el valor de la salida especifica de dicho filtro.
* @param in puntero al arreglo de valores de tipo float que conforman la entrada del sistema.
* @param out puntero a un arreglo de valores tipo float que conforman la salida del ecualizador y son enviados a la tarjeta de audio a reproducirse.
*/
void controlVolume::filter(int blockSize, int volumeGain,int g32,int g64,int g125,int g250,int g500,int g1k,int g2k,int g4k,int g8k,int g16k, float *in, float *out){

    //Se inicializan los punteros que almacenaran la salida de cada filtro.
    float* pf32 = new float[blockSize];
    float* pf64 = new float[blockSize];
    float* pf125 = new float[blockSize];
    float* pf250 = new float[blockSize];
    float* pf500 = new float[blockSize];
    float* pf1k = new float[blockSize];
    float* pf2k = new float[blockSize];
    float* pf4k = new float[blockSize];
    float* pf8k = new float[blockSize];
    float* pf16k = new float[blockSize];

    float* salidaReverb = new float[blockSize];

    //Se llama la funcion que realiza el filtrado para cada uno de los filtros.
    //filtroGeneral(int blockSize, int volumeGain, float *in, float *out, fftw_complex *hk, float *temporal)
    //blocksize es L o el tamaño que se obtiene de la entrada.
    //volumeGain es la ganancia de volumen que viene de cada slider
    //in es la entrada en valores flotantes
    //out es la y(n) para cada filtro
    //hk es el filtro en el dominio de la frecuencia
    //temporal es un bloque del último proceso de filtrado, usado en solapamiento y suma
    filtroGeneral(blockSize,g32,in,pf32,f32,datos32);
    filtroGeneral(blockSize,g64,in,pf64,f64,datos64);
    filtroGeneral(blockSize,g125,in,pf125,f125,datos125);
    filtroGeneral(blockSize,g250,in,pf250,f250,datos250);
    filtroGeneral(blockSize,g500,in,pf500,f500,datos500);
    filtroGeneral(blockSize,g1k,in,pf1k,f1k,datos1k);
    filtroGeneral(blockSize,g2k,in,pf2k,f2k,datos2k);
    filtroGeneral(blockSize,g4k,in,pf4k,f4k,datos4k);
    filtroGeneral(blockSize,g8k,in,pf8k,f8k,datos8k);
    filtroGeneral(blockSize,g16k,in,pf16k,f16k,datos16k);

    for (int n=0; n<blockSize;++n){

        out[n] = 0.04 * (volumeGain)*(pf32[n]+pf64[n]+pf125[n]+pf250[n]+pf500[n]+pf1k[n]+pf2k[n]+pf4k[n]+pf8k[n]+pf16k[n]);
        //out[n] = 0.01 * (volumeGain)*(salidaReverb[n]);
    }

    //Si el botón de reverb está activado, se aplica el filtro, si no, no se hace nada
    if (VentanaSingleton::instance()->getReverbActivo())
    {
        if(inicio){
            inicio = false;
        }
        filtroGeneral(blockSize, 10, out, salidaReverb, hkeverb, datosReverb);
        // La salida va a ser el filtro multiplicado por una constante
        for (int n=0; n<blockSize;++n){
            out[n] = 0.03 * (volumeGain)*(salidaReverb[n]);
        }

    }

    // Si el botón de visualizador está activo, obtiene el espectro de poder y muestra las barras
    if (VentanaSingleton::instance()->getBarrasActivo())
    {
        obtenerEspectroPoder(out);
    }
    else // Si no, entonces deja las barras en el mínimo
    {
        VentanaSingleton::instance()->setBin1(1);
        VentanaSingleton::instance()->setBin2(1);
        VentanaSingleton::instance()->setBin3(1);
        VentanaSingleton::instance()->setBin4(1);
        VentanaSingleton::instance()->setBin5(1);
        VentanaSingleton::instance()->setBin6(1);
        VentanaSingleton::instance()->setBin7(1);
        VentanaSingleton::instance()->setBin8(1);
        VentanaSingleton::instance()->setBin9(1);
        VentanaSingleton::instance()->setBin10(1);
    }

    //Al realizar el procedimiento una vez se define que ya no es el inicio de la cancion.
    if(inicio){
        inicio = false;
    }

    //Se libera la memoria solicitada.
    delete pf32;
    delete pf64;
    delete pf125;
    delete pf250;
    delete pf500;
    delete pf1k;
    delete pf2k;
    delete pf4k;
    delete pf8k;
    delete pf16k;
    delete salidaReverb;
}
