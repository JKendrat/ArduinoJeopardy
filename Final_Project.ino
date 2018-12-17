#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int switchPin1 = 7;
int switchPin2 = 8;
int switchState1 = 0;
int switchState2 = 0;
int prevSwitchState1 = 0;
int prevSwitchState2 = 0;
int nextScreen = 0;
int player1Points = 0;
int player2Points = 0;
int player1Bet = 0;
int player2Bet = 0;
int select;
String selectedCategory;
int points;
String selectedPlayer;
String playerAnswer;
String realAnswer;
int numberofQuestions = 0;
int categoryChoice[] = {1, 2, 3};
int categoryValue[] = {100, 200, 300}; 
String Categories[] = {"Instruments", "Math", "Computers"};
int selectedPointValue;
String instrumentQuestions1[]= {"The saxophone", "The serpent is a", "The piano has"};
String instrumentQuestions2[]= {"was made in 1846", "brass instrument", "85 keys"};
String mathQuestions1[] = {"22 + 19", "56 + 45", "40 % 5"};
String mathQuestions2[] = {"= 41", "= 102", "= 1"};
String Computers1[] = {"DNS stands for", "DRAM is faster", "3A6 in binary is:"};
String Computers2[] = {"Domain Name Sys.", "than SRAM", "0011 1010 0110"};
String finalJeopardy1 = "Dark magician is";
String finalJeopardy2 = "magic attributed";
String instrumentAnswers[]= {"True", "True", "True"};
String mathAnswers[] = {"True", "False", "False"};
String computerAnswers[] = {"True", "False", "True"};
int bettingPoints[] = {0, 100, 200, 300, 400, 500};
String finaljeopardyAnswer[] = {"False"};
int contrast = 13;

void setup() {
  // put your setup code here, to run once:
  // Sets up the first screen, the screen, the lcds, the contrast and the buttons
  // Portrays the welcome screens and the categories
  // Begins jeopardy when the right button is pressed
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(contrast, HIGH);
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  
  lcd.begin(16, 2);
  lcd.print("This");
  delay(1000);
  lcd.setCursor(8, 0);
  lcd.print("is");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Jeopardy");
  delay(1400);
  lcd.clear();
  lcd.print("Category 1:");
  lcd.setCursor(0, 1);
  lcd.print("Intstruments");
  delay(2400);
  lcd.clear();
  lcd.print("Category 2:");
  lcd.setCursor(0, 1);
  lcd.print("Math");
  delay(2400);
  lcd.clear();
  lcd.print("Category 3:");
  lcd.setCursor(0, 1);
  lcd.print("Computers");
  delay(1600);
  lcd.clear();
  lcd.print("Press right");
  lcd.setCursor(0, 1);
  lcd.print("button");
}

