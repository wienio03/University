#include <iostream>
using namespace std;
// VARIABLES
unsigned int sessions;
int elementIndex, length, invLength, shiftLength, switchLength, shiftpos, sortLength;
char operation;
// MAIN
int main() {
    cin >> sessions;
    int i = 0;
    while (i < sessions) {
        cin >> length;
        int tab[length];
        int j = 0;
        while (j < length) {
            cin >> tab[j];
            j++;
        }
        j = 0;
        while (j < length) {
            cout << tab[j] << " ";
            j++;
        }

        cout << endl;
        do {
            cin >> operation;

            //INV
            if(operation=='R'){
                cin >> elementIndex >> invLength;
                int invFrag;
                if (invLength>0)invFrag=length/invLength;
                else invFrag=0;
                int b = 0;
                while (b < invFrag && invFrag!=0) {
                    while(elementIndex<0)elementIndex=length-(-elementIndex);
                    if (elementIndex != length) elementIndex = elementIndex % length;
                    else elementIndex = 0;
                    int flIndex = elementIndex + invLength - 1;
                    if (flIndex<0) flIndex=length-(-flIndex);
                    if (flIndex != length) flIndex = flIndex % length;
                    else flIndex = 0;
                    int k = elementIndex;
                    int n = flIndex;
                    int m = 0;
                    while (m < (invLength / 2)) {
                        while (n < 0) n = length - (-n);
                        while (k < 0) k = length - (-k);
                        if (k != length) k = k % length;
                        else k = 0;
                        if (n != length) n = n % length;
                        else n = 0;
                        swap(tab[k], tab[n]);
                        k++;
                        n--;
                        m++;
                        if (n < 0) n = length - (-n);
                    }
                    b++;
                    elementIndex = elementIndex + invLength;

                }
            }
            if(operation=='M')
            {
                cin >> elementIndex >> shiftLength >> shiftpos;
                if(shiftLength>length)shiftLength=length;
                if(shiftpos>=shiftLength && shiftLength!=0)shiftpos=shiftpos%shiftLength;
                if(shiftpos<=-shiftLength && shiftLength!=0)shiftpos=-((-shiftpos)%shiftLength);
                int z=shiftpos;
                if (shiftpos > 0) {
                    int LdSL, c=0;
                    if(shiftLength>0)LdSL=length/shiftLength;
                    else LdSL=0;
                    while (c <= LdSL && LdSL!=0) {
                        shiftpos=z;
                        while (elementIndex < 0) elementIndex = length - (-elementIndex);
                        if (elementIndex != length) elementIndex = elementIndex % length;
                        else elementIndex = 0;
                        int slIndex = elementIndex + shiftLength - 1;
                        if (slIndex != length) slIndex = slIndex % length;
                        else slIndex = 0;
                        int x = elementIndex;
                        int y = slIndex;
                        while (shiftpos > 0) {
                            int temp = tab[y];
                            int g = y;
                            int u = y - 1;
                            while (g != x) {
                                if (g < 0)g = length - (-g);
                                if (u < 0)u = length - (-u);
                                if (g >= length) tab[g]=tab[g-length];
                                if (u >= length)u = 0+(-(length-u));
                                if (g >= length)g = 0+(-(length-g));
                                tab[g] = tab[u];
                                g--;
                                u--;
                                if (g < 0)g = length - (-g);
                                if (u < 0)u = length - (-u);
                            }
                            tab[x] = temp;
                            shiftpos--;
                        }
                        c++;
                        if(c==LdSL&&(length%shiftLength==0)){
                            c=c+1;
                        }
                        if(c==LdSL){
                            shiftLength=length%shiftLength;
                            elementIndex=slIndex+1;
                        }
                        else elementIndex = elementIndex + shiftLength;
                    }
                }

                if (z < 0) {
                    shiftpos=z;
                    int LdSL;
                    if(shiftLength>0)LdSL=length/shiftLength;
                    else LdSL=0;
                    int v = 0;
                    while (v <= LdSL && LdSL!=0) {shiftpos=z;
                        while (elementIndex < 0) elementIndex = length - (-elementIndex);
                        if (elementIndex != length) elementIndex = elementIndex % length;
                        else elementIndex = 0;
                        int slIndex = elementIndex + shiftLength - 1;
                        if (slIndex != length) slIndex = slIndex % length;
                        else slIndex = 0;
                        int x = elementIndex;
                        int y = slIndex;
                        while (shiftpos < 0) {
                            int temp = tab[x];
                            int g = x;
                            int u = x+1;
                            while (g != y) {
                                if (g >= length) tab[g]=tab[g-length];
                                if (u >= length)u = 0+(-(length-u));
                                if (g >= length)g = 0+(-(length-g));
                                tab[g]=tab[u];
                                g++;
                                if (g >= length)g = 0+(-(length-g));
                                u++;
                            }
                            tab[y] = temp;
                            shiftpos++;
                        }
                        v++;
                        if(v==LdSL&&(length%shiftLength==0)){
                            v=v+1;
                        }
                        if(v==LdSL){
                            shiftLength=length%shiftLength;
                            elementIndex=slIndex+1;
                        }
                        else elementIndex = elementIndex + shiftLength;
                    }
                }
            }
            if (operation=='C'){
                cin >> elementIndex >> switchLength;
                int r=0;
                int swFragments;
                if(switchLength>0) swFragments=length/switchLength;
                else swFragments=0;
                while (r<(swFragments/2) && swFragments!=0) {
                    while (elementIndex<0)elementIndex=0+(length-(-elementIndex));
                    while (elementIndex>=length)elementIndex=0+(-(length-elementIndex));
                    if (elementIndex != length) elementIndex = elementIndex % length;
                    else elementIndex = 0;
                    int q = elementIndex;
                    int e = 0;
                    int w = q + switchLength;
                    while (e < switchLength) {
                        if (q != length) q = q % length;
                        else q = 0;
                        if (w != length) w = w % length;
                        else w = 0;
                        swap(tab[q], tab[w]);
                        q++;
                        w++;
                        e++;
                    }
                    r++;
                    elementIndex = elementIndex + 2 * switchLength;
                }
            }
            if(operation=='S'){
                cin >> elementIndex >> sortLength;
                if(sortLength>length)sortLength=length;
                if(sortLength<(-length))sortLength=-length;
                int tempLH = sortLength;
                int LdSWL;
                if(sortLength!=0) LdSWL = length / sortLength;
                else LdSWL=0;
                if (sortLength > 0 && LdSWL!=0) {
                    int c = 0;
                    while (c <= LdSWL) {
                        int d = 0, f = 0;
                        while (d < sortLength - 1) {
                            int x = elementIndex;
                            int y = elementIndex + 1;
                            while (f < sortLength - 1) {
                                while (x >= length)x = 0 + (-(length - x));
                                while (x < 0)x = 0 + (length - (-x));
                                if (x != length)x = x % length;
                                while (y >= length) y = 0 + (-(length - y));
                                while (y < 0)y = 0 + (length - (-y));
                                if (y != length)y = y % length;
                                if (tab[x] > tab[y])swap(tab[x], tab[y]);
                                x++;
                                y++;
                                f++;
                            }
                            d++;
                            f = 0;
                        }
                        c++;
                        if (c == LdSWL && (length % sortLength == 0)) {
                            c = c + 1;
                        }

                        if (c == LdSWL) {
                            sortLength = length % sortLength;
                            elementIndex = elementIndex + tempLH;
                        }
                        else  elementIndex = elementIndex + sortLength;
                    }
                }
                int tempHL = (-sortLength);
                if (sortLength < 0 && LdSWL!=0) {
                    int c = 0;
                    while (c >= LdSWL ) {
                        int d = 0, f = 0;
                        while (d < tempHL -1 ) {
                            int x = elementIndex;
                            int y = elementIndex + 1;
                            while (f < tempHL -1 ) {
                                while(x >= length)x = 0 + (-(length - x));
                                while (x < 0)x = 0 + (length - (-x));
                                if (x != length)x = x % length;
                                while (y >= length) y = 0 + (-(length - y));
                                while (y < 0)y = 0 + (length - (-y));
                                if (y != length)y = y % length;
                                if (tab[x] < tab[y])swap(tab[x], tab[y]);
                                x++;
                                y++;
                                f++;
                            }
                            d++;
                            f = 0;
                        }
                        c--;
                        if (c == LdSWL && (length % tempHL == 0)) {
                            c = c - 1;
                        }
                        if (c == LdSWL) {
                            elementIndex = elementIndex + tempHL;
                            tempHL=length%(-(sortLength));
                        }
                        else elementIndex = elementIndex + tempHL;
                    }
                }
            }
        }
        while(operation!='F');
        j = 0;
        while (j < length) {
            cout << tab[j] << " ";
            j++;
        }
        i++;
        if(i<sessions)cout<<endl;
    }
    return 0;
}
