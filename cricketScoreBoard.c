#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*initialize an enum for Runs from 0, 1, 2, 3*/
enum RUNS{ RUN0, RUN1, RUN2, RUN3};
#define FOUR 4
#define SIX 6fdsfgsjdfgjsf
#define WICKET 7
#define WIDE "Wd"
#define OVER 6

int MAX = INT_MIN;

/*
struct Player - keeping record of each player 
*/
struct Player{
  int fours, sixes, balls, score;
};

/*
struct Team - Keeping record of each team such number of Overs, wickets, total score for each player in team.
*/
struct Team{
  struct Player *players;
  unsigned noOfPlayer;
  int totalScore, totalWickets, totalOver;
};


/*
Initialize player struct given the number of players in each team
*/
struct Player *initPlayers(unsigned noOfPlayers){
  struct Player *players = (struct Player *)malloc(sizeof(struct Player) * noOfPlayers);
  for(int i=0; i<noOfPlayers; i++){
    players[i].fours = players[i].balls = players[i].sixes = players[i].score = 0;
  }//for

  return players;
}//initPlayers


/*
Initialize team struct for team1 and team2 with players, their records, total score.
*/
struct Team *initTeams(unsigned noOfPlayers){
  struct Team *teams = (struct Team *)malloc(sizeof(struct Team) * 2);
  for(int i=0; i<2; i++){
    teams[i].noOfPlayer = noOfPlayers;
    teams[i].players    = initPlayers(noOfPlayers);
    teams[i].totalScore = teams[i].totalWickets = teams[i].totalOver = 0;
  }//for
  return teams;
}//struct Team


/*
Utility to find max of two numbers
*/
int max(int a, int b){
  return a>b?a:b;
}//max


/*
Utility to swap two values
*/
int swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}//swap


/*
Function to convert runs and wicket to a number.
*/
int convertRuns(char *input){
  if(strcmp(input, "1")==0)
    return RUN1;
  else if(strcmp(input, "2")==0)
    return RUN2;
  else if(strcmp(input, "0")==0)
    return RUN0;
  else if(strcmp(input, "3")==0)
    return RUN3;
  else if(strcmp(input, "4")==0)
    return FOUR;
  else if(strcmp(input, "6")==0)
    return SIX;
  else if(strcmp(input, "W")==0)
    return WICKET;
  else 
    return -1;
}//runs


/*
function to print score board after every over
*/
void printScoreBoard(struct Team *teams, int player1, int player2){
  printf("\n============================================================");
  printf("\nPlayer Name|\t\tScore|\t4s|\t6s|\tballs|\n");
  printf("============================================================\n");

  for(int i=0; i<teams->noOfPlayer; i++){
    if(player1==i) //print current player1
      printf("P%d*\t\t|\t%d|\t%d|\t%d|\t%d|\n", i+1, teams->players[i].score, teams->players[i].fours, teams->players[i].sixes, teams->players[i].balls);
    else if(player2==i) //print current player2
      printf("P%d*\t\t|\t%d|\t%d|\t%d|\t%d|\n", i+1, teams->players[i].score, teams->players[i].fours, teams->players[i].sixes, teams->players[i].balls);
    else
      printf("P%d\t\t|\t%d|\t%d|\t%d|\t%d|\n", i+1, teams->players[i].score, teams->players[i].fours, teams->players[i].sixes, teams->players[i].balls);
  }//for
}//printScoreBoard


/*
Function to get current player batting
*/
int getCurrentPlayer(int *wickets, int noOfPlayers, int player2){
  for(int curr=0; curr<noOfPlayers; curr++){
    if( (wickets[curr]==0 || wickets[curr]==2) && curr!=player2 ){
      wickets[curr] = 2;
      return curr;
    }//fir
  }//for
  return -1;
}//getCurrentPlayer


