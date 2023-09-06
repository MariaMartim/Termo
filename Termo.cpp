#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>

// Maria Eduarda Alves Martim

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

string minusculo(string palpite){ //transformar o palpite em minusculo
    for (int i=0; i<palpite.length(); i++){
        palpite[i]=tolower(palpite[i]);
    }
    return palpite;
}

bool testarposicao( string palpite, char letra){ //testar se a letra esta na palavra mas na posição errada
    for (int i=0; i<palpite.length(); i++){
        if (palpite[i]==letra ){
            return true;
        }
    }
    return false;
}

string posicoes(string palavra, string palpite){ // teste das posições das letras
    for (int i=0; i<palavra.length(); i++){
        if (palavra[i]==palpite[i]){
            SetConsoleTextAttribute(cor, 2); //verde
            cout<<palpite[i]<<" ";
        }
        else {
            if (testarposicao(palavra, palpite[i])==true){ //testar se a letra esta na palavra
                SetConsoleTextAttribute(cor, 14); //amarelo
                cout<<palpite[i]<<" ";
            }
        
            else {
                SetConsoleTextAttribute(cor, 4); //vermelho
                cout<<palpite[i]<<" ";
            }
            
        }
         
    }

    SetConsoleTextAttribute(cor, 7);
    return palpite;
    
}

bool palavracerta(string palavra, string palpite){ //checagem de palavra correta
    if (palavra==palpite){
        return true;
    }
    else return false;
}




