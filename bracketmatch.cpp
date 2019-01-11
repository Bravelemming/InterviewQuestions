int bracket_match(string bracket_string) {
    int leftbracket = 0;
    int rightbracket = 0;
    int result;
    
    for (char x : bracket_string){
        if (x == '(' ) {leftbracket++;}
        else if (x == ')' ) {rightbracket++;}
    }
    result = abs(leftbracket - rightbracket);
    
    return result;
}