#include <stdio.h>
#include <iostream>
#include "ListData.hpp"
using namespace std;



ListData::ListData() {
    m_size = 0;
    m_list = new float[1024];
    for (int i = 0; i < 1024; i++)
    {
        m_list[i] = 0;
    }
}

ListData::ListData(int size) {
    if (size > 1024){cout << "Taille max -> 1024" << endl;return;}
    m_size = 0;
    m_list = new float[size];
    for (int i = 0; i < size; i++)
    {
        m_list[i] = 0;
    }
}

ListData::~ListData() {
    delete[] m_list;
}

void ListData::AddData(int value){
    if (m_size == 1024) {cout << "Liste deja remplie" << endl; return;}
    m_list[m_size] = value;
    m_size++;
    return;
}

void ListData::PrintData() const {
    if (m_size == 0){cout << "Liste vide" << endl; return;}
    cout << "{" << m_list[0];
    for (int i = 1; i < m_size; i++) {
        cout << "," << m_list[i];
    }
    cout << "}" << endl;
    return;
}

float ListData::SomData() const {
    int result = 0;
    for (int i = 0; i < m_size; i++)
    {
        result += m_list[i];
    }
    cout << result << endl;
    return result;
}

float ListData::MoyData() const {
    if (m_size == 0){cout << "Liste vide" << endl; return 0;}
    float moy = (float)SomData()/m_size;
    cout << moy << endl;
    return moy;
}

float ListData::MinData() const {
    if (m_size == 0){cout << "Liste vide" << endl; return 0;}
    int minTmp = 0;
    for (int i = 0; i < m_size; i++)
    {
        if (minTmp > m_list[i]) minTmp = m_list[i];
    }
    cout << minTmp << endl;
    return minTmp;
}

float ListData::MaxData() const {
    if (m_size == 0){cout << "Liste vide" << endl; return 0;}
    int maxTmp;
    for (int i = 0; i < m_size; i++)
    {
        if (maxTmp < m_list[i]) maxTmp = m_list[i];
    }
    cout << maxTmp << endl;
    return maxTmp;
}

float ListData::VariationMax() const {
    if (m_size == 0){cout << "Liste vide" << endl; return 0;}
    int varMaxTmp = 0;
    for (int i = 0; i < m_size - 1; i++)
    {
        int currentData = m_list[i];
        for (int j = 1; j < m_size; j++)
        {
            float currentVar = currentData - m_list[j];
            if ( currentVar < 0) {
                varMaxTmp = varMaxTmp < -currentVar? currentVar : varMaxTmp;
            }
            else {
                varMaxTmp = varMaxTmp < currentVar? currentVar : varMaxTmp;
            }
        }
    }
    cout << varMaxTmp << endl;
    return varMaxTmp;
}