void loop() {
  // put your main code here, to run repeatedly:
  // When a player is choosing a category, the right button chooses a category and left confirms the selection
  // First person to hit their button, player 1 is the left button and player 2 is the right button, gets to answer
  // When a player gets to answer left button represents true and right button represents false
  switchState1 = digitalRead(switchPin1);
  switchState2 = digitalRead(switchPin2);
    if(switchState1 != prevSwitchState1 || switchState2 != prevSwitchState2){
      lcd.clear();
      
      if(switchState1 == HIGH && switchState2 == HIGH ){ 

          
          
        
      }else if(switchState1 == HIGH && nextScreen == 0){
        //Confirm selection of category        
        categoryConfirm();
     
      }else if(switchState2 == HIGH && nextScreen == 0){
      //Moves the cursor to the next category
      chooseCategory();
        
    }

     else if(switchState1 == HIGH && nextScreen == 1){
        //Confirms point value for the category
        pointConfirm();
     
      }else if(switchState2 == HIGH && nextScreen == 1){
      //Moves the cursor to the next bit
      choosePointValue();
        
     }else if(switchState1 == HIGH && nextScreen == 2){
        //If player1 hits the button first, they get to answer
        player1Choice();
     
      }else if(switchState2 == HIGH && nextScreen == 2){
      //If player2 hits the button first, they get to answer
        player2Choice();
        
     }else if(switchState1 == HIGH && nextScreen == 3){
        //If player1 hits the button first, they get to answer
        True();
     
      }else if(switchState2 == HIGH && nextScreen == 3){
      //If player2 hits the button first, they get to answer
        False();
        
     }else if(switchState1 == HIGH && nextScreen == 4){
        
        
     
      }else if(switchState2 == HIGH && nextScreen == 4){
      
        
        
     }else if(switchState1 == HIGH && nextScreen == 5){
        //Allows player 1 to confirm their bet
        confirmplayer1Bet();
     
      }else if(switchState2 == HIGH && nextScreen == 5){
      //Allows player 1 to create a bet
        chooseplayer1Bet();
        
     }else if(switchState1 == HIGH && nextScreen == 6){
        //Allows player 2 to confirm their bet
        confirmplayer2Bet();
     
      }else if(switchState2 == HIGH && nextScreen == 6){
      //Allows player 2 to choose their bet
        chooseplayer2Bet();
        
     }else if(switchState1 == HIGH && nextScreen == 7){
        //Allows player 2 to confirm their bet
        player1Choice();
     
      }else if(switchState2 == HIGH && nextScreen == 7){
      //Allows player 2 to choose their bet
        player2Choice();
        
     }else if(switchState1 == HIGH && nextScreen == 8){
        //Allows player 2 to confirm their bet
        True();
     
      }else if(switchState2 == HIGH && nextScreen == 8){
      //Allows player 2 to choose their bet
        False();
        
     }   
    
    //Displays player points and categories
    if(nextScreen == 0){
        lcd.setCursor(0, 0);
        lcd.print(Categories[select]);
        lcd.setCursor(0, 1);
        lcd.print("P1:");
        lcd.print(player1Points);
        lcd.setCursor(8, 1);
        lcd.print("P2:");
        lcd.print(player2Points);
        
    }
   //Allows players to select the question they wish to answer
    if(nextScreen == 1){
      lcd.setCursor(0, 0);
      lcd.print("How many points?");
      lcd.setCursor(0, 1);
      lcd.print(categoryValue[select]);
          
        
    }
   //Gets a question from the arrays, determines which question from that category it is and then displays it
    if(nextScreen == 2){
      lcd.setCursor(0, 0);
       lcd.print("Players Ready?"); 
       delay(1000);
       lcd.clear();
      if(selectedCategory == "Instruments"){
        if(points == 100){
          lcd.print(instrumentQuestions1[0]);
          lcd.setCursor(0, 1);
          lcd.print(instrumentQuestions2[0]);
        } else if(points == 200){
          lcd.print(instrumentQuestions1[1]);
          lcd.setCursor(0, 1);
          lcd.print(instrumentQuestions2[1]);
        } else{
          lcd.print(instrumentQuestions1[2]);
          lcd.setCursor(0, 1);
          lcd.print(instrumentQuestions2[2]);
        }
      } else if(selectedCategory == "Math"){
        if(points == 100){
          lcd.print(mathQuestions1[0]);
          lcd.setCursor(0, 1);
          lcd.print(mathQuestions2[0]);
        } else if(points == 200){
          lcd.print(mathQuestions1[1]);
          lcd.setCursor(0, 1);
          lcd.print(mathQuestions2[1]);
        } else{
          lcd.print(mathQuestions1[2]);
          lcd.setCursor(0, 1);
          lcd.print(mathQuestions2[2]);
        }
      } else{
        if(points == 100){
          lcd.print(Computers1[0]);
          lcd.setCursor(0, 1);
          lcd.print(Computers2[0]);
        } else if(points == 200){
          lcd.print(Computers1[1]);
          lcd.setCursor(0, 1);
          lcd.print(Computers2[1]);
        } else{
          lcd.print(Computers1[2]);
          lcd.setCursor(0, 1);
          lcd.print(Computers2[2]);
        }
      } 

     
        
    }
    //Displays true or false 
    if(nextScreen == 3){
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("True");
      lcd.setCursor(10, 0);
      lcd.print("False");

      
    }
    //Checks to see if the answer is correct and if it is time to move to the next question
    if(nextScreen == 4){
      lcd.clear();
      checkAnswer();
      checkfinalQuestion();
      
    }
    //Displays player 1's bet
    if(nextScreen == 5){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Player 1 bet:");
      lcd.setCursor(0, 1);
      lcd.print(bettingPoints[select]);
      
    }
    //Displays player2's bet
    if(nextScreen == 6){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Player 2 bet:");
      lcd.setCursor(0, 1);
      lcd.print(bettingPoints[select]);
    }
    
    //Displays final jeopardy question
    if(nextScreen == 7){
      lcd.clear();
      delay(1000);
      lcd.setCursor(0, 0);
      lcd.print(finalJeopardy1);
      lcd.setCursor(0, 1);
      lcd.print(finalJeopardy2);
        
    }
    //Final true or false screen
     if(nextScreen == 8){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("True");
      lcd.setCursor(10, 0);
      lcd.print("False");
     }
     //Displays the winner
     if(nextScreen == 9){
       lcd.clear();
       delay(1600);
       checkfinalAnswer();
       delay(600);
       winner();
     }
   prevSwitchState1 = switchState1;
   prevSwitchState2 = switchState2;
    
     
   }
   
}
//confirms selection of category    
int categoryConfirm(){
  selectedCategory = Categories[select];
  nextScreen++;
}
//confirms selection of points
int pointConfirm(){
  points = categoryValue[select];
  nextScreen++;
}
//confirms player 1 bet
int confirmplayer1Bet(){
  player1Bet = bettingPoints[select];
  nextScreen++;
}
//Confirms player 2 bet
int confirmplayer2Bet(){
  player2Bet = bettingPoints[select];
  nextScreen++;
}

