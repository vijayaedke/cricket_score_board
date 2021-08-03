# Phonepe

## Problem:
Write a cricket scorecard that will show the score for a team along with score of each player. You will be given the number of players in each team, the number of overs and their batting order as input. Then, we can input overs ball by ball with the runs scored on that ball (could be wide, no ball or a wicket as well). You are expected to print individual scores, number of balls faced, number of 4s, number of 6s for all the players from the batting side at the end of every over. You also need to print total score, total wickets. Essentially, you need to keep a track of all the players, strike changes (at the end of the over or after taking singles or 3s) and maintain their scores, also keep track of extra bowls that are being bowled (like wides or no balls). You also need to print which team
won the match at the end.  
This is the bare minimum solution which is expected for the problem. You can add some more features once you are done with these, like maintaining bowlers record (total overs bowled, runs conceded, wickets taken, maiden overs, dot balls, economy, etc.). Total team extras, batsman strike rates, etc. can be added too. But these are "good to have" features, please try to complete the bare minimum first. Make sure your code is readable and maintainable and preferably object oriented. It should be modular and extensible, to add new features if needed.

## Sample input and output:  
No. of players for each team: 5  
No. of overs: 2   
Batting Order for team 1:  
P1  
P2  
P3  
P4  
P5  
## Over 1:  
1  
1  
1  
1  
1  
2  
## Scorecard for Team 1:  
#### Player Name&emsp;Score&emsp;4s&emsp;6s&emsp;Balls  
#### P1*&emsp;&emsp;&emsp;&emsp;&emsp;3&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;3  
#### P2*&emsp;&emsp;&emsp;&emsp;&emsp;4&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;3  
#### P3&emsp;&emsp;&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0  
#### P4&emsp;&emsp;&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0  
#### P5&emsp;&emsp;&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0  
#### Total: 7/0  
#### Overs: 1  
Over 2:  
W  
4  
4  
Wd  
W  
1  
6  
## Scorecard for Team 1:  
#### Player Name Score 4s 6s Balls  
#### P1&emsp;&emsp;&emsp;&emsp;&emsp;3&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;4  
#### P2*&emsp;&emsp;&emsp;&emsp;&emsp;10&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;1&emsp;&emsp;&emsp;4  
#### P3&emsp;&emsp;&emsp;&emsp;&emsp;8&emsp;&emsp;&emsp;2&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;3  
#### P4*&emsp;&emsp;&emsp;&emsp;&emsp;1&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;1  
#### P5&emsp;&emsp;&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0  
#### Total: 23/2  
#### Overs: 2  
### Batting Order for team 2:  
P6  
P7  
P8  
P9  
P10  
Over 1:  
4  
6  
W  
W  
1  
1  
## Scorecard for Team 2:  
#### Player Name Score 4s 6s Balls  
#### P6&emsp;&emsp;&emsp;&emsp;&emsp;10&emsp;&emsp;&emsp;1&emsp;&emsp;&emsp;1&emsp;&emsp;&emsp;3  
#### P7*&emsp;&emsp;&emsp;&emsp;&emsp;1&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;1  
#### P8&emsp;&emsp;&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;1  
#### P9*&emsp;&emsp;&emsp;&emsp;&emsp;1&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;1  
#### P10&emsp;&emsp;&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0  
#### Total: 12/1  
#### Overs: 1  
Over 2:  
6  
1  
W  
W  
## Scorecard for Team 2:  
#### Player Name Score 4s 6s Balls  
#### P6&emsp;&emsp;&emsp;&emsp;&emsp;10&emsp;&emsp;&emsp;1&emsp;&emsp;&emsp;1&emsp;&emsp;&emsp;2  
#### P7*&emsp;&emsp;&emsp;&emsp;&emsp;8&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;1&emsp;&emsp;&emsp;3  
#### P8&emsp;&emsp;&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;1  
#### P9&emsp;&emsp;&emsp;&emsp;&emsp;1&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;2  
#### P10&emsp;&emsp;&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;0&emsp;&emsp;&emsp;1  
#### Total: 19/4  
#### Overs: 1.4  
### Result: Team 1 won the match by 4 runs  
