#include "app.h"

int main() {
    bnum n(2152, 5);
    bnum n2("1011121314151617", 5);
    bnum n3("1011121314151617", 2);
    //bnum n3(n2);
    //bnum n4("101112131415161718192021222324252627282930",2);
    /*if(n2==n3){
        cout << "São iguais" << endl;
    }else{
        cout << "São diferentes"<< endl;
    }*/
    //cout << (n=n2).toStr() << endl;
    //cout << n.toStr() << endl;
    //cout << n2.toStr() << endl;
    //cout << n3.toStr() << endl;
    //cout << 4.toStr() << endl;
    //cout << (n2+987654321).toStr() << endl;
    //cout << (n2+n4).toStr(); << endl;
    //cout << (n2*19000).toStr() << endl;
    //cout << (n*n2).toStr() << endl;
    bnum n5(10000,5); 
    app::factorial(n5);
    //app::frequencetable(n2);
 }