int main(){
    bool t1=false, t2=false, t3=false, t4=false;
    int tent_termo=0, tent_dueto=0, tent_trieto=0, tent_quarteto=0;
    string palpite;
    int opcao;
    int igual=0;
    int index;
    int quant, quantidade;
    string palavra;
    string dueto[2];
    string trieto[3];
    string quarteto[4];

    srand(time(NULL));

    
    do{ //menu do jogo
    cout<<"   "<<"JOGO  TERMO"<<"   "<<endl;
    cout<<"   "<<"----------"<<"   "<<endl;
    cout<<"      "<<"MODOS"<<"   "<<endl; 
    cout<<"   "<<"----------"<<"   "<<endl;
    do{ //opcoes
    cout<<">1-TERMO"<<endl;
    cout<<">2-DUETO"<<endl;
    cout<<">3-TRIETO"<<endl;
    cout<<">4-QUARTETO"<<endl;
    cout<<">0-SAIR"<<endl<<endl;
    cin>>opcao;
    }while(opcao<0 || opcao>4);
    system("cls");
    
    switch(opcao){


        
        case 1: //TERMO
            //randomizar dentro do switch
            tent_termo=0;
            index=rand()%63;
            palavra=lista[index];

            for (int i=0; i<palavra.length(); i++){ //mostrando os espaços da palavra
            cout<<"_ ";
            }
            cout<<endl;

            while (tent_termo<6){ //pedir tentativas ate acertar a palavra ou ate acabar as tentativas
                cout<<endl<<"tentativas: "<<tent_termo+1<<"/6"<<endl;

            do{
            cout<<"Digite seu palpite: ";
            cin>>palpite;
            }while(palpite.length()!=5); //perdir palpite ate que a palavra tenha 5 letras

            palpite=minusculo(palpite); //transformar em minusculo
            posicoes(palavra, palpite);

            if (palpite==palavra){
                cout<<endl<<"Parabens, voce acertou a palavra!"<<endl<<endl; // caso acerte a palavra
                break;
            }
            else tent_termo++;
            }
            if (tent_termo==6){
                cout<<endl<<"Voce perdeu!"<<endl; //caso erre a palavra ate acabar as tentativas
                cout<<"A palavra era: "<<palavra<<endl<<endl;
            }
            break;
        
        
        
        
        case 2: //DUETO
            t1=false;
            t2=false;
            tent_dueto=0;
            quant=0;
            do{ //randomizar as palavras sem repetição
                index=rand()%63;
                dueto[quant]=lista[index];
                for (int j=0; j<quant; j++){
                    if (dueto[quant]==dueto[j]){
                        igual=1;
                    }
                }
                if (igual==0){
                    quant++;
                }
            }while(quant<2);

            quant=0;       
            while(quant<2){ //mostrar os espaços para as palavras
                for(int i=0; i<dueto[0].length(); i++){
                    cout<<"_ ";
                }
                cout<<"     ";
                quant++;
            }
            cout<<endl;
            

            do{
                
            do{
                cout<<endl<<"tentativas: "<<tent_dueto+1<<"/7"<<endl;
                cout<<endl<<"Digite seu palpite: ";
                cin>>palpite;
            }while(palpite.length()!=5); //pedir tentativa ate a palavra ter 5 letras
            palpite=minusculo(palpite); //transformar o palpite em minusculo

             
            if(t1 == false){
            posicoes(dueto[0], palpite); //mostrar as posicoes do palpite na palavra
            }else{
                for (int i=0; i<dueto[0].length(); i++){ //caso acerte, mostrar a palavra certa em toda tentativa em verde
                SetConsoleTextAttribute(cor, 2);
                cout<<dueto[0][i]<<" ";
                SetConsoleTextAttribute(cor, 7);
                }
            }
            cout<<"     ";
            
            if (t2==false){
            posicoes(dueto[1], palpite); 
            }else{
                for (int i=0; i<dueto[1].length(); i++){
                SetConsoleTextAttribute(cor, 2);
                cout<<dueto[1][i]<<" ";
                SetConsoleTextAttribute(cor, 7);
                }
            }

            if (!t1){
                t1=palavracerta(dueto[0], palpite); //parar quando acertar a palavra
            }

            if (!t2){
                t2=palavracerta(dueto[1], palpite); 
            }

            //adicionar tentativas
            tent_dueto++;

            if (t2 and t1){ //caso acerte as duas palavras
                cout<<endl<<"Parabens, voce acertou as palavras! "<<endl<<endl;
                break;
            }
            
            
            }while (tent_dueto<7); //pedir tentativa ate acertar a palavra ou ate acabar as tentativas
            
            
            if (tent_dueto==7){
                cout<<endl<<"Voce perdeu!"<<endl;
                cout<<"A palavras eram: "<<dueto[0]<<" e "<<dueto[1]<<endl<<endl;
                
            }
            break;


            

        case 3: //TRIETO 
            t1=false;
            t2=false;
            t3=false;
            tent_trieto=0;
            quantidade=0;
            do{ //randomizar as palavras sem repetição
                index=rand()%63;
                trieto[quantidade]=lista[index];
                for (int j=0; j<quantidade; j++){
                    if (trieto[quantidade]==trieto[j]){
                        igual=1;
                    }
                }
                if (igual==0){
                    quantidade++;
                }
            }while(quantidade<3);

            quantidade=0;
            while(quantidade<3){ //mostrar os espaços para as palavras
                for(int i=0; i<trieto[0].length(); i++){
                    cout<<" _ ";
                }
                cout<<"     ";
                quantidade++;
            }
            cout<<endl;
             
            do{
                
            do{
                cout<<endl<<"tentativas: "<<tent_trieto+1<<"/8"<<endl;
                cout<<endl<<"Digite seu palpite: ";
                cin>>palpite;
            }while(palpite.length()!=5); //pedir tentativa ate a palavra ter 5 letras
            palpite=minusculo(palpite); //transformar o palpite em minusculo

            if (t1 == false){
            posicoes(trieto[0], palpite); //mostrar as posicoes do palpite na palavra
            }else{
                for (int i=0; i<trieto[0].length(); i++){
                SetConsoleTextAttribute(cor, 2);
                cout<<trieto[0][i]<<" ";
                SetConsoleTextAttribute(cor, 7);
                }
            }

            cout<<"     ";

            if (t2==false){
            posicoes(trieto[1], palpite); //mostrar as posicoes do palpite na palavra
            }else{
                for (int i=0; i<trieto[1].length(); i++){
                SetConsoleTextAttribute(cor, 2);
                cout<<trieto[1][i]<<" ";
                SetConsoleTextAttribute(cor, 7);
                }
            }

            cout<<"     ";

            if(t3==false){
            posicoes(trieto[2], palpite);//mostrar as posicoes do palpite na palavra
            }else{
                for (int i=0; i<trieto[2].length(); i++){
                SetConsoleTextAttribute(cor, 2);
                cout<<trieto[2][i]<<" ";
                SetConsoleTextAttribute(cor, 7);
                }
            }

            if (!t1){
                t1=palavracerta(trieto[0], palpite); //testar se o palpite esta certo
            }

            if (!t2){
                t2=palavracerta(trieto[1], palpite); //testar se o palpite esta certo
            }

            if (!t3){
                t3=palavracerta(trieto[2], palpite); //testar se o palpite esta certo
            }

            //adicionar tentativas
            tent_trieto++;

            if (t1 and t2 and t3){
                cout<<endl<<"Parabens, voce acertou as palavras! "<<endl<<endl;
                break;
            }
            
            
            }while (tent_trieto<8); //pedir tentativa ate acertar a palavra ou ate acabar as tentativas
            
            
            if (tent_trieto==8){
                cout<<endl<<"Voce perdeu!"<<endl;
                cout<<"A palavras eram: "<<trieto[0]<<", "<<trieto[1]<<" e "<<trieto[2]<<endl<<endl;
                
            }
            break;



        case 4: //QUARTETO
            t1=false;
            t2=false;
            t3=false;
            t4=false;
            tent_quarteto=0;
            quantidade=0;
            do{ //randomizar as palavras sem repetição
                index=rand()%63;
                quarteto[quantidade]=lista[index];
                for (int j=0; j<quantidade; j++){
                    if (quarteto[quantidade]==quarteto[j]){
                        igual=1;
                    }
                }
                if (igual==0){
                    quantidade++;
                }
            }while(quantidade<4);

            quantidade=0;
            while(quantidade<3){ //mostrar os espaços para as palavras
                for(int i=0; i<quarteto[0].length(); i++){
                    cout<<" _ ";
                }
                cout<<"     ";
                quantidade++;
            }
            cout<<endl;
             
            
            do{
                
            do{
                cout<<endl<<"tentativas: "<<tent_quarteto+1<<"/9"<<endl;
                cout<<endl<<"Digite seu palpite: ";
                cin>>palpite;
            }while(palpite.length()!=5); //pedir tentativa ate a palavra ter 5 letras
            palpite=minusculo(palpite); //transformar o palpite em minusculo

            if(t1==false){
            posicoes(quarteto[0], palpite);//mostrar as posicoes do palpite na palavra
            }else{
                for (int i=0; i<quarteto[0].length(); i++){
                SetConsoleTextAttribute(cor,2);
                cout<<quarteto[0][i]<<" ";	
                SetConsoleTextAttribute(cor,7);
                }
            } 

            cout<<"     ";

            if (t2==false){
            posicoes(quarteto[1], palpite); 
            }else{
                for (int i=0; i<quarteto[1].length(); i++){
                SetConsoleTextAttribute(cor,2);
                cout<<quarteto[1][i]<<" ";	
                SetConsoleTextAttribute(cor,7);
                }
            }

            cout<<"     ";

            if(t3==false){
            posicoes(quarteto[2], palpite); 
            }else{
                for(int i=0; i<quarteto[2].length(); i++){
                SetConsoleTextAttribute(cor,2);
                cout<<quarteto[2][i]<<" ";
                SetConsoleTextAttribute(cor, 7);
                }       
            }

            cout<<"     ";

            if (t4==false){
            posicoes(quarteto[3], palpite); 
            }else{
                for(int i=0; i<quarteto[3].length(); i++){
                SetConsoleTextAttribute(cor,2);
                cout<<quarteto[3][i]<<" ";
                SetConsoleTextAttribute(cor, 7);
                }
            }

            if (!t1){
                t1=palavracerta(quarteto[0], palpite); //testar se o palpite esta certo
            }

            if (!t2){
                t2=palavracerta(quarteto[1], palpite); //testar se o palpite esta certo
            }

            if (!t3){
                t3=palavracerta(quarteto[2], palpite); //testar se o palpite esta certo
            }
            if (!t4){
                t4=palavracerta(quarteto[3], palpite); //testar se o palpite esta certo
            }

            //adicionar tentativas
            tent_quarteto++;

            if (t1 and t2 and t3 and t4){ //caso acerte todas as palavras
                cout<<endl<<"Parabens, voce acertou as palavras! "<<endl<<endl;
                break;
            }
            
            
            }while (tent_quarteto<9); //pedir tentativa ate acertar a palavra ou ate acabar as tentativas
            
            
            if (tent_quarteto==9){ //caso esgote as tentativas
                cout<<endl<<"Voce perdeu!"<<endl;
                cout<<"A palavras eram: "<<quarteto[0]<<", "<<quarteto[1]<<", "<<quarteto[2]<<" e "<<quarteto[3]<<endl<<endl;
                
            }
            break;
    
    }   



    cout << "Deseja continuar jogando?" << endl; //repetição do menu
	cout << ">1-SIM" << endl;
	cout << ">0-NAO" << endl;
	cin >> opcao;
    system("cls");

    }while(opcao!=0);
}
