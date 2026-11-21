#include <iostream>
#include <cstdlib>

//Vasilev A.H. C++ programming in example and tasks

//Convert Mile to Kilometers
int example1(){

    const double kmInMile = 1.609344;
    double distMile, distKm;

    std::cout << "Укажите расстояние в милях :";
    std::cin >> distMile;
    
    distKm = distMile * kmInMile;

    std::cout << "Расстояние в км :" << distKm << std::endl;
    std::system("pause>nul");
    return 0;
}

void example2(){
    
    const int ftInMile = 5280;
    const double kmInMile = 1.609344;
    
    //Mile, Foot, Kilometers, Meters 
    int dMile, dFt, dKm, dM;
    std::cout << "Distance in Mile ";
    std::cin >> dMile;
    std::cout << "Distance in Foots ";
    std::cin >> dFt;

    double distMile = dMile + (double) dFt / ftInMile;

    double distKm = distMile * kmInMile;

    dKm = (int) distKm;

    dM = (int) ((distKm-dKm) * 1000);
    std::cout << "Distance in km "<< dKm <<" and meters " << dM << std::endl;
    std::system("pause>nul");
}


double getDistanceMile(){
    double dist;
    std::cout << "Input distance in miles: " << std::endl;
    std::cin >> dist;
    return dist;
}


double getDistanceKilometers(double dist){
    double kmInMile = 1.609344;
    return dist * kmInMile;
}

int main(){
    double distMile=getDistanceMile();
    std::cout << "Distance in Kilometers: " << getDistanceKilometers(distMile) << std::endl;
    std::system("pause>nul");
    return 0;
}