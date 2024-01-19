int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    int ans = 2;

    if(a == e && !(a == c && d > min(b, f) && d < max(b, f))) return 1;
    else if(b == f && !(b == d && c > min(a, e) && c < max(a, e))) return 1;
    else if (c + d == e + f && !(c + d == a + b && a > min(c, e) && a < max(c, e))) return 1;
    else if (c - d == e - f && !(c - d == a - b && a > min(c, e) && a < max(c, e))) return 1;

    return ans;
}
