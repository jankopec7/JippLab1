#include <iostream>  

using namespace std;

int main(){ 

    float masa_ciala, wzrost, BMI;

    cout << "Podaj masę ciała[kg]: ";
    cin >> masa_ciala;
    cout << "Podaj wzrost [m]: ";
    cin >> wzrost;

    BMI = (masa_ciala)/(wzrost * wzrost);

    cout << "Twoj wskaźnik BMI: " << endl;

    if(BMI < 16)   
    cout << "mniej niż 16 - wygłodzenie";
    else if(BMI < 17)  
    cout << "16 - 16.99 - wychudzenie";
    else if(BMI < 18.5)
    cout << "17 - 18.49 - niedowaga";
    else if(BMI < 25)
    cout << "18.5 - 24.99 - wartość prawidłowa";
    else if(BMI < 30)
    cout << "25 - 29.99 - nadwaga";
    else if(BMI < 35)
    cout << "30 - 34.99 - I stopień otyłości";
    else if(BMI < 40)
    cout << "35 - 39.99 - II stopień otyłości";
    else
    cout << "powyżej 40 - otyłość skrajna";

    return 0;
}