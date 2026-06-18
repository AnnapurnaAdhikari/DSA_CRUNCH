class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = abs(30*hour - 5.5*minutes);
        // int minu = minutes/5;
        // if(minu){
        //     angle += (hour - minu)*30 + 15;

        // }
        // else angle += (hour - minu)*30;
        // return angle <= 360 - angle ? abs(angle) : abs(360-angle);
        return angle <= 360 - angle? angle: 360 - angle;
    }
};