#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "adv_math.h"
#include "basic_math.h"
#include "adv_math.cpp"
#include "basic_math.cpp"

int main()
{
    double number, count = 0, ariSum = 0, ariMean, devSum = 0, stdDev, tmp;
    char whiteSpace;

    //Pro výpočet sumy čísel ze stdin
    while(scanf("%lf%c", &number, &whiteSpace)!=EOF)
    {
        //Aritmeticky prumer
        ariSum = add(ariSum, number);
        count++;
        //
    }

    if(count != 0)
    {
        ariMean = divide(ariSum, count, 0);
    }

    //printf("Aritmeticky prumer: %lf\n", ariMean);

    rewind(stdin);

    //Pro výpočet čitatele rozptylu
    while(scanf("%lf%c", &number, &whiteSpace)!=EOF)
    {
        tmp = sub(number, ariMean);
        tmp = Exponent(tmp, 2, 0.000001, 0);
        devSum = add(devSum, tmp);
    }

    //Směrdatná odchylka
    stdDev = NthRoot(divide(devSum, count, 0), 2, 0.000001, 0);

    //printf("Smerodatna odchylka:\nCitatel: %lf\nJmenovatel: %.0lf\nSměrodatná odchylka: %0.5lf/n", devSum, count, stdDev);

    return 0;
}