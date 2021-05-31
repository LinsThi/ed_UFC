#include "bnum.h"

nodo::nodo(int x) {
    key = x;
    next = nullptr;
};

int sizeNumber(int n){
    int cont = 0;
    if(n == 0){
        return 1;
    }
    while(n != 0){
        cont++;
        n = n/10;
    }
    return cont;
}

void bnum::igualaNodo(nodo* num, nodo* bigN, bnum* resultado){
    int contNodoA = 0, contNodoB = 0;
    nodo* almiA; nodo* almiB;
    for(almiA = num; almiA->next != nullptr; almiA = almiA->next, contNodoA++);
    for(almiB = bigN; almiB->next != nullptr; almiB = almiB->next, contNodoB++);
    
    contNodoA++; contNodoB++;

    if(contNodoA > contNodoB){
        while(contNodoB < contNodoA){
            contNodoB++;
            nodo* No = new nodo(0, nullptr);
            almiB->next = No;
            almiB = almiB->next;
        }
    }else if(contNodoB > contNodoA){
        while(contNodoA < contNodoB){
            contNodoA++;
            nodo* No = new nodo(0, nullptr);
            almiA->next = No;
            almiA = almiA->next;
        }
    }

    nodo* NoAux = resultado->number;contNodoA--;
    while(contNodoA > 0){
        contNodoA--;
        nodo* No = new nodo(0, nullptr);
        NoAux->next = No;
        NoAux = NoAux->next;
    }
}

bnum::bnum(){

}

bnum::bnum(int x, int d) {
    this->d = d;
    int dAux=pow(10,d), aux = 0;
    number = new nodo(x%dAux, nullptr);
    nodo* No; x = x/dAux;
    while(x > 0){
        if(number->next == nullptr){
            aux = x%dAux;
            x = x/dAux;

            No = new nodo(aux, nullptr);
            number->next = No;
        }else{
            aux = x%dAux;
            x = x/dAux;

            nodo* H = new nodo(aux, nullptr);
            No->next = H;
            No = No->next;
        }
    }
}

bnum::bnum(string s, int d) {
    this->d = d; char aux[d] = "";nodo* No; int valor = 0;
    if(s.length() <= d){
        for(int x = 0; x < s.length(); x++){
            aux[x] = s[x];
        }
        valor = atoi(aux);
        number = new nodo(valor, nullptr);
    }else{
        number = new nodo(0, nullptr);
        for(int i = s.length(); i > 0; i-=d){
            if(number->next == nullptr){
                for(int x = i-d, z = 0; z < d; x++, z++){
                    aux[z] = s[x];
                }
                valor = atoi(aux);
                No = new nodo(0, nullptr);
                number->key = valor; number->next = No;
            }else{
                for(int x = i-d, z = 0; z < d; x++, z++){
                    aux[z] = s[x];
                }
                valor = atoi(aux);
                No->key = valor;
                if(i-d > 0){
                    nodo* H = new nodo(0,nullptr);
                    No->next = H; No = No->next;
                }else{
                    int cont = 0;
                    while(i >= 0){
                        i--; cont++;
                    }
                    cont--;
                    if(cont > 0){
                        for(int q = 0; q < d; q++){ //Reseta vetor.
                            aux[q] = 0;
                        }
                        for(int q = 0; q < cont ;q++){
                            aux[q] = s[q];
                        }
                        valor = atoi(aux);
                        No->key = valor;
                    }
                }
            }
            for(int q = 0; q < d; q++){ //Reseta vetor.
                aux[q] = 0;
            }
        }
    }
}

bnum::bnum(const bnum& b) {
    this->d = b.d; int i = 0;
    this->number = b.number;
    nodo* aux = b.number->next; nodo* No;
    for(int i = 0;aux != nullptr;aux = aux->next, i++){
        if(i == 0){
            No = new nodo(aux->key, nullptr);
            number->next = No;
        }else{
            nodo* H = new nodo(aux->key, nullptr);
            No->next = H;
            No = No->next;
        }
    }
}

bnum& bnum::operator=(const bnum& b) {
    this->d = b.d; int i = 0;
    this->number = b.number;
    nodo* aux = b.number->next; nodo* No;
    for(int i = 0;aux != nullptr;aux = aux->next, i++){
        if(i == 0){
            No = new nodo(aux->key, nullptr);
            number->next = No;
        }else{
            nodo* H = new nodo(aux->key, nullptr);
            No->next = H;
            No = No->next;
        }
    }
    return *this;
}


