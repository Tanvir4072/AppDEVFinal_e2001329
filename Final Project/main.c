#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <curl/curl.h>
#include "Appdev.h"

int main(void)
{
    CURL* curl;
    CURLcode res;
    char postsring[200];
    combo c = minmax(); // generate a combo of min/MAX value

    sprintf(postsring, "min=%d&max=%d", c.min, c.max);

    curl = curl_easy_init();
    if (curl) {

        curl_easy_setopt(curl, CURLOPT_URL, "http://www.cc.puv.fi/~e2001329/echo.php");

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postsring);


        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));


        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}