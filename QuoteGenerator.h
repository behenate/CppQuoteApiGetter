#ifndef PROJECT2_QUOTEGENERATOR_H
#define PROJECT2_QUOTEGENERATOR_H

#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QSpacerItem>
#include "curl/curl.h"
#include <iostream>
#include "RSJparser.tcc"
using namespace std;

class QuoteGenerator {
public:
    QuoteGenerator(){};
    void getQuote(QLabel *quote, QLabel *author);
};


#endif //PROJECT2_QUOTEGENERATOR_H