//Allows player 1 to use points up to 500 to bet
int chooseplayer1Bet(){

    select = (select + 1)%6;
  
}
//Allows player 2 to use points up to 500 to bet
int chooseplayer2Bet(){
    
  select = (select + 1)%6;
}
//Checks to see when to move on to final jeopardy
int checkfinalQuestion(){
  if(numberofQuestions == 9){
    delay(1000);
    lcd.clear();
    lcd.print("Final Question");
    delay(500);
    lcd.clear();
    lcd.print("Both players may");
    lcd.setCursor(0, 1);
    lcd.print("enter up to 500");
    delay(1000);
    nextScreen = 5;
  } else{
    nextScreen = 0;
    numberofQuestions++;
  }
}
//Allows player to choose a category
int chooseCategory(){
  
      select = (select + 1)%3;    
}
//Allows player to choose a point value
int choosePointValue(){
  
      select = (select + 1)%3;    
}
//Determines if player1 got to their button first
int player1Choice(){
  selectedPlayer = "Player 1";
  lcd.clear();
  lcd.print("Player 1");
  lcd.setCursor(0, 1);
  lcd.print("gets to answer");
  delay(1000);
  nextScreen++;
}
//Determines if player2 got to their button first
int player2Choice(){
  selectedPlayer = "Player 2";
  lcd.clear();
  lcd.print("Player 2");
  lcd.setCursor(0, 1);
  lcd.print("gets to answer");
  delay(1000);
  nextScreen++;
}
//Sets the player's answer to true
int True(){
  playerAnswer = "True";
  nextScreen++;
}
//Sets the player's answer to false
int False(){
  playerAnswer = "False";
  nextScreen++;
}
//Checks to see if the answer the player gives is correct and then distribute points
//Turns on green LED when answer is correct
//Turns on red LED when the answer is wrong
int checkAnswer(){
   if(selectedCategory == "Instruments"){
        if(points == 100){
          if(instrumentAnswers[0] == playerAnswer){
            lcd.print("Correct");
            digitalWrite(9, HIGH);
            if(selectedPlayer == "Player 1"){
              player1Points = player1Points + 100;
            } else{
              player2Points = player2Points + 100;
            }
          } else{
            lcd.print("Wrong");
            digitalWrite(10, HIGH);
             if(selectedPlayer == "Player 1"){
              player1Points = player1Points - 100;
            } else{
              player2Points = player2Points - 100;
            }
          }
        } else if(points == 200){
          if(instrumentAnswers[1] == playerAnswer){
            lcd.print("Correct");
            digitalWrite(9, HIGH);
            if(selectedPlayer == "Player 1"){
              player1Points = player1Points + 200;
            } else{
              player2Points = player2Points + 200;
            }
          } else{
            lcd.print("Wrong");
            digitalWrite(10, HIGH);
             if(selectedPlayer == "Player 1"){
              player1Points = player1Points - 200;
            } else{
              player2Points = player2Points - 200;
            }
          }
        } else{
          if(instrumentAnswers[2] == playerAnswer){
            lcd.print("Correct");
            digitalWrite(9, HIGH);
            if(selectedPlayer == "Player 1"){
              player1Points = player1Points + 300;
            } else{
              player2Points = player2Points + 300;
            }
          } else{
            lcd.print("Wrong");
            digitalWrite(10, HIGH);
             if(selectedPlayer == "Player 1"){
              player1Points = player1Points - 300;
            } else{
              player2Points = player2Points - 300;
            }
          }
        }
      } else if(selectedCategory == "Math"){
        if(points == 100){
          if(mathAnswers[0] == playerAnswer){
            lcd.print("Correct");
            digitalWrite(9, HIGH);
            if(selectedPlayer == "Player 1"){
              player1Points = player1Points + 100;
            } else{
              player2Points = player2Points + 100;
            }
          } else{
            lcd.print("Wrong");
            digitalWrite(10, HIGH);
             if(selectedPlayer == "Player 1"){
              player1Points = player1Points - 100;
            } else{
              player2Points = player2Points - 100;
            }
          }
        } else if(points == 200){
          if(mathAnswers[1] == playerAnswer){
            lcd.print("Correct");
            digitalWrite(9, HIGH);
            if(selectedPlayer == "Player 1"){
              player1Points = player1Points + 200;
            } else{
              player2Points = player2Points + 200;
            }
          } else{
            lcd.print("Wrong");
            digitalWrite(10, HIGH);
             if(selectedPlayer == "Player 1"){
              player1Points = player1Points - 200;
            } else{
              player2Points = player2Points - 200;
            }
          }
        } else{
          if(mathAnswers[2] == playerAnswer){
            lcd.print("Correct");
            digitalWrite(9, HIGH);
            if(selectedPlayer == "Player 1"){
              player1Points = player1Points + 300;
            } else{
              player2Points = player2Points + 300;
            }
          } else{
            lcd.print("Wrong");
            digitalWrite(10, HIGH);
             if(selectedPlayer == "Player 1"){
              player1Points = player1Points - 300;
            } else{
              player2Points = player2Points - 300;
            }
          }
        }
      } else{
        if(points == 100){
          if(computerAnswers[0] == playerAnswer){
            lcd.print("Correct");
            digitalWrite(9, HIGH);
            if(selectedPlayer == "Player 1"){
              player1Points = player1Points + 100;
            } else{
              player2Points = player2Points + 100;
            }
          } else{
            lcd.print("Wrong");
            digitalWrite(10, HIGH);
             if(selectedPlayer == "Player 1"){
              player1Points = player1Points - 100;
            } else{
              player2Points = player2Points - 100;
            }
          }
        } else if(points == 200){
          if(computerAnswers[1] == playerAnswer){
            lcd.print("Correct");
            digitalWrite(9, HIGH);
            if(selectedPlayer == "Player 1"){
              player1Points = player1Points + 200;
            } else{
              player2Points = player2Points + 200;
            }
          } else{
            lcd.print("Wrong");
            digitalWrite(10, HIGH);
             if(selectedPlayer == "Player 1"){
              player1Points = player1Points - 200;
            } else{
              player2Points = player2Points - 200;
            }
          }
        } else{
          if(computerAnswers[2] == playerAnswer){
            lcd.print("Correct");
            digitalWrite(9, HIGH);
            if(selectedPlayer == "Player 1"){
              player1Points = player1Points + 300;
            } else{
              player2Points = player2Points + 300;
            }
          } else{
            lcd.print("Wrong");
            digitalWrite(10, HIGH);
             if(selectedPlayer == "Player 1"){
              player1Points = player1Points - 300;
            } else{
              player2Points = player2Points - 300;
            }
          }
        }
     }
     delay(800);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
}
//Checks to see if the answer to the final question is correct
int checkfinalAnswer(){
  if(finaljeopardyAnswer[0] == playerAnswer){
    
    if(selectedPlayer == "Player 1"){
      player1Points = player1Points + player1Bet;
    } else{
      player1Points = player1Points - player1Bet;
    }   
  

  if(selectedPlayer == "Player 2"){
    player2Points = player2Points + player2Bet;
  } else{
    player2Points = player2Points - player2Bet;
  }
 }
}
//Determines the winner of the game and then displays it
int winner(){
  if(player1Points > player2Points){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Player 1 Wins");
    lcd.setCursor(0, 1);
    lcd.print("P1: ");
    lcd.print(player1Points);
    lcd.setCursor(8, 1);
    lcd.print("P2: ");
    lcd.print(player2Points);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Player 2 Wins");
    lcd.setCursor(0, 1);
    lcd.print("P1: ");
    lcd.print(player1Points);
    lcd.setCursor(8, 1);
    lcd.print("P2: ");
    lcd.print(player2Points);
  }
}
