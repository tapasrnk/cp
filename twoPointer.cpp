void add(int r) {

}
void remove(int l) {

}
bool good(int l,int r) {

}
void solve(){
    int n;
    int l = 0;
    int ans = 0;
    for (int r = 0; r < n; r++) {
        add (r);
        while (good(l,r)) {
            remove (l);
        }
        //update answer
    }
}