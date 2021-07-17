function solution(s) {
    if (s.length%2===0)
        return s[parseInt(s.length/2,10)-1]+s[parseInt(s.length/2,10)];
    else
        return s[parseInt(s.length/2,10)];
}
