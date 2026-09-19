class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closX=max(x1, min(xCenter, x2));
        int closY=max(y1, min(yCenter, y2));
        int disX=xCenter-closX;
        int disY=yCenter-closY;
        return disX*disX+disY*disY<=radius*radius;
    }
};