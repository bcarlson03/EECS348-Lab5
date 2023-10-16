#include <stdio.h>


int main()
    {

    //The five ways a team can score are stored in an array.
    int scores[] = {2, 3, 6, 7, 8};
    //Initializes userScore to a number greater than 1, and starts a while loop.
    int userScore = 2;
    //The while loop will continue until the user enters 0 or 1.
    //In the loop, the user will be prompted to enter an NFL score, and then it will print all the possible combinations of scores.
    while(userScore != 1 && userScore != 0)
        {
            printf("Enter 0 or 1 to stop\n");
            printf("Enter an NFL score: ");
            scanf("%d", &userScore);
            //If the user enters a score greater than 1, than a bunch of nested for loops will go through all the possible combinations of ways to score that are up to the score that the user entered.
            //Each for loop checks for the maximum number of times a team can score in that way without going over the given score.
            //At the end, if a given combination of scoring methods equals the score the user is looking for, it will print that number of eaching scoring method labeled accordingly.
            //If the score combination doesnt equal the user entered score then it will not be printed. This is what prevents scores that are less than the user given score from being printed.
            if(userScore > 1)
            {
                for(int twoPtSafety = 0; twoPtSafety * scores[0] <= userScore; twoPtSafety++)
                    {
                        for(int threePtFg = 0; threePtFg * scores[1] <= userScore; threePtFg++)
                            {
                                for(int sixPtTd = 0; sixPtTd * scores[2] <= userScore; sixPtTd++)
                                    {
                                        for(int sevenPtTd = 0; sevenPtTd * scores[2] <= userScore; sevenPtTd++)
                                            {
                                                for(int eightPtTd = 0; eightPtTd * scores[2] <= userScore; eightPtTd++)
                                                    {
                                                        if(twoPtSafety * scores[0] + threePtFg * scores[1] + sixPtTd * scores[2] + sevenPtTd * scores[3] + eightPtTd * scores[4] == userScore)
                                                            {
                                                                printf("%d TD + 2Pt, %d TD + FG, %d TD, %d 3Pt FG, %d Safety\n", eightPtTd, sevenPtTd, sixPtTd, threePtFg, twoPtSafety);
                                                            }
                                                    }
                                            }
                                    }
                            }
                    }
                

            }
        
        }
    return 0;
    }