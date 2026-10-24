class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int aa = stoi(arriveAlice.substr(0, 2));
        int ab = stoi(arriveBob.substr(0, 2));
        int la = stoi(leaveAlice.substr(0, 2));
        int lb = stoi(leaveBob.substr(0, 2));

        int arra = 0, arrb = 0, lea= 0, leb =0;
        for(int i  = 0; i < aa-1; i++){
            arra += month_days[i];
        }
        arra += stoi(arriveAlice.substr(3, 2));
        for(int i  = 0; i < ab-1; i++)arrb += month_days[i];
        arrb += stoi(arriveBob.substr(3, 2));
        for(int i  = 0; i < la-1; i++)lea += month_days[i];
        lea += stoi(leaveAlice.substr(3, 2));
        for(int i  = 0; i < lb-1; i++)leb += month_days[i];
        leb += stoi(leaveBob.substr(3, 2));

        int a = arra>arrb? arra:arrb;
        int l = lea<leb? lea:leb;

        return l-a >= 0? l-a+1:0;

    }
};