/*
Function to calculate score and display the score board for each team and current players
*/
void displayScoreBoard(int *over, int *battingOrder, struct Team *teams, int *wicket, int player1, int player2){
  player1 = getCurrentPlayer(wicket, teams->noOfPlayer, player2);
  player2 = getCurrentPlayer(wicket, teams->noOfPlayer, player1);
  int order=0;
  
  for(int i=0; i<OVER; i++){
    if(player1<0 || player2<0){
      printScoreBoard(teams, player1,player2);
      printf("Total : %d/%d\n", teams->totalScore, teams->totalWickets);
      printf("\nOvers : %d.%d", teams->totalOver/6, teams->totalOver%6);
      return;
    }
    wicket[player1] = 2, wicket[player2] = 2;
    switch(over[i]){
      case FOUR: // check for fours by the player i.e. player1
        teams->totalScore +=4;
        teams->totalOver +=1;
        teams->players[battingOrder[player1]-1].fours +=1;
        teams->players[battingOrder[player1]-1].score +=4;
        teams->players[battingOrder[player1]-1].balls +=1;
      break;

      case SIX:
        teams->totalScore +=6;
        teams->totalOver +=1;
        teams->players[battingOrder[player1]-1].sixes +=1;
        teams->players[battingOrder[player1]-1].score +=6;
        teams->players[battingOrder[player1]-1].balls +=1;
      break;

      case WICKET:
        teams->totalWickets +=1;
        teams->totalOver +=1;
        teams->players[battingOrder[player1]-1].balls +=1;
        wicket[player1] = 1;
        player1 = getCurrentPlayer(wicket, teams->noOfPlayer, player2);
      break;

      default:
        teams->totalOver +=1;
        teams->totalScore += over[i];
        teams->players[battingOrder[player1]-1].score +=over[i];
        teams->players[battingOrder[player1]-1].balls +=1;
        if(over[i]%2==1) //for add runs such as 1 or 3, swap the turn of current batting player1 and player2
          swap(&player1, &player2);
    }//switch
    MAX = max(MAX, teams->totalScore);
  }//for

  printScoreBoard(teams, player1, player2);
  printf("Total : %d/%d\n", teams->totalScore, teams->totalWickets);
  printf("Overs : %d.%d\n", teams->totalOver/6, teams->totalOver%6);
      
}//displayScoreBoard

int main(){
  int noOfPlayers, noOfOvers;
  int *over,  *battingOrder;

  //Number of players in a team and number of overs in the match
  scanf("%d %d",&noOfPlayers, &noOfOvers);
  struct Team *teams = initTeams(noOfPlayers);
  
  for(int teamNum=0; teamNum<2; teamNum++){
    int wicket[teams->noOfPlayer];
    memset(wicket, 0, sizeof(wicket));
    int player1=-1, player2=-1;
    
    //batting order
    battingOrder = (int *)malloc(sizeof(int) * noOfPlayers);
    for(int i=0;i<noOfPlayers;i++){
      scanf("%d", &battingOrder[i]);
    }
    printf("\nDone with batting order\n");

    for(int currOver = 0; currOver < noOfOvers; currOver++){
      //over input for curr+1 team
      over = (int *)malloc(sizeof(int) * OVER);
      for(int currBall=0; currBall<OVER; currBall++){
          char input[2]; 
          scanf("%s", input);

          //check if current ball is wide, then add it into total score and continue the over with one more ball
          if(strcmp(input, WIDE)==0) {
            teams[teamNum].totalScore+=1;
            currBall--;
          }
          else
            over[currBall] = convertRuns(input);
      }//over

      /*
      Display score baord after every over.
      */
      printf("\n============Team %d Over %d=================\n", teamNum+1, currOver+1);
      displayScoreBoard(over, battingOrder, &teams[teamNum], wicket, player1, player2);

      /*check if current over has all the wickets*/
      if(teams[teamNum].totalWickets == (teams->noOfPlayer-1))
        currOver = noOfOvers;
    }//curr over

  }//for teamNum 

  //check if the score is equal for both the teams, then draw the match
  int draw = teams[0].totalScore == teams[1].totalScore ? 1 : 0;
  if(!draw){
    //check the winner of the cricket match, display the winner along with score difference.
    int winner = MAX == teams[0].totalScore ? 1: 2 ;
    int loser = winner == 1 ? 2 : 1;
    printf("\nResult: Team %d won match by %d run",winner, (MAX - teams[loser-1].totalScore));
  }
  else{
    printf("\nResult: Match draw between both team1 and team2 with score %d", MAX);
  }
  
  return 1;
}
