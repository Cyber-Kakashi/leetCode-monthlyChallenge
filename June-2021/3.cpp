// Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const unsigned int m = 1000000007;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long mw = 0, mh = 0;
        int i = 0, vs = verticalCuts.size() - 1, hs = horizontalCuts.size() - 1;
        while (i < vs || i < hs) {
            if (i < hs)
                mh = max(long(horizontalCuts[i+1] - horizontalCuts[i]), mh);
            
            if (i < vs)
                mw = max(long(verticalCuts[i+1] - verticalCuts[i]), mw);
            
            i++;
        }
        mw = max(long(verticalCuts[0]), mw);
        mw = max(long(w - verticalCuts[vs]), mw);
        mh = max(long(horizontalCuts[0]), mh);
        mh = max(long(h - horizontalCuts[hs]), mh);
        
        return (int)((mh * mw) % (long)(m));
    }
};