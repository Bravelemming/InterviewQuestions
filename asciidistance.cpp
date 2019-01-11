int ascii_distance(string str1, string str2) {
    int sum1 = 0;
    int sum2 = 0;
    int distance = 0;
    
    for (char x : str1) {
        sum1 = sum1 + int(x);
    }
    
    for (char x : str2) {
        sum2 = sum2 + int(x);
    }
    
    distance = abs( sum1 - sum2);
    
     return 0;
    
}