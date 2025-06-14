int differenceOfSums(int n, int m) {
    int ans = 0;
    for(int i = 1; i < n + 1; i++){
        if(i % m != 0){
            ans += i;
        }else{
            ans -= i;
        }
    }
    return ans;
}

int differenceOfSums(int n, int m) {
    int k = n / m; //m , 2m, 3m, ..., km
    return n * (n + 1) / 2 - 2 * (m * k * (k + 1) / 2);
}
