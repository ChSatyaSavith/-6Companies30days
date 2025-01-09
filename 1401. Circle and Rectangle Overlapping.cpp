class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) 
    {
        int xp,yp;
        if(x1<=xCenter && xCenter<=x2)
        {
            xp = xCenter;
        }
        else if(xCenter<x1)
        {
            xp = x1;
        }
        else if(xCenter>x2)
        {
            xp = x2;
        }

        if(y1<=yCenter && yCenter<=y2)
        {
            yp = yCenter;
        }
        else if(yCenter<y1)
        {
            yp = y1;
        }
        else if(yCenter>y2)
        {
            yp = y2;
        }

        if(distance(xCenter,yCenter,xp,yp)<=radius)
        {
            return true;
        }
        return false;
    }
    float distance(float x1,float y1,float x2,float y2)
    {
        return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    }
};