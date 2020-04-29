/**
 * @file stddev.cpp
 * 
 * @brief Program pro výpočet směrodatné odchylky
 * @author Thanh Quang Tran
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "./../libs/basic_math.h"
#include "./../libs/adv_math.h"


int main()
{
    double number, count = 0, ariSum = 0, ariMean, devSum = 0, stdDev, tmp;
    char whiteSpace;

    if (isatty(0)) 
    {
        printf("Input was not redirected.\n");
        return -1;
    }
    else
    {
        //Výpočet sumy čísel ze stdin
        while(scanf("%lf%c", &number, &whiteSpace)!=EOF)
        {
            //Aritmetický průměr
            ariSum = add(ariSum, number);
            count++;
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
            tmp = Exponent(tmp, 2, 0.000000000001, 0);
            devSum = add(devSum, tmp);
        }

        //Směrodatná odchylka
        stdDev = NthRoot(divide(devSum, count, 0), 2, 0.000000000001, 0);

        //printf("Smerodatna odchylka:\nCitatel: %lf\nJmenovatel: %.0lf\nSměrodatná odchylka: %0.5lf\n", devSum, count, stdDev);
    }
    return 0;
}