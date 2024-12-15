class Solution {
    public int countBinarySubstrings(String s) {
        String temp = "";
        int pre_cnt = 0, cnt = 0, tot = 0;
        for (int i = 0; i < s.length(); i++) {
            if (temp == "") {
                temp = "" + s.charAt(i);
                cnt = 1;
            } else if (temp.charAt(0) != s.charAt(i)) {
                tot += Math.min(pre_cnt, cnt);
                temp = "" + s.charAt(i);
                pre_cnt = cnt;
                cnt = 1;
            } else {
                temp += s.charAt(i);
                cnt++;
            }
        }
        tot += Math.min(pre_cnt, cnt);
        return tot;
    }
}