bnum& bnum::operator+(int x) {
    bnum* numero; numero = new bnum(x, d); 
    resultado = new bnum(0, d); 
    nodo* Aux = number; nodo* AuxResult = new nodo(0,nullptr); nodo* No;
    int vaiUm = 0, i = 0;
    
    igualaNodo(numero->number, number, resultado);

    while(numero->number != nullptr){
        if(numero->number->key + Aux->key + vaiUm > pow(10,d)-1){
            AuxResult->key = (numero->number->key + Aux->key + vaiUm)%(int)pow(10,d);
            vaiUm = (numero->number->key + Aux->key + vaiUm)/pow(10,d);
        }else{
            AuxResult->key = numero->number->key + Aux->key + vaiUm; vaiUm = 0;
        }

        if(i == 0){
            resultado->number->key = AuxResult->key;
            No = resultado->number->next;
            i++;
        }else{
            No->key = AuxResult->key;
            if(No->next!=nullptr){
                No = No->next;
            }
        }
        numero->number = numero->number->next; Aux = Aux->next;
    }
    if(vaiUm>0){
        nodo* F = new nodo(vaiUm, nullptr);
        No->next = F;
        No = No->next;
    }
    return *resultado;
}

bnum& bnum::operator+(const bnum& b) {
    bnum x = b; string refatora;
    bnum* numero; bnum* bigN;
    if(d < b.d){
        refatora = x.toStr();
        numero = new bnum(refatora,d);
        bigN = new bnum(*this);
    }else if(b.d < d){
        refatora = toStr();
        bigN = new bnum(refatora,d);
        numero = new bnum(b);
    }else{
        numero = new bnum(b);
        bigN = new bnum(*this);
    }

    resultado = new bnum(0, d); 
    nodo* Aux = bigN->number; nodo* AuxResult = new nodo(0,nullptr); nodo* No;
    int vaiUm = 0, i = 0;

    igualaNodo(numero->number, bigN->number, resultado);

    while(numero->number != nullptr){
        if(numero->number->key + Aux->key + vaiUm > pow(10,d)-1){
            AuxResult->key = (numero->number->key + Aux->key + vaiUm)%(int)pow(10,d);
            vaiUm = (numero->number->key + Aux->key + vaiUm)/pow(10,d);
        }else{
            AuxResult->key = numero->number->key + Aux->key + vaiUm; vaiUm = 0;
        }

        if(i == 0){
            resultado->number->key = AuxResult->key;
            No = resultado->number->next;
            i++;
        }else{
            No->key = AuxResult->key;
            if(No->next!=nullptr){
                No = No->next;
            }
        }
        numero->number = numero->number->next; Aux = Aux->next;
    }
    if(vaiUm>0){
        nodo* F = new nodo(vaiUm, nullptr);
        No->next = F;
        No = No->next;
    }
    return *resultado;
}

bnum& bnum::operator*(int x) {
    bnum* numero; numero = new bnum(x, d); 
    nodo* Aux; nodo* resto = new nodo(0,nullptr); nodo* No;
    int vaiUm = 0, contEscorrega = 0;
    bool fim = false; string final = "";

    int contNodoA=0, contNodoB=0;
    for(nodo* almiA = number; almiA->next != nullptr; almiA = almiA->next, contNodoA++);
    for(nodo* almiB = numero->number; almiB->next != nullptr; almiB = almiB->next, contNodoB++);
    if(contNodoB > contNodoA){
        nodo* s = numero->number;
        numero->number = number;
        Aux = s;
    }else{
        Aux = number;
    }
    bnum result(0,d); bnum soma(0,d);
    while(numero->number != nullptr){
        if(contEscorrega > 0){
            No = new nodo(0, nullptr);
            for(int x = 0; x < contEscorrega; x++){
                if(x == 0){
                    soma.number->key = 0;
                }else{
                    if(x != 1){
                        nodo* K = new nodo(0, nullptr);
                        No->next = K;
                        No = No->next;
                    }
                }
            }
        }

        for(;Aux != nullptr; Aux = Aux->next){
            if(Aux->key * numero->number->key + vaiUm > pow(10,d)-1){
                resto->key = (Aux->key * numero->number->key + vaiUm) % (int)pow(10,d);
                vaiUm = (Aux->key * numero->number->key + vaiUm)/pow(10,d);
            }else{
                resto->key = Aux->key * numero->number->key + vaiUm; 
                vaiUm = 0;
            }

            if(soma.number->next == nullptr){
                soma.number->key = resto->key;
                if(Aux->next == nullptr){
                    if(vaiUm>0){
                        No = new nodo(vaiUm, nullptr);
                        soma.number->next = No; vaiUm = 0;
                    }else{
                        fim = true;
                    }
                }else{
                    No = new nodo(0, nullptr);
                    soma.number->next = No;
                }
            }else{
                No->key = resto->key;
                if(Aux->next != nullptr){
                    nodo* H = new nodo(0, nullptr);
                    No->next = H;
                    No = No->next;
                }
            }
        }
        if(vaiUm > 0){
            nodo* H = new nodo(vaiUm, nullptr);
            No->next = H;
            No = No->next; vaiUm = 0;
        }
        if(!fim){
            contEscorrega++;
            result = result+soma;
        }else{
            final = soma.toStr();
        }
        numero->number = numero->number->next;
    }
    if(vaiUm > 0){
        nodo* H = new nodo(vaiUm, nullptr);
        No->next = H;
        No = No->next; vaiUm = 0;
    }
    if(fim){
        resultado = new bnum(final, d);
    }else{
        resultado = new bnum(result);
    }
    return *resultado;
}

