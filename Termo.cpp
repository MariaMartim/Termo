#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);

string lista[]={"coisa", "prato", "ratos",
                "casos", "trave", "teste",
                "gatos", "tatus", "pelos",
                "lisos", "casas", "gatas", 
                "falar", "beber", "bebes", 
                "pular", "livro", "filme", 
                "corpo", "sonho", "olhos", 
                "nariz", "doces", "rosas", 
                "juizo", "exato", "ponte", 
                "canto", "norte", "zebra", 
                "sapos", "troca", "lixos", 
                "lutar", "lutas", "outro", 
                "grilo", "pouco", "muito", 
                "vento", "peixe", "tigre", 
                "cabra", "cobra", "cores", 
                "taxas", "coxas", "tente", 
                "fixos", "deixa", "minha", 
                "galos", "sacos", "balas", 
                "lindo", "linda", "longa", 
                "longo", "louca", "louco", 
                "pelos", "junto", "feito", 
                "quero", "texto", "peito"};

string minusculo(string palpite){
    for (int i=0; i<palpite.length(); i++){
        palpite[i]=tolower(palpite[i]);
    }
    return palpite;
}

bool testarposicao(char letra, string palpite){
    for (int i=0; i<palpite.length(); i++){
        if (letra==palpite[i]){
            return true;
        }
    }
    return false;
}

string posicoes(string palavra, string palpite){
    for (int i=0; i<palavra.length(); i++){
        if (palavra[i]==palpite[i]){
            palavra[i]=palpite[i];
            SetConsoleTextAttribute(cor, 2);
            cout<<palpite[i]<<" ";
        }
        else {
            if (testarposicao(palavra[i], palpite)){
                SetConsoleTextAttribute(cor, 14);
                cout<<palpite[i]<<" ";
            }
            else {
                SetConsoleTextAttribute(cor, 4);
                cout<<palpite[i]<<" ";
            }
        }
         
    }

    SetConsoleTextAttribute(cor, 7);
    return palpite;
    
}

bool palavracerta(string palavra, string palpite){
    if (palavra==palpite){
        return true;
    }
    return false;
}



int main(){
    int tent_termo=0, tent_dueto=0, tent_trieto=0, tent_quarteto=0;
    string palpite;
    int opcao;
    int index;
    string palavra;
    string dueto1, dueto2;
    string trieto1, trieto2, trieto3;
    string quarteto1, quarteto2, quarteto3, quarteto4;
    srand(time(NULL));

    //laço de repetiçao para menu do jogo

    cout<<"   "<<"JOGO  TERMO"<<"   "<<endl;
    cout<<"   "<<"----------"<<"   "<<endl;
    cout<<"      "<<"MODOS"<<"   "<<endl; 
    cout<<"   "<<"----------"<<"   "<<endl;
    do{
    cout<<">1-TERMO"<<endl;
    cout<<">2-DUETO"<<endl;
    cout<<">3-TRIETO"<<endl;
    cout<<">4-QUARTETO"<<endl;
    cin>>opcao;
    }while(opcao<1 || opcao>4);
    
    switch(opcao){
        
        case 1: //TERMO
            //  randomizar dentro do switch
            index=rand()%63;
            palavra=lista[index];
            for (int i=0; i<palavra.length(); i++){ //mostrando a palavra do termo para testar
            cout<<palavra[i];
            }
            cout<<endl;

            for (int i=0; i<palavra.length(); i++){
            cout<<"_ ";
            }
            cout<<endl;

            while (tent_termo<6){
                cout<<endl<<"tentativas: "<<tent_termo<<"/6"<<endl;

            do{
            cout<<"Digite seu palpite: ";
            cin>>palpite;
            }while(palpite.length()!=5);

            palpite=minusculo(palpite);
            posicoes(palavra, palpite);

            if (palavra==palpite){
                cout<<endl<<"Parabens, voce acertou a palavra!"<<endl;
                break;
            }
            else tent_termo++;
            }
            if (tent_termo==6){
                cout<<endl<<"Voce perdeu!"<<endl;
                cout<<"A palavra era: "<<palavra<<endl;
            }
            break;
        
        
        
        
        case 2: //DUETO
            int quant=0;
            index=rand()%63;
            dueto1=lista[index]; //randomizar a primeira palavra
            index=rand()%63;
            dueto2=lista[index]; //randomizar a segunda palavra

            for (int i=0; i<palavra.length(); i++){ //mostrando a palavra do termo para testar
            cout<<dueto1[i];
            }
            cout<<"     ";
            for (int i=0; i<palavra.length(); i++){ //mostrando a palavra do termo para testar
            cout<<dueto2[i];
            }
        
            while(quant<2){ //mostrar os espaços para as palavras
                for(int i=0; i<dueto1.length(); i++){
                    cout<<"_ ";
                }
                cout<<"     ";
                quant++;
            }
            while (tent_dueto<7){ //contagem de tentativas
                cout<<endl<<"tentativas: "<<tent_dueto<<"/7"<<endl;
            
            do{
            cout<<"Digite seu palpite: ";
            cin>>palpite;
            }while(palpite.length()!=5); //pedir tentativa ate a palavra ter 5 letras

            palpite=minusculo(palpite);
            posicoes(dueto1, palpite);
            palavracerta(dueto1, palpite);
            cout<<"     ";
            posicoes(dueto2, palpite);
            palavracerta(dueto2, palpite);

            if (palavracerta(dueto1, palpite) && palavracerta(dueto2, palpite)){
                cout<<endl<<"Parabens, voce acertou as palavras!"<<endl;
                break;
            }
            else tent_dueto++;
            
            if (tent_dueto==7){
                cout<<endl<<"Voce perdeu!"<<endl;
                cout<<"A palavras eram: "<<dueto1<<" e "<<dueto2<<endl;
            }
            
            }
        
        }

}
