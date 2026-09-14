class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
     // Check if one rectangle is to the left, right, above, or below the other
        bool is_left = rec1[2] <= rec2[0];
        bool is_right = rec1[0] >= rec2[2];
        bool is_bottom = rec1[3] <= rec2[1];
        bool is_top = rec1[1] >= rec2[3];
        
        // They overlap if they are NOT mutually exclusive of overlapping directions
        return !(is_left || is_right || is_bottom || is_top);   
    }
};