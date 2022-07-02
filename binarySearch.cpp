bool ok(int m){

}
void solve() {
    //Two invarient l point to possible answer and r point to not possible answer
    int l = -1, r = -1;
    while (l + 1 < r) {
        //Find the middle point
        int m = l + (r - l) / 2;
        //Function to check if the middle point is possible answer or not
        if (ok(m)) {
            //If possible answer then move l to m
            l = m;
        }else {
            //If not possible answer then move r to m
            r = m;
        }
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> 05d37b8e6c4f0d7debfaebc9555ac6af9742ea1d