bnum& bnum::operator*(const bnum& b){
    bnum x = b; string refatora;
    bnum* numero; bnum* bigN;
    if(d != b.d){
        refatora = x.toStr();
        numero = new bnum(refatora,d);
        bigN = new bnum(*this);
    }else{
        numero = new bnum(b);
        bigN = new bnum(*this);
    }

    nodo* Aux; nodo* resto = new nodo(0,nullptr); nodo* No;
    int vaiUm = 0, contEscorrega = 0;
    bool fim = false; string final = "";

    int contNodoA=0, contNodoB=0;
    for(nodo* almiA = bigN->number; almiA->next != nullptr; almiA = almiA->next, contNodoA++);
    for(nodo* almiB = numero->number; almiB->next != nullptr; almiB = almiB->next, contNodoB++);
    if(contNodoB > contNodoA){
        nodo* s = numero->number;
        numero->number = number;
        Aux = s;
    }else{
        Aux = bigN->number;
    }

    bnum result(0,d); bnum soma(0,d);
    while(numero->number != nullptr){
        if(contEscorrega > 0){
            No = new nodo(0, nullptr);
            for(int x = 0; x < contEscorrega; x++){
                if(x == 0){
                    soma.number->key = 0;
                }else{
                    if(x != 1){
                        nodo* K = new nodo(0, nullptr);
                        No->next = K;
                        No = No->next;
                    }
                }
            }
        }

        for(;Aux != nullptr; Aux = Aux->next){
            if(Aux->key * numero->number->key + vaiUm > pow(10,d)-1){
                
                resto->key = (Aux->key * numero->number->key + vaiUm) % (int)pow(10,d);
                vaiUm = (Aux->key * numero->number->key + vaiUm)/pow(10,d);
            }else{
                resto->key = Aux->key * numero->number->key + vaiUm; 
                vaiUm = 0;
            }

            if(soma.number->next == nullptr){
                soma.number->key = resto->key;
                if(Aux->next == nullptr){
                    if(vaiUm>0){
                        No = new nodo(vaiUm, nullptr);
                        soma.number->next = No; vaiUm = 0;
                    }else{
                        fim = true;
                    }
                }else{
                    No = new nodo(0, nullptr);
                    soma.number->next = No;
                }
            }else{
                No->key = resto->key;
                if(Aux->next != nullptr){
                    nodo* H = new nodo(0, nullptr);
                    No->next = H;
                    No = No->next;
                }
            }
        }
        if(vaiUm > 0){
            nodo* H = new nodo(vaiUm, nullptr);
            No->next = H;
            No = No->next; vaiUm = 0;
        }
        if(!fim){
            contEscorrega++;
            result = result+soma;
        }else{
            final = soma.toStr();
        }
        numero->number = numero->number->next;
    }
    if(vaiUm > 0){
        nodo* H = new nodo(vaiUm, nullptr);
        No->next = H;
        No = No->next; vaiUm = 0;
    }
    if(fim){
        resultado = new bnum(final, d);
    }else{
        resultado = new bnum(result);
    }
    return *resultado;
}

bool bnum::operator==(const bnum& b){
    string refatora = ""; bnum x(b); refatora = x.toStr();
    bnum numero (refatora, d); bnum bigN(*this);
    int contNodoA = 0, contNodoB = 0;
    for(nodo* almi = bigN.number; almi != nullptr; almi = almi->next){
        contNodoA++;
    }
    for(nodo* almi = numero.number; almi != nullptr; almi = almi->next){
        contNodoB++;
    }

    if(contNodoA == contNodoB){
        int cont = 0;
        nodo* almiB = numero.number;
        for(nodo* almi = bigN.number; almi != nullptr; almi = almi->next,  almiB = almiB->next){
            if(almi->key == almiB->key){
                cont++;
            }
        }
        if(cont == contNodoA){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

string bnum::toStr() {
    string resultado = "";
    nodo* almi; nodo* almiAux;

    for(almi = number; almi != nullptr; almi = almi->next);
    
    do{
        almiAux = number;
        while(1){
            if(almiAux->next != almi){
                almiAux = almiAux->next;
            }else{
                almi = almiAux;
                int tamanho = sizeNumber(almi->key);
                if(tamanho < d){
                    if(almi->next != nullptr){
                        while(tamanho < d){
                            resultado += "0";
                            tamanho++;
                        }
                    }
                    resultado += to_string(almi->key);
                }else{
                    resultado += to_string(almi->key);
                }
                break;
            }
        }
    }while(almiAux != number);

    return resultado;
}

bnum::~bnum() {

}