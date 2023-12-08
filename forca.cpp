#include <iostream>

using namespace std;

#define CLEAR system("clear");

int main(){
  
  string topic="", word="";
  char char_letter;
  int word_sz=0, it=0;
  bool check=1;
 
  cout << "-----JOGO DA FORCA-----\n\n";
  cout << "Palavra: ";
  cin >> word;
  CLEAR
  
  //String length calc
  for(; it<sizeof(word) || check==true; it++){
      if(word[it]=='\0'){
        word_sz+=it;
        check=0;
        break;
      }
  }
  
  char* word_overwrite = (char*) malloc(word_sz);
  char* word_show = (char*) malloc(word_sz);
  
  for(int letters=0; letters<word_sz ; letters++){
      word_overwrite[letters] = (word[letters]=='-') ? '-' : '_';
  }
  
  it=0;
  int lt=0, score=0;
  int life=6;
  bool gameover=0, game=1;
  
  system("stty cbreak");
  do{
    
      CLEAR // Revisar sobreposicao de caracter word_show
      cout << "Score: " << score << "          Remain life: " << life << "\n\nTries: " << word_show  << "\n\n" << "\n\n\n\n\n\n\n\n" << word_overwrite << "\n";
      
      //Compara lt com word para a condicao de vitoria
      if(lt==word_sz){
        cout << "VOCE VENCEU O JOGO!\n";
        break;
      }
      
      if(life==0){
        cout << "VOCE PERDEU!\n";
        break;
      }
      
      cin >> char_letter;
 
      for(int i=0; i<word_sz; i++) 
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
      
      gameover=false;
      
  }while(true);
  system("stty -cbreak");
  
  return 0;
}