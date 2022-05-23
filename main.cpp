#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QSpacerItem>
#include <iostream>
using namespace std;
#include "QuoteGenerator.h"



int main(int argc, char *argv[]) {
    QApplication app (argc, argv);
    QApplication::setApplicationName("Change Your Life");
    QWidget window;
    window.setGeometry(200,200,1000, 200);

    QPushButton *button = new QPushButton("Life-changing quote", &window);
    button->setGeometry(10, 10, 80, 30);
    QLabel *quote = new QLabel("You miss 100% of the shots you don't take ~Wanye Gretzky ~Michael Scott", &window);
    QFont quote_font = QFont("Times", 13, QFont::Cursive);
    quote_font.setItalic(true);
    quote->setFont(quote_font);
    quote->setWordWrap(true);
    QLabel *author = new QLabel("~Michael Scott", &window);
    author->setFont(QFont("Times", 11, QFont::StyleItalic));


    // Create a grid layout with two columns and one row
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(quote, 0, 0,1,3);
    layout->addWidget(author, 1, 0);
    layout->addWidget(button, 2, 1);

    // Setup spacers
    QSpacerItem *layout_v_spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(layout_v_spacer, 3, 0);
    QSpacerItem *button_left_spacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);
    layout->addItem(button_left_spacer, 2, 0);
    QSpacerItem *button_right_spacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);
    layout->addItem(button_right_spacer, 2, 2);
    QuoteGenerator generator = QuoteGenerator();
    generator.getQuote(quote, author);
    // On button click, get a quote
    QPushButton::connect(button, &QPushButton::clicked, [&]() {
        generator.getQuote(quote, author);
    });
    window.setLayout(layout);

    window.show();
    return app.exec();
}
