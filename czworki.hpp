//
//  czworki.hpp
//  czworki klasami
//
//  Created by Łukasz Michalak on 01/04/2019.
//  Copyright © 2019 Łukasz Michalak. All rights reserved.
//

#ifndef czworki_hpp
#define czworki_hpp

#include <stdio.h>

class czworki{
public:
    czworki();
    void zabawa();
private:
    void _animacja(int i,int gracz,int kolumna);
    void _wielkosc_planszy();
    int _wygrana(int gracz);
    int _dlugosc;
    void _poka();
    int _wysokosc;
    int** _gra;
    void _ruch(int gracz);
};

#endif /* czworki_hpp */
