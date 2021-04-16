#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    while (true) {
        string outcome;
        cout << "Enter the race outcome: " ;
        //ZZAZAA

    Label:
        cin >> outcome;
        if (outcome == "done") break;
        char totalTeams[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        int scores[26] = {0};
        int counts[26] = {0};
        for(int i = 0; i < outcome.length(); i++){
            while(outcome[i]>'Z'|| outcome[i]<'A'){
                cout << "Error, only uppercase characters are allowd. Please try again: " << endl;
                cin >> outcome;
            }
        }
        for (int i =0; i < 26; i++){
            for (int j =0; j < outcome.length(); j++){
                if (totalTeams[i] == outcome[j]){
                    counts[i]++;
                    scores[i]+= j+1;
                }
            }
        }
        int runner = 0;
        for (int i = 0; i < 26; i++){
            if (counts[i] >= runner)
            runner = counts[i];
        }
        for (int i=0; i<26; i++)
        while (counts[i] != 0 && counts[i] != runner){
            cout << "Error, teams do not have the same number of runners. Please try again: " << endl;
           goto Label;
            
        }
        int teams = 0;
        double averageScores[26] = {0.0};
        for (int i = 0; i < 26; i++){
            averageScores[i] = (double) scores[i] / counts[i];
            if (counts[i] != 0) teams++;
        }
        cout << "There are: " << teams << " teams."<< endl;
        cout << "Each team has " << outcome.length() / teams << " runners." << endl;
        cout << "Team" <<"     "<< "Score" << endl;
        for (int i = 0; i < 26;i++){
            if (counts[i] != 0){
                cout << totalTeams[i] << "         "<< averageScores[i];
                cout << endl;
            }
        }
        double minimum = 100.0;
        char winTeam = '\0';
        for (int i = 0; i < 26; i++){
            if(averageScores[i] < minimum) minimum = averageScores[i];

            if (minimum == (double) scores[i] / counts[i]) winTeam = totalTeams[i];
        }
        cout << "The winning team is team "<< winTeam << " with a score of " << minimum << "." << endl;
    }
    return 0;
}
