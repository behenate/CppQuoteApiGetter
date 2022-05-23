#include "QuoteGenerator.h"
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QSpacerItem>
#include "curl/curl.h"
#include <iostream>
#include "RSJparser.tcc"
using namespace std;
// This is the writer call back function used by curl
static int writer(char *data, size_t size, size_t nmemb,
                  std::string *buffer)
{
    int result = 0;
    buffer->append(data, size * nmemb);
    result = size * nmemb;
    return result;
}

void QuoteGenerator::getQuote(QLabel *quote, QLabel *author){
    string link = "https://api.quotable.io/random";
    string url(link);

    cout << "Retrieving " << url << endl;

//    JSON string buffer
    string buffer;

    CURL *curl;
    CURLcode result;

    // Create our curl handle
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl)
    {
        // Curl options
        curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
        curl_easy_setopt(curl, CURLOPT_HEADER, 0);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

        // GET from url
        result = curl_easy_perform(curl);

        // Always cleanup
        curl_easy_cleanup(curl);
//        parse result
        if (result == CURLE_OK)
        {
            cout << buffer << "\n";
            RSJresource my_json(buffer);
            string quote_str = my_json["content"].as<std::string>("default string");
            string author_str = my_json["author"].as<std::string>("default string");
            author_str = "~" + author_str;
            quote->setText(QString::fromStdString(quote_str));
            author->setText(QString::fromStdString(author_str));
            cout << quote_str << endl;
            cout << author_str << endl;
            buffer="";
        }
    }
}

