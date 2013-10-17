//
//  main.cpp
//  FactorialBigNum2
//
//  Created by Diego Cristobal Navia Fuentes on 14-10-13.
//  Copyright (c) 2013 Diego Cristobal Navia Fuentes. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
const int cantidadDigitosVector2=1000;

struct ArregloVector {
    int numero[1000]; // El vector
};





//IMPRIME LOS DIGITOS DE UN VECTOR
void imprimirNum(vector<short> vector1){
    
    for (int i=0; i<vector1.size(); i++) {
     
        cout<<vector1[i]<<" | ";
        
    }
    cout<<endl;
}

//Cambiar(Alarga) pisicion el vector que sta adentro EJ: v1 :1000 v2:100  -> v2:0100
vector<short> alargarVector(vector<short> vector1,int largoVectorMayor){
    
    vector<short> vectorAux;
    int auxContador=0;
    int largoVector1=(int)vector1.size();
    int espacioRestante=largoVectorMayor;
    cout<<"LARGO VECTOR mAYOR :"<<largoVectorMayor<<endl;
    if (largoVectorMayor>vector1.size()) {
        for (int i=0; i<largoVectorMayor; i++) {
          
            if (espacioRestante<=largoVector1) {
                vectorAux.push_back(vector1[auxContador]);
                auxContador++;
            }
            else{
                vectorAux.push_back(0);
            }
            espacioRestante--;
            
        }
        
    }
    else{
        vectorAux=vector1;
    }
    cout<<"Vector Alargado :"<<endl;
    imprimirNum(vectorAux);
    return vectorAux;
}


//Sumar Los digitos de los Vectores
vector<short> sumaVectoresEspecial(vector<short> vectores[],int cantVectores){
    vector<short> vectorResultado;
    vector<short> vectoresAlargados[cantidadDigitosVector2];
    vector<short> vectorAux;
    int sumaAux1=0;
    int largoAux=0;
    
    
    largoAux=(int)vectores[0].size();
   
    for (int i=0; i<cantVectores; i++) {
        vectoresAlargados[i]=alargarVector(vectores[i], largoAux);
        cout<<"VEctores Alargador :"<<endl;
        imprimirNum(vectoresAlargados[i]);
        
    }
    
    cout<<"Temrina Vectores ALARGADOS "<<endl;
    
    for (int i=0; i<largoAux; i++) {
       
        for (int j=0; j<cantVectores; j++) {
            vectorAux=vectoresAlargados[j];
            imprimirNum(vectorAux);
            sumaAux1=sumaAux1+vectorAux[i];
            
        }
        vectorResultado.push_back(sumaAux1);
        sumaAux1=0;
    }
    
    cout<<"Suma Vectores Especial Resultado :"<<endl;
    imprimirNum(vectorResultado);
    
    return vectorResultado;
    
}


// CONVERTIR DE INT A VECTOR

vector<short> convertirIntAVector(int numero){
    vector<short> vector1;
    vector<short> vector2;
    int largo=0;
    int aux=0;
    int contador=0;
    
    while (numero!=0) {
        aux=numero%10;
        numero=numero/10;
        contador++;
        vector1.push_back(aux);
        
    }
    
    
    largo=(int)vector1.size()-1;
    for (int i=largo; i>=0; i--) {
        vector2.push_back(vector1[i]);
    }
    return vector2;
}

//Convertir vector a INT

int convertirVectorAInt(vector<short> vector1){
    int numero = 0;
    int aux=0;
    int contador2=(int)vector1.size()-1;
    
    for (int i=0; i<vector1.size(); i++) {
        aux=vector1[i];
        numero=numero+(aux*pow(10, contador2));
        contador2--;
    }
    
    return numero;
}

vector<short> agregarCerosVector(int numeroMayor,int digitoMultiplicar,int largo){
    vector<short> auxVector;
    int auxNumero=0;
    int resultadoMulti;
    resultadoMulti=numeroMayor*digitoMultiplicar;
    auxVector=convertirIntAVector(resultadoMulti);
    int largoAuxVector=(int)auxVector.size();
    
    cout<<"LARGO QUE ENTRA :"<<largo<<endl;
  
    
    for (int i=0; i<largo; i++) {
        
       
            auxVector.push_back(0);
        
        
    }
    cout<<"Imprimir Agregar Ceros :"<<endl;
    imprimirNum(auxVector);
    
    
    
    
    return auxVector;
}

void multiplicar(vector<short> vector1,vector<short> vector2){
    
    int numeroMayor=0;
    vector<short> sumaVector[cantidadDigitosVector2];
    int contadorAtras=(int)vector2.size()-1;
    vector<short> auxVector;
    
    if (vector1.size()>=vector2.size()) {
        numeroMayor=convertirVectorAInt(vector1);
        
        for (int i=0; i<vector2.size(); i++) {
            sumaVector[i]=agregarCerosVector(numeroMayor,vector2[i],contadorAtras);
            contadorAtras--;
        }
        
        
    }
    /* ERA PARA SABER QUE PASABA CON LOS VECTORES QUE SE CREARON MULTIPLICANDO
     int numeroAux;
    for (int i=0;i<vector2.size(); i++) {
        numeroAux=convertirVectorAInt(sumaVector[i]);
        cout<<"Numero Multiplicado :"<<numeroAux<<endl;
    }
    */
    sumaVectoresEspecial(sumaVector,(int)vector2.size());
     
    
}


//SEPARA CADA LETRA DE UN STRING LO DEJA EN UN VECTOR NUMERICO
vector<short> separarNumero(string entrada){
    vector<short> vector1;
    
    
    int aux;
    
    for (int i=0; i<entrada.length(); i++) {
        
        aux=(int)entrada[i] - 48;
        vector1.push_back(aux);
        
    }
    
    return vector1;
    
}


int main(int argc, const char * argv[])
{

    string entrada;
    int entrada2;
    vector<short> vector1;
    vector<short> vector2;
    
    cout<<"::INGRESE UN NUMERO::"<<endl;
    cin>>entrada;
    cout<<"::INGRESE OTRO NUMERO::"<<endl;
    cin>>entrada2;
    
    
    int a=100000*70000;
    cout<<"Multiplicacion numero Grande"<<a<<endl;
    vector1=separarNumero(entrada);
    //cout<<"Numero Vector a Int : "<<convertirVectorAInt(vector1)<<endl;
    //cout<<"Numero INT a Vector :"<<endl;
    vector2=convertirIntAVector(entrada2);
    cout<<"Numeros A multiplicar :"<<endl;
    cout<<"A : ";
    imprimirNum(vector1);
    cout<<endl;
    cout<<"B : ";
    imprimirNum(vector2);
    cout<<endl;
    multiplicar(vector1, vector2);
 
    
    cout<<endl;
    //imprimirNum(vector1);
    //cout<<"ALargar Vector :"<<endl;
    //alargarVector(vector2, 2);

    //std::cout << "Hello, World!\n";
    return 0;
}

