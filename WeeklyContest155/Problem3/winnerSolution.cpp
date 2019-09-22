/* 
 *  This is the solution submitted by the winner of Weekly Contest 155, tfliao
 *  https://leetcode.com/tfliao/
 */


vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int best = 9999999;
    vector<vector<int>> result;
    for (int i=1;i<arr.size();++i) {
        int diff = arr[i] - arr[i-1];
        if (diff < best) {
            result.clear();
            best = diff;
          }
        if (diff == best) {
            vector<int> p({arr[i-1], arr[i]});
            result.push_back(p);
        }
    }
        
    return result;
}
