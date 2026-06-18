class Solution {
public:
    double angleClock(int hour, int minutes) {
        //formula based
        // double angle = abs(30*hour - 5.5*minutes);
        // return angle <= 360 - angle? angle: 360 - angle;

        //logic
        double minute = minutes * 6;
        double hourHand = (hour % 12) * 30 + (minutes * 0.5);
        double diff = abs(hourHand - minute);
        return min(diff, 360.0 - diff);
    }
};