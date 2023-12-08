#include <iostream>

using namespace std;

#define CLEAR system("clear");

 string stickman[6]= {
    "(+_+)\n",
    "/ | \n",
    "/\n",
    "  | \n",
    " * *\n",
    "|   |\n"
    
  }; //descobrir como usar isso no meio da animacao enquanto decresce.


int main(){
  
  //char ttt[] Desenvolver o jogo do TIC TOC TAE depois, Jogo da velha usando 3x3 array;
  string topic="", word="figado-de-galinha";
  char char_letter;
  int word_sz=0, it=0;
  bool check=1;
 
  cout << "-----JOGO DA FORCA-----\n\n";
  cout << "Defina o tema e a palavra.\n";
  cout << "Tema comida: ";
  //cin >> topic;
  cout << "\nPalavra: ";
  cin >> word;
  //CLEAR
  
  //String length calc
  for(; it<sizeof(word) || check==true; it++){
      if(word[it]=='\0'){
        word_sz+=it;
        check=0;
        break;
      }
  }
  
  char* word_overwrite = (char*) malloc(word_sz);
  
  for(int letters=0; letters<word_sz ; letters++){
      word_overwrite[letters] = (word[letters]=='-') ? '-' : '_';
  }
  
  it=0;
  int lt=0, score=0;
  int life=6;
  bool gameover=0, game=1;
  char* word_show = (char*) malloc(word_sz);
  
  system("stty cbreak");
  do{
    
      gameover=false;
      
      CLEAR // Revisar sobreposicao de caracter word_show
      cout << "Score: " << score << "          Remain life: " << life << "\n\nTries: " << word_show  << "\n\n" << "\n\n\n\n\n\n\n\n" << word_overwrite << "\n";
      
      //Compara lt com word para a condicao de vitoria
      if(lt==word_sz){
        cout << "VOCE VENCEU O JOGO!\n";
        break;
      }
      
      if(life==0){
        cout << "VOCE PERDEU BURRAL!\n";
        break;
      }
      
      cin >> char_letter;
 
      for(int i=0; i<word_sz; i++) //Verifica cada letra 16 vezes e substitui a forca.
        {
          
          if(char_letter==word[i] && word_overwrite[i]!='-' && char_letter!=word_overwrite[i]){
            word_overwrite[i] = char_letter;
            score++;
            lt++;
            gameover=true;
          }
          //CondicaodeWIN verifica se a forca ja esta completa e retorna lt++;
          if(lt!=word_sz && word_overwrite == word){
            lt++;
          }
          
        }
      
      if(!gameover){
          word_show[it++] = char_letter;
        --life;
      }
      
  }while(true);

  system("stty -cbreak");
  
  return 0;
}