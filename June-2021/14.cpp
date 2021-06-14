// Maximum Units on Truck

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b) {return a[1] > b[1]; });
        int totalBoxes = 0;
        int totalUnits = 0;
        for (int i = 0; i < boxTypes.size(); i++) {
            if (totalBoxes + boxTypes[i][0] <= truckSize) {
                totalBoxes += boxTypes[i][0];
                totalUnits += (boxTypes[i][0] * boxTypes[i][1]);
            } else {
                totalUnits += (truckSize - totalBoxes) * boxTypes[i][1];
                totalBoxes = truckSize;
            }
            
            if (totalBoxes == truckSize) {
                return totalUnits;
            }
        }
        
        return totalUnits;
    }
};