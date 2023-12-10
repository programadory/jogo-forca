#include <iostream>

using namespace std;

#define CLEAR system("clear"); //Macro to clean up terminal contend.

int main(){
  
  /* 1th block of variables */
  
  string topic="", word="";
  char char_letter;
  int word_sz=0, it=0;
  bool check=1;
  
  /* Catching data from user */
  
  cout << "-----JOGO DA FORCA-----\n\n";
  cout << "Palavra: ";
  cin >> word;
  CLEAR
  
  /* String lengh calculator */
  
  for(; it<sizeof(word) || check==true; it++){
      if(word[it]=='\0'){
        word_sz+=it;
        check=0;
        break;
      }
  }

  /* Allocating dynamic memory to our main variables. */
  
  char* word_overwrite = (char*) malloc(word_sz); 
  char* word_show = (char*) malloc(word_sz);
  
  /* Filling up variable with animation purposes */
  
  for(int letters=0; letters<word_sz ; letters++){
      word_overwrite[letters] = (word[letters]=='-') ? '-' : '_';
  }
  
  /* Stickman drawing */
  
  string stickman[9]= { 
    " .------\n",
    " |  (+_+)\n", //life 5
    " |  / | ",    //life 4
    "/\n",         //life 3
    " |    | \n",  //life 2
    " |   * *\n",  //life 1
    " |  |   |\n", //life 0
    " |      \n",  
    "---     \n"
    
  };
  
  /* Hang drawing */
  
  string stickman_overwrite[9]= { 
    " .------\n",
    " |  \n", 
    " |  ",  
    "\n",  
    " |    \n",  
    " |   \n",  
    " |  \n", 
    " |      \n", 
    "---"  
    
  };
  
  /* 2th block of variables, game variables */
  
  it=0;
  int i3=0;
  int lt=0, score=0;
  int life=6;
  bool gameover=0;

  system("stty cbreak"); //Disable wait-till-Enter-click on Termux
  
  /* Main looping */
  
  do{
     
      CLEAR
      
      /*Printing game contend on screen */
      
      cout << "Score: " << score << "          Remain life: " << life << "\n\nTries: " << word_show  << "\n\n";
      
      /* Drawing hangman */
      
      for(int i=0; i<8; i++){ //Desenho do boneco vazio.
        cout << stickman_overwrite[i];
      }
 
      /* Printing line animation */ 
      
      cout << stickman_overwrite[8] << " " << word_overwrite << "\n";
      
      /* Win or Lose statements */
      
      if(lt==word_sz){
        cout << "\nVOCE VENCEU O JOGO!\n\n";
        break;
      }
      
      if(life==0){
        cout << "\nVOCE PERDEU!\n\n";
        break;
      }
      
      /* User hangman game input */
      
      cin >> char_letter;
      
      /* Iterating all over the array word[] and word_overwrite[] looking for hints, if hint then the character is added to word[] array then return a lot of variable changes, as score, lt that represents ( - ) character, predicting an error from user and the condition not be satisfied. */
      
      for(int i=0; i<word_sz; i++) 
        {
          
          if(char_letter==word[i] && word_overwrite[i]!='-' && char_letter!=word_overwrite[i]){
            word_overwrite[i] = char_letter;
            score++;
            lt++;
            gameover=true;
          }
          
          if(lt!=word_sz && word_overwrite == word){
            lt++;
          }
          
        }
      
      /* Statement due to a no-equal input from user, decreasing and increasing life, stickman to overwrite the current drawer according to the life counting. */
      
      if(!gameover){
        if(i3==0){ //Fixing the drawing start point.  
          i3++;
        }
        stickman_overwrite[i3] = stickman[i3];
        
        word_show[it++] = char_letter;
        --life;
        i3++;
      }
      
      /* Reseting gameover statement */    
      
      gameover=false;
      
  }while(true);
  
  system("stty -cbreak");
  
  return 0;
}
