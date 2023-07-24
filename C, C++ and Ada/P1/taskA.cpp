#include<iostream>
using namespace std;

int main() {
    //WEJĹCIE
    int l, sila1, sila2, i = 0, gryA = 0, gryB = 0, gryC = 0, gryD = 0;
    double wynikA = 0, wynikB = 0, wynikC = 0, wynikD = 0, remisA = 0, remisB = 0, remisC = 0, remisD = 0,
            przegraneA = 0, przegraneB = 0, przegraneC = 0, przegraneD = 0;
    char wybor1, wybor2, gracz1, gracz2;
    cin >> l;
    while (i < l) {
        cin >> gracz1 >> wybor1 >> sila1 >> gracz2 >> wybor2 >> sila2;
        i++;
        //J
        if (wybor1 == 'J' && wybor2 == 'P') {
            //wygrane gdy wygrywa 1
            if (gracz1 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz1 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz1 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz1 == 'd') {
                wynikD++;
                gryD++;
            }
            //przegrane gdy wygrywa 1
            if (gracz2 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz2 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz2 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz2 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'P' && wybor2 == 'J') {
            //wygrane gdy wygrywa 2
            if (gracz2 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz2 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz2 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz2 == 'd') {
                wynikD++;
                gryD++;
            }
            //przegrane gdy wygrywa 2
            if (gracz1 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz1 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz1 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz1 == 'd') {
                gryD++;
                przegraneD++;
            }

        }
        if (wybor1 == 'J' && wybor2 == 'S') {

            if (gracz1 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz1 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz1 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz1 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz2 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz2 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz2 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz2 == 'd') {
                gryD++;
                przegraneD++;
            }

        }
        if (wybor1 == 'S' && wybor2 == 'J') {

            if (gracz2 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz2 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz2 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz2 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz1 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz1 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz1 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz1 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        //J



        //K
        if (wybor1 == 'K' && wybor2 == 'J') {
            if (gracz1 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz1 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz1 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz1 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz2 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz2 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz2 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz2 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'J' && wybor2 == 'K') {

            if (gracz2 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz2 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz2 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz2 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz1 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz1 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz1 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz1 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'K' && wybor2 == 'N') {
            if (gracz1 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz1 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz1 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz1 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz2 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz2 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz2 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz2 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'N' && wybor2 == 'K') {
            if (gracz2 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz2 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz2 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz2 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz1 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz1 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz1 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz1 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        //K



        //N
        if (wybor1 == 'N' && wybor2 == 'J') {
            if (gracz1 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz1 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz1 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz1 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz2 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz2 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz2 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz2 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'J' && wybor2 == 'N') {
            if (gracz2 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz2 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz2 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz2 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz1 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz1 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz1 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz1 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'N' && wybor2 == 'P') {
            if (gracz1 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz1 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz1 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz1 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz2 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz2 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz2 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz2 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'P' && wybor2 == 'N') {
            if (gracz2 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz2 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz2 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz2 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz1 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz1 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz1 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz1 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        //N



        //P
        if (wybor1 == 'P' && wybor2 == 'K') {
            if (gracz1 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz1 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz1 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz1 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz2 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz2 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz2 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz2 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'K' && wybor2 == 'P') {
            if (gracz2 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz2 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz2 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz2 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz1 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz1 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz1 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz1 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'P' && wybor2 == 'S') {
            if (gracz1 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz1 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz1 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz1 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz2 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz2 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz2 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz2 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'S' && wybor2 == 'P') {
            if (gracz2 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz2 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz2 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz2 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz1 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz1 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz1 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz1 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        //P



        //S
        if (wybor1 == 'S' && wybor2 == 'K') {
            if (gracz1 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz1 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz1 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz1 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz2 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz2 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz2 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz2 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'K' && wybor2 == 'S') {
            if (gracz2 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz2 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz2 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz2 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz1 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz1 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz1 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz1 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'S' && wybor2 == 'N') {
            if (gracz1 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz1 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz1 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz1 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz2 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz2 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz2 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz2 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if (wybor1 == 'N' && wybor2 == 'S') {
            if (gracz2 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz2 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz2 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz2 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz1 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz1 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz1 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz1 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        //S

        //TE SAME WYBORY
        if (wybor1 == wybor2 && sila1 > sila2) {
            if (gracz1 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz1 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz1 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz1 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz2 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz2 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz2 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz2 == 'd') {
                gryD++;
                przegraneD++;
            }

        }
        if (wybor1 == wybor2 && sila2 > sila1) {
            if (gracz2 == 'a') {
                wynikA++;
                gryA++;
            }
            if (gracz2 == 'b') {
                wynikB++;
                gryB++;
            }
            if (gracz2 == 'c') {
                wynikC++;
                gryC++;
            }
            if (gracz2 == 'd') {
                wynikD++;
                gryD++;
            }

            if (gracz1 == 'a') {
                gryA++;
                przegraneA++;
            }
            if (gracz1 == 'b') {
                gryB++;
                przegraneB++;
            }
            if (gracz1 == 'c') {
                gryC++;
                przegraneC++;
            }
            if (gracz1 == 'd') {
                gryD++;
                przegraneD++;
            }
        }
        if ((wybor1 == wybor2) && (sila1 == sila2)) {
            if (gracz1 == 'a') {
                gryA++;
                remisA++;
            }
            if (gracz1 == 'b') {
                gryB++;
                remisB++;
            }
            if (gracz1 == 'c') {
                gryC++;
                remisC++;
            }
            if (gracz1 == 'd') {
                gryD++;
                remisD++;
            }

            if (gracz2 == 'a') {
                gryA++;
                remisA++;
            }
            if (gracz2 == 'b') {
                gryB++;
                remisB++;
            }
            if (gracz2 == 'c') {
                gryC++;
                remisC++;
            }
            if (gracz2 == 'd') {
                gryD++;
                remisD++;
            }
        }



    }
    //PROCENT

    double pwA = (wynikA / gryA) * 100, pwB = (wynikB / gryB) * 100, pwC = (wynikC / gryC) * 100, pwD =
            (wynikD / gryD) * 100;

    double ppA = (przegraneA / gryA) * 100, ppB = (przegraneB / gryB) * 100, ppC = (przegraneC / gryC) * 100,
            ppD = (przegraneD / gryD) * 100;

    double prA = (remisA / gryA) * 100, prB = (remisB / gryB) * 100, prC = (remisC / gryC) * 100, prD =
            (remisD / gryD) * 100;



    //graczA
    if (gryA != 0 && wynikA != 0 && przegraneA != 0 && remisA != 0) {
        cout << "gracz a" << endl << "    " << "wygrane: " << pwA << "%" << endl << "    " << "remisy: " << prA
             << "%"  << endl << "    "<<  "przegrane: " << ppA << "%";

    }
    if (gryA != 0 && wynikA != 0 && przegraneA != 0 && remisA == 0) {
        cout << "gracz a" << endl << "    " << "wygrane: " << pwA << "%" << endl << "    " << "przegrane: " << ppA
             << "%";

    }
    if (gryA != 0 && wynikA != 0 && przegraneA == 0 && remisA != 0) {
        cout << "gracz a" << endl << "    " << "wygrane: " << pwA << "%" << endl << "    "<< "remisy: " << prA << "%";

    }
    if (gryA != 0 && wynikA != 0 && przegraneA == 0 && remisA == 0) {
        cout << "gracz a" << endl << "    " << "wygrane: " << pwA << "%";

    }
    if (gryA != 0 && wynikA == 0 && przegraneA != 0 && remisA != 0) {
        cout << "gracz a" << endl << "    " << "remisy: " << prA
             << "%"
             << endl << "    "<< "przegrane: " << ppA << "%";

    }
    if (gryA != 0 && wynikA == 0 && przegraneA != 0 && remisA == 0) {
        cout << "gracz a" << endl << "    " << "przegrane: " << ppA << "%";

    }

    if (gryA != 0 && wynikA == 0 && przegraneA == 0 && remisA != 0 ) {
        cout << "gracz a" << endl << "    " <<  "remisy: " << prA << "%";

    }
    if ((gryC !=0 || gryD !=0 || gryB!=0) && gryA !=0) cout << endl << endl;
    //graczB
    if (gryB != 0 && wynikB != 0 && przegraneB != 0 && remisB != 0) {
        cout << "gracz b" << endl << "    " << "wygrane: " << pwB << "%" << endl << "    " << "remisy: " << prB
             << "%" << endl << "    " << "przegrane: " << ppB << "%";

    }
    if (gryB != 0 && wynikB != 0 && przegraneB != 0 && remisB == 0) {
        cout << "gracz b" << endl << "    " << "wygrane: " << pwB << "%" << endl << "    " << "przegrane: " << ppB
             << "%";

    }
    if (gryB != 0 && wynikB != 0 && przegraneB == 0 && remisB != 0) {
        cout << "gracz b" << endl << "    " << "wygrane: " << pwB << "%" << endl << "    "<< "remisy: " << prB << "%";

    }
    if (gryB != 0 && wynikB != 0 && przegraneB == 0 && remisB == 0) {
        cout << "gracz b" << endl << "    " << "wygrane: " << pwB << "%";

    }
    if (gryB != 0 && wynikB == 0 && przegraneB != 0 && remisB != 0) {
        cout << "gracz b" << endl << "    " << "remisy: " << prB
             << "%" << endl << "    " << "przegrane: " << ppB << "%";

    }
    if (gryB != 0 && wynikB == 0 && przegraneB != 0 && remisB == 0) {
        cout << "gracz b" << endl << "    " << "przegrane: " << ppB << "%";
        }
    if (gryB != 0 && wynikB == 0 && przegraneB == 0 && remisB != 0 ) {
        cout << "gracz b" << endl << "    " << "remisy: " << prB << "%";

    }
    if ((gryC !=0 || gryD !=0) && gryB !=0) cout << endl << endl;

    //gracz C
    if (gryC != 0 && wynikC != 0 && przegraneC != 0 && remisC != 0) {
        cout << "gracz c" << endl << "    " << "wygrane: " << pwC << "%" << endl << "    " << "remisy: " << prC
             << "%" << endl << "    "<< "przegrane: " << ppC << "%";

    }
    if (gryC != 0 && wynikC != 0 && przegraneC != 0 && remisC == 0) {
        cout << "gracz c" << endl << "    " << "wygrane: " << pwC << "%" << endl << "    " << "przegrane: " << ppC
             << "%";

    }
    if (gryC != 0 && wynikC != 0 && przegraneC == 0 && remisC != 0) {
        cout << "gracz c" << endl << "    " << "wygrane: " << pwC << "%" << endl << "    " << "remisy: " << prC << "%";

    }
    if (gryC != 0 && wynikC != 0 && przegraneC == 0 && remisC == 0) {
        cout << "gracz c" << endl << "    " << "wygrane: " << pwC << "%";
    }
    if (gryC != 0 && wynikC == 0 && przegraneC != 0 && remisC != 0) {
        cout << "gracz c" << endl << "    " << "remisy: " << prC
             << "%" << endl << "    " << "przegrane: " << ppC << "%";

    }
    if (gryC != 0 && wynikC == 0 && przegraneC != 0 && remisC == 0) {
        cout << "gracz c" << endl << "    " << "przegrane: " << ppC << "%";
        }
    if (gryC != 0 && wynikC == 0 && przegraneC == 0 && remisC != 0 ) {
        cout << "gracz c" << endl << "    " << "remisy: " << prC << "%";

    }
    if (gryD !=0 && gryC !=0) cout  << endl << endl;
    //graczD
    if (gryD != 0 && wynikD != 0 && przegraneD != 0 && remisD != 0) {
        cout << "gracz d" << endl << "    " << "wygrane: " << pwD << "%" << endl << "    " << "remisy: " << prD
             << "%" << endl << "    " << "przegrane: " << ppD << "%";
    }
    if (gryD != 0 && wynikD != 0 && przegraneD != 0 && remisD == 0) {
        cout << "gracz d" << endl << "    " << "wygrane: " << pwD << "%" << endl << "    " << "przegrane: " << ppD
             << "%";
    }
    if (gryD != 0 && wynikD != 0 && przegraneD == 0 && remisD != 0) {
        cout << "gracz d" << endl << "    " << "wygrane: " << pwD << "%" << endl << "    " << "remisy: " << prD << "%";

    }
    if (gryD != 0 && wynikD != 0 && przegraneD == 0 && remisD == 0) {
        cout << "gracz d" << endl << "    " << "wygrane: " << pwD << "%";
    }
    if (gryD != 0 && wynikD == 0 && przegraneD != 0 && remisD != 0) {
        cout << "gracz d" << endl << "    " << "remisy: " << prD
             << "%" << endl << "    " << "przegrane: " << ppD << "%";
    }
    if (gryD != 0 && wynikD == 0 && przegraneD != 0 && remisD == 0) {
        cout << "gracz d" << endl << "    " << "przegrane: " << ppD << "%";  }
    if (gryD != 0 && wynikD == 0 && przegraneD == 0 && remisD != 0 ) {
        cout << "gracz d" << endl << "    " << "remisy: " << prD << "%";
    }
    return 0;
}
