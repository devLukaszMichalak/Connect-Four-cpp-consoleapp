//
//  czworki.cpp
//  czworki klasami
//
//  Created by Łukasz Michalak on 01/04/2019.
//  Copyright © 2019 Łukasz Michalak. All rights reserved.
//
#include <unistd.h>
#include "czworki.hpp"
#include <iostream>

void czworki::_wielkosc_planszy(){
    do{
        std::cout<<"Prosze podac wysokosc: ";
        std::cin>>_wysokosc; //bo od 0
        std::cout<<"Prosze podac dlugosc: ";
        std::cin>>_dlugosc; //bo od 0
        if(_wysokosc<4||_dlugosc<4){
            std::cout<<"Plansza musi miec conajmnej 4 na 4, zeby gra miala sens!"<<std::endl;
            continue;
            }
            break;
            }while(1);
}

czworki::czworki(){
    _wielkosc_planszy();
    _gra=new int* [_wysokosc];
    for(int i=0;i<_wysokosc;i++){
        _gra[i]=new int [_dlugosc];
    }
    for(int i=0;i<_wysokosc;i++){
        for(int j=0;j<_dlugosc;j++){
            _gra[i][j]=0;
        }
    }
}

int czworki::_wygrana(int gracz){
    int prosto=0,skos_prawo=0,skos_lewo=0,pion=0;
    for(int i=0;i<_wysokosc;i++){
        for(int j=0;j<_dlugosc;j++){
            for(int k=0;k<4;k++){
                if(j+k<_dlugosc){
                    if(_gra[i][j+k]==gracz){
                        prosto++;
                    }
                }
                if(i+k<_wysokosc){
                    if(_gra[i+k][j]==gracz){
                        pion++;
                    }
                }
                if(j+k<_dlugosc&&i+k<_wysokosc){
                    if(_gra[i+k][j+k]==gracz){
                        skos_prawo++;
                    }
                }
                if(j>=3&&i+k<_wysokosc){
                    if(_gra[i+k][j-k]==gracz){
                        skos_lewo++;
                    }
                }
            }
            if(prosto==4||skos_lewo==4||skos_prawo==4||pion==4){
                return 1; //wygrana
            }
            prosto=pion=skos_prawo=skos_lewo=0;
        }
    }
    return 0;
}
void czworki::_animacja(int i,int gracz,int kolumna){
    for(int h=_wysokosc-1;h>i;h--){
        _gra[h][kolumna]=gracz;
        _poka();
        usleep(200000);
        system("clear");
        _gra[h][kolumna]=0;
        system("clear");
    }
}

void czworki::_poka(){
    for(int i=0;i<_wysokosc;i++){
        for(int j=0;j<_dlugosc;j++){
            std::cout<<_gra[_wysokosc-1-i][j]<<_gra[_wysokosc-1-i][j]<<"   ";
        }
        std::cout<<std::endl;
        for(int j=0;j<_dlugosc;j++){
            std::cout<<_gra[_wysokosc-1-i][j]<<_gra[_wysokosc-1-i][j]<<"   ";
        }
        std::cout<<std::endl<<std::endl;
    }
    for(int i=0;i<5*_dlugosc-3;i++){
        std::cout<<"-";
    }
    std::cout<<std::endl;
    for(int i=0;i<_dlugosc;i++){
        std::cout<<i+1<<"    ";
    }
    std::cout<<std::endl;
}

void czworki::_ruch(int gracz){
    using namespace std;
    cout<<"Gracz "<<gracz<<endl;
    int kolumna,wpisanie=0;
    do{
        cout<<"Prosze podac kolumne do wrzucenia: ";
        cin>>kolumna;
        if(kolumna<=_dlugosc&&kolumna>0){
            kolumna-=1;
            for(int i=0;i<_wysokosc;i++){
                if(_gra[i][kolumna]==0){
                    system("clear");
                    _animacja(i,gracz, kolumna);
                    _gra[i][kolumna]=gracz;
                    wpisanie=1;
                    i=_wysokosc;
                }
            }
            if(wpisanie==1){
                return;
            }
            else{
                cout<<"Nie ma juz miejsca! ";
            }
        }
        else{
            cout<<"Liczba musi byc wieksza od 0 oraz mniejsza od "<<_dlugosc+1<<endl;
        }
    }while(1);
}

void czworki::zabawa(){
    system("clear");
    _poka();
    for(int i=0,gracz=1;i<_wysokosc*_dlugosc;i++,gracz+=1){
        _ruch(gracz);
        system("clear");
        _poka();
        if(_wygrana(gracz)==1){
            std::cout<<"Gracz "<<gracz<<" wygral :D"<<std::endl;
            break;
        }else if (i==_wysokosc*_dlugosc-1){
            std::cout<<"Remis!"<<std::endl;
        }
        if(gracz==2){
            gracz-=2;//zmiana graczy
        }
    }
}